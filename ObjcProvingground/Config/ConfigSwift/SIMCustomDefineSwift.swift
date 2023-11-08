import Foundation
import UIKit

public let SIMColorThemeNavigationBar = NSKeyedUnarchiver.unarchiveObject(with: UserDefaults.standard.value(forKey: "UIColorThemeNavigationBar") as! Data)

public func SIMLocalized(_ key: String) -> String {
    guard let appLanguage = UserDefaults.standard.object(forKey: "appLanguage") as? String else { return key }
    guard let path = Bundle.main.path(forResource: appLanguage , ofType: "lproj") else { return key }
    return Bundle(path: path)?.localizedString(forKey: key, value: nil, table: "SIMLocalizable") ?? key
}
 
public func RGBA(_ r: CGFloat, _ g: CGFloat, _ b: CGFloat, _ a: CGFloat) -> UIColor {
    UIColor(red: r / 255.0, green: g / 255.0, blue: b / 255.0, alpha: a)
}
 
public let defaultTextColor : UIColor = UIColorWithHex("666666")
public let defaultBlackTextColor : UIColor = UIColorWithHex("333333")
public let defaultDetailTextColor : UIColor = UIColorWithHex("999999")
public let defaultRedTextColor : UIColor = UIColorWithHex("F64735")

public let UIColorWithHex = { (hex:String) -> UIColor in
    return UIColor.init(fromHexCode: hex)
}


// MARK: - 屏幕高度 & 屏幕宽度 & 放大系数
/// 屏幕高度
let kScreenHeight = UIScreen.main.bounds.size.height
/// 屏幕宽度
let kScreenWidth = UIScreen.main.bounds.size.width

@objc public class SIMSwiftTool : NSObject {
    
    @objc static let share = SIMSwiftTool()
    /// 获取最顶层的ViewController
    @objc public func topViewController() -> UIViewController? {
        var resultViewController: UIViewController? = nil
        // 多window的情况下， 需要对window进行有效选择选择
        if let rootViewController = UIApplication.shared.keyWindow?.rootViewController {
            resultViewController = __topViewController(object: rootViewController)
            while resultViewController?.presentedViewController != nil {
                resultViewController = resultViewController?.presentedViewController
                resultViewController = __topViewController(object: resultViewController)
            }
        }
        return resultViewController
    }
    private func __topViewController(object: AnyObject!) -> UIViewController? {
        if let navigationController = object as? UINavigationController {
            return __topViewController(object: navigationController.viewControllers.last)
        }
        else if let tabBarController = object as? UITabBarController {
            if tabBarController.selectedIndex < (tabBarController.viewControllers?.count)! {
                return __topViewController(object: tabBarController.viewControllers![tabBarController.selectedIndex])
            }
        }
        else if let vc = object as? UIViewController {
            return vc
        }

        return nil
    }
}
