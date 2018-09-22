#include "MainComponent.h"
#include "MenuIDs.h"

namespace
{

MainComponent::Alignment menuEntryToAlignment(MenuEntry menuEntry)
{
    switch(menuEntry)
    {
    case MenuEntry::FormatLeftAlign:
        return MainComponent::Alignment::LeftAlign;
    case MenuEntry::FormatRightAlign:
        return MainComponent::Alignment::RightAlign;
    case MenuEntry::FormatJustify:
        return MainComponent::Alignment::Justify;
    case MenuEntry::FormatCenter:
        return MainComponent::Alignment::Center;
    }
}
    
MenuEntry alignmentToMenuEntry(MainComponent::Alignment alignment)
{
    switch(alignment)
    {
    case MainComponent::Alignment::LeftAlign:
        return MenuEntry::FormatLeftAlign; 
    case MainComponent::Alignment::RightAlign:
        return MenuEntry::FormatRightAlign; 
    case MainComponent::Alignment::Justify:
        return MenuEntry::FormatJustify;
    case MainComponent::Alignment::Center:
        return MenuEntry::FormatCenter;
    }
}
    
}

MainComponent::MainComponent() : menuBar(this)
{
    addAndMakeVisible(&menuBar);
    addAndMakeVisible(&statusBarLabel);
    
    setSize (600, 400);

    PropertiesFile::Options options;
    options.applicationName = ProjectInfo::projectName;
    options.folderName = ProjectInfo::projectName;
    options.filenameSuffix = "settings";
    options.osxLibrarySubFolder = "Application Support";
    m_appProperties.setStorageParameters(options);

    PropertiesFile* props = m_appProperties.getUserSettings();
    m_italicFormatFlag = props->getBoolValue("italic-format", false);
    m_boldFormatFlag = props->getBoolValue("bold-format", false);
    m_alignment = static_cast<Alignment>(props->getIntValue("alignment", 0));
        
    setApplicationCommandManagerToWatch(&m_commandManager);
    m_commandManager.registerAllCommandsForTarget(this);
    addKeyListener(m_commandManager.getKeyMappings());
}

MainComponent::~MainComponent()
{
    PropertiesFile* props = m_appProperties.getUserSettings();
    props->setValue("italic-format", m_italicFormatFlag);
    props->setValue("bold-format", m_boldFormatFlag);
    props->setValue("alignment", static_cast<int>(m_alignment));
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
}

void MainComponent::resized()
{
    menuBar.setBounds(0, 0, getWidth(), 25);
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

        menu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::EditUndo));
        menu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::EditRedo));
        menu.addSeparator();
        
        menu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::EditCut));
        menu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::EditCopy));
        menu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::EditPaste));
        menu.addSeparator();
        
        PopupMenu formatSubMenu;
        formatSubMenu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::FormatBold));
        formatSubMenu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::FormatItalic));
        formatSubMenu.addSeparator();
        formatSubMenu.addSectionHeader("Alignment");
        formatSubMenu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::FormatLeftAlign));
        formatSubMenu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::FormatRightAlign));
        formatSubMenu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::FormatJustify));
        formatSubMenu.addCommandItem(&m_commandManager, menuEntryToId(MenuEntry::FormatCenter));
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
    case MenuEntry::FormatSetLineSpacing:
        statusBarLabel.setText("Edit->Format->SetLineSpacing invoked", dontSendNotification);
        break;
    case MenuEntry::FormatSetParagraphSpacing:
        statusBarLabel.setText("Edit->Format->SetParagraphSpacing invoked", dontSendNotification);
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
    Array<CommandID> commands { 
        menuEntryToId(MenuEntry::FileNew),
        menuEntryToId(MenuEntry::FileOpen),
        menuEntryToId(MenuEntry::FileSave),
        menuEntryToId(MenuEntry::FilePrint),
        menuEntryToId(MenuEntry::FileExit),
        menuEntryToId(MenuEntry::EditUndo),
        menuEntryToId(MenuEntry::EditRedo),
        menuEntryToId(MenuEntry::EditCut),
        menuEntryToId(MenuEntry::EditCopy),
        menuEntryToId(MenuEntry::EditPaste),
        menuEntryToId(MenuEntry::FormatBold),
        menuEntryToId(MenuEntry::FormatItalic),
        menuEntryToId(MenuEntry::FormatLeftAlign),
        menuEntryToId(MenuEntry::FormatRightAlign),
        menuEntryToId(MenuEntry::FormatJustify),
        menuEntryToId(MenuEntry::FormatCenter)
    };
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
    case MenuEntry::EditUndo:
        result.setInfo (menuEntryToString(MenuEntry::EditUndo), String::empty, "Menu", 0);
        result.addDefaultKeypress ('Z', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::EditRedo:
        result.setInfo (menuEntryToString(MenuEntry::EditRedo), String::empty, "Menu", 0);
        result.addDefaultKeypress ('Z', ModifierKeys::ctrlModifier | ModifierKeys::altModifier);
        break;
    case MenuEntry::EditCut:
        result.setInfo (menuEntryToString(MenuEntry::EditCut), String::empty, "Menu", 0);
        result.addDefaultKeypress ('X', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::EditCopy:
        result.setInfo (menuEntryToString(MenuEntry::EditCopy), String::empty, "Menu", 0);
        result.addDefaultKeypress ('C', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::EditPaste:
        result.setInfo (menuEntryToString(MenuEntry::EditPaste), String::empty, "Menu", 0);
        result.addDefaultKeypress ('V', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FormatBold:
        result.setInfo (menuEntryToString(MenuEntry::FormatBold), String::empty, "Menu", ApplicationCommandInfo::CommandFlags::isTicked);
        result.setTicked(m_boldFormatFlag);
        result.addDefaultKeypress ('B', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FormatItalic:
        result.setInfo (menuEntryToString(MenuEntry::FormatItalic), String::empty, "Menu", ApplicationCommandInfo::CommandFlags::isTicked);
        result.setTicked(m_italicFormatFlag);
        result.addDefaultKeypress ('I', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FormatLeftAlign:
        result.setInfo (menuEntryToString(MenuEntry::FormatLeftAlign), String::empty, "Menu", ApplicationCommandInfo::CommandFlags::isTicked);
        result.setTicked(m_alignment == Alignment::LeftAlign);
        result.addDefaultKeypress ('L', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FormatRightAlign:
        result.setInfo (menuEntryToString(MenuEntry::FormatRightAlign), String::empty, "Menu", ApplicationCommandInfo::CommandFlags::isTicked);
        result.setTicked(m_alignment == Alignment::RightAlign);
        result.addDefaultKeypress ('R', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FormatJustify:
        result.setInfo (menuEntryToString(MenuEntry::FormatJustify), String::empty, "Menu", ApplicationCommandInfo::CommandFlags::isTicked);
        result.setTicked(m_alignment == Alignment::Justify);
        result.addDefaultKeypress ('J', ModifierKeys::ctrlModifier);
        break;
    case MenuEntry::FormatCenter:
        result.setInfo (menuEntryToString(MenuEntry::FormatCenter), String::empty, "Menu", ApplicationCommandInfo::CommandFlags::isTicked);
        result.setTicked(m_alignment == Alignment::Center);
        result.addDefaultKeypress ('E', ModifierKeys::ctrlModifier);
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
        statusBarLabel.setText("Edit->Pase invoked", dontSendNotification);
        break;
    case MenuEntry::FormatBold:
        onFormatBold();
        break;
    case MenuEntry::FormatItalic:
        onFormatItalic();
        break;
    case MenuEntry::FormatLeftAlign:
        onAlignmentChanged(info.commandID);
        statusBarLabel.setText("Edit->Format->LeftAlign invoked", dontSendNotification);
        break;
    case MenuEntry::FormatRightAlign:
        onAlignmentChanged(info.commandID);
        statusBarLabel.setText("Edit->Format->RightAlign invoked", dontSendNotification);
        break;
    case MenuEntry::FormatJustify:
        onAlignmentChanged(info.commandID);
        statusBarLabel.setText("Edit->Format->Justify invoked", dontSendNotification);
        break;
    case MenuEntry::FormatCenter:
        onAlignmentChanged(info.commandID);
        statusBarLabel.setText("Edit->Format->Center invoked", dontSendNotification);
        break;    
    default:
        Logger::getCurrentLogger()->writeToLog("Could not perform");
        return false;
    }
    menuItemsChanged();
    return true;
}

void MainComponent::onFormatBold()
{
    statusBarLabel.setText("Edit->Format->Bold invoked", dontSendNotification);
    ApplicationCommandInfo result(menuEntryToId(MenuEntry::FormatBold));
    getCommandInfo(menuEntryToId(MenuEntry::FormatBold), result);
    m_boldFormatFlag = !m_boldFormatFlag;
    result.setTicked(m_boldFormatFlag);
}

void MainComponent::onFormatItalic()
{
    statusBarLabel.setText("Edit->Format->Italic invoked", dontSendNotification);
    ApplicationCommandInfo result(menuEntryToId(MenuEntry::FormatItalic));
    getCommandInfo(menuEntryToId(MenuEntry::FormatItalic), result);
    m_italicFormatFlag = !m_italicFormatFlag;
    result.setTicked(m_italicFormatFlag);
}

void MainComponent::onAlignmentChanged(CommandID commandID)
{
    Alignment desiredAlignment = menuEntryToAlignment(static_cast<MenuEntry>(commandID));
    MenuEntry currMenuEntry = alignmentToMenuEntry(m_alignment);
    
    if (m_alignment != desiredAlignment)
    {
        // check the desired alignment
        Logger::outputDebugString ("Checking Desired Menu Entry: " + menuEntryToString(static_cast<MenuEntry>(commandID)));
        ApplicationCommandInfo desiredResult(commandID);
        getCommandInfo(commandID, desiredResult);
        desiredResult.setTicked(true);
        
        // uncheck the previous alignment
        Logger::outputDebugString ("Unchecking Previous Menu Entry: " + menuEntryToString(currMenuEntry));
        ApplicationCommandInfo previousResult(menuEntryToId(currMenuEntry));
        getCommandInfo(menuEntryToId(currMenuEntry), previousResult);
        previousResult.setTicked(false);
        
        m_alignment = desiredAlignment;
    }
    
}

void MainComponent::mouseDown(const MouseEvent & e)
{
    if (e.mods.isPopupMenu())
    {
        PopupMenu menu;
        menu.addItem (menuEntryToId(MenuEntry::EditCut), menuEntryToString(MenuEntry::EditCut));
        menu.addItem (menuEntryToId(MenuEntry::EditCopy), menuEntryToString(MenuEntry::EditCopy));
        menu.addItem (menuEntryToId(MenuEntry::EditPaste), menuEntryToString(MenuEntry::EditPaste));

        menu.showMenuAsync(PopupMenu::Options(),   ModalCallbackFunction::forComponent (menuCallback, this));
    }
}

void MainComponent::menuCallback (int result, MainComponent* thisComponent)
{
    if (thisComponent != nullptr)
    {
        if (result == menuEntryToId(MenuEntry::EditCut))
        {
            thisComponent->statusBarLabel.setText("Context Menu -> Cut invoked", dontSendNotification);
        }
        else if (result == menuEntryToId(MenuEntry::EditCopy))
        {
            thisComponent->statusBarLabel.setText("Context Menu -> Copy invoked", dontSendNotification);
        }
        else if (result == menuEntryToId(MenuEntry::EditPaste))
        {
            thisComponent->statusBarLabel.setText("Context Menu -> Paste invoked", dontSendNotification);
        }
    }
}
