#pragma once

#include <vector>
#include <QtGui>

/* The Shape class now contains every control point a object is required to display
 * Also a dedicated method for painting the points is given
 * Adding points requires upper logic, and using these points owes to its child
 */

namespace DrawContext {

	class Shape
	{
	public:

		Shape();
		virtual ~Shape();
		virtual void Draw(QPainter& paint) = 0;

		/* Draw control points, with lines and "+" mark */
		void DrawCtrlPoints(QPainter& paint);

		/* Attr to maintain and decouple messages */
		void setAttr(std::string& s, int a);

		/* returns -1 if not found */
		int getAttr(std::string& s);

		/* Checking if it's the correct control point (within a preset range in px)
		 * return -1 if not, and index (>=0) if found
		 */
		int getCtrlPoint(QPoint& cursor, int range);

		/* return ctrl_points */
		const std::vector<QPoint>& getCtrlPoints(void);

		/* index is given in getCtrlPoint */
		void modifyCtrlPoint(int index, QPoint& dest);

	protected:
		std::vector<QPoint> ctrl_points;
		std::map<std::string, int> attr;

	};

};