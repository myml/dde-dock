/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QScopedPointer>
#include <QLabel>

#include "abstracttraywidget.h"

class QGSettings;

class IndicatorTrayWidget: public AbstractTrayWidget
{
    Q_OBJECT
public:
    explicit IndicatorTrayWidget(const QString &indicatorName, QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~IndicatorTrayWidget();

    QString itemKeyForConfig() override;
    void updateIcon() override;
    void sendClick(uint8_t, int, int) override;
    void enableLabel(bool enable);
    static QString toIndicatorKey(const QString &indicatorName) { return QString("indicator:%1").arg(indicatorName); }
    static bool isIndicatorKey(const QString &itemKey) { return itemKey.startsWith("indicator:"); }

protected:
    void resizeEvent(QResizeEvent *event) override;

public Q_SLOTS:
    Q_SCRIPTABLE void setPixmapData(const QByteArray &data);
    Q_SCRIPTABLE void setText(const QString &text);

private slots:
    void onGSettingsChanged(const QString &key);

Q_SIGNALS:
    void clicked(uint8_t, int, int);

private:
    QLabel *m_label;

    QString m_indicatorName;
    const QGSettings *m_gsettings;
    bool m_enableClick;              // 置灰时设置为false，不触发click信号
};

