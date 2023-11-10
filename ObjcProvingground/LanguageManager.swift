//
//  LanguageManager.swift
//  PGTalk
//
//  Created by JACK on 2020/10/27.
//  Copyright © 2020  . All rights reserved.
//

import Foundation

@objc public class LanguageManager : NSObject {
    @objc static public func g_Languages() -> NSArray {
        // localCode 保持本地文件前缀一致
//        return  [LanguageModel(name: "简体中文", remoteCode: "zh-cn", localCode: "zh-Hans",tips: "将要切换到简体中文"),
//                 LanguageModel(name: "繁體中文", remoteCode: "zh-tc", localCode: "zh-Hant",tips: "將要切換到繁體中文"),
//                 LanguageModel(name: "English", remoteCode: "en-us", localCode: "en",tips: "Will switch to English"),
//                 LanguageModel(name: "日本語", remoteCode: "zh-jp", localCode: "ja",tips: "日本語に切り替えます"),
//                 LanguageModel(name: "한국어", remoteCode: "zh-ko", localCode: "ko",tips: "곧 한국 어로 바 꿀 것이다."),
//                 LanguageModel(name: "ภาษาไทย", remoteCode: "zh-th", localCode: "th",tips: "จะเปลี่ยนเป็นภาษาไทย")]
        return  [LanguageModel(name: "繁體中文", remoteCode: "zh-tc", localCode: "zh-Hant",tips: "將要切換到繁體中文"),
                 LanguageModel(name: "简体中文", remoteCode: "zh-cn", localCode: "zh-Hans",tips: "将要切换到简体中文"),
                 LanguageModel(name: "English", remoteCode: "en-us", localCode: "en",tips: "Will switch to English"),
                 LanguageModel(name: "日本語", remoteCode: "zh-jp", localCode: "ja",tips: "日本語に切り替えます"),
                 LanguageModel(name: "한국어", remoteCode: "zh-ko", localCode: "ko",tips: "곧 한국 어로 바 꿀 것이다."),
                 LanguageModel(name: "ภาษาไทย", remoteCode: "zh-th", localCode: "th",tips: "จะเปลี่ยนเป็นภาษาไทย"),
                 LanguageModel(name: "Việt Nam", remoteCode: "zh-vn", localCode: "vi",tips: "Sắp chuyển sang tiếng Việt")]
    }
    
    @objc static public func local_transferToRemote(localStr: String?) -> String {
        var transfer_appLanguage = ""

        //设置了语言
        let string = localStr ?? UserDefaults.standard.object(forKey: "appLanguage") as? String
        transfer_appLanguage = "en-us"
        let languageAll = LanguageManager.g_Languages()
        for language in languageAll {
            guard let language = language as? LanguageModel else {
                continue
            }
            if string?.hasPrefix(language.localCode) ?? false {
                transfer_appLanguage = language.remoteCode
                break
            }
        }
        
        return transfer_appLanguage
    }
    @objc static public func localLanguageCode() -> String {
        return UserDefaults.standard.object(forKey: "appLanguage") as? String ?? ""
    }
    @objc static public func setLanguageFromIphone() {
//        guard UserDefaults.standard.object(forKey: "language") == nil  else { return }
        let language = UserDefaults.standard.object(forKey: "language") as? String ?? ""
        guard let languageStr = NSLocale.preferredLanguages.first  else { return }
        if languageStr == language {
            // 系统语言与上次记录的系统语言相同
            let defaults = UserDefaults(suiteName: "group.com.FBS.NewsPGTalk.IM")
            let appLang = defaults?.object(forKey: "appLanguage") as? String ?? ""
            if (appLang.isEmpty) {
                let appLanguage = UserDefaults.standard.object(forKey: "appLanguage") as? String ?? ""
                defaults?.set(appLanguage, forKey: "appLanguage")
            }
            return;
        }
        let defaults = UserDefaults(suiteName: "group.com.FBS.NewsPGTalk.IM")
        
        if languageStr.hasPrefix("zh-Hans") {
            UserDefaults.standard.set("zh-Hans", forKey: "appLanguage")
            UserDefaults.standard.set(languageStr, forKey: "language")
            defaults?.set("zh-Hans", forKey: "appLanguage")
        } else if languageStr.hasPrefix("en") {
            UserDefaults.standard.set("en", forKey: "appLanguage")
            UserDefaults.standard.set(languageStr, forKey: "language")
            defaults?.set("en", forKey: "appLanguage")
        } else if languageStr.hasPrefix("ja") {
            UserDefaults.standard.set("ja", forKey: "appLanguage")
            UserDefaults.standard.set(languageStr, forKey: "language")
            defaults?.set("ja", forKey: "appLanguage")
        } else if languageStr.hasPrefix("ko") {
            UserDefaults.standard.set("ko", forKey: "appLanguage")
            UserDefaults.standard.set(languageStr, forKey: "language")
            defaults?.set("ko", forKey: "appLanguage")
        } else if languageStr.hasPrefix("th") {
            UserDefaults.standard.set("th", forKey: "appLanguage")
            UserDefaults.standard.set(languageStr, forKey: "language")
            defaults?.set("th", forKey: "appLanguage")
        } else if languageStr.hasPrefix("vi") {
            UserDefaults.standard.set("vi", forKey: "appLanguage")
            UserDefaults.standard.set(languageStr, forKey: "language")
            defaults?.set("vi", forKey: "appLanguage")
        } else if languageStr.hasPrefix("zh-Hant") {
            UserDefaults.standard.set("zh-Hant", forKey: "appLanguage")
            UserDefaults.standard.set(languageStr, forKey: "language")
            defaults?.set("zh-Hant", forKey: "appLanguage")
        } else {
            // 没有
            let appLanguage = UserDefaults.standard.object(forKey: "appLanguage") as? String ?? ""
            if appLanguage.isEmpty {
                UserDefaults.standard.set("en", forKey: "appLanguage")
                UserDefaults.standard.set(languageStr, forKey: "language")
                defaults?.set("en", forKey: "appLanguage")
            } else {
                UserDefaults.standard.set(languageStr, forKey: "language")
                defaults?.set("en", forKey: "appLanguage")
            }
        }
    }
}
@objc class LanguageModel : NSObject {
    @objc var name : String!
    @objc var remoteCode : String!
    @objc var localCode : String!
    
    @objc var tips : String!
    
    init(name : String,remoteCode : String,localCode : String) {
        self.name = name
        self.remoteCode = remoteCode
        self.localCode = localCode
    }
    init(name : String,remoteCode : String,localCode : String,tips : String) {
        self.name = name
        self.remoteCode = remoteCode
        self.localCode = localCode
        self.tips = tips
    }
}


 
