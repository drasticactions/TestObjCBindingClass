#import "SimDeviceFramework.h"
#import "SimDisplayIOSurfaceRenderable-Protocol.h"
#import "SimDisplayRenderable-Protocol.h"
#import <IOSurface/IOSurface.h>
#import <IOSurface/IOSurfaceObjC.h>

@implementation SimDeviceFramework

- (instancetype)initWithSurface:(id<SimDisplayIOSurfaceRenderable, SimDisplayRenderable>)surface
{
  _surface = surface;

  return self;
}

- (void)setup:(NSUUID *)uuid queue:(dispatch_queue_t)queue ioCallback:(CallbackIOSurface)ioCallback cgRects:(CallbackNSArray)cgRects
{
  void (^ioSurfaceChanged)(IOSurface *) = ^void(IOSurface *surface) {
    dispatch_async(queue, ^{
        ioCallback(surface);
    });
  };

  [self.surface registerCallbackWithUUID:uuid ioSurfacesChangeCallback:ioSurfaceChanged];

  [self.surface registerCallbackWithUUID:uuid damageRectanglesCallback:^(NSArray<NSValue *> *frames) {
    dispatch_async(queue, ^{
        cgRects(frames);
    });
  }];
}

- (void)remove:(NSUUID *)uuid
{
    [self.surface unregisterIOSurfacesChangeCallbackWithUUID:uuid];
    [self.surface unregisterDamageRectanglesCallbackWithUUID:uuid];
}
@end
