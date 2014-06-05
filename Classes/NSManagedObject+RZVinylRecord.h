//
//  NSManagedObject+RZVinylRecord.h
//  RZVinylDemo
//
//  Created by Nick Donaldson on 6/4/14.
//
//  Copyright 2014 Raizlabs and other contributors
//  http://raizlabs.com/
//
//  Permission is hereby granted, free of charge, to any person obtaining
//  a copy of this software and associated documentation files (the
//                                                                "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish,
//  distribute, sublicense, and/or sell copies of the Software, and to
//  permit persons to whom the Software is furnished to do so, subject to
//  the following conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

@import CoreData;

@class RZCoreDataStack;

@interface NSManagedObject (RZVinylRecord)

//
//  Creation
//

/**
 *  Create and return a new instance in the current thread's default context.
 *
 *  @return A new object instance.
 */
+ (instancetype)rzv_newObject;

/**
 *  Create and return a new instance in the provided context.
 *
 *  @param context The context in which to create the instance.
 *
 *  @return A new object instance.
 */
+ (instancetype)rzv_newObjectInContext:(NSManagedObjectContext *)context;

/**
 *  Return an instance of this managed object class with the provided value for its primary key
 *  from the current thread's context.
 *
 *  @param primaryValue The value of the primary key (e.g. the remoteID)
 *  @param createNew    Pass YES to create a new object if one is not found.
 *
 *  @warning Calling this on a class that does not return a value for @p rzv_primaryKey will throw an exception.
 *
 *  @return An existing or new instance of this managed object class with the provided primary key
 *          value, or nil if @p createNew is NO and an existing object was not found.
 */
+ (instancetype)rzv_objectWithPrimaryKeyValue:(id)primaryValue createNew:(BOOL)createNew;

/**
 *  Return an instance of this managed object class with the provided value for its primary key
 *  from the provided context.
 *
 *  @param primaryValue The value of the primary key (e.g. the remoteID)
 *  @param createNew    Pass YES to create a new object if one is not found.
 *  @param context      The context
 *
 *  @warning Calling this on a class that does not return a value for @p rzv_primaryKey will throw an exception.
 *
 *  @return An existing or new instance of this managed object class with the provided primary key
 *          value, or nil if @p createNew is NO and an existing object was not found.
 */
+ (instancetype)rzv_objectWithPrimaryKeyValue:(id)primaryValue createNew:(BOOL)createNew inContext:(NSManagedObjectContext *)context;

//
//  Query/Fetch
//

/**
 *  Return an array of all objects of the receiver's entity in the current thread's context.
 *
 *  @return All objects of this class's entity type.
 */
+ (NSArray *)rzv_all;

/**
 *  Return an array of all objects of the receiver's entity in the current thread's context, optionally sorted.
 *
 *  @param sortDescriptors An array of sort descriptors to sort the results.
 *
 *  @return All objects of this class's entity type.
 */
+ (NSArray *)rzv_allSorted:(NSArray *)sortDescriptors;

/**
 *  Return an array of all objects of the receiver's entity in the provided context, optionally sorted.
 *
 *  @param sortDescriptors An array of sort descriptors to sort the results.
 *  @param context         The context from which to fetch objects.
 *
 *  @return All objects of this class's entity type.
 */
+ (NSArray *)rzv_allSorted:(NSArray *)sortDescriptors inContext:(NSManagedObjectContext *)context;

/**
 *  Return the results of a fetch on the current thread's context using a predicate or format string.
 *
 *  @param query An @p NSPredicate or predicate format string. Passing nil will return all objects.
 *
 *  @return The results of the fetch.
 */
+ (NSArray *)rzv_where:(id)query;

/**
 *  Return the results of a fetch on the current thread's context using a predicate or format string
 *  with optional sorting.
 *
 *  @param query            An @p NSPredicate or predicate format string. Passing nil will return all objects.
 *  @param sortDescriptors  An optional array of sort descriptors.
 *
 *  @return The results of the fetch.
 */
+ (NSArray *)rzv_where:(id)query sort:(NSArray *)sortDescriptors;

/**
 *  Return the results of a fetch on a particular context using a predicate or format string
 *  with optional sorting.
 *
 *  @param query            An @p NSPredicate or predicate format string. Passing nil will return all objects.
 *  @param sortDescriptors  An optional array of sort descriptors.
 *  @param context          The managed object context on which to perform the fetch. Must not be nil.
 *
 *  @return The results of the fetch.
 */
+ (NSArray *)rzv_where:(id)query sort:(NSArray *)sortDescriptors inContext:(NSManagedObjectContext *)context;


+ (NSUInteger)rzv_count;

+ (NSUInteger)rzv_countInContext:(NSManagedObjectContext *)context;

+ (NSUInteger)rzv_countWhere:(id)query;

+ (NSUInteger)rzv_countWhere:(id)query inContext:(NSManagedObjectContext *)context;

////
////  Save/Delete
////
//
//- (BOOL)save;
//
//- (BOOL)delete;

//
//  Metadata
//

+ (NSString *)rzv_entityName;

//
//  Subclassing
//

/**
 *  Overrie in subclasses to provide the keypath to the property uniquely
 *  identifying this object
 *
 *  @return The keypath of the property uniquely identifying this object.
 */
+ (NSString *)rzv_primaryKey;

/**
 *  Override in subclasses to provide a different data stack for use with this
 *  model object class. Defaults to the @p +defaultStack of @p RZDataStackAccess
 *
 *  @return The data stack to use for this model object class.
 */
+ (RZCoreDataStack *)rzv_coreDataStack;

@end