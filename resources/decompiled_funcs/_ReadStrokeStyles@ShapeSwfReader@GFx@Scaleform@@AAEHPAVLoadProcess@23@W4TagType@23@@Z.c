int __thiscall Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(
        Scaleform::GFx::ShapeSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::Render::FillStyleType *tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v5; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pBuffer; // ecx
  Scaleform::GFx::LoadProcess *U16; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // ecx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  int v11; // ebp
  unsigned int Size; // edi
  int v13; // ebp
  Scaleform::Render::FillStyleType *v14; // edi
  int v15; // ebp
  Scaleform::GFx::SWFProcessInfo *v16; // eax
  Scaleform::GFx::TagType v17; // esi
  int v18; // eax
  int v19; // esi
  int off; // [esp+14h] [ebp-4h]
  Scaleform::GFx::LoadProcess *pa; // [esp+1Ch] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v5 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v5 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  pBuffer = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pAltStream->Stream.pBuffer;
  LOBYTE(pBuffer) = *((_BYTE *)&pBuffer->__vftable + Pos);
  pAltStream->Stream.Pos = Pos + 1;
  U16 = (Scaleform::GFx::LoadProcess *)(unsigned __int8)pBuffer;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(pBuffer);
  if ( U16 == (Scaleform::GFx::LoadProcess *)255 )
  {
    U16 = (Scaleform::GFx::LoadProcess *)(unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v9);
  }
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v11 = p_ProcessInfo->Stream.Pos + p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.DataSize;
  Size = this->StrokeStyles.Data.Size;
  off = v11;
  Scaleform::ArrayData<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->StrokeStyles.Data,
    (unsigned int)U16 + Size);
  if ( !U16 )
    return v11;
  v13 = 7 * Size;
  v14 = tagType;
  v15 = 4 * v13;
  pa = U16;
  do
  {
    v16 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v16 )
      v16 = &p->ProcessInfo;
    v16->Stream.UnusedBits = 0;
    tagType = (Scaleform::Render::FillStyleType *)((char *)this->StrokeStyles.Data.Data + v15);
    v17 = (Scaleform::GFx::TagType)tagType;
    Scaleform::GFx::StrokeStyleSwfReader::Read((Scaleform::GFx::StrokeStyleSwfReader *)&tagType, p, v14);
    v18 = *(_DWORD *)(v17 + 20);
    if ( v18 && (*(_DWORD *)(v18 + 8) || *(_DWORD *)(v18 + 52) != -1) )
      this->Shape->Flags |= 1u;
    v19 = *(_DWORD *)(v17 + 20);
    if ( v19 )
    {
      if ( *(_DWORD *)(v19 + 52) != -1 )
        this->Shape->Flags |= 4u;
    }
    v15 += 28;
    pa = (Scaleform::GFx::LoadProcess *)((char *)pa - 1);
  }
  while ( pa );
  return off;
}
