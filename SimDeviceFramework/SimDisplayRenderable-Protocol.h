#import <Foundation/Foundation.h>
#import "FoundationXPCProtocolProxyable.h"

@protocol SimDisplayRenderable <FoundationXPCProtocolProxyable, NSObject>
@property (nonatomic, readonly) long long displaySizeInBytes;
@property (nonatomic, readonly) long long displayPitch;
@property (nonatomic, readonly) struct CGSize optimizedDisplaySize;
@property (nonatomic, readonly) struct CGSize displaySize;

- (void)unregisterDamageRectanglesCallbackWithUUID:(NSUUID *)arg1;
- (void)registerCallbackWithUUID:(NSUUID *)arg1 damageRectanglesCallback:(void (^)(NSArray *))arg2;

@end
