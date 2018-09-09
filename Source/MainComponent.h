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
                      , public ApplicationCommandTarget
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
    
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& c) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;

private:
    ApplicationCommandManager m_commandManager;
    Label label;
    Slider slider;
    Label statusBarLabel;
    MenuBarComponent menuBar;
    ApplicationProperties appProperties;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
