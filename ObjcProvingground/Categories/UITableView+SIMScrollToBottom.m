//
//  UITableView+SIMScrollToBottom.m
//  SAMIM
//
//  Created by ZIKong on 2018/10/12.
//  Copyright © 2018  . All rights reserved.
//

#import "UITableView+SIMScrollToBottom.h"

@implementation UITableView (SIMScrollToBottom)
- (void)sim_scrollToBottom:(BOOL)animation
{
    if (animation) {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.01 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [self toBottom:animation];
        });
    }else{
        [self toBottom:animation];
    }

}

- (void)toBottom:(BOOL)animation {
    NSInteger row = [self numberOfRowsInSection:0] - 1;
    if (row > 0)
    {
        NSIndexPath *indexPath = [NSIndexPath indexPathForRow:row inSection:0];
        [self scrollToRowAtIndexPath:indexPath atScrollPosition:UITableViewScrollPositionBottom animated:animation];
    }
}


@end
