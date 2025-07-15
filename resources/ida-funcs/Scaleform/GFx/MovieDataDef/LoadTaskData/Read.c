void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::Read(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::LoadProcess *plp,
        Scaleform::GFx::MovieBindProcess *pbp)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // edi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::GFx::TagType v7; // ebp
  void (__thiscall *v8)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *); // eax
  Scaleform::GFx::LoadProcess::LoadStateType LoadState; // eax
  signed int v10; // [esp+1Ch] [ebp-18h]
  signed int v11; // [esp+20h] [ebp-14h]
  Scaleform::GFx::TagInfo pTagInfo; // [esp+24h] [ebp-10h] BYREF
  char argc; // [esp+38h] [ebp+4h]

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
  Scaleform::GFx::Stream::LogParseClass(&pAltStream->Stream, &this->Header.FrameRect);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &pAltStream->Stream,
    aNoteSwfFrameRa,
    this->Header.FPS,
    this->Header.FrameCount);
  this->TagCount = 0;
  Instance = Scaleform::AmpServer::GetInstance();
  plp->pLoadData.pObject->SwdHandle = Instance->GetNextSwdHandle(Instance);
  v10 = 0;
  argc = 0;
  v11 = this->Header.FileLength / 0x1E;
  if ( v11 < 0x2000 )
    v11 = 0x2000;
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
    v7 = Scaleform::GFx::Stream::OpenTag(&pAltStream->Stream, &pTagInfo);
    v10 += pTagInfo.TagLength;
    if ( argc && (this->LoadingFrame == 1 || v10 > v11 || pTagInfo.TagLength > 0x2000) )
    {
      Scaleform::WaitCondition::NotifyAll(&this->pFrameUpdate.pObject->WC);
      argc = 0;
      v10 = 0;
    }
    Scaleform::GFx::LoadProcess::ReportProgress(plp, &this->FileURL, &pTagInfo, 0);
    if ( v7 != Tag_EndFrame )
    {
      if ( (unsigned int)v7 >= Tag_SWF_TagTableEnd )
      {
        if ( (unsigned int)(v7 - 1000) <= 9 )
        {
          v8 = (void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::GFx_GFX_TagLoaderTable[v7 - 1000];
          goto LABEL_17;
        }
      }
      else
      {
        v8 = (void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::SWF_TagLoaderTable[v7];
LABEL_17:
        if ( v8 )
        {
          v8(
            (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)&pTagInfo,
            (unsigned int)plp,
            (const Scaleform::GFx::AS3::Value *)&pTagInfo);
          goto LABEL_20;
        }
      }
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, aNoTagLoaderFor, v7);
      Scaleform::GFx::Stream::LogTagBytes(&pAltStream->Stream);
    }
LABEL_20:
    Scaleform::GFx::Stream::CloseTag(&pAltStream->Stream);
    ++this->TagCount;
    if ( v7 == Tag_EndFrame )
    {
      if ( !Scaleform::GFx::MovieDataDef::LoadTaskData::FinishLoadingFrame(this, plp, 0) )
        return;
      argc = 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  ShowFrame\n");
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
