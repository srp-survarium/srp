void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::Read(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::LoadProcess *plp,
        Scaleform::GFx::MovieBindProcess *pbp)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // ecx
  Scaleform::GFx::TagType v7; // ebp
  Scaleform::GFx::AS3::Instances::fl_geom::Transform *v8; // ecx
  void (__thiscall *v9)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *); // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // ecx
  Scaleform::GFx::LoadProcess::LoadStateType LoadState; // eax
  int tagLoadedBytes; // [esp+1Ch] [ebp-18h]
  signed int loadUpdateIncrement; // [esp+20h] [ebp-14h]
  Scaleform::GFx::TagInfo tagInfo; // [esp+24h] [ebp-10h] BYREF
  char notifyNeeded; // [esp+38h] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)plp->pAltStream;
  if ( !pAltStream )
    pAltStream = &plp->ProcessInfo;
  EnterCriticalSection(&this->PlaylistLock.cs);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Playlist.Data,
    this->Header.FrameCount);
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->InitActionList.Data,
    this->Header.FrameCount);
  LeaveCriticalSection(&this->PlaylistLock.cs);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v6);
  this->TagCount = 0;
  tagLoadedBytes = 0;
  notifyNeeded = 0;
  loadUpdateIncrement = this->Header.FileLength / 0x1E;
  if ( loadUpdateIncrement < 0x2000 )
    loadUpdateIncrement = 0x2000;
  if ( pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize >= plp->ProcessInfo.FileEndPos )
  {
LABEL_32:
    LoadState = plp->LoadState;
    if ( plp->FrameTags[LoadState].Data.Size || LoadState == LS_LoadingRoot && plp->InitActionTags.Data.Size )
    {
      Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(this, plp, 1);
      if ( pbp )
        Scaleform::GFx::MovieBindProcess::BindNextFrame(pbp);
    }
    else
    {
      Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->LoadingFrame, LS_LoadFinished);
    }
    return;
  }
  while ( !this->LoadingCanceled )
  {
    v7 = Scaleform::GFx::Stream::OpenTag(&pAltStream->Stream, &tagInfo);
    tagLoadedBytes += tagInfo.TagLength;
    if ( notifyNeeded && (this->LoadingFrame == 1 || tagLoadedBytes > loadUpdateIncrement || tagInfo.TagLength > 0x2000) )
    {
      Scaleform::WaitCondition::NotifyAll(&this->pFrameUpdate.pObject->WC);
      notifyNeeded = 0;
      tagLoadedBytes = 0;
    }
    Scaleform::GFx::LoadProcess::ReportProgress(plp, &this->FileURL, &tagInfo, 0);
    if ( v7 != Tag_EndFrame )
    {
      if ( (unsigned int)v7 >= Tag_SWF_TagTableEnd )
      {
        v8 = (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)(v7 - 1000);
        if ( (unsigned int)(v7 - 1000) <= 9 )
        {
          v9 = (void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::GFx_GFX_TagLoaderTable[v7 - 1000];
          goto LABEL_17;
        }
      }
      else
      {
        v9 = (void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::SWF_TagLoaderTable[v7];
LABEL_17:
        if ( v9 )
        {
          v9(v8, (unsigned int)plp, (const Scaleform::GFx::AS3::Value *)&tagInfo);
          goto LABEL_20;
        }
      }
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v8);
    }
LABEL_20:
    Scaleform::GFx::Stream::CloseTag(&pAltStream->Stream);
    ++this->TagCount;
    if ( v7 == Tag_EndFrame )
    {
      if ( !Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(this, plp, 0) )
        return;
      notifyNeeded = 1;
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v10);
      if ( pbp )
        Scaleform::GFx::MovieBindProcess::BindNextFrame(pbp);
    }
    else if ( v7 == Tag_End
           && pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize != plp->ProcessInfo.FileEndPos )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
        &pAltStream->Stream,
        "Loader - Stream-end tag hit, but not at the end of the file yet; stopping for safety");
      goto LABEL_32;
    }
    if ( pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize >= plp->ProcessInfo.FileEndPos )
      goto LABEL_32;
  }
  Scaleform::GFx::LoadProcess::CleanupFrameTags(plp);
  if ( pbp )
    Scaleform::GFx::MovieBindProcess::SetBindState(pbp, 3u);
  Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(this, this->LoadingFrame, LS_LoadCanceled);
}
