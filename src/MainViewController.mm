#import <UIKit/UIKit.h>
#include "EnvironmentChecker.hpp"

@interface MainViewController : UIViewController
@property (nonatomic, strong) UILabel *statusLabel;
@property (nonatomic, strong) UIButton *checkButton;
@property (nonatomic, strong) UIButton *demoButton;
@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor systemBackgroundColor];
    [self setupUI];
}

- (void)setupUI {
    UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, 80, self.view.frame.size.width - 40, 40)];
    titleLabel.text = @"MS PLUG IN";
    titleLabel.font = [UIFont boldSystemFontOfSize:28];
    titleLabel.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:titleLabel];

    self.statusLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, 150, self.view.frame.size.width - 40, 100)];
    self.statusLabel.numberOfLines = 0;
    self.statusLabel.textAlignment = NSTextAlignmentCenter;
    self.statusLabel.text = @"Chào mừng đến với MS Plug In!\nBấm 'Start Check' để quét môi trường.";
    [self.view addSubview:self.statusLabel];

    self.checkButton = [UIButton buttonWithType:UIButtonTypeSystem];
    self.checkButton.frame = CGRectMake(40, 280, self.view.frame.size.width - 80, 50);
    [self.checkButton setTitle:@"Start System Check" forState:UIControlStateNormal];
    self.checkButton.backgroundColor = [UIColor systemBlueColor];
    [self.checkButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    self.checkButton.layer.cornerRadius = 10;
    [self.checkButton addTarget:self action:@selector(onCheckClicked) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.checkButton];

    self.demoButton = [UIButton buttonWithType:UIButtonTypeSystem];
    self.demoButton.frame = CGRectMake(40, 350, self.view.frame.size.width - 80, 50);
    [self.demoButton setTitle:@"Skip to Demo Mode" forState:UIControlStateNormal];
    [self.demoButton addTarget:self action:@selector(onDemoClicked) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.demoButton];
}

- (void)onCheckClicked {
    MSPlugIn::EnvironmentChecker checker;
    MSPlugIn::SystemInfo info = checker.runDiagnostics();

    if (info.envType == MSPlugIn::EnvironmentType::JAILBREAK_MODE) {
        self.statusLabel.text = @"[Jailbreak Detected]\nĐang chuyển hướng mở Sileo...";
        NSURL *sileoURL = [NSURL URLWithString:@"sileo://source/https://your-custom-repo.github.io/"];
        if ([[UIApplication sharedApplication] canOpenURL:sileoURL]) {
            [[UIApplication sharedApplication] openURL:sileoURL options:@{} completionHandler:nil];
        }
    } 
    else if (info.envType == MSPlugIn::EnvironmentType::TROLLSTORE_MODE) {
        self.statusLabel.text = @"[TrollStore Detected]\nKhởi động FULL Mode:\nMulti-Melon & Live Inject!";
    } 
    else {
        self.statusLabel.text = @"[Non-JB Device]\nGợi ý dùng SideStore / AltStore.\nChuyển sang Demo Mode...";
    }
}

- (void)onDemoClicked {
    self.statusLabel.text = @"Đã vào Demo Mode!\nMenu Bật/Tắt Dylib sẵn sàng tiêm vào IPA.";
}

@end

