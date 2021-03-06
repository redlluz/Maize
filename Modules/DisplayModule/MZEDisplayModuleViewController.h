#import <MediaPlayerUI/MPVolumeControllerDelegate-Protocol.h>
#import <MaizeUI/MZEContentModuleContentViewController-Protocol.h>
#import "MZEDisplayModuleViewControllerDelegate-Protocol.h"
#import <MaizeUI/MZEModuleSliderView.h>
#import <MediaPlayerUI/MPVolumeController.h>
#import <QuartzCore/CALayer+Private.h>

@interface MZEDisplayModuleViewController : UIViewController <MPVolumeControllerDelegate, MZEContentModuleContentViewController>
{
    __weak id <MZEDisplayModuleViewControllerDelegate> _delegate;
    MZEModuleSliderView *_sliderView;
    BOOL _expanded;
}

@property(retain, nonatomic, readwrite) MPVolumeController *volumeController;
@property(retain, nonatomic, readwrite) MZEModuleSliderView *sliderView; 
@property(nonatomic) __weak id <MZEDisplayModuleViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) BOOL allowsInPlaceFiltering;
@property(readonly, nonatomic) CALayer *punchOutRootLayer;
@property(readonly, nonatomic, getter=isGroupRenderingRequired) BOOL groupRenderingRequired;
@property(readonly, nonatomic, getter=isContentClippingRequired) BOOL contentClippingRequired;
@property(readonly, nonatomic) CGFloat preferredExpandedContentWidth;
@property(readonly, nonatomic) CGFloat preferredExpandedContentHeight;
@property(readonly, nonatomic) float currentBrightness;

- (void)_sliderValueDidChange:(MZEModuleSliderView *)slider;
- (void)willTransitionToExpandedContentMode:(BOOL)willTransition;
- (void)setGlyphState:(NSString *)glyphState;
- (void)setGlyphPackage:(CAPackage *)glyphPackage;
//- (void)setOtherGlyphPackage:(CAPackage *)otherGlyphPackage;
//- (void)viewWillTransitionToSize:(struct CGSize)arg1 withTransitionCoordinator:(id)arg2;
- (void)viewDidLoad;
- (void)loadView;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (float)_backlightLevel;
- (void)_setBacklightLevel:(float)backlightLevel;
- (void)_noteScreenBrightnessDidChange:(id)changed;
- (void)_updateWithCurrentBrightnessAnimated:(BOOL)animated;

@end

