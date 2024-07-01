#import <Foundation/Foundation.h>

#import "FoundationXPCProtocolProxyable.h"

@protocol SimDisplayIOSurfaceRenderable <FoundationXPCProtocolProxyable>

@property (readonly, nullable, nonatomic) id ioSurface;

@property (readonly, nullable, nonatomic) id framebufferSurface;

@property (readonly, nullable, nonatomic) id maskedFramebufferSurface;

- (void)unregisterIOSurfaceChangeCallbackWithUUID:(NSUUID *)arg1;
- (void)registerCallbackWithUUID:(NSUUID *)arg1 ioSurfaceChangeCallback:(void (^)(id))arg2;

- (void)unregisterIOSurfacesChangeCallbackWithUUID:(NSUUID *)arg1;
- (void)registerCallbackWithUUID:(NSUUID *)arg1 ioSurfacesChangeCallback:(void (^)(id))arg2;

@end




