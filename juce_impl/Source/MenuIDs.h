/*
  ==============================================================================

    MenuIDs.h
    Created: 8 Sep 2018 10:01:22pm
    Author:  asit

  ==============================================================================
*/

#pragma once

#include <string>

enum class MenuEntry {
    FileNew = 1000,
    FileOpen,
    FileSave,
    FilePrint,
    FileExit,
    
    EditUndo = 2000,
    EditRedo,
    EditCut,
    EditCopy,
    EditPaste,
    EditFormat,
    
    HelpAbout = 3000,
    HelpAboutQt,
    
    FormatBold = 4000,
    FormatItalic,
    FormatLeftAlign,
    FormatRightAlign,
    FormatJustify,
    FormatCenter,
    FormatSetLineSpacing,
    FormatSetParagraphSpacing,
};

std::string menuEntryToString(MenuEntry entry);
std::string menuEntryToIconName(MenuEntry entry);
int menuEntryToId(MenuEntry entry);