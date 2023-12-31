 
//MARK: -  全屏弹出框工具

import UIKit
 
//MARK: - Show Animation type
public enum TYPopupShowAnimation {
    case None
    case FadeIn
    case SlideInFromTop
    case SlideInFromBottom
    case SlideInFromLeft
    case SlideInFromRight
    case Custom // Need implements 'showCustomAnimation'
}

//MARK: - Dismiss Animation
public enum TYPopupDismissAnimation {
    case None
    case FadeOut
    case SlideOutToTop
    case SlideOutToBottom
    case SlideOutToLeft
    case SlideOutToRight
    case Custom // Need implements 'dismissCustomAnimation'
}


//MARK : - Popup Config
public class TYPopViewConfig {
    
    /// Dismiss touch the Background if ture.
    public var dismissTouchBackground = true
    
    /// Popup corner radius value.
    public var cornerRadius: CGFloat = 0
    
    /// Background overlay color.  118,118,118
    public var overlayColor = UIColor(red: 118/255, green: 118/255, blue: 118/255, alpha: 0.5)
    
    /// Show animation type.
    public var showAnimation = TYPopupShowAnimation.FadeIn
    
    /// Dismiss animation type.
    public var dismissAnimation = TYPopupDismissAnimation.FadeOut
    
    /// Clouser show animation is completed.
    /// Pass the popup view to argument.
    public var showCompletion: ((UIView) -> Void)? = nil
    
    /// Clouser disimss animation is completed.
    /// Pass the popup view to argument.
    public var dismissCompletion: ((UIView) -> Void)? = nil
    
    public var showCustomAnimation: (UIView, UIView, (AnyObject) -> Void) -> Void = { containerView, popupView, completion in }
    
    public var dismissCustomAnimation: (UIView, UIView, (AnyObject) -> Void) -> Void = { containerView, popupView, completion in }
    
    public init() {}
}
/// Association key
private var containerViewAssociationKey: UInt8 = 0
private var popupViewAssociationKey: UInt8 = 0
private var configAssociationKey: UInt8 = 0

//MARK: - UIViewController + STZPopupView
extension UIViewController {
    /// Popup view
    private var popupView: UIView? {
        get {
            return objc_getAssociatedObject(self, &popupViewAssociationKey) as? UIView
        }
        set {
            objc_setAssociatedObject(self, &popupViewAssociationKey, newValue, objc_AssociationPolicy.OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    /// Popup config
    private var config: TYPopViewConfig? {
        get {
            return objc_getAssociatedObject(self, &configAssociationKey) as? TYPopViewConfig
        }
        set {
            objc_setAssociatedObject(self, &configAssociationKey, newValue, objc_AssociationPolicy.OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
    }
    
    // MARK: - Show popup
    
    /**
    Show popup
    
    :param: popupView Popup view
    :param: config    Config (Option)
    */
    public func presentPopupView(popupView: UIView,config: TYPopViewConfig!) {
        self.view.addSubview(popupView)
        self.popupView = popupView
        self.config = config
        showAnimation()
    }
    public func presentPopupViewForNav(popupView: UIView,config: TYPopViewConfig!) {
        self.navigationController?.view.addSubview(popupView)  // navigationController 添加
        self.popupView = popupView
        self.config = config
        showAnimation()
    }
    public func presentPopupViewForTabBar(popupView: UIView,config: TYPopViewConfig!) {
        self.tabBarController?.tabBar.addSubview(popupView)  // navigationController 添加
        self.popupView = popupView
        self.config = config
        showAnimation()
    }
    public func presentPopupViewForWindow(popupView: UIView,config: TYPopViewConfig!) {
        
        if  let keyWindow = UIApplication.shared.keyWindow {
            keyWindow.addSubview(popupView)
            self.popupView = popupView
            self.config = config
            showAnimation()
        }
    }
    private func showAnimation() {
        if let config = self.config {
            switch (config.showAnimation) {
            case .None:
                completionShowAnimation(finished: true)
            case .FadeIn:
                fadeIn()
            case .SlideInFromTop:
                slideInFromTop()
            case .SlideInFromBottom:
                slideInFromBottom()
            case .SlideInFromLeft:
                slideInFromLeft()
            case .SlideInFromRight:
                slideInFromRight()
            case .Custom:
                if let containerView = self.view, let popupView = popupView {
                    config.showCustomAnimation(containerView, popupView, { _ in self.completionShowAnimation(finished: true) })
                }
            }
        }
    }
    
    private func completionShowAnimation(finished: Bool) {
        if let completion = config?.showCompletion, let popupView = popupView {
            completion(popupView)
        }
    }
    
    // MARK: - Dismiss popup
    
    /**
    Dismiss popup
    */
    public func dismissPopupView(popupView:UIView) {
        self.popupView = popupView
        dismissAnimation()
    }
    
    private func completionDismissAnimation(finished: Bool) {
        if let completion = config?.dismissCompletion, let popupView =  popupView {
            completion(popupView)
        }
        
        // remove view
        config = nil
    }
    
    private func dismissAnimation() {
        if let config = self.config {
            switch (config.dismissAnimation) {
            case .None:
                fadeOut()
            case .FadeOut:
                fadeOut()
            case .SlideOutToTop:
                slideOutToTop()
            case .SlideOutToBottom:
                slideOutToBottom()
            case .SlideOutToLeft:
                slideOutToLeft()
            case .SlideOutToRight:
                slideOutToRight()
            case .Custom:
                if let containerView = self.view, let popupView = popupView {
                    config.dismissCustomAnimation(containerView, popupView, { _ in self.completionDismissAnimation(finished: true) })
                }
            }
        }
    }
    
    // MARK: - Show Animation
    
    private func fadeIn() {
        if let containerView = self.popupView {
            containerView.alpha = 0
            UIView.animate(withDuration: 0.1, animations: {
                containerView.alpha = 1
                }, completion: completionShowAnimation)
        }
    }
    
    private func slideInFromTop() {
        if let popupView = popupView {
            let center = popupView.center
            var frame = popupView.frame
            frame.origin.y = -frame.height
            popupView.frame = frame
            
            UIView.animate(withDuration: 0.3, animations: {
                popupView.center = center
                }, completion: completionShowAnimation)
        }
    }
    
    private func slideInFromBottom() {
        if let containerView = self.view, let popupView = popupView {
            
            var frame = popupView.frame
            frame.origin.y = kScreenHeight
            popupView.frame = frame
            
            UIView.animate(withDuration: 0.38, animations: {
                var frame = popupView.frame
                frame.origin.y = kScreenHeight -  frame.height
                popupView.frame = frame
                }, completion: completionShowAnimation)
        }
    }
    
    private func slideInFromLeft() {
        if let containerView = self.view, let popupView = popupView {
            
            var frame = popupView.frame
            frame.origin.x = -frame.width
            popupView.frame = frame
            
            UIView.animate(withDuration: 0.3, animations: {
                var frame = popupView.frame
                frame.origin.x = 0
                popupView.frame = frame
                }, completion: completionShowAnimation)
        }
    }
    
    private func slideInFromRight() {
        if let containerView = self.navigationController!.view, let popupView = popupView {
            var frame = popupView.frame
            frame.origin.x = containerView.frame.width+frame.width
            popupView.frame = frame
            
            UIView.animate(withDuration: 0.3, animations: {
                var frame = popupView.frame
                frame.origin.x = containerView.frame.width-frame.width
                popupView.frame = frame
                }, completion: completionShowAnimation)
        }
    }
    
    // MARK: - Dismiss Animation
    
    private func fadeOut() {
        if let containerView = self.popupView {
            UIView.animate(withDuration: 0.1, animations: {
                containerView.alpha = 0
                }, completion: completionDismissAnimation)
            containerView.removeFromSuperview()
        }
    }
    
    private func slideOutToTop() {
        if let _ = self.view, let popupView = popupView {
            UIView.animate(withDuration: 0.3, animations: {
                var frame = popupView.frame
                frame.origin.y = -frame.height
                popupView.frame = frame
                }, completion: completionDismissAnimation)
        }
    }
    
    private func slideOutToBottom() {
        if let containerView = self.view, let popupView = popupView {
            UIView.animate(withDuration: 0.38, animations: {
                var frame = popupView.frame
                frame.origin.y = kScreenHeight
                popupView.frame = frame
                }, completion: completionDismissAnimation)
        }
    }
    
    private func slideOutToLeft() {
        if let _ = self.view, let popupView = popupView {
            UIView.animate(withDuration: 0.3, animations: {
                var frame = popupView.frame
                frame.origin.x = -frame.width
                popupView.frame = frame
                }, completion: completionDismissAnimation)
        }
    }
    private func slideOutToRight() {
        if let containerView = self.view, let popupView = popupView {
            UIView.animate(withDuration: 0.3, animations: {
                var frame = popupView.frame
                frame.origin.x = containerView.frame.width
                popupView.frame = frame
                }, completion: completionDismissAnimation)
        }
    }
}
//MARK: -  全屏  弹出框 showWithBgInWindow  bgEnble : 是否可点击阴影关闭弹出框
 @objc class SIMPopTool : NSObject {
    func showWithBgInView(view:UIView,inView:UIView,showAnimation:TYPopupShowAnimation = .None,dismissAnimation:TYPopupDismissAnimation = .None,bgColor:UIColor = RGBA(0,0,0,0.4),bgEnble:Bool = true) {
        guard let topVc = SIMSwiftTool.share.topViewController() else {
            return
        }
        let bg = UIButton(frame: inView.bounds)
        bg.backgroundColor = bgColor
        bg.addBlock(for: .touchUpInside) { (_) in
            if bgEnble {
                SIMSwiftTool.share.topViewController()?.dismissPopupView(popupView: view)
            }
        }

        topVc.presentPopupView(popupView: bg,config: TYPopViewConfig())
        let config = TYPopViewConfig()
        config.dismissCompletion = { (view1) ->Void in
            bg.removeFromSuperview()
            view.removeFromSuperview()
        }
        config.showAnimation = showAnimation
        config.dismissAnimation = dismissAnimation
        topVc.presentPopupView(popupView: view,config: config)
    }
    
    func showWithBgInWindow(view:UIView,showAnimation:TYPopupShowAnimation = .None,dismissAnimation:TYPopupDismissAnimation = .None,bgColor:UIColor = RGBA(0,0,0,0.4),bgEnble:Bool = true) {
        guard let topVc = SIMSwiftTool.share.topViewController() else {
            return
        }
        
        var bg = UIButton(frame: CGRect(x: 0, y: 0, width: kScreenWidth, height: kScreenHeight))
        if(UIApplication.shared.statusBarOrientation == .landscapeLeft || UIApplication.shared.statusBarOrientation == .landscapeRight){
            bg = UIButton(frame: CGRect(x: 0, y: 0, width: kScreenHeight, height: kScreenWidth))
        }
//        let bg = UIButton(frame: CGRect(x: 0, y: 0, width: kScreenWidth, height: kScreenHeight))
        bg.backgroundColor = bgColor
        bg.addBlock(for: .touchUpInside) { (_) in
            if bgEnble {
                topVc.dismissPopupView(popupView: view)
            }
        }
        topVc.presentPopupViewForWindow(popupView: bg,config: TYPopViewConfig())
        let config = TYPopViewConfig()
        config.dismissCompletion = { (view) ->Void in
            bg.removeFromSuperview()
        }
        config.showAnimation = showAnimation
        config.dismissAnimation = dismissAnimation
        topVc.presentPopupViewForWindow(popupView: view,config: config)
    }
 }
