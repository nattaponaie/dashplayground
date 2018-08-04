//
//  DPBuildServerController.h
//  dashPlayground
//
//  Created by NATTAPON AIEMLAOR on 3/8/18.
//  Copyright © 2018 dashfoundation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuildServerViewController.h"
#import <NMSSH/NMSSH.h>

@interface DPBuildServerController : NSObject {
    BuildServerViewController *_buildServerViewController;
}

@property(strong, nonatomic, readwrite) BuildServerViewController *buildServerViewController;

+(DPBuildServerController*)sharedInstance;

-(NSString*)getBuildServerIP;
-(void)setBuildServerIP:(NSString*)ipAddress;

- (NSMutableArray*)getAllRepository:(NMSSHSession*)buildServerSession;

@end
