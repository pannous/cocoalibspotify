//
//  SPAsyncLoadingObserver.h
//  CocoaLibSpotify Mac Framework
//
//  Created by Daniel Kennett on 12/04/2012.
/*
 Copyright (c) 2011, Spotify AB
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 * Neither the name of Spotify AB nor the names of its contributors may 
 be used to endorse or promote products derived from this software 
 without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL SPOTIFY AB BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

/** Helper class providing a simple callback mechanism for when objects are loaded. */ 

@interface SPAsyncLoadingObserver : NSObject

/** Call the provided callback block when all passed items are loaded.
 
 The callback block will be triggered immediately if no items are provided 
 or all provided items are already loaded.
 
 @param items An array of items conforming to the `SPAsyncLoading` protocol.
 @param block The block to call when all given items are loaded.
 */
+(void)waitUntilLoaded:(NSArray *)items then:(void (^)(NSArray *))block;

/** Call the provided callback block when all passed items are loaded or the
 given timeout is reached.
 
 The callback block will be triggered immediately if no items are provided 
 or all provided items are already loaded.
 
 @param items An array of items conforming to the `SPAsyncLoading` protocol.
 @param timeout Time to allow before timing out.
 @param block The block to call when all given items are loaded or the timeout is reached.
 */
+(void)waitUntilLoaded:(NSArray *)items timeout:(NSTimeInterval)timeout then:(void (^)(NSArray *loadedItems, NSArray *notLoadedItems))block;

@end
