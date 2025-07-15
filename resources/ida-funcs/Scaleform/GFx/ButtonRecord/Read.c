char __thiscall Scaleform::GFx::ButtonRecord::Read(
        Scaleform::GFx::ButtonRecord *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v6; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pBuffer; // ecx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // ecx
  Scaleform::Render::FilterSet *v16; // eax
  Scaleform::GFx::Resource *v17; // eax
  Scaleform::GFx::Resource *v18; // ebp
  Scaleform::RefCountVImpl *pObject; // ecx
  int v20; // ecx
  unsigned int v21; // ecx
  unsigned __int8 v22; // al
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // ecx
  char flags; // [esp+10h] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v6 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v6 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  pBuffer = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pAltStream->Stream.pBuffer;
  LOBYTE(pBuffer) = *((_BYTE *)&pBuffer->__vftable + Pos);
  pAltStream->Stream.Pos = Pos + 1;
  flags = (char)pBuffer;
  if ( !(_BYTE)pBuffer )
    return 0;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(pBuffer);
  this->Flags = 0;
  if ( (flags & 8) != 0 )
  {
    this->Flags = 1;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v11);
  }
  if ( (flags & 4) != 0 )
  {
    this->Flags |= 2u;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v11);
  }
  if ( (flags & 2) != 0 )
  {
    this->Flags |= 4u;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v11);
  }
  if ( (flags & 1) != 0 )
  {
    this->Flags |= 8u;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v11);
  }
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v11);
  this->CharacterId.Id = Scaleform::GFx::LoadProcess::ReadU16(p);
  this->Depth = Scaleform::GFx::LoadProcess::ReadU16(p);
  Scaleform::GFx::Stream::ReadMatrix(&p_ProcessInfo->Stream, &this->ButtonMatrix);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v12);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v13);
  if ( tagType == Tag_ButtonCharacter2 )
  {
    Scaleform::GFx::Stream::ReadCxformRgba(&p_ProcessInfo->Stream, &this->ButtonCxform);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v15);
  }
  if ( (flags & 0x10) != 0 )
  {
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v14);
    v16 = (Scaleform::Render::FilterSet *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 24, 0);
    if ( v16 )
    {
      Scaleform::Render::FilterSet::FilterSet(v16, 0);
      v18 = v17;
    }
    else
    {
      v18 = 0;
    }
    if ( Scaleform::GFx::LoadFilters<Scaleform::GFx::Stream>(
           &p_ProcessInfo->Stream,
           (Scaleform::Render::FilterSet *)v18) )
    {
      if ( v18 )
        Scaleform::RefCountImpl::AddRef(v18);
      pObject = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      this->pFilters.pObject = (Scaleform::Render::FilterSet *)v18;
    }
    if ( v18 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18);
  }
  if ( (flags & 0x20) != 0 )
  {
    v20 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( v20 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
    v21 = p_ProcessInfo->Stream.Pos;
    v22 = p_ProcessInfo->Stream.pBuffer[v21];
    v23 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v21 + 1);
    p_ProcessInfo->Stream.Pos = (unsigned int)v23;
    if ( !v22 || v22 > 0xEu )
      v22 = 1;
    this->BlendMode = v22;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v23);
    return 1;
  }
  else
  {
    this->BlendMode = Blend_None;
    return 1;
  }
}
