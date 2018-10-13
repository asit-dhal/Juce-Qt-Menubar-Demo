import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Menubar Demo")
    minimumWidth: 400
    minimumHeight: 300

    // File Menu

    Action {
        id: fileNewAction
        text: "New"
        shortcut: "ctrl+n"
        icon.source: "icons/file-new.svg"
        icon.name: "file-new"
    }

    Action {
        id: fileOpenAction
        text: "Open"
        shortcut: "ctrl+o"
        icon.source: "icons/file-open.svg"
        icon.name: "file-open"
    }

    Action {
        id: fileSaveAction
        text: "Save"
        shortcut: "ctrl+s"
        icon.source: "icons/file-save.svg"
        icon.name: "file-save"
    }

    Action {
        id: filePrintAction
        text: "Print"
        shortcut: "ctrl+p"
        icon.source: "icons/file-print.svg"
        icon.name: "file-print"
    }

    Action {
        id: fileExitAction
        text: "Exit"
        shortcut: "ctrl+x"
        icon.source: "icons/file-exit.svg"
        icon.name: "file-exit"
    }

    // Edit Menu

    Action {
        id: editUndoAction
        text: "Undo"
        shortcut: "ctrl+z"
        icon.source: "icons/edit-undo.svg"
        icon.name: "edit-undo"
    }

    Action {
        id: editRedoAction
        text: "Redo"
        shortcut: "ctrl+alt+z"
        icon.source: "icons/edit-redo.svg"
        icon.name: "edit-redo"
    }

    Action {
        id: editCutAction
        text: "Cut"
        shortcut: "ctrl+x"
        icon.source: "icons/edit-cut.svg"
        icon.name: "edit-cut"
    }

    Action {
        id: editCopyAction
        text: "Copy"
        shortcut: "ctrl+c"
        icon.source: "icons/edit-copy.svg"
        icon.name: "edit-copy"
    }

    Action {
        id: editPasteAction
        text: "Paste"
        shortcut: "ctrl+v"
        icon.source: "icons/edit-paste.svg"
        icon.name: "edit-paste"
    }

    // format

    Action {
        id: formatBoldAction
        text: "Bold"
        shortcut: "ctrl+b"
        icon.source: "icons/format-bold.svg"
        icon.name: "format-bold"
    }

    Action {
        id: formatItalicAction
        text: "Italic"
        shortcut: "ctrl+i"
        icon.source: "icons/format-italic.svg"
        icon.name: "format-italic"
    }

    Action {
        id: formatLeftAlignAction
        text: "Left Align"
        icon.source: "icons/format-left-align.svg"
        icon.name: "format-left-align"
    }

    Action {
        id: formatRightAlignAction
        text: "Right Align"
        icon.source: "icons/format-right-align.svg"
        icon.name: "format-right-align"
    }

    Action {
        id: formatCenterAction
        text: "Center"
        icon.name: "format-center"
    }

    Action {
        id: formatJustifyAction
        text: "Justify"
        icon.source: "icons/format-justify.svg"
        icon.name: "format-justify"
    }

    Action {
        id: formatLineSpacingAction
        text: "Set Line Spacing..."
        icon.name: "set-line-spacing"
    }

    Action {
        id: formatParagraphSpacingAction
        text: "Set Paragraph Spacing..."
        icon.name: "set-line-spacing"
    }

    // Help

    Action {
        id: helpAboutMe
        text: "About Me"
        icon.name: "about-me"
    }

    Action {
        id: helpAboutQt
        text: "About Qt"
        icon.name: "about-qt"
    }


    menuBar: MenuBar {
        Menu {
            title: "&File"
            MenuItem {action: fileNewAction }
            MenuItem {action: fileOpenAction }
            MenuItem {action: fileSaveAction }
            MenuItem {action: filePrintAction }
            MenuSeparator {}
            MenuItem {action: fileExitAction }
        }

        Menu {
            title: "&Edit"
            MenuItem {action: editUndoAction }
            MenuItem {action: editRedoAction }
            MenuSeparator {}
            MenuItem {action: editCutAction }
            MenuItem {action: editCopyAction }
            MenuItem {action: editPasteAction }

            Menu {
                title: "Format"
                MenuItem {action: formatBoldAction }
                MenuItem {action: formatItalicAction }
                MenuSeparator {}
                MenuItem {action: formatLeftAlignAction }
                MenuItem {action: formatRightAlignAction }
                MenuItem {action: formatCenterAction }
                MenuItem {action: formatJustifyAction }
                MenuSeparator {}
                MenuItem {action: formatLineSpacingAction }
                MenuItem {action: formatParagraphSpacingAction }
            }
        }

        Menu {
            title: "&Help"
            MenuItem { action: helpAboutMe }
            MenuItem { action: helpAboutQt }
        }
    }
}
