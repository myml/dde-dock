/*
 * Copyright (C) 2018 ~ 2020 Uniontech Technology Co., Ltd.
 *
 * Author:     chenjun <chenjun@uniontech.com>
 *
 * Maintainer: chenjun <chenjun@uniontech.com>
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

#include <QObject>
#include <QTest>
#include <QMenu>

#include <gtest/gtest.h>
#define private public
#include "menuworker.h"
#include "dockitemmanager.h"
#undef private

class Test_MenuWorker : public ::testing::Test
{};

TEST_F(Test_MenuWorker, coverage_test)
{
    MenuWorker *worker = new MenuWorker(new DBusDock("com.deepin.dde.daemon.Dock", "/com/deepin/dde/daemon/Dock", QDBusConnection::sessionBus()));
    DockItemManager::instance()->m_pluginsInter->m_pluginsMap.clear();
    QMenu *menu = new QMenu();
    menu = worker->createMenu(menu);
    ASSERT_FALSE(menu->isEmpty());

//    worker->showDockSettingsMenu();

    delete menu;
    delete worker;
}

TEST_F(Test_MenuWorker, setAutoHide)
{
   MenuWorker *worker = new MenuWorker(new DBusDock("com.deepin.dde.daemon.Dock", "/com/deepin/dde/daemon/Dock", QDBusConnection::sessionBus()));

   ASSERT_TRUE(worker->m_autoHide);
   worker->setAutoHide(false);

   ASSERT_FALSE(worker->m_autoHide);
   worker->setAutoHide(true);
   ASSERT_TRUE(worker->m_autoHide);

   delete worker;
}
