// Minimal Objective-C++ view controller placeholder

#import <Foundation/Foundation.h>

// Nếu bạn sẽ xây dựng App iOS thực tế, hãy import UIKit và triển khai UIViewController.
// Đây chỉ là file placeholder để lưu trữ mã Objective-C++ trong repo.

@interface MainViewController : NSObject

- (instancetype)init;
- (void)start;

@end

@implementation MainViewController

- (instancetype)init {
    self = [super init];
    if (self) {
        // Init
    }
    return self;
}

- (void)start {
    NSLog(@"[MainViewController] start placeholder");
}

@end
