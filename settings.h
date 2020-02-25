#ifndef CONSTS_H
#define CONSTS_H
#include <QSettings>

static const int game_scene_width = 390;
static const int game_scene_height = 260;
static const int player_width = game_scene_height/7.5;
static const int player_height = game_scene_height/7.5;
static const int enemy_width = game_scene_height/12;
static const int enemy_height = game_scene_height/12;
static const int bullet_width = game_scene_height/75;
static const int bullet_height = game_scene_height/30;
static const int panel_offset = game_scene_height/6;

class SettingsManager : public QObject{
    Q_OBJECT
private:
    QSettings m_settings;

public:
    SettingsManager(const QString &organization, const QString &application);
    QVariant getVariantSetting(const QString &key);
    int getIntSetting(const QString &key);
    bool getBoolSetting(const QString &key);
    bool setSettingValue(const QString &key, const QVariant val);
};

#endif // CONSTS_H
