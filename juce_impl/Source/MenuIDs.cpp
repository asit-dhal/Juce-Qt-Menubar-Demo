/*
  ==============================================================================

    MenuIDs.cpp
    Created: 8 Sep 2018 10:01:22pm
    Author:  asit

  ==============================================================================
*/

#include "MenuIDs.h"

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

std::string menuEntryToIconName(MenuEntry entry)
{
    switch(entry)
    {
    case MenuEntry::FileNew:   return "file-new.svg";
    case MenuEntry::FileOpen:  return "file-open.svg";
    case MenuEntry::FileSave:  return "file-save.svg";
    case MenuEntry::FilePrint: return "file-print.svg";
    case MenuEntry::FileExit:  return "file-exit.svg";
    
    case MenuEntry::EditUndo:  return "edit-undo.svg";
    case MenuEntry::EditRedo:  return "edit-redo.svg";
    case MenuEntry::EditCut:   return "edit-cut.svg";
    case MenuEntry::EditCopy:  return "edit-copy.svg";
    case MenuEntry::EditPaste: return "edit-paste.svg";
    
    case MenuEntry::FormatBold:       return "format-bold.svg";
    case MenuEntry::FormatItalic:     return "format-italic.svg";
    case MenuEntry::FormatLeftAlign:  return "format-left-align.svg";
    case MenuEntry::FormatRightAlign: return "format-right-align.svg";
    case MenuEntry::FormatJustify:    return "format-justify.svg";
    }
}

int menuEntryToId(MenuEntry entry)
{
    return static_cast<int>(entry);
}