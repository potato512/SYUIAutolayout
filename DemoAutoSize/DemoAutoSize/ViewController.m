//
//  ViewController.m
//  DemoAutoSize
//
//  Created by zhangshaoyu on 16/6/8.
//  Copyright © 2016年 zhangshaoyu. All rights reserved.
//

#import "ViewController.h"
#import "AutoSizeCGRect.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSString *title = [NSString stringWithFormat:@"适配 %@", (IS_IPHONE_4_OR_LESS_AutoSize ? @"iPhone4" : (IS_IPHONE_5_AutoSize ? @"iPhone5" : (IS_IPHONE_6_AutoSize ? @"iPhone6" : @"iPhone6Plus")))];
    self.title = title;
    
    
    CGFloat originY = 80.0;
    
    UILabel *label001 = [[UILabel alloc] init];
    [self.view addSubview:label001];
    label001.backgroundColor = [UIColor greenColor];
    label001.adjustsFontSizeToFitWidth = YES;
    label001.text = @"CGRectMake(10.0, 80.0, 200.0, 30.0)";
    // 使用系统自带的CGRectMake方法，无适配
    label001.frame = CGRectMake(10.0, originY, 200.0, 30.0);
    
    originY += (CGRectGetHeight(label001.frame) + 10.0);
    
    UILabel *label002 = [[UILabel alloc] init];
    [self.view addSubview:label002];
    label002.backgroundColor = [UIColor brownColor];
    label002.adjustsFontSizeToFitWidth = YES;
    label002.text = [NSString stringWithFormat:@"AutoSizeDidCGRectMake(10.0, %@, 200.0, 30.0)", @(originY)];
    label002.frame = AutoSizeDidCGRectMake(10.0, originY, 200.0, 30.0);
    
    // 方法1 获取实际高度
//    originY += (CGRectGetHeight(label002.frame) + 10.0);
    // 方法2 根据适配比例计算实际高度
    originY += (AutoSizeGetHeight(30.0) + 10.0);
    
    UILabel *label003 = [[UILabel alloc] init];
    [self.view addSubview:label003];
    label003.backgroundColor = [UIColor purpleColor];
    label003.adjustsFontSizeToFitWidth = YES;
    label003.text = [NSString stringWithFormat:@"AutoSizeDidCGRectMake(10.0, %@, 200.0, 30.0)", @(originY)];
    // 使用自定义的CGRectMake方法，根据不同版本进行适配
    // 方法1 宽高根据适配比例自动进行计算适配
//    label003.frame = AutoSizeShouldCGRectMake(10.0, originY, 200.0, 30.0, YES, YES);
    // 方法2 宽高根据适配比例自动进行计算适配
    CGFloat height = AutoSizeGetHeight(30.0);
    CGFloat width = AutoSizeGetWidth(200.0);
    label003.frame = CGRectMake(10.0, originY, width, height);
    // 方法3 宽高根据适配比例自动进行计算适配
//    label003.frame = AutoSizeDidCGRectMake(10.0, originY, 200.0, 30.0);
    
    originY += (CGRectGetHeight(label003.frame) + 10.0);
    
    UIImageView *imageview001 = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"image"]];
    [self.view addSubview:imageview001];
    imageview001.backgroundColor = [UIColor greenColor];
    // 使用系统自带的CGRectMake方法，无适配
    imageview001.frame = CGRectMake(10.0, originY, 100.0, 100.0);
    
    CGFloat originX = (CGRectGetWidth(imageview001.frame) + 10.0 + 10.0);
    
    UIImageView *imageview002 = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"image"]];
    [self.view addSubview:imageview002];
    imageview002.backgroundColor = [UIColor greenColor];
    // 使用自定义的CGRectMake方法，根据不同版本进行适配
    // 方法1 宽高根据适配比例自动进行计算适配，图标设置非正方法
//    imageview002.frame = AutoSizeShouldCGRectMake(originX, originY, 100.0, 100.0, YES, YES);
    // 方法2 高根据适配比例自动进行计算适配，图标设置为正方法
    CGFloat sizeImage = AutoSizeGetHeight(100.0);
    imageview002.frame = CGRectMake(originX, originY, sizeImage, sizeImage);
    // 方法3 宽高根据适配比例自动进行计算适配，图标设置非正方法
//    imageview002.frame = AutoSizeDidCGRectMake(originX, originY, 100.0, 100.0);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
