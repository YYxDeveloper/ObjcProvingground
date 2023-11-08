//
//  UIImage+GradientColor.swift
//  PGTalk
//
//  Created by macmini on 2021/1/21.
//  Copyright © 2021  _J. All rights reserved.
//

import Foundation
import UIKit

@objc extension UIImage {
    @objc class func gradientImage(colors: [UIColor], locations: [NSNumber], startPoint: CGPoint, endPoint: CGPoint, size: CGSize) -> UIImage? {
        UIGraphicsBeginImageContext(size)
        let context = UIGraphicsGetCurrentContext()
        if let context = context {
            
            var cgColors: [CGColor] = []
            for color in colors {
                cgColors.append(color.cgColor)
            }
            
            let layer = CAGradientLayer()
            layer.frame = CGRect(x: 0, y: 0, width: size.width, height: size.height)
            layer.colors = cgColors
            layer.locations = locations
            layer.startPoint = startPoint
            layer.endPoint = endPoint
            layer.render(in: context)
        }
        let image = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return image
    }
}
