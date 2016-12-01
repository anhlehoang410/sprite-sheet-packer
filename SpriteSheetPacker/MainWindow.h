#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "SpriteAtlas.h"
#include "SpritesTreeWidget.h"
#include "PublishStatusDialog.h"
#include "SpritePackerProjectFile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void refreshFormats();
    void refreshOpenRecentMenu();
    void createRefreshButton();

    void refreshAtlas(bool generate = true);
    void refreshPreview();

    void openSpritePackerProject(const QString& fileName);
    void saveSpritePackerProject(const QString& fileName);
    void setProjectDirty();

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
    void closeEvent(QCloseEvent* event);

private slots:
    void openRecent();
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionAddSprites_triggered();
    void on_actionAddFolder_triggered();
    void on_actionRemove_triggered();
    void on_actionPublish_triggered();
    void on_actionAbout_triggered();
    void on_actionPreferences_triggered();

    void on_destFolderToolButton_clicked();
    void on_dataFormatSetupToolButton_clicked();
    void on_addScalingVariantPushButton_clicked();

    void spritesTreeWidgetItemSelectionChanged();
    void removeScalingVariant();

    void propertiesValueChanged();

    void on_algorithmComboBox_currentTextChanged(const QString& text);
    void on_trimModeComboBox_currentIndexChanged(int value);
    void on_trimSpinBox_valueChanged(int value);
    void on_epsilonHorizontalSlider_valueChanged(int value);
    void on_textureBorderSpinBox_valueChanged(int value);
    void on_spriteBorderSpinBox_valueChanged(int value);
    void on_imageFormatComboBox_currentIndexChanged(int index);
    void on_pixelFormatComboBox_currentIndexChanged(int index);
    void on_dataFormatComboBox_currentIndexChanged(int value);
    void on_destPathLineEdit_textChanged(const QString& text);
    void on_spriteSheetLineEdit_textChanged(const QString& text);
    void on_optModeComboBox_currentTextChanged(const QString &text);
    void on_optLevelSlider_valueChanged(int value);
    void on_premultipliedCheckBox_toggled(bool checked);

    void scalingVariantWidgetValueChanged(bool);

private:
    Ui::MainWindow*         ui;
    SpritesTreeWidget*      _spritesTreeWidget;
    QString                 _currentProjectFileName;
    QToolButton*            _openButton;
    QVector<SpriteAtlas>    _spriteAtlas;
    bool                    _blockUISignals;
    bool                    _projectDirty;
    bool                    _atlasDirty;
};

#endif // MAINWINDOW_H
