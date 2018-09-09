#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MainComponent   : public Component
                      , public MenuBarModel
                      , public ApplicationCommandTarget
{
public:
    MainComponent();
    ~MainComponent();

    void paint (Graphics&) override;
    void resized() override;
    
    StringArray getMenuBarNames();
    PopupMenu getMenuForIndex(int index, const String& name);
    void menuItemSelected(int menuID, int index);
    
    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(Array<CommandID>& c) override;
    void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo& info) override;
    
    void mouseDown(const MouseEvent & e);
    static void menuCallback (int result, MainComponent* thisComponent);

private:
    ApplicationCommandManager m_commandManager;
    Label label;
    Slider slider;
    Label statusBarLabel;
    MenuBarComponent menuBar;
    ApplicationProperties appProperties;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
