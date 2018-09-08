/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
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
    
    // Get the user settings, rather than settings common to all users.
    PropertiesFile* props = appProperties.getUserSettings();
    
    // Initialize the label and slider values.
    label.setText (props->getValue ("label", "<empty>"),
                   dontSendNotification);
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
    const char* names[] = { "Label", "Slider", 0 };
    return StringArray(names);
}

PopupMenu MainComponent::getMenuForIndex(int index, const String& name)
{
    PopupMenu menu;
    
    if (name == "Label")
    {
        menu.addItem(LabelClear, "Clear");
    }
    else if (name == "Slider")
    {
        menu.addItem(SliderMin, "Set to minimum", true, true);
        menu.addItem(SliderMax, "Set to maximum", true, true);
    }
    
    return menu;
}

void MainComponent::menuItemSelected(int menuID, int index)
{
    switch(menuID)
    {
    case LabelClear:
        {
        label.setText(String::empty, dontSendNotification);
        AlertWindow *alert = new AlertWindow ("Enter the text","DISC ID", AlertWindow::InfoIcon );
	    alert->addButton ("Continue",1,KeyPress(),KeyPress());
	    alert->addTextEditor ("edit","","Disc Id");
	    alert->addToDesktop (4); 
	    alert->setBounds(230,150,300,500);
	    int returnValue = alert->runModalLoop();
        delete alert;
        break;
        }
    case SliderMin:
        slider.setValue(slider.getMinimum());
        break;
    case SliderMax:
        slider.setValue(slider.getMaximum());
        break;
    }
}