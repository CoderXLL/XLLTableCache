//
//  EMMConvert.h
//  EMMCache
//
//  Created by 肖乐 on 2017/5/17.
//  Copyright © 2017年 EasyMoveMobile. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EMMConvert : NSObject


/**
 将字典或数组转成json

 @param object 字典或数组对象
 @return json字符串
 */
+ (NSString *)convertObjectToJsonString:(id)object;

/**
 将json字符串转成数组或字典

 @param jsonString json字符串
 @return 数组或字典
 */
+ (instancetype)convertJsonStringToObject:(NSString *)jsonString;

@end
