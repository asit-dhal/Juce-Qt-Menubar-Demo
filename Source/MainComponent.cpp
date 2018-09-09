#include "MainComponent.h"
#include "MenuIDs.h"

MainComponent::MainComponent() : menuBar(this)
{
    label.setEditable(true);
    addAndMakeVisible(&menuBar);
    addAndMakeVisible(&label);
    addAndMakeVisible(&slider);
    addAndMakeVisible(&statusBarLabel);
    
    setSize (600, 400);
    
    PropertiesFile::Options options;
    options.applicationName     = ProjectInfo::projectName;
    options.folderName          = ProjectInfo::projectName;
    options.filenameSuffix      = "settings";
    options.osxLibrarySubFolder = "Application Support";
    appProperties.setStorageParameters (options);
    
    PropertiesFile* props = appProperties.getUserSettings();
    label.setText (props->getValue ("label", "<empty>"), dontSendNotification);
    slider.setValue (props->getDoubleValue ("slider", 0.0));
    
    setApplicationCommandManagerToWatch(&m_commandManager);
    m_commandManager.registerAllCommandsForTarget(this);
    addKeyListener(m_commandManager.getKeyMappings());
}

MainComponent::~MainComponent()
{
    PropertiesFile* props = appProperties.getUserSettings();
    props->setValue ("label", label.getText());
    props->setValue ("slider", slider.getValue());
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
    menuBar.setBounds(0, 0, getWidth(), 25);
    label.setBounds(10, 30, getWidth()-20, 20);
    slider.setBounds(10, 60, getWidth()-20, 20);
    statusBarLabel.setBounds(0, getHeight()-20, getWidth(), 20);
}

StringArray MainComponent::getMenuBarNames()
{
    auto names = { "File", "Edit", "Help"};
    return StringArray(names);
}

PopupMenu MainComponent::getMenuForIndex(int index, const String& name)
{
    PopupMenu menu;
    
    if (name == "File")
    {
        menu.addCommandItem (&m_commandManager, menuEntryToId(MenuEntry::FileNew));
        menu.addCommandItem (&m_commandManager, menuEntryToId(MenuEntry::FileOpen));
        menu.addCommandItem (&m_commandManager, menuEntryToId(MenuEntry::FileSave));
        menu.addCommandItem (&m_commandManager, menuEntryToId(MenuEntry::FilePrint));
        menu.addSeparator();
        menu.addCommandItem (&m_commandManager, menuEntryToId(MenuEntry::FileExit));
    }
    else if (name == "Edit")
    {
        menu.addItem(menuEntryToId(MenuEntry::EditUndo), menuEntryToString(MenuEntry::EditUndo));
        menu.addItem(menuEntryToId(MenuEntry::EditRedo), menuEntryToString(MenuEntry::EditRedo));
        menu.addSeparator();
        
        menu.addItem(menuEntryToId(MenuEntry::EditCut), menuEntryToString(MenuEntry::EditCut));
        menu.addItem(menuEntryToId(MenuEntry::EditCopy), menuEntryToString(MenuEntry::EditCopy));
        menu.addItem(menuEntryToId(MenuEntry::EditPaste), menuEntryToString(MenuEntry::EditPaste));
        menu.addSeparator();
        
        PopupMenu formatSubMenu;
        formatSubMenu.addItem(menuEntryToId(MenuEntry::FormatBold), menuEntryToString(MenuEntry::FormatBold));
        formatSubMenu.addItem(menuEntryToId(MenuEntry::FormatItalic), menuEntryToString(MenuEntry::FormatItalic));
        menu.addSeparator();
        formatSubMenu.addSectionHeader("Alignment");
        formatSubMenu.addItem(menuEntryToId(MenuEntry::FormatLeftAlign), menuEntryToString(MenuEntry::FormatLeftAlign));
        formatSubMenu.addItem(menuEntryToId(MenuEntry::FormatRightAlign), menuEntryToString(MenuEntry::FormatRightAlign));
        formatSubMenu.addItem(menuEntryToId(MenuEntry::FormatJustify), menuEntryToString(MenuEntry::FormatJustify));
        formatSubMenu.addItem(menuEntryToId(MenuEntry::FormatCenter), menuEntryToString(MenuEntry::FormatCenter));
        formatSubMenu.addSeparator();
        formatSubMenu.addItem(menuEntryToId(MenuEntry::FormatSetLineSpacing), menuEntryToString(MenuEntry::FormatSetLineSpacing));
        formatSubMenu.addItem(menuEntryToId(MenuEntry::FormatSetParagraphSpacing), menuEntryToString(MenuEntry::FormatSetParagraphSpacing));
        menu.addSubMenu("Format", formatSubMenu);
    }
    else if (name == "Help")
    {
        menu.addItem(menuEntryToId(MenuEntry::HelpAbout), menuEntryToString(MenuEntry::HelpAbout));
        menu.addItem(menuEntryToId(MenuEntry::HelpAboutQt), menuEntryToString(MenuEntry::HelpAboutQt));
    }
    
    return menu;
}

void MainComponent::menuItemSelected(int menuID, int index)
{
    switch(static_cast<MenuEntry>(menuID))
    {
    case MenuEntry::EditUndo:
        statusBarLabel.setText("Edit->Undo invoked", dontSendNotification);
        break;
    case MenuEntry::EditRedo:
        statusBarLabel.setText("Edit->Redo invoked", dontSendNotification);
        break;
    case MenuEntry::EditCut:
        statusBarLabel.setText("Edit->Cut invoked", dontSendNotification);
        break;
    case MenuEntry::EditCopy:
        statusBarLabel.setText("Edit->Copy invoked", dontSendNotification);
        break;
    case MenuEntry::EditPaste:
        statusBarLabel.setText("Edit->Paste invoked", dontSendNotification);
        break;
    case MenuEntry::EditFormat:
        statusBarLabel.setText("Edit->Format invoked", dontSendNotification);
        break;
   case MenuEntry::HelpAbout:
        statusBarLabel.setText("Help->About invoked", dontSendNotification);
        break;
   case MenuEntry::HelpAboutQt:
        statusBarLabel.setText("Help->AboutQt invoked", dontSendNotification);
        break;
    }
}

ApplicationCommandTarget* MainComponent::getNextCommandTarget()
{
    return nullptr;
}

void MainComponent::getAllCommands(Array<CommandID>& c)
{
    Array<CommandID> commands { menuEntryToId(MenuEntry::FileNew),
                                menuEntryToId(MenuEntry::FileOpen),
                                menuEntryToId(MenuEntry::FileSave),
                                menuEntryToId(MenuEntry::FilePrint),
                                menuEntryToId(MenuEntry::FileExit) };
    c.addArray(commands);
}

void MainComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result)
{
    switch(static_cast<MenuEntry>(commandID))
    {
    case MenuEntry::FileNew:
        result.setInfo (menuEntryToString(MenuEntry::FileNew), String::empty, "Menu", 0);
        result.addDefaultKeypress ('N', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FileOpen:
        result.setInfo (menuEntryToString(MenuEntry::FileOpen), String::empty, "Menu", 0);
        result.addDefaultKeypress ('O', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FileSave:
        result.setInfo (menuEntryToString(MenuEntry::FileSave), String::empty, "Menu", 0);
        result.addDefaultKeypress ('S', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FilePrint:
        result.setInfo (menuEntryToString(MenuEntry::FilePrint), String::empty, "Menu", 0);
        result.addDefaultKeypress ('P', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FileExit:
        result.setInfo (menuEntryToString(MenuEntry::FileExit), String::empty, "Menu", 0);
        result.addDefaultKeypress ('Q', ModifierKeys::ctrlModifier);
        break;
    }
}

bool MainComponent::perform(const InvocationInfo& info)
{
    switch (static_cast<MenuEntry>(info.commandID))
    {
    case MenuEntry::FileNew:
        statusBarLabel.setText("File->New invoked", dontSendNotification);
        break;
    case MenuEntry::FileOpen:
        statusBarLabel.setText("File->Open invoked", dontSendNotification);
        break;
    case MenuEntry::FileSave:
        statusBarLabel.setText("File->Save invoked", dontSendNotification);
        break;
    case MenuEntry::FilePrint:
        statusBarLabel.setText("File->Print invoked", dontSendNotification);
        break;
    case MenuEntry::FileExit:
        statusBarLabel.setText("File->Exit invoked", dontSendNotification);
        JUCEApplication::getInstance()->systemRequestedQuit();
        break;
    default:
        Logger::getCurrentLogger()->writeToLog("Could not perform");
        return false;
    }

    return true;
}
