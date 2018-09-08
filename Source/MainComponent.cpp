#include "MainComponent.h"
#include "MenuIDs.h"

MainComponent::MainComponent() : menuBar(this)
{
    label.setEditable(true);
    addAndMakeVisible(&menuBar);
    addAndMakeVisible(&label);
    addAndMakeVisible(&slider);
    
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
        menu.addItem(menuEntryToId(MenuEntry::FileNew), menuEntryToString(MenuEntry::FileNew));
        menu.addItem(menuEntryToId(MenuEntry::FileOpen), menuEntryToString(MenuEntry::FileOpen));
        menu.addItem(menuEntryToId(MenuEntry::FileSave), menuEntryToString(MenuEntry::FileSave));
        menu.addItem(menuEntryToId(MenuEntry::FilePrint), menuEntryToString(MenuEntry::FilePrint));
        menu.addSeparator();
        menu.addItem(menuEntryToId(MenuEntry::FileExit), menuEntryToString(MenuEntry::FileExit));
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
    case MenuEntry::FileNew:
        label.setText("FileNew", dontSendNotification);
        break;
    case MenuEntry::FileOpen:
        label.setText("FileOpen", dontSendNotification);
        break;
    case MenuEntry::FileSave:
        label.setText("FileSave", dontSendNotification);
        break;
    case MenuEntry::FilePrint:
        label.setText("FilePrint", dontSendNotification);
        break;
    case MenuEntry::FileExit:
        label.setText("FileExit", dontSendNotification);
        break;
    case MenuEntry::EditUndo:
        label.setText("EditUndo", dontSendNotification);
        break;
    case MenuEntry::EditRedo:
        label.setText("EditRedo", dontSendNotification);
        break;
    case MenuEntry::EditCut:
        label.setText("EditCut", dontSendNotification);
        break;
    case MenuEntry::EditCopy:
        label.setText("EditCopy", dontSendNotification);
        break;
    case MenuEntry::EditPaste:
        label.setText("EditPaste", dontSendNotification);
        break;
    case MenuEntry::EditFormat:
        label.setText("EditFormat", dontSendNotification);
        break;
   case MenuEntry::HelpAbout:
        label.setText("HelpAbout", dontSendNotification);
        break;
   case MenuEntry::HelpAboutQt:
        label.setText("HelpAboutQt", dontSendNotification);
        break;
    }
}