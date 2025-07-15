int __thiscall Scaleform::GFx::ShapeSwfReader::ReadFillStyles(
        Scaleform::GFx::ShapeSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        int tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v6; // eax
  unsigned int Pos; // eax
  unsigned __int8 v8; // cl
  int U16; // esi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  unsigned int Size; // edi
  unsigned int v12; // edi
  Scaleform::GFx::SWFProcessInfo *v13; // eax
  Scaleform::Render::FillStyleType *FillStyle; // esi
  Scaleform::Render::ComplexFill *pObject; // eax
  Scaleform::Render::ComplexFill *v16; // esi
  int v18; // [esp+10h] [ebp-8h]
  Scaleform::GFx::FillStyleSwfReader v19; // [esp+14h] [ebp-4h] BYREF
  int v20; // [esp+1Ch] [ebp+4h]

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
  U16 = v8;
  if ( tagType > 2 && v8 == 255 )
    U16 = (unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p);
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v18 = p_ProcessInfo->Stream.Pos + p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.DataSize;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  GFx_ReadFillStyles: count = %d\n",
    U16);
  Size = this->FillStyles.Data.Size;
  if ( U16 )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->FillStyles,
      Size + U16);
    v12 = Size;
    v20 = U16;
    do
    {
      v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !v13 )
        v13 = &p->ProcessInfo;
      v13->Stream.UnusedBits = 0;
      v19.FillStyle = &this->FillStyles.Data.Data[v12];
      FillStyle = v19.FillStyle;
      Scaleform::GFx::FillStyleSwfReader::Read(&v19, p, tagType);
      pObject = FillStyle->pFill.pObject;
      if ( pObject && (pObject->pImage.pObject || pObject->BindIndex != -1) )
        this->Shape->Flags |= 1u;
      v16 = FillStyle->pFill.pObject;
      if ( v16 && v16->BindIndex != -1 )
        this->Shape->Flags |= 4u;
      ++v12;
      --v20;
    }
    while ( v20 );
  }
  return v18;
}
