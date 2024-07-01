#import <Foundation/Foundation.h>
#import "SimDisplayIOSurfaceRenderable-Protocol.h"
#import "SimDisplayRenderable-Protocol.h"
#import <IOSurface/IOSurface.h>
#import <IOSurface/IOSurfaceObjC.h>

typedef void (^CallbackIOSurface)(IOSurface *surface);
typedef void (^CallbackNSArray)(NSArray *cgRects);

@protocol SimDeviceEventEmitterDelegate <NSObject>
- (void)didChangeIOSurface:(IOSurface *)surface;
- (void)didReceiveDamageRect:(NSArray *)cgRects;
@end

@interface SimDeviceFramework : NSObject

@property (nonatomic, strong, readonly) id<SimDisplayIOSurfaceRenderable, SimDisplayRenderable> surface;

- (instancetype)initWithSurface:(id<SimDisplayIOSurfaceRenderable, SimDisplayRenderable>)surface;
- (void)setup:(NSUUID *)uuid queue:(dispatch_queue_t)queue ioCallback:(CallbackIOSurface)ioCallback cgRects:(CallbackNSArray)cgRects;
- (void)remove:(NSUUID *)uuid;

@end
