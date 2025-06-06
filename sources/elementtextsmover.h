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
#ifndef ELEMENT_TEXTS_MOVER_H
#define ELEMENT_TEXTS_MOVER_H

#include <QSet>
#include <QPointF>
#include <QHash>

class QGraphicsItem;
class DiagramTextItem;
class Diagram;
class QGraphicsItemGroup;
class QGraphicsSceneMouseEvent;

/**
	This class manages the interactive movement of element text items on a
	particular diagram.
*/
class ElementTextsMover
{
	public:
		ElementTextsMover();
	private:
		ElementTextsMover(const ElementTextsMover &);

	public:
		bool isReady() const;
		int  beginMovement(Diagram *diagram, QGraphicsItem *driver_item = nullptr);
		void continueMovement(QGraphicsSceneMouseEvent *event);
		void endMovement();

	private:
		QString undoText() const;

	private:
		bool m_movement_running = false;
		Diagram *m_diagram = nullptr;
		QGraphicsItem *m_movement_driver = nullptr;
		QHash <DiagramTextItem *, QPointF> m_texts_hash;
		QHash <QGraphicsItemGroup *, QPointF> m_grps_hash;
		QHash <QGraphicsItem *, QPointF> m_items_hash;
		int m_text_count = 0,
			m_group_count = 0;
};
#endif
