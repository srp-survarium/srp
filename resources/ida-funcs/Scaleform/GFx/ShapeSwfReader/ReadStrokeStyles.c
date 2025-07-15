int __thiscall Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(
        Scaleform::GFx::ShapeSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        unsigned int *tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v5; // eax
  unsigned int Pos; // eax
  unsigned __int8 v7; // cl
  int U16; // esi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  int v10; // ebp
  unsigned int Size; // edi
  int v12; // ebp
  unsigned int *v13; // edi
  int v14; // ebp
  Scaleform::GFx::SWFProcessInfo *v15; // eax
  unsigned int *v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // esi
  int v21; // [esp+14h] [ebp-4h]
  int v22; // [esp+1Ch] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v5 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v5 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  v7 = pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  U16 = v7;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  GFx_ReadStrokeStyles: count = %d\n",
    v7);
  if ( U16 == 255 )
  {
    U16 = (unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p);
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  GFx_ReadStrokeStyles: count2 = %d\n",
      U16);
  }
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v10 = p_ProcessInfo->Stream.Pos + p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.DataSize;
  Size = this->StrokeStyles.Data.Size;
  v21 = v10;
  Scaleform::ArrayData<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->StrokeStyles.Data,
    Size + U16);
  if ( !U16 )
    return v10;
  v12 = 7 * Size;
  v13 = tagType;
  v14 = 4 * v12;
  v22 = U16;
  do
  {
    v15 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v15 )
      v15 = &p->ProcessInfo;
    v15->Stream.UnusedBits = 0;
    tagType = (unsigned int *)((char *)this->StrokeStyles.Data.Data + v14);
    v16 = tagType;
    Scaleform::GFx::StrokeStyleSwfReader::Read((Scaleform::GFx::StrokeStyleSwfReader *)&tagType, p, v13);
    v17 = v16[5];
    if ( v17 && (*(_DWORD *)(v17 + 8) || *(_DWORD *)(v17 + 52) != -1) )
      this->Shape->Flags |= 1u;
    v18 = v16[5];
    if ( v18 )
    {
      if ( *(_DWORD *)(v18 + 52) != -1 )
        this->Shape->Flags |= 4u;
    }
    v14 += 28;
    --v22;
  }
  while ( v22 );
  return v21;
}
