/*
	Copyright 2006-2025 The QElectroTech Team
	This file is part of QElectroTech.
	
	QElectroTech is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.
	
	QElectroTech is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with QElectroTech.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef GENERALCONFIGURATIONPAGE_H
#define GENERALCONFIGURATIONPAGE_H

#include "configpage.h"

#include <QWidget>

namespace Ui {
	class GeneralConfigurationPage;
}

class GeneralConfigurationPage : public ConfigPage
{
	Q_OBJECT
	
	public:
		explicit GeneralConfigurationPage(QWidget *parent = nullptr);
		~GeneralConfigurationPage() override;
	
		virtual void applyConf() override;
		virtual QString title() const override;
		virtual QIcon icon() const override;
	
	private slots:
		void on_m_font_pb_clicked();
		void on_m_dyn_text_font_pb_clicked();
		void on_m_common_elmt_path_cb_currentIndexChanged(int index);
		void on_m_company_elmt_path_cb_currentIndexChanged(int index);
		void on_m_custom_elmt_path_cb_currentIndexChanged(int index);
		void on_m_company_tbt_path_cb_currentIndexChanged(int index);
		void on_m_custom_tbt_path_cb_currentIndexChanged(int index);
		void on_m_indi_text_font_pb_clicked();
		void on_MaxPartsElementEditorList_sb_valueChanged(int value);
		void on_DiagramEditor_Grid_PointSize_min_sb_valueChanged(int value);
		void on_ElementEditor_Grid_PointSize_min_sb_valueChanged(int value);

	private:
		void fillLang();
	
	private:
		Ui::GeneralConfigurationPage *ui;
};

#endif // GENERALCONFIGURATIONPAGE_H
