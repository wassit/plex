#pragma once

/*
 *      Copyright (C) 2005-2008 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "Song.h"
#include "Artist.h"

class TiXmlDocument;
class CScraperUrl;
struct SScraperInfo;

namespace MUSIC_GRABBER
{
class CMusicArtistInfo
{
public:
  CMusicArtistInfo(void);
  CMusicArtistInfo(const CStdString& strArtist, const CScraperUrl& strArtistURL);
  virtual ~CMusicArtistInfo(void);
  bool Loaded() const;
  void SetLoaded(bool bOnOff);
  void SetArtist(const CArtist& artist);
  const CArtist& GetArtist() const;
  CArtist& GetArtist();
  const CScraperUrl& GetArtistURL() const;
  bool Load(CHTTP& http, const SScraperInfo& info, const CStdString& strFunction="GetArtistDetails", const CScraperUrl* url=NULL);
  bool Parse(const TiXmlElement* artist, bool bChained=false);
protected:
  CArtist m_artist;
  CScraperUrl m_artistURL;
  bool m_bLoaded;
};
};
