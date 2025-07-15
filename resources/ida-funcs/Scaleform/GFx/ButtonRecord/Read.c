char __thiscall Scaleform::GFx::ButtonRecord::Read(
        Scaleform::GFx::ButtonRecord *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v6; // eax
  unsigned int Pos; // eax
  unsigned __int8 v8; // cl
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  unsigned int U16; // ebp
  Scaleform::Render::FilterSet *v12; // eax
  Scaleform::GFx::Resource *v13; // eax
  Scaleform::GFx::Resource *v14; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  int v16; // ecx
  unsigned int v17; // ecx
  unsigned __int8 v18; // al
  unsigned __int8 v19; // [esp+10h] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v6 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v6 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  v8 = pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  v19 = v8;
  if ( !v8 )
    return 0;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "-- action record:  ");
  this->Flags = 0;
  if ( (v19 & 8) != 0 )
  {
    this->Flags = 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "HitTest ");
  }
  if ( (v19 & 4) != 0 )
  {
    this->Flags |= 2u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "Down ");
  }
  if ( (v19 & 2) != 0 )
  {
    this->Flags |= 4u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "Over ");
  }
  if ( (v19 & 1) != 0 )
  {
    this->Flags |= 8u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "Up ");
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "\n");
  U16 = (unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p);
  this->CharacterId.Id = U16;
  this->Depth = Scaleform::GFx::LoadProcess::ReadU16(p);
  Scaleform::GFx::Stream::ReadMatrix(&p_ProcessInfo->Stream, &this->ButtonMatrix);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &p_ProcessInfo->Stream,
    "   CharId = %d, Depth = %d\n",
    U16,
    this->Depth);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "   mat:\n");
  Scaleform::GFx::Stream::LogParseClass(&p_ProcessInfo->Stream, &this->ButtonMatrix);
  if ( tagType == Tag_ButtonCharacter2 )
  {
    Scaleform::GFx::Stream::ReadCxformRgba(&p_ProcessInfo->Stream, &this->ButtonCxform);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "   cxform:\n");
    Scaleform::GFx::Stream::LogParseClass(&p_ProcessInfo->Stream, &this->ButtonCxform);
  }
  if ( (v19 & 0x10) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "   HasFilters\n");
    v12 = (Scaleform::Render::FilterSet *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 24, 0);
    if ( v12 )
    {
      Scaleform::Render::FilterSet::FilterSet(v12, 0);
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    if ( Scaleform::GFx::LoadFilters<Scaleform::GFx::Stream>(
           &p_ProcessInfo->Stream,
           (Scaleform::Render::FilterSet *)v14) )
    {
      if ( v14 )
        Scaleform::RefCountImpl::AddRef(v14);
      pObject = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      this->pFilters.pObject = (Scaleform::Render::FilterSet *)v14;
    }
    if ( v14 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14);
  }
  if ( (v19 & 0x20) != 0 )
  {
    v16 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( v16 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
    v17 = p_ProcessInfo->Stream.Pos;
    v18 = p_ProcessInfo->Stream.pBuffer[v17];
    p_ProcessInfo->Stream.Pos = v17 + 1;
    if ( !v18 || v18 > 0xEu )
      v18 = 1;
    this->BlendMode = v18;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&p_ProcessInfo->Stream, "   HasBlending, %d\n", v18);
    return 1;
  }
  else
  {
    this->BlendMode = Blend_None;
    return 1;
  }
}
