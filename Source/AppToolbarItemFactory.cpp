/*
  ==============================================================================

    AppToolbarItemFactory.cpp
    Created: 22 Sep 2018 3:59:44pm
    Author:  asit

  ==============================================================================
*/

#include "AppToolbarItemFactory.h"
#include "MenuIDs.h"

AppToolbarItemFactory::AppToolbarItemFactory() {}
AppToolbarItemFactory::~AppToolbarItemFactory() {}

void AppToolbarItemFactory::getAllToolbarItemIds(Array<int>& ids)
{
    ids.add(menuEntryToId(MenuEntry::FileNew));
    ids.add(menuEntryToId(MenuEntry::FileOpen));
    ids.add(menuEntryToId(MenuEntry::FileSave));
    ids.add(menuEntryToId(MenuEntry::FilePrint));
    ids.add(menuEntryToId(MenuEntry::FileExit));
    
    /*ids.add(menuEntryToId(MenuEntry::EditUndo));
    ids.add(menuEntryToId(MenuEntry::EditRedo));
        
    ids.add(menuEntryToId(MenuEntry::EditCut));
    ids.add(menuEntryToId(MenuEntry::EditCopy));
    ids.add(menuEntryToId(MenuEntry::EditPaste));
        
    ids.add(menuEntryToId(MenuEntry::FormatBold));
    ids.add(menuEntryToId(MenuEntry::FormatItalic));

    ids.add(menuEntryToId(MenuEntry::FormatLeftAlign));
    ids.add(menuEntryToId(MenuEntry::FormatRightAlign));
    ids.add(menuEntryToId(MenuEntry::FormatJustify));
    ids.add(menuEntryToId(MenuEntry::FormatCenter));
    ids.add(menuEntryToId(MenuEntry::FormatSetLineSpacing));
    ids.add(menuEntryToId(MenuEntry::FormatSetParagraphSpacing));
    
    ids.add(menuEntryToId(MenuEntry::HelpAbout));
    ids.add(menuEntryToId(MenuEntry::HelpAboutQt));*/
}

void AppToolbarItemFactory::getDefaultItemSet(Array<int>& ids)
{
    ids.add(menuEntryToId(MenuEntry::FileNew));
    ids.add(menuEntryToId(MenuEntry::FileOpen));
    ids.add(menuEntryToId(MenuEntry::FileSave));
    ids.add(menuEntryToId(MenuEntry::FilePrint));
    ids.add(menuEntryToId(MenuEntry::FileExit));
    
    /*ids.add(menuEntryToId(MenuEntry::EditUndo));
    ids.add(menuEntryToId(MenuEntry::EditRedo));
        
    ids.add(menuEntryToId(MenuEntry::EditCut));
    ids.add(menuEntryToId(MenuEntry::EditCopy));
    ids.add(menuEntryToId(MenuEntry::EditPaste));*/
}

ToolbarItemComponent* AppToolbarItemFactory::createItem(int itemId) 
{
    switch(static_cast<MenuEntry>(itemId))
    {
    case MenuEntry::FileNew:
        return createButtonFromZipFileSVG(itemId, menuEntryToString(MenuEntry::FileNew), menuEntryToIconName(MenuEntry::FileNew));
    case MenuEntry::FileOpen:
        return createButtonFromZipFileSVG(itemId, menuEntryToString(MenuEntry::FileOpen), menuEntryToIconName(MenuEntry::FileOpen));
    case MenuEntry::FileSave:
        return createButtonFromZipFileSVG(itemId, menuEntryToString(MenuEntry::FileSave), menuEntryToIconName(MenuEntry::FileSave));
    case MenuEntry::FilePrint:
        return createButtonFromZipFileSVG(itemId, menuEntryToString(MenuEntry::FilePrint), menuEntryToIconName(MenuEntry::FilePrint));
    case MenuEntry::FileExit:
        return createButtonFromZipFileSVG(itemId, menuEntryToString(MenuEntry::FileExit), menuEntryToIconName(MenuEntry::FileExit));
    }
    
    return nullptr; 
}


ToolbarButton* AppToolbarItemFactory::createButtonFromZipFileSVG(const int itemId, const String& text, const String& filename)
{
    if (m_iconsFromZipFile.size() == 0)
    {
        auto assetsDir = File::getSpecialLocation(File::currentExecutableFile);
        auto resourceFile = assetsDir.getChildFile("icons.zip");
        jassert(resourceFile.existsAsFile());
        ZipFile icons (resourceFile, true);
        for(auto i = 0; i < icons.getNumEntries(); ++i)
        {
            std::unique_ptr<InputStream> svgFileStream(icons.createStreamForEntry(i));
            if (svgFileStream.get() != nullptr)
            {
                m_iconNames.add(icons.getEntry(i)->filename);
                m_iconsFromZipFile.add(Drawable::createFromImageDataStream(*svgFileStream));
            }
        }
    }
        
    auto* image = m_iconsFromZipFile[m_iconNames.indexOf(filename)]->createCopy();
    return new ToolbarButton(itemId, text, image, 0);
}