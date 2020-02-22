#ifndef CONSTS_H
#define CONSTS_H
#include <QSettings>

static const int game_scene_width = 900;
static const int game_scene_height = 600;
static const int player_width = 80;
static const int player_height = 80;
static const int enemy_width = 50;
static const int enemy_height = 50;
static const int bullet_width = 7;
static const int bullet_height = 20;
static const int panel_offset = 100;

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
