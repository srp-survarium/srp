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
  Scaleform::GFx::TagType v10; // ebx
  void *v11; // ebp
  unsigned int Size; // eax
  void (__thiscall *v13)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *); // eax
  Scaleform::GFx::LoadProcess::LoadStateType LoadState; // eax
  unsigned int v15; // eax
  Scaleform::String v16; // [esp+Ch] [ebp-18h] BYREF
  unsigned int v17; // [esp+10h] [ebp-14h]
  Scaleform::GFx::TagInfo pTagInfo; // [esp+14h] [ebp-10h] BYREF

  v3 = p;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  TagEndPosition = Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream);
  p->LoadState = LS_LoadingSprite;
  p->pTimelineDef = this;
  v7 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  v17 = TagEndPosition;
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
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  frames = %d\n", this->FrameCount);
  this->LoadingFrame = 0;
  if ( pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize < TagEndPosition )
  {
    do
    {
      v10 = Scaleform::GFx::Stream::OpenTag(&pAltStream->Stream, &pTagInfo);
      Scaleform::String::String(&v16, (const __m128i *)((v3->pLoadData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::LoadProcess::ReportProgress(v3, &v16, &pTagInfo, 1);
      v11 = (void *)(v16.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v16.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
      if ( v10 == Tag_EndFrame )
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
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
          &pAltStream->Stream,
          "  ShowFrame (sprite, char id = %d)\n",
          LOWORD(charId.Id));
        ++this->LoadingFrame;
        goto LABEL_21;
      }
      if ( (unsigned int)v10 >= Tag_SWF_TagTableEnd )
      {
        if ( (unsigned int)(v10 - 1000) > 9 )
          goto LABEL_20;
        v13 = (void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::GFx_GFX_TagLoaderTable[v10 - 1000];
      }
      else
      {
        v13 = (void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Transform *, unsigned int, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::SWF_TagLoaderTable[v10];
      }
      if ( !v13 )
      {
LABEL_20:
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, aNoTagLoaderFor, v10);
        goto LABEL_21;
      }
      v13(
        (Scaleform::GFx::AS3::Instances::fl_geom::Transform *)&pTagInfo,
        (unsigned int)p,
        (const Scaleform::GFx::AS3::Value *)&pTagInfo);
LABEL_21:
      Scaleform::GFx::Stream::CloseTag(&pAltStream->Stream);
      v3 = p;
    }
    while ( pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize < v17 );
  }
  LoadState = v3->LoadState;
  if ( v3->FrameTags[LoadState].Data.Size || LoadState == LS_LoadingRoot && v3->InitActionTags.Data.Size )
  {
    v15 = this->Playlist.Data.Size;
    if ( this->LoadingFrame == v15 )
    {
      Scaleform::ArrayData<Scaleform::GFx::TimelineDef::Frame,Scaleform::AllocatorLH<Scaleform::GFx::TimelineDef::Frame,265>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->Playlist.Data,
        v15 + 1);
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
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &pAltStream->Stream,
    "  -- sprite END, char id = %d --\n",
    LOWORD(charId.Id));
}
