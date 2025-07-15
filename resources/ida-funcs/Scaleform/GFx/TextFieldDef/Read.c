void __thiscall Scaleform::GFx::TextFieldDef::Read(
        Scaleform::GFx::TextFieldDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::Render::Rect<float> *p_TextRect; // ebx
  bool v6; // bl
  int v7; // eax
  unsigned int Pos; // eax
  unsigned __int16 v9; // cx
  unsigned int Id; // eax
  Scaleform::GFx::Resource *SizeMask; // ecx
  unsigned int EntryCount; // eax
  int v13; // ecx
  unsigned int v14; // eax
  unsigned __int16 v15; // cx
  double v16; // st7
  int v17; // ecx
  unsigned int v18; // eax
  unsigned __int16 v19; // dx
  int v20; // eax
  unsigned int v21; // eax
  Scaleform::GFx::TextFieldDef::alignment v22; // edx
  int v23; // eax
  unsigned int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  int v27; // eax
  unsigned int v28; // eax
  int v29; // eax
  unsigned int v30; // eax
  __int16 v31; // cx
  Scaleform::GFx::TextFieldDef::alignment Alignment; // eax
  double v33; // st7
  bool v34; // [esp+53h] [ebp-Dh]
  bool v35; // [esp+54h] [ebp-Ch]
  bool v36; // [esp+55h] [ebp-Bh]
  bool v37; // [esp+56h] [ebp-Ah]
  bool v38; // [esp+57h] [ebp-9h]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType v39; // [esp+58h] [ebp-8h] BYREF

  if ( p->pAltStream )
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  else
    pAltStream = &p->ProcessInfo;
  p_TextRect = &this->TextRect;
  Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &this->TextRect);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &pAltStream->Stream,
    "  TextRect = { l: %f, t: %f, r: %f, b: %f }\n",
    p_TextRect->x1,
    this->TextRect.y1,
    this->TextRect.x2,
    this->TextRect.y2);
  pAltStream->Stream.UnusedBits = 0;
  v38 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 8u;
  else
    this->Flags &= ~8u;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &pAltStream->Stream,
    "  WordWrap = %d, Multiline = %d, Password = %d, ReadOnly = %d\n",
    this->Flags & 1,
    (this->Flags >> 1) & 1,
    (this->Flags >> 2) & 1,
    (this->Flags >> 3) & 1);
  v35 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  v36 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  v6 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  v34 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 0x10u;
  else
    this->Flags &= ~0x10u;
  v37 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags &= ~0x20u;
  else
    this->Flags |= 0x20u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 0x40u;
  else
    this->Flags &= ~0x40u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 0x1000u;
  else
    this->Flags &= ~0x1000u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags |= 0x80u;
  else
    this->Flags &= ~0x80u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
    this->Flags &= ~0x100u;
  else
    this->Flags |= 0x100u;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &pAltStream->Stream,
    "  AutoSize = %d, Selectable = %d, Border = %d, Html = %d, UseDeviceFont = %d\n",
    (this->Flags >> 4) & 1,
    (this->Flags >> 5) & 1,
    (this->Flags >> 6) & 1,
    (this->Flags >> 7) & 1,
    HIBYTE(this->Flags) & 1);
  if ( v6 )
  {
    v7 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v7 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    Pos = pAltStream->Stream.Pos;
    v9 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
    pAltStream->Stream.Pos = Pos + 2;
    this->FontId.Id = v9;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  HasFont: font id = %d\n", v9);
    Id = this->FontId.Id;
    v39.EntryCount = 0;
    v39.SizeMask = 0;
    Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
      p->pLoadData.pObject,
      &v39,
      (Scaleform::GFx::ResourceId)Id);
    SizeMask = (Scaleform::GFx::Resource *)v39.SizeMask;
    if ( !v39.EntryCount && v39.SizeMask )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v39.SizeMask);
      SizeMask = (Scaleform::GFx::Resource *)v39.SizeMask;
    }
    if ( this->pFont.HType == RH_Pointer && this->pFont.BindIndex )
    {
      Scaleform::GFx::Resource::Release(this->pFont.pResource);
      SizeMask = (Scaleform::GFx::Resource *)v39.SizeMask;
    }
    EntryCount = v39.EntryCount;
    this->pFont.HType = v39.EntryCount;
    this->pFont.BindIndex = (unsigned int)SizeMask;
    if ( !EntryCount && SizeMask )
      Scaleform::GFx::Resource::Release(SizeMask);
  }
  else
  {
    if ( !v34 )
      goto LABEL_51;
    Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->FontClass);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "  HasFontClass: font class = %s\n",
      (const char *)((this->FontClass.HeapTypeBits & 0xFFFFFFFC) + 8));
  }
  v13 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v13 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v14 = pAltStream->Stream.Pos;
  v15 = *(_WORD *)&pAltStream->Stream.pBuffer[v14];
  pAltStream->Stream.Pos = v14 + 2;
  *(float *)&v39.EntryCount = (float)v15;
  v16 = *(float *)&v39.EntryCount;
  this->TextHeight = *(float *)&v39.EntryCount;
  *(float *)&v39.EntryCount = v16 * 0.05000000074505806;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &pAltStream->Stream,
    "  FontHeight = %f\n",
    *(float *)&v39.EntryCount);
LABEL_51:
  if ( v35 )
  {
    Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, &this->ColorV);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  HasColor\n");
  }
  if ( v36 )
  {
    v17 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v17 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v18 = pAltStream->Stream.Pos;
    v19 = *(_WORD *)&pAltStream->Stream.pBuffer[v18];
    pAltStream->Stream.Pos = v18 + 2;
    this->MaxLength = v19;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  HasMaxLength: len = %d\n", v19);
  }
  if ( v37 )
  {
    this->Flags |= 0x200u;
    v20 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v20 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    v21 = pAltStream->Stream.Pos;
    v22 = pAltStream->Stream.pBuffer[v21];
    pAltStream->Stream.Pos = v21 + 1;
    this->Alignment = v22;
    v23 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v23 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v24 = pAltStream->Stream.Pos;
    v39.EntryCount = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v24];
    pAltStream->Stream.Pos = v24 + 2;
    this->LeftMargin = (float)(int)v39.EntryCount;
    v25 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v25 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v26 = pAltStream->Stream.Pos;
    v39.EntryCount = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v26];
    pAltStream->Stream.Pos = v26 + 2;
    this->RightMargin = (float)(int)v39.EntryCount;
    v27 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v27 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v28 = pAltStream->Stream.Pos;
    v39.EntryCount = *(__int16 *)&pAltStream->Stream.pBuffer[v28];
    pAltStream->Stream.Pos = v28 + 2;
    this->Indent = (float)(int)v39.EntryCount;
    v29 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v29 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v30 = pAltStream->Stream.Pos;
    v31 = *(_WORD *)&pAltStream->Stream.pBuffer[v30];
    v39.EntryCount = v31;
    pAltStream->Stream.Pos = v30 + 2;
    Alignment = this->Alignment;
    *(float *)&v39.EntryCount = (float)v31;
    v33 = *(float *)&v39.EntryCount;
    this->Leading = *(float *)&v39.EntryCount;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "  HasLayout: alignment = %d, leftmarg = %f, rightmarg = %f, indent = %f, leading = %f\n",
      Alignment,
      this->LeftMargin,
      this->RightMargin,
      this->Indent,
      v33);
  }
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->VariableName);
  if ( v38 )
    Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &this->DefaultText);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &pAltStream->Stream,
    "EditTextChar, varname = %s, text = %s\n",
    (const char *)((this->VariableName.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const char *)((this->DefaultText.HeapTypeBits & 0xFFFFFFFC) + 8));
}
