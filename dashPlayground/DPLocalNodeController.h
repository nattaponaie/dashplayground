//
//  DPLocalNodeController.h
//  dashPlayground
//
//  Created by Sam Westrich on 4/5/17.
//  Copyright © 2017 dashfoundation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "MasternodeSyncStatusTransformer.h"
#import "DashCallbacks.h"

#define DASHD_PATH @"DASHD_PATH"
#define DASHCLI_PATH @"DASHCLI_PATH"

@interface DPLocalNodeController : NSObject

@property (atomic,assign) MasternodeSync syncStatus;
@property (nonatomic,copy) NSString * dashCliPath;
@property (nonatomic,copy) NSString * dashDPath;

- (void)startDash:(dashClb)clb forChain:(NSString*)chainNetwork;

- (void)stopDash:(dashClb)clb forChain:(NSString*)chainNetwork;

- (void)checkDash:(dashActiveClb)clb forChain:(NSString*)chainNetwork;

- (void)checkDashStopped:(dashActiveClb)clb;

-(void)checkSyncStatus:(dashSyncClb)clb forChain:(NSString*)chainNetwork;

-(NSDictionary*)getSyncStatus;

-(NSArray*)outputs:(NSString*)chainNetwork;

- (NSData *)runDashRPCCommand:(NSString *)commandToRun;

-(NSString *)runDashRPCCommandString:(NSString *)commandToRun forChain:(NSString*)chainNetwork;

-(NSDictionary *)runDashRPCCommandArray:(NSString *)commandToRun;

-(NSDictionary *)runDashRPCCommandArrayWithArray:(NSArray *)commandToRun;

- (NSString *)runDashRPCCommandStringWithArray:(NSArray *)commandToRun;

-(NSDictionary*)masternodeInfoInMasternodeConfigurationFileForMasternode:(NSManagedObject*)masternode;

-(void)updateMasternodeConfigurationFileForMasternode:(NSManagedObject*)masternode clb:(dashClb)clb;

+(DPLocalNodeController*)sharedInstance;

@end
