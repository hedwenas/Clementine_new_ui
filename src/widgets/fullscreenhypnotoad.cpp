/* This file is part of Clementine.
   Copyright 2010, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "fullscreenhypnotoad.h"

#include <QMovie>

FullscreenHypnotoad::FullscreenHypnotoad()
  : movie_(new QMovie(":/hypnotoad.gif"))
{
  setMovie(movie_);
  setScaledContents(true);

  // White background
  QPalette p(palette());
  p.setColor(QPalette::Window, Qt::white);
  setPalette(p);
}

void FullscreenHypnotoad::mouseReleaseEvent(QMouseEvent* e) {
  hide();
}

void FullscreenHypnotoad::keyReleaseEvent(QKeyEvent* e) {
  hide();
}

void FullscreenHypnotoad::showEvent(QShowEvent*) {
  movie_->start();
}

void FullscreenHypnotoad::hideEvent(QHideEvent*) {
  movie_->stop();
}
