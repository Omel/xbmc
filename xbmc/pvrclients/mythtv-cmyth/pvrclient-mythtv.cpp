#include "pvrclient-mythtv.h"
#include "client.h"



PVRClientMythTV::PVRClientMythTV()
  :m_con(),m_eventHandler(),m_db(),m_protocolVersion(""),m_connectionString(""),m_EPGstart(0),m_EPGend(0),m_channelGroups(),m_categoryMap()
{
m_categoryMap.insert(catbimap::value_type("Movie",0x10));
m_categoryMap.insert(catbimap::value_type("Movie", 0x10));
m_categoryMap.insert(catbimap::value_type("Movie - Detective/Thriller", 0x11));
m_categoryMap.insert(catbimap::value_type("Movie - Adventure/Western/War", 0x12));
m_categoryMap.insert(catbimap::value_type("Movie - Science Fiction/Fantasy/Horror", 0x13));
m_categoryMap.insert(catbimap::value_type("Movie - Comedy", 0x14));
m_categoryMap.insert(catbimap::value_type("Movie - Soap/melodrama/folkloric", 0x15));
m_categoryMap.insert(catbimap::value_type("Movie - Romance", 0x16));
m_categoryMap.insert(catbimap::value_type("Movie - Serious/Classical/Religious/Historical Movie/Drama", 0x17));
m_categoryMap.insert(catbimap::value_type("Movie - Adult   ", 0x18));
m_categoryMap.insert(catbimap::value_type("Drama", 0x1F));//MythTV use 0xF0 but xbmc doesn't implement this.
m_categoryMap.insert(catbimap::value_type("News", 0x20));
m_categoryMap.insert(catbimap::value_type("News/weather report", 0x21));
m_categoryMap.insert(catbimap::value_type("News magazine", 0x22));
m_categoryMap.insert(catbimap::value_type("Documentary", 0x23));
m_categoryMap.insert(catbimap::value_type("Intelligent Programmes", 0x24));
m_categoryMap.insert(catbimap::value_type("Entertainment", 0x30));
m_categoryMap.insert(catbimap::value_type("Game Show", 0x31));
m_categoryMap.insert(catbimap::value_type("Variety Show", 0x32));
m_categoryMap.insert(catbimap::value_type("Talk Show", 0x33));
m_categoryMap.insert(catbimap::value_type("Sports", 0x40));
m_categoryMap.insert(catbimap::value_type("Special Events (World Cup, World Series, etc)", 0x41));
m_categoryMap.insert(catbimap::value_type("Sports Magazines", 0x42));
m_categoryMap.insert(catbimap::value_type("Football (Soccer)", 0x43));
m_categoryMap.insert(catbimap::value_type("Tennis/Squash", 0x44));
m_categoryMap.insert(catbimap::value_type("Misc. Team Sports", 0x45));
m_categoryMap.insert(catbimap::value_type("Athletics", 0x46));
m_categoryMap.insert(catbimap::value_type("Motor Sport", 0x47));
m_categoryMap.insert(catbimap::value_type("Water Sport", 0x48));
m_categoryMap.insert(catbimap::value_type("Winter Sports", 0x49));
m_categoryMap.insert(catbimap::value_type("Equestrian", 0x4A));
m_categoryMap.insert(catbimap::value_type("Martial Sports", 0x4B));
m_categoryMap.insert(catbimap::value_type("Kids", 0x50));
m_categoryMap.insert(catbimap::value_type("Pre-School Children's Programmes", 0x51));
m_categoryMap.insert(catbimap::value_type("Entertainment Programmes for 6 to 14", 0x52));
m_categoryMap.insert(catbimap::value_type("Entertainment Programmes for 10 to 16", 0x53));
m_categoryMap.insert(catbimap::value_type("Informational/Educational", 0x54));
m_categoryMap.insert(catbimap::value_type("Cartoons/Puppets", 0x55));
m_categoryMap.insert(catbimap::value_type("Music/Ballet/Dance", 0x60));
m_categoryMap.insert(catbimap::value_type("Rock/Pop", 0x61));
m_categoryMap.insert(catbimap::value_type("Classical Music", 0x62));
m_categoryMap.insert(catbimap::value_type("Folk Music", 0x63));
m_categoryMap.insert(catbimap::value_type("Jazz", 0x64));
m_categoryMap.insert(catbimap::value_type("Musical/Opera", 0x65));
m_categoryMap.insert(catbimap::value_type("Ballet", 0x66));
m_categoryMap.insert(catbimap::value_type("Arts/Culture", 0x70));
m_categoryMap.insert(catbimap::value_type("Performing Arts", 0x71));
m_categoryMap.insert(catbimap::value_type("Fine Arts", 0x72));
m_categoryMap.insert(catbimap::value_type("Religion", 0x73));
m_categoryMap.insert(catbimap::value_type("Popular Culture/Traditional Arts", 0x74));
m_categoryMap.insert(catbimap::value_type("Literature", 0x75));
m_categoryMap.insert(catbimap::value_type("Film/Cinema", 0x76));
m_categoryMap.insert(catbimap::value_type("Experimental Film/Video", 0x77));
m_categoryMap.insert(catbimap::value_type("Broadcasting/Press", 0x78));
m_categoryMap.insert(catbimap::value_type("New Media", 0x79));
m_categoryMap.insert(catbimap::value_type("Arts/Culture Magazines", 0x7A));
m_categoryMap.insert(catbimap::value_type("Fashion", 0x7B));
m_categoryMap.insert(catbimap::value_type("Social/Policical/Economics", 0x80));
m_categoryMap.insert(catbimap::value_type("Magazines/Reports/Documentary", 0x81));
m_categoryMap.insert(catbimap::value_type("Economics/Social Advisory", 0x82));
m_categoryMap.insert(catbimap::value_type("Remarkable People", 0x83));
m_categoryMap.insert(catbimap::value_type("Education/Science/Factual", 0x90));
m_categoryMap.insert(catbimap::value_type("Nature/animals/Environment", 0x91));
m_categoryMap.insert(catbimap::value_type("Technology/Natural Sciences", 0x92));
m_categoryMap.insert(catbimap::value_type("Medicine/Physiology/Psychology", 0x93));
m_categoryMap.insert(catbimap::value_type("Foreign Countries/Expeditions", 0x94));
m_categoryMap.insert(catbimap::value_type("Social/Spiritual Sciences", 0x95));
m_categoryMap.insert(catbimap::value_type("Further Education", 0x96));
m_categoryMap.insert(catbimap::value_type("Languages", 0x97));
m_categoryMap.insert(catbimap::value_type("Leisure/Hobbies", 0xA0));
m_categoryMap.insert(catbimap::value_type("Tourism/Travel", 0xA1));
m_categoryMap.insert(catbimap::value_type("Handicraft", 0xA2));
m_categoryMap.insert(catbimap::value_type("Motoring", 0xA3));
m_categoryMap.insert(catbimap::value_type("Fitness & Health", 0xA4));
m_categoryMap.insert(catbimap::value_type("Cooking", 0xA5));
m_categoryMap.insert(catbimap::value_type("Advertizement/Shopping", 0xA6));
m_categoryMap.insert(catbimap::value_type("Gardening", 0xA7));
m_categoryMap.insert(catbimap::value_type("Original Language", 0xB0));
m_categoryMap.insert(catbimap::value_type("Black & White", 0xB1));
m_categoryMap.insert(catbimap::value_type("\"Unpublished\" Programmes", 0xB2));
m_categoryMap.insert(catbimap::value_type("Live Broadcast", 0xB3));
}


  int PVRClientMythTV::Genre(CStdString g)
  {
      int retval=0;
      try{
        retval=m_categoryMap.by<mythcat>().at(g);
      }
      catch(std::out_of_range){}
      return retval;
  }
  CStdString PVRClientMythTV::Genre(int g)
  {
    CStdString retval="";
      try{
        retval=m_categoryMap.by<pvrcat>().at(g);
      }
      catch(std::out_of_range){}
      return retval;
  }


void Log(int l,char* msg)
{
   
  if(msg&&l!=CMYTH_DBG_NONE)
  {
    bool doLog=false;
    addon_log_t loglevel;
    switch( l)
    {
      case CMYTH_DBG_ERROR:
        loglevel=LOG_ERROR;
        doLog=true;
        break;
      case CMYTH_DBG_WARN:
      case CMYTH_DBG_INFO:
        loglevel=LOG_INFO;
        break;
      case CMYTH_DBG_DETAIL:
      case CMYTH_DBG_DEBUG:
      case CMYTH_DBG_PROTO:
      case CMYTH_DBG_ALL: 
        loglevel=LOG_DEBUG;
        break;
    }    
    if(XBMC&&doLog)
      XBMC->Log(loglevel,"LibCMyth: %s",  msg);
  }
}

bool PVRClientMythTV::Connect()
{
  CMYTH->DbgAll();
  CMYTH->SetDbgMsgcallback(Log);
  m_con=MythConnection(g_szHostname,g_iMythPort);
  if(!m_con.IsConnected())
    return false;
  m_eventHandler=m_con.CreateEventHandler();
  m_protocolVersion.Format("%i",m_con.GetProtocolVersion());
  m_connectionString.Format("%s:%i",g_szHostname,g_iMythPort);
  m_db=MythDatabase(g_szHostname,g_szMythDBname,g_szMythDBuser,g_szMythDBpassword);
  m_channels=m_db.ChannelList();
  m_channelGroups=m_db.GetChannelGroups();
  return true;
}

const char* PVRClientMythTV::GetBackendName()
{
  return m_con.GetServer();
}


const char * PVRClientMythTV::GetBackendVersion()
{
  return m_protocolVersion;
}

const char * PVRClientMythTV::GetConnectionString()
{
  return m_connectionString;
}

bool PVRClientMythTV::GetDriveSpace(long long *iTotal, long long *iUsed)
{
  return m_con.GetDriveSpace(*iTotal,*iUsed);
}

PVR_ERROR PVRClientMythTV::GetEPGForChannel(PVR_HANDLE handle, const PVR_CHANNEL &channel, time_t iStart, time_t iEnd)
{
  if(iStart!=m_EPGstart&&iEnd!=m_EPGend)
  {
    m_EPG=m_db.GetGuide(iStart,iEnd);
    m_EPGstart=iStart;
    m_EPGend=iEnd;
  }
  for(std::vector<MythProgram>::iterator it=m_EPG.begin();it!=m_EPG.end();it++)
  {
    if(it->chanid==channel.iUniqueId)
    {
      EPG_TAG tag;
      tag.endTime=it->endtime;
      tag.iChannelNumber=it->channum;
      tag.startTime=it->starttime;
      tag.strTitle=it->title;
      tag.strPlot= it->description;
      unsigned int seriesid=atoi(it->seriesid);
      if(seriesid!=0)
        tag.iUniqueBroadcastId=atoi(it->seriesid);
      else
        tag.iUniqueBroadcastId=(tag.startTime<<16)+(tag.iChannelNumber&0xffff);
      int genre=Genre(it->category);
      
      tag.iGenreSubType=genre&0x0F;
      tag.iGenreType=genre&0xF0;
      //unimplemented
      tag.strEpisodeName="";
      tag.strGenreDescription="";
      tag.strIconPath="";
      tag.strPlotOutline="";
      tag.bNotify=false;
      tag.firstAired=0;
      tag.iEpisodeNumber=0;
      tag.iEpisodePartNumber=0;
      tag.iParentalRating=0;
      tag.iSeriesNumber=0;
      tag.iStarRating=0;
      
      
      PVR->TransferEpgEntry(handle,&tag);
    }
   }
   return PVR_ERROR_NO_ERROR;
  }


int PVRClientMythTV::GetNumChannels()
{
  return m_channels.size();
}

//bool isRadio(MythChannel v){return v.IsRadio();}

PVR_ERROR PVRClientMythTV::GetChannels(PVR_HANDLE handle, bool bRadio)
{
  for (std::map<int,MythChannel>::iterator it = m_channels.begin(); it != m_channels.end(); it++)
  {
    if (it->second.IsRadio()==bRadio)
    {
      PVR_CHANNEL tag;
      tag.bIsHidden=!it->second.Visible();
      tag.bIsRadio=it->second.IsRadio();
      tag.iUniqueId=it->first;
      tag.iChannelNumber=it->second.Number(); //Swap ID and Number?
      CStdString chanName= it->second.Name();
      tag.strChannelName = chanName;
      CStdString icon = it->second.Icon();
      tag.strIconPath = icon;

      //Unimplemented
      tag.strStreamURL="";
      tag.strInputFormat="";
      tag.iEncryptionSystem=0;
      

      PVR->TransferChannelEntry(handle,&tag);
    }
  }
  return PVR_ERROR_NO_ERROR;
}

int PVRClientMythTV::GetRecordingsAmount(void)
{
  m_recordings=m_con.GetRecordedPrograms();
  return m_recordings.size();
}


PVR_ERROR PVRClientMythTV::GetRecordings(PVR_HANDLE handle)
{
  if(m_recordings.size()==0)
    m_recordings=m_con.GetRecordedPrograms();
for (boost::unordered_map<CStdString, MythProgramInfo>::iterator it = m_recordings.begin(); it != m_recordings.end(); it++)
  {
    PVR_RECORDING tag;
    tag.iDuration=it->second.Duration();
    tag.recordingTime=it->second.RecStart();
    CStdString chanName=it->second.ChannelName();
    CStdString plot=it->second.Description();
    CStdString path=it->second.Path();
    CStdString title=it->second.Title();

    tag.strChannelName=chanName;
    tag.strPlot=plot;
    CStdString id=it->second.Path();
    tag.strRecordingId=id;
    CStdString group=it->second.RecordingGroup();
    tag.strDirectory=group=="Default"?"":group;
    tag.strTitle=title;
    int genre=Genre(it->second.Category());      
    tag.iGenreSubType=genre&0x0F;
    tag.iGenreType=genre&0xF0;

    //Unimplemented
    
    tag.iLifetime=0;
    tag.iPriority=0;
    //tag.recordingTime=0;
    tag.strPlotOutline="";
    tag.strStreamURL="";
    
    
    
    PVR->TransferRecordingEntry(handle,&tag);
  }
  return PVR_ERROR_NO_ERROR;
}

 PVR_ERROR PVRClientMythTV::DeleteRecording(const PVR_RECORDING &recording)
 {
   
   //long long uid=*reinterpret_cast<const long long*>(recording.strRecordingId);
   CStdString id=recording.strRecordingId;
   bool ret = m_con.DeleteRecording(m_recordings[id]);
   if(ret && m_recordings.erase(recording.strRecordingId))
   {
     PVR->TriggerRecordingUpdate();
     return PVR_ERROR_NO_ERROR;

   }
   else
     return PVR_ERROR_NOT_DELETED;
 }

 int PVRClientMythTV::GetTimersAmount(void)
 {
  std::vector<MythTimer> m_timers=m_db.GetTimers();
  return m_timers.size();
 }

  PVR_ERROR PVRClientMythTV::GetTimers(PVR_HANDLE handle)
  {
    std::vector<MythTimer> m_timers=m_db.GetTimers();
    for (std::vector<MythTimer>::iterator it = m_timers.begin(); it != m_timers.end(); it++)
  {
    PVR_TIMER tag;
    tag.endTime=it->EndTime();
    tag.iClientChannelUid=it->ChanID();
    tag.iClientIndex=it->RecordID();
    tag.startTime=it->StartTime();
    CStdString title=it->Title();
    tag.strTitle=title;
    CStdString summary=it->Description(); 
    tag.strSummary=summary;
    tag.state=PVR_TIMER_STATE_SCHEDULED;
        int genre=Genre(it->Category());
    tag.iGenreSubType=genre&0x0F;
    tag.iGenreType=genre&0xF0;

    //Unimplemented
    tag.bIsRepeating=false;
    tag.firstDay=0;
    tag.iEpgUid=0;
    tag.iLifetime=0;
    tag.iMarginEnd=0;
    tag.iMarginStart=0;
    tag.iPriority=0;
    tag.iWeekdays=0;
    tag.strDirectory="";
    
    PVR->TransferTimerEntry(handle,&tag);
  }
  return PVR_ERROR_NO_ERROR;
}

  PVR_ERROR PVRClientMythTV::AddTimer(const PVR_TIMER &timer)
  {
    CStdString category=Genre(timer.iGenreType);

    int id=m_db.AddTimer(timer.iClientChannelUid,m_channels[timer.iClientChannelUid].Name(),timer.strSummary,timer.startTime,timer.endTime,timer.strTitle,category);
    if(id<0)
      return PVR_ERROR_NOT_POSSIBLE;
    if(!m_con.UpdateSchedules(id))
      return PVR_ERROR_NOT_POSSIBLE;
    PVR->TriggerTimerUpdate();
    return PVR_ERROR_NO_ERROR;
  }

  PVR_ERROR PVRClientMythTV::DeleteTimer(const PVR_TIMER &timer, bool bForceDelete)
  {
    if(!m_db.DeleteTimer(timer.iClientIndex))
      return PVR_ERROR_NOT_POSSIBLE;
    m_con.UpdateSchedules(-1);
    PVR->TriggerTimerUpdate();
    return PVR_ERROR_NO_ERROR;
  }
  
  PVR_ERROR PVRClientMythTV::UpdateTimer(const PVR_TIMER &timer)
  {
    CStdString category=Genre(timer.iGenreType);
    if(!m_db.UpdateTimer(timer.iClientIndex,timer.iClientChannelUid,m_channels[timer.iClientChannelUid].Name(),timer.strSummary,timer.startTime,timer.endTime,timer.strTitle,category))
       return PVR_ERROR_NOT_POSSIBLE;
    m_con.UpdateSchedules(timer.iClientIndex);
    return PVR_ERROR_NO_ERROR;
  }


  bool PVRClientMythTV::OpenLiveStream(const PVR_CHANNEL &channel)
  {
    if(m_rec.IsNull())
    {
      m_rec=m_con.GetFreeRecorder();
      XBMC->Log(LOG_DEBUG,"%s: Opening new recorder %i",__FUNCTION__,m_rec.ID());
      m_eventHandler.SetRecorder(m_rec);
      MythChannel chan=m_channels[channel.iUniqueId];
      return m_rec.SpawnLiveTV(chan);
    }
    else
      return true;

  }


  void PVRClientMythTV::CloseLiveStream()
{
  m_rec.Stop();
  m_rec=NULL;
  return;
}

int PVRClientMythTV::ReadLiveStream(unsigned char *pBuffer, unsigned int iBufferSize)
{
  if(m_rec.IsNull())
    return -1;
  return m_rec.ReadLiveTV(pBuffer,iBufferSize);
}

int PVRClientMythTV::GetCurrentClientChannel()
{
  if(m_rec.IsNull())
    return -1;
  MythProgramInfo currentProgram=m_rec.GetCurrentProgram();
  return currentProgram.ChannelID();
  /*
  CStdString channel=currentProgram.ChannelName();
  return currentProgram.ChannelID();
  for(std::vector<MythChannel>::iterator it=m_channels.begin();it!=m_channels.end();it++)
  {
    if(it->Name()==channel)
      return it->ID();
  }
  return -1;*/
}

bool PVRClientMythTV::SwitchChannel(const PVR_CHANNEL &channelinfo)
{
  MythChannel chan=m_channels[channelinfo.iUniqueId];
  return m_rec.SetChannel(chan);
}

long long PVRClientMythTV::SeekLiveStream(long long iPosition, int iWhence) { 
  int whence=iWhence==SEEK_SET?WHENCE_SET:iWhence==SEEK_CUR?WHENCE_CUR:WHENCE_END;
  return m_rec.LiveTVSeek(iPosition,whence);
  }

long long PVRClientMythTV::LengthLiveStream()
{
  return m_rec.LiveTVDuration();
}

PVR_ERROR PVRClientMythTV::SignalStatus(PVR_SIGNAL_STATUS &signalStatus)
{
  MythSignal signal=m_eventHandler.GetSignal();
  signalStatus.dAudioBitrate=0;
  signalStatus.dDolbyBitrate=0;
  signalStatus.dVideoBitrate=0;
  signalStatus.iBER=signal.BER();
  signalStatus.iSignal=signal.Signal();
  signalStatus.iSNR=signal.SNR();
  signalStatus.iUNC=signal.UNC();
  CStdString ID;
  CStdString adaptorStatus=signal.AdapterStatus();
  ID.Format("Myth Recorder %i",m_rec.ID());
  strcpy(signalStatus.strAdapterName,ID.Buffer());
  strcpy(signalStatus.strAdapterStatus,adaptorStatus.Buffer());
  return PVR_ERROR_NO_ERROR;
}

bool PVRClientMythTV::OpenRecordedStream(const PVR_RECORDING &recinfo)
{
  //long long uid=*reinterpret_cast<const long long*>(recinfo.strRecordingId);
  CStdString id=recinfo.strRecordingId;
  m_file=m_con.ConnectFile(m_recordings[id]);

  return !m_file.IsNull();
}

void PVRClientMythTV::CloseRecordedStream()
{
  m_file=0;
}

int PVRClientMythTV::ReadRecordedStream(unsigned char *pBuffer, unsigned int iBufferSize)
{
  return m_file.Read(pBuffer,iBufferSize);
}

long long PVRClientMythTV::SeekRecordedStream(long long iPosition, int iWhence)
{
  int whence=iWhence==SEEK_SET?WHENCE_SET:iWhence==SEEK_CUR?WHENCE_CUR:WHENCE_END;
	return m_file.Seek(iPosition,whence);
}


long long PVRClientMythTV::LengthRecordedStream()
{
  return m_file.Duration();
}


  int PVRClientMythTV::GetChannelGroupsAmount()
    {
  return m_channelGroups.size();
 }

  PVR_ERROR PVRClientMythTV::GetChannelGroups(PVR_HANDLE handle, bool bRadio)
    {
      PVR_CHANNEL_GROUP tag;
      for(boost::unordered_map<CStdString, std::vector<int>>::iterator it=m_channelGroups.begin();it!=m_channelGroups.end();it++)
      {
        tag.strGroupName=it->first;
        tag.bIsRadio=bRadio;
        for(std::vector<int>::iterator it2=it->second.begin();it2!=it->second.end();it2++)
          if(m_channels[*it2].IsRadio()==bRadio)
          {
            PVR->TransferChannelGroup(handle,&tag);
            break;
          }
      }

      return PVR_ERROR_NO_ERROR;
    
  }

  PVR_ERROR PVRClientMythTV::GetChannelGroupMembers(PVR_HANDLE handle, const PVR_CHANNEL_GROUP &group)
    {
    PVR_CHANNEL_GROUP_MEMBER tag;
    int i=0;
    for(std::vector<int>::iterator it=m_channelGroups[group.strGroupName].begin();it!=m_channelGroups[group.strGroupName].end();it++)
    {
      MythChannel chan=m_channels[*it]; 
      if(group.bIsRadio==chan.IsRadio())
      {
        tag.iChannelNumber=i++;
        tag.iChannelUniqueId=chan.ID();
        tag.strGroupName=group.strGroupName;
        PVR->TransferChannelGroupMember(handle,&tag);
      }
    }
    return PVR_ERROR_NO_ERROR;
  }