//  Copyright 2013 Ben Blakely. All rights reserved.
//  See included License file for licensing information.

#import <Foundation/Foundation.h>

@interface BBActionSheet : NSObject

@property (nonatomic) NSString *title;
@property (nonatomic, readonly, getter=isVisible) BOOL visible;
@property (nonatomic) UIActionSheetStyle actionSheetStyle;
@property (nonatomic, readonly) NSInteger numberOfButtons;
@property (nonatomic) NSInteger cancelButtonIndex;
@property (nonatomic) NSInteger destructiveButtonIndex;
@property (nonatomic, readonly) NSInteger firstOtherButtonIndex;
@property (nonatomic, copy) void (^willDismissHandler)(NSInteger buttonIndex);
@property (nonatomic, copy) void (^didDismissHandler)(NSInteger buttonIndex);

- (id)initWithTitle:(NSString *)title;

- (NSInteger)addButtonWithTitle:(NSString *)title clicked:(void (^)())handler;
- (NSInteger)addButtonWithTitle:(NSString *)title willDismiss:(void (^)())handler;
- (NSInteger)addButtonWithTitle:(NSString *)title didDismiss:(void (^)())handler;
- (NSInteger)addButtonWithTitle:(NSString *)title
                        clicked:(void (^)())clicked
                    willDismiss:(void (^)())willDismiss
                     didDismiss:(void (^)())didDismiss;
- (NSInteger)addCancelButtonWithTitle:(NSString *)title;

- (NSString*)buttonTitleAtIndex:(NSInteger)buttonIndex;

- (void)showFromTabBar:(UITabBar *)view;
- (void)showFromToolbar:(UIToolbar *)view;
- (void)showInView:(UIView *)view;
- (void)showFromBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated;
- (void)showFromRect:(CGRect)rect inView:(UIView *)view animated:(BOOL)animated;

- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

@end
