//
//  PanelNavigationControllerViewController.h
//  WordPress
//
//  Created by Jorge Bernal on 5/21/12.
//  Copyright (c) 2012 WordPress. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PanelNavigationController : UIViewController

#pragma mark - Initialization

- (id)initWithDetailController:(UIViewController *)detailController masterViewController:(UIViewController *)masterController;

#pragma mark - Navigation methods
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated; // Uses a horizontal slide transition. Has no effect if the view controller is already in the stack.

- (UIViewController *)popViewControllerAnimated:(BOOL)animated; // Returns the popped controller.
- (NSArray *)popToViewController:(UIViewController *)viewController animated:(BOOL)animated; // Pops view controllers until the one specified is on top. Returns the popped controllers.
- (NSArray *)popToRootViewControllerAnimated:(BOOL)animated; // Pops until there's only a single view controller left on the stack. Returns the popped controllers.

#pragma mark - Controllers
@property(nonatomic,retain) UIViewController *detailViewController; // The first detail controller
- (void)setDetailViewController:(UIViewController *)detailViewController closingSidebar:(BOOL)closingSidebar;
@property(nonatomic,retain) UIViewController *masterViewController; // The sidebar (left) controller
@property(nonatomic,readonly,retain) UINavigationController *navigationController; // The navigation controller on iPhone.
@property(nonatomic,readonly,retain) UIViewController *rootViewController; // The navigation controller on iPhone, masterViewController on iPad
@property(nonatomic,readonly,retain) UIViewController *topViewController; // The top view controller on the stack.
@property(nonatomic,readonly,retain) UIViewController *visibleViewController; // Return modal view controller if it exists. Otherwise the top view controller.

//@property(nonatomic,copy) NSArray *viewControllers; // The current view controller stack.

@end

#pragma mark - UIViewController extensions

@interface UIViewController (PanelNavigationController)
@property(nonatomic,readonly,retain) PanelNavigationController* panelNavigationController;
@end