/*
  ==============================================================================

    MenuIDs.cpp
    Created: 8 Sep 2018 10:01:22pm
    Author:  asit

  ==============================================================================
*/

#include "MenuIDs.h"
#include "AppIcons.h"

std::string menuEntryToString(MenuEntry entry)
{
    switch(entry)
    {
    case MenuEntry::FileNew:   return "New";
    case MenuEntry::FileOpen:  return "Open";
    case MenuEntry::FileSave:  return "Save";
    case MenuEntry::FilePrint: return "Print";
    case MenuEntry::FileExit:  return "Exit";

    case MenuEntry::EditUndo:  return "Undo";
    case MenuEntry::EditRedo:  return "Redo";
    case MenuEntry::EditCut:   return "Cut";
    case MenuEntry::EditCopy:  return "Copy";
    case MenuEntry::EditPaste: return "Paste";
    case MenuEntry::EditFormat: return "Format";

    case MenuEntry::HelpAbout: return "About";
    case MenuEntry::HelpAboutQt: return "About JUCE";

    case MenuEntry::FormatBold:       return "Bold";
    case MenuEntry::FormatItalic:     return "Italic";
    case MenuEntry::FormatLeftAlign:  return "Left Align";
    case MenuEntry::FormatRightAlign: return "Right Align";
    case MenuEntry::FormatJustify:    return "Justify";
    case MenuEntry::FormatCenter:     return "Center";
    case MenuEntry::FormatSetLineSpacing: return "Set Line Spacing...";
    case MenuEntry::FormatSetParagraphSpacing: return "Set Paragraph Spacing...";
    }
}

Drawable* menuEntryToDrawable(MenuEntry entry)
{
    switch(entry)
    {
    case MenuEntry::FileNew:   return Drawable::createFromImageData(AppIcons::filenew_svg, AppIcons::filenew_svgSize);
    case MenuEntry::FileOpen:  return Drawable::createFromImageData(AppIcons::fileopen_svg, AppIcons::fileopen_svgSize);
    case MenuEntry::FileSave:  return Drawable::createFromImageData(AppIcons::filesave_svg, AppIcons::filesave_svgSize);
    case MenuEntry::FilePrint: return Drawable::createFromImageData(AppIcons::fileprint_svg, AppIcons::fileprint_svgSize);
    case MenuEntry::FileExit:  return Drawable::createFromImageData(AppIcons::fileexit_svg, AppIcons::fileexit_svgSize);

    case MenuEntry::EditUndo:  return Drawable::createFromImageData(AppIcons::editundo_svg, AppIcons::editundo_svgSize);
    case MenuEntry::EditRedo:  return Drawable::createFromImageData(AppIcons::editredo_svg, AppIcons::editredo_svgSize);
    case MenuEntry::EditCut:   return Drawable::createFromImageData(AppIcons::editcut_svg, AppIcons::editcut_svgSize);
    case MenuEntry::EditCopy:  return Drawable::createFromImageData(AppIcons::editcopy_svg, AppIcons::editcopy_svgSize);
    case MenuEntry::EditPaste: return Drawable::createFromImageData(AppIcons::editpaste_svg, AppIcons::editpaste_svgSize);

    case MenuEntry::FormatBold:       return Drawable::createFromImageData(AppIcons::formatbold_svg, AppIcons::formatbold_svgSize);
    case MenuEntry::FormatItalic:     return Drawable::createFromImageData(AppIcons::formatitalic_svg, AppIcons::formatitalic_svgSize);
    case MenuEntry::FormatLeftAlign:  return Drawable::createFromImageData(AppIcons::formatleftalign_svg, AppIcons::formatleftalign_svgSize);
    case MenuEntry::FormatRightAlign: return Drawable::createFromImageData(AppIcons::formatrightalign_svg, AppIcons::formatrightalign_svgSize);
    case MenuEntry::FormatJustify:    return Drawable::createFromImageData(AppIcons::formatjustify_svg, AppIcons::formatjustify_svgSize);
    }
}

int menuEntryToId(MenuEntry entry)
{
    return static_cast<int>(entry);
}
