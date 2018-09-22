#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "MenuIDs.h"

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
    
    void onFormatBold();
    void onFormatItalic();
    void onAlignmentChanged(CommandID commandID);
    void onToolbarButtonClick(int itemId);
    
    enum class Alignment
    {
        LeftAlign,
        RightAlign,
        Justify,
        Center
    };
    
    

private:
    class AppToolbarItemFactory : public ToolbarItemFactory
    {
    public:
        AppToolbarItemFactory(MainComponent *mainComponent) : m_mainComponent(mainComponent){}
        void getAllToolbarItemIds(Array<int>& ids) override;
        void getDefaultItemSet(Array<int>& ids) override;
        ToolbarItemComponent* createItem(int itemId) override;
    
    private:
        StringArray m_iconNames;
        OwnedArray<Drawable> m_iconsFromZipFile;
        ToolbarButton* createButtonFromZipFileSVG(const int itemId, const String& text, const String& filename);
        MainComponent *m_mainComponent;
    };

    ApplicationCommandManager m_commandManager;
    Label statusBarLabel;
    MenuBarComponent menuBar;
    ApplicationProperties m_appProperties;
    Toolbar m_toolbar;
    AppToolbarItemFactory m_factory;

    bool m_italicFormatFlag;
    bool m_boldFormatFlag;
    Alignment m_alignment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
