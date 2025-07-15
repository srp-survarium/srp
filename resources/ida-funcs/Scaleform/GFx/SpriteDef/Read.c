void __thiscall Scaleform::GFx::SpriteDef::Read(
        Scaleform::GFx::SpriteDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::ResourceId charId)
{
  Scaleform::GFx::LoadProcess *v3; // ebp
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  unsigned int TagEndPosition; // ebx
  int v7; // eax
  unsigned int Pos; // eax
  unsigned __int16 v9; // dx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // ecx
  Scaleform::GFx::TagType v11; // ebx
  void *v12; // ebp
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // ecx
  unsigned int Size; // eax
  void (__thiscall *v15)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *); // eax
  Scaleform::GFx::LoadProcess::LoadStateType LoadState; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // ecx
  unsigned int v18; // eax
  Scaleform::String fileURL; // [esp+Ch] [ebp-18h] BYREF
  unsigned int tagEnd; // [esp+10h] [ebp-14h]
  Scaleform::GFx::TagInfo tagInfo; // [esp+14h] [ebp-10h] BYREF

  v3 = p;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  TagEndPosition = Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream);
  p->LoadState = LS_LoadingSprite;
  p->pTimelineDef = this;
  v7 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  tagEnd = TagEndPosition;
  pAltStream->Stream.UnusedBits = 0;
  if ( v7 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v9 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  this->FrameCount = v9;
  if ( !v9 )
    this->FrameCount = 1;
  Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Playlist.Data,
    this->FrameCount);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v10);
  this->LoadingFrame = 0;
  if ( pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize < TagEndPosition )
  {
    do
    {
      v11 = Scaleform::GFx::Stream::OpenTag(&pAltStream->Stream, &tagInfo);
      Scaleform::String::String(&fileURL, (char *)((v3->pLoadData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::LoadProcess::ReportProgress(v3, &fileURL, &tagInfo, 1);
      v12 = (void *)(fileURL.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((fileURL.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
      if ( v11 == Tag_EndFrame )
      {
        Size = this->Playlist.Data.Size;
        if ( this->LoadingFrame == Size )
        {
          Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Resize(
            &this->Playlist.Data,
            Size + 1);
          Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
            &pAltStream->Stream,
            "An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d",
            LOWORD(charId.Id),
            this->FrameCount,
            this->LoadingFrame + 1);
        }
        Scaleform::GFx::LoadProcess::CommitFrameTags(p);
        Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)LOWORD(charId.Id));
        ++this->LoadingFrame;
        goto LABEL_21;
      }
      if ( (unsigned int)v11 >= Tag_SWF_TagTableEnd )
      {
        if ( (unsigned int)(v11 - 1000) > 9 )
          goto LABEL_20;
        v15 = (void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::GFx_GFX_TagLoaderTable[v11 - 1000];
      }
      else
      {
        v15 = (void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::SWF_TagLoaderTable[v11];
      }
      if ( !v15 )
      {
LABEL_20:
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v13);
        goto LABEL_21;
      }
      v15(
        (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)&tagInfo,
        (unsigned int)p,
        (const Scaleform::GFx::AS3::Value *)&tagInfo);
LABEL_21:
      Scaleform::GFx::Stream::CloseTag(&pAltStream->Stream);
      v3 = p;
    }
    while ( pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize < tagEnd );
  }
  LoadState = v3->LoadState;
  v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(3 * LoadState + 204);
  if ( *((_DWORD *)&v3->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable
       + (_DWORD)v17)
    || LoadState == LS_LoadingRoot && v3->InitActionTags.Data.Size )
  {
    v18 = this->Playlist.Data.Size;
    if ( this->LoadingFrame == v18 )
    {
      Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->Playlist.Data,
        v18 + 1);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
        &pAltStream->Stream,
        "An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d",
        LOWORD(charId.Id),
        this->FrameCount,
        this->LoadingFrame + 1);
    }
    Scaleform::GFx::LoadProcess::CommitFrameTags(v3);
  }
  v3->LoadState = LS_LoadingRoot;
  v3->pTimelineDef = 0;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v17);
}
