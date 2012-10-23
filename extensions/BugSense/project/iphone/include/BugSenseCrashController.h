/*
 
 BugSenseCrashController.h
 BugSense-iOS
 
 Copyright (c) 2012 BugSense Inc.
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 
 Author: Nick Toumpelis, nick@bugsense.com
 Author: John Lianeris, jl@bugsense.com
 
 */

#define BUGSENSE_LOG(__EXCEPTION, __TAG) [BugSenseCrashController logException:__EXCEPTION withTag:__TAG]

OBJC_EXPORT @interface BugSenseCrashController : NSObject <UIAlertViewDelegate>

+ (BugSenseCrashController *) sharedInstanceWithBugSenseAPIKey:(NSString *)APIKey;

+ (BugSenseCrashController *) sharedInstanceWithBugSenseAPIKey:(NSString *)APIKey 
                                                userDictionary:(NSDictionary *)userDictionary;

+ (BugSenseCrashController *) sharedInstanceWithBugSenseAPIKey:(NSString *)APIKey 
                                                userDictionary:(NSDictionary *)userDictionary
                                               sendImmediately:(BOOL)immediately;

+ (BOOL) logException:(NSException *)exception withTag:(NSString *)tag;

@end
