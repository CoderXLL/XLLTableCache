//
//  EMMDBQueue.h
//  EMMCache
//
//  Created by 肖乐 on 2017/5/16.
//  Copyright © 2017年 EasyMoveMobile. All rights reserved.
//  操作FMDB的queue

#import <Foundation/Foundation.h>
#import "FMDB.h"

@interface EMMDBQueue : NSObject


/**
 初始化queue对象（单例）

 @return queue对象
 */
+ (instancetype)shareInstance;


/**
 操作数据库的queue
 */
@property (nonatomic, retain, readonly) FMDatabaseQueue *dbQueue;


/**
 设置数据库名称

 @param baseName 数据库名称
 */
- (void)setDataBaseName:(NSString *)baseName;

@end
