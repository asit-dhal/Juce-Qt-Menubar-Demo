/*
  ==============================================================================

    AppToolbarItemFactory.h
    Created: 22 Sep 2018 3:59:44pm
    Author:  asit

  ==============================================================================
*/

#pragma once

#include <memory>

class AppToolbarItemFactory : public ToolbarItemFactory
{
public:
    AppToolbarItemFactory();
    ~AppToolbarItemFactory();
    void getAllToolbarItemIds(Array<int>& ids) override;
    void getDefaultItemSet(Array<int>& ids) override;
    ToolbarItemComponent* createItem(int itemId) override;
    
private:
    StringArray m_iconNames;
    OwnedArray<Drawable> m_iconsFromZipFile;
    
    ToolbarButton* createButtonFromZipFileSVG(const int itemId, const String& text, const String& filename);
};