#pragma once
/*
 *  PlexSourceScanner.h
 *  Plex
 *
 *  Created by Elan Feingold & James Clarke on 13/11/2009.
 *  Copyright 2009 Plex Development Team. All rights reserved.
 *
 */

#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include "CriticalSection.h"
#include "FileItem.h"
#include "SingleLock.h"
#include "Settings.h"
#include "Thread.h"

class HostSources
{
 public:

  VECSOURCES    videoSources;
  VECSOURCES    musicSources;
  VECSOURCES    pictureSources;
  CFileItemList librarySections;
};

typedef boost::shared_ptr<HostSources> HostSourcesPtr;
typedef pair<string, HostSourcesPtr> StringSourcesPair;

////////////////////////////////////////////
class CPlexSourceScanner : public CThread
{
public:
  
  virtual void Process();
  
  static void ScanHost(const string& host, const string& hostLabel, const string& url);
  static void RemoveHost(const string& host);
  
  static void MergeSourcesForWindow(int windowId);
  
  static void Lock() { ::EnterCriticalSection(g_lock); }
  static map<string, HostSourcesPtr>& GetMap() { return g_hostSourcesMap; }
  static void Unlock() { ::LeaveCriticalSection(g_lock); }

  static int GetActiveScannerCount() { return g_activeScannerCount; } 
  
protected:
  
  static void MergeSource(VECSOURCES& sources, VECSOURCES& remoteSources);
  static void CheckForRemovedSources(VECSOURCES& sources, int windowId);
  
  CPlexSourceScanner(const string& host, const string& hostLabel, const string& url)
  : m_host(host)
  , m_hostLabel(hostLabel)
  , m_url(url)
  {
    Create(true);
  }
  
  virtual ~CPlexSourceScanner() {}
  
private:
  
  string m_host;
  string m_hostLabel;
  string m_url;
  
  static map<string, HostSourcesPtr> g_hostSourcesMap;
  static CCriticalSection g_lock;
  static int g_activeScannerCount;
};
