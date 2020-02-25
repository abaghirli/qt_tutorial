#include "settings.h"


SettingsManager::SettingsManager(const QString &organization, const QString &application)
    : m_settings(organization, application)
{
    //setting default values
    m_settings.setValue("bullet/speed", 50);
    m_settings.setValue("bullet/firing_speed", 5); // shots per second
    m_settings.setValue("enemy/speed", 5);
    m_settings.setValue("player/speed", 50);
    m_settings.setValue("game/spawn/speed", 20);
    m_settings.setValue("game/sound", 50);
    m_settings.setValue("game/music", 50);
}

QVariant SettingsManager::getVariantSetting(const QString &key)
{
    return m_settings.value(key);
}

int SettingsManager::getIntSetting(const QString &key)
{
    return m_settings.value(key).toInt();
}

bool SettingsManager::getBoolSetting(const QString &key)
{
    return m_settings.value(key).toBool();
}

bool SettingsManager::setSettingValue(const QString &key, const QVariant val)
{
    m_settings.setValue(key, val);
    return true;
}

