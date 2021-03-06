//
//  RZPersonLoader.h
//  RZVinylDemo
//
//  Created by Nick Donaldson on 6/20/14.
//  Copyright (c) 2014 Raizlabs. All rights reserved.
//

/**
 *  Imports person objects asynchronously from a static JSON file in batches using RZImport
 */
@interface RZPersonLoader : NSObject

- (void)loadPeopleWithBatchSize:(NSUInteger)batchSize
                     completion:(void(^)(NSError *err))completion;

@end
