//
//	 ______    ______    ______
//	/\  __ \  /\  ___\  /\  ___\
//	\ \  __<  \ \  __\_ \ \  __\_
//	 \ \_____\ \ \_____\ \ \_____\
//	  \/_____/  \/_____/  \/_____/
//
//
//	Copyright (c) 2013-2014, {Bee} open source community
//	http://www.bee-framework.com
//
//
//	Permission is hereby granted, free of charge, to any person obtaining a
//	copy of this software and associated documentation files (the "Software"),
//	to deal in the Software without restriction, including without limitation
//	the rights to use, copy, modify, merge, publish, distribute, sublicense,
//	and/or sell copies of the Software, and to permit persons to whom the
//	Software is furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//	IN THE SOFTWARE.
//

#import "Bee_Precompile.h"
#import "Bee_Foundation.h"

#if __BEE_MOCKSERVER__

#import "Bee_HTTPPackage.h"
#import "Bee_HTTPRequest.h"
#import "Bee_HTTPRequestQueue.h"

#pragma mark -

AS_PACKAGE( BeePackage_HTTP, BeeHTTPMockServer, mockServer );

#pragma mark -

@class BeeHTTPMockServer;
@compatibility_alias BeeMockServer BeeHTTPMockServer;

#pragma mark -

@interface BeeHTTPMockServer : NSObject

AS_SINGLETON( BeeHTTPMockServer )

@property (nonatomic, retain) NSMutableArray * mapping;

- (void)load;
- (void)unload;

+ (void)route:(BeeHTTPRequest *)req;
- (BOOL)route:(BeeHTTPRequest *)req;
- (BOOL)prehandle:(BeeHTTPRequest *)req;
- (void)posthandle:(BeeHTTPRequest *)req;

- (void)rule:(NSString *)rule;
- (void)rule:(NSString *)rule action:(SEL)action;
- (void)rule:(NSString *)rule action:(SEL)action target:(id)target;

@end

#endif	// #if __BEE_MOCKSERVER__
