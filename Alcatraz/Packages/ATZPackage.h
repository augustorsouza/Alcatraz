// Package.h
//
// Copyright (c) 2014 Marin Usalj | supermar.in
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

@class ATZInstaller;


typedef NS_ENUM(NSUInteger, ATZPackageWebsiteType) {
    ATZPackageWebsiteTypeGithub,
    ATZPackageWebsiteTypeBitbucket,
    ATZPackageWebsiteTypeOtherGit,
};

@interface ATZPackage : NSObject <NSCoding>

@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *summary;
@property (strong, nonatomic) NSString *type;
@property (strong, nonatomic) NSString *remotePath;
@property (strong, nonatomic) NSString *revision;
@property (strong, nonatomic) NSString *screenshotPath;
@property (nonatomic, readonly) NSString *website;
@property (nonatomic, readonly) NSString *extension;
@property (nonatomic, readonly) BOOL isBlacklisted;
@property (nonatomic, readonly) BOOL isInstalled;
@property (nonatomic, assign)   BOOL requiresRestart;
@property (nonatomic, readonly) ATZPackageWebsiteType websiteType;

- (id)initWithDictionary:(NSDictionary *)dict;

- (void)installWithProgress:(void(^)(NSString *progressMessage, CGFloat progress))progress
                 completion:(void(^)(NSError *failure))completion;

- (void)updateWithProgress:(void(^)(NSString *progressMessage, CGFloat progress))progress
                completion:(void(^)(NSError *failure))completion;

- (void)removeWithCompletion:(void(^)(NSError *failure))completion;

- (void)whitelistWithCompletion:(void(^)(NSError *failure))completion;


#pragma mark - Abstract

- (ATZInstaller *)installer;

@end
