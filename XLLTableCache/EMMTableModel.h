//
//  EMMTableModel.h
//  EMMCache
//
//  Created by 肖乐 on 2017/5/16.
//  Copyright © 2017年 EasyMoveMobile. All rights reserved.
//  表里面存的为模型数据，将需要存储的数据模型存入表里面即可

#import <Foundation/Foundation.h>
#import "FMDB.h"

@interface EMMTableModel : NSObject


/**
 主键
 */
@property (nonatomic, assign) int majorKey;

/**
 表的列名
 */
@property (nonatomic, strong, readonly) NSMutableArray *columnNames;

/**
 列类型
 */
@property (nonatomic, strong, readonly) NSMutableArray *columnTypes;


/**
 创建数据表（必须由所属类调用）

 @return YES 创建成功
 */
+ (BOOL)creatDBTable;


/**
 得到表中所有的字段

 @return 所有字段集合
 */
+ (NSArray *)getTableColumns;



//////////////////////// 增删改查操作 /////////////////////////////

#pragma mark - 增
/**
 将对象属性插入到表中
 
 @return YES 插入成功
 */
- (BOOL)insertSingleData;


/**
 批量插入

 @param objects 插入的数据模型集合(多个不同模型)
 @return YES 插入成功
 */
+ (BOOL)insertObjects:(NSArray <EMMTableModel *> *)objects;

#pragma mark - 删
/**
 将对象从表里删除

 @return YES 删除成功
 */
- (BOOL)deleteSingleData;

/**
 批量删除

 @param objects 删除的数据模型集合
 @return YES 删除成功
 */
+ (BOOL)deleteObjects:(NSArray <EMMTableModel *> *)objects;

/**
 根据条件删除（必须由所属类调用）

 @param format 条件 形式例如：@"Where MajorKey < \'%d\'", 4
 @return YES 删除成功
 */
+ (BOOL)deleteObjectByFormat:(NSString *)format, ... NS_REQUIRES_NIL_TERMINATION;

/**
 全部删除

 @return YES 删除成功
 */
+ (BOOL)deleteAllData;

#pragma mark - 查

/**
 查询全部数据

 @return 查询全部的数据模型集合
 */
+ (NSArray <EMMTableModel *> *)queryAllData;

/**
 通过条件查询

 @param format 条件 形式例如：@"Where MajorKey < \'%d\'", 4
 @return 根据条件查询的模型集合
 */
+ (NSArray <EMMTableModel *> *)queryDataWithFormat:(NSString *)format, ... NS_REQUIRES_NIL_TERMINATION;

#pragma mark - 改
/**
 根据条件更新

 @param format 条件
 @return YES 事务更新成功
 */
- (BOOL)updateDataWithFormat:(NSString *)format, ... NS_REQUIRES_NIL_TERMINATION;


/**
 在子类中重写，主要是用于存储模型中的字典,数组

 @return 模型中的字典数组属性集合
 */
+ (NSArray *)specialTransients;

@end
