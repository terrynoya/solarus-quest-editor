/*
 * Copyright (C) 2014-2018 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus Quest Editor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus Quest Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUSEDITOR_IMPORT_DIALOG_H
#define SOLARUSEDITOR_IMPORT_DIALOG_H

#include "quest.h"
#include "ui_import_dialog.h"
#include <QDialog>

namespace SolarusEditor {

/**
 * @brief Dialog to import files from another quest.
 */
class ImportDialog : public QDialog {
  Q_OBJECT

public:

  explicit ImportDialog(Quest& destination_quest, QWidget* parent = nullptr);

  const Quest& get_source_quest() const;
  Quest& get_destination_quest() const;

signals:

  void destination_quest_rename_file_requested(Quest& quest, const QString& path);

public slots:

  void browse_source_quest();

private:

  Ui::ImportDialog ui;

  Quest source_quest;
  Quest& destination_quest;
};

}

#endif