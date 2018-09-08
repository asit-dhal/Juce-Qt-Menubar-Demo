/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives irnside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
                      , public MenuBarModel
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    StringArray getMenuBarNames();
    PopupMenu getMenuForIndex(int index, const String& name);
    void menuItemSelected(int menuID, int index);

private:
    Label label;
    Slider slider;
    MenuBarComponent menuBar;
    ApplicationProperties appProperties;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
