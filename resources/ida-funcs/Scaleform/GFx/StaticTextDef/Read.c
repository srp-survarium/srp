void __thiscall Scaleform::GFx::StaticTextDef::Read(
        Scaleform::GFx::StaticTextDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::Render::Rect<float> *p_TextRect; // ebx
  int v5; // eax
  unsigned int Pos; // eax
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // eax
  unsigned __int8 v10; // cl
  int v11; // ecx
  unsigned int v12; // eax
  unsigned __int8 v13; // cl
  int v14; // ebx
  int v15; // eax
  unsigned int v16; // eax
  Scaleform::GFx::ResourceId v17; // ebx
  Scaleform::GFx::Resource *SizeMask; // ecx
  int v19; // edx
  unsigned int v20; // eax
  __int16 v21; // cx
  int v22; // eax
  unsigned int v23; // eax
  __int16 v24; // cx
  int v25; // eax
  unsigned int v26; // eax
  unsigned __int16 v27; // cx
  Scaleform::GFx::StaticTextRecord *v28; // eax
  Scaleform::GFx::StaticTextRecord *v29; // edi
  bool v30; // zf
  Scaleform::GFx::Resource *pResource; // ecx
  unsigned int v32; // eax
  int v33; // ecx
  double CumulativeAdvance; // st7
  int v35; // [esp+18h] [ebp-88h]
  char v36; // [esp+67h] [ebp-39h]
  char v37; // [esp+68h] [ebp-38h]
  char v38; // [esp+69h] [ebp-37h]
  char v39; // [esp+6Ah] [ebp-36h]
  char v40; // [esp+6Bh] [ebp-35h]
  float v42; // [esp+70h] [ebp-30h]
  Scaleform::Render::Color pc; // [esp+74h] [ebp-2Ch] BYREF
  unsigned int Id; // [esp+78h] [ebp-28h]
  int v45; // [esp+7Ch] [ebp-24h]
  int advanceBits; // [esp+80h] [ebp-20h]
  int glyphBits; // [esp+84h] [ebp-1Ch]
  unsigned int EntryCount; // [esp+88h] [ebp-18h]
  Scaleform::GFx::Resource *v49; // [esp+8Ch] [ebp-14h]
  float v50; // [esp+90h] [ebp-10h]
  float v51; // [esp+94h] [ebp-Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType v52; // [esp+98h] [ebp-8h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
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
  Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &this->MatrixPriv);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  mat:\n");
  Scaleform::GFx::Stream::LogParseClass(&pAltStream->Stream, &this->MatrixPriv);
  v5 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v5 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  v7 = pAltStream->Stream.pBuffer[Pos++];
  v8 = pAltStream->Stream.DataSize - Pos;
  pAltStream->Stream.Pos = Pos;
  glyphBits = v7;
  pAltStream->Stream.UnusedBits = 0;
  if ( v8 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  v9 = pAltStream->Stream.Pos;
  v10 = pAltStream->Stream.pBuffer[v9];
  pAltStream->Stream.Pos = v9 + 1;
  advanceBits = v10;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "begin text records\n");
  v36 = 0;
  v42 = 0.0;
  Id = 0;
  v51 = 0.0;
  EntryCount = 0;
  v50 = 0.0;
  v49 = 0;
  while ( 1 )
  {
    v11 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v11 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    v12 = pAltStream->Stream.Pos;
    v13 = pAltStream->Stream.pBuffer[v12];
    v14 = v13;
    pAltStream->Stream.Pos = v12 + 1;
    if ( !v13 )
      break;
    if ( v36 )
    {
      v36 = 0;
      v28 = Scaleform::GFx::StaticTextRecordList::AddRecord(&this->TextRecords);
      v29 = v28;
      if ( v28 )
      {
        v30 = EntryCount == 0;
        v28->Offset.x = v50;
        v28->Offset.y = v51;
        if ( v30 && v49 )
          Scaleform::RefCountImpl::AddRef(v49);
        if ( v29->pFont.HType == RH_Pointer )
        {
          pResource = v29->pFont.pResource;
          if ( pResource )
            Scaleform::GFx::Resource::Release(pResource);
        }
        v32 = EntryCount;
        v29->pFont.BindIndex = (unsigned int)v49;
        v33 = advanceBits;
        v29->pFont.HType = v32;
        v29->TextHeight = v42;
        LOWORD(v32) = Id;
        v29->ColorV = pc;
        v35 = glyphBits;
        v29->FontId = v32;
        Scaleform::GFx::StaticTextRecord::Read(v29, &pAltStream->Stream, v14, v35, v33);
        CumulativeAdvance = Scaleform::GFx::StaticTextRecord::GetCumulativeAdvance(v29);
        v50 = CumulativeAdvance + v50;
      }
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
        &pAltStream->Stream,
        "  GlyphRecords: count = %d\n",
        v14);
    }
    else
    {
      v37 = ((int)v13 >> 3) & 1;
      v38 = ((int)v13 >> 2) & 1;
      v36 = 1;
      v40 = ((int)v13 >> 1) & 1;
      v39 = v13 & 1;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  text style change\n");
      if ( v37 )
      {
        v15 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v15 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v16 = pAltStream->Stream.Pos;
        v17.Id = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v16];
        pAltStream->Stream.Pos = v16 + 2;
        Id = v17.Id;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
          &pAltStream->Stream,
          "  HasFont: font id = %d\n",
          v17.Id);
        v52.EntryCount = 0;
        v52.SizeMask = 0;
        Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(p->pLoadData.pObject, &v52, v17);
        SizeMask = (Scaleform::GFx::Resource *)v52.SizeMask;
        if ( !v52.EntryCount && v52.SizeMask )
        {
          Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v52.SizeMask);
          SizeMask = (Scaleform::GFx::Resource *)v52.SizeMask;
        }
        if ( !EntryCount && v49 )
        {
          Scaleform::GFx::Resource::Release(v49);
          SizeMask = (Scaleform::GFx::Resource *)v52.SizeMask;
        }
        EntryCount = v52.EntryCount;
        v49 = SizeMask;
        if ( !v52.EntryCount && SizeMask )
          Scaleform::GFx::Resource::Release(SizeMask);
      }
      if ( v38 )
      {
        if ( tagType == Tag_DefineText )
          Scaleform::GFx::Stream::ReadRgb(&pAltStream->Stream, &pc);
        else
          Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, &pc);
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  HasColor\n");
      }
      if ( v39 )
      {
        v19 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v19 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v20 = pAltStream->Stream.Pos;
        v21 = *(_WORD *)&pAltStream->Stream.pBuffer[v20];
        v45 = v21;
        pAltStream->Stream.Pos = v20 + 2;
        v50 = (float)v21;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  XOffset = %g\n", v50);
      }
      if ( v40 )
      {
        v22 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v22 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v23 = pAltStream->Stream.Pos;
        v24 = *(_WORD *)&pAltStream->Stream.pBuffer[v23];
        v45 = v24;
        pAltStream->Stream.Pos = v23 + 2;
        v51 = (float)v24;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  YOffset = %g\n", v51);
      }
      if ( v37 )
      {
        v25 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v25 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v26 = pAltStream->Stream.Pos;
        v27 = *(_WORD *)&pAltStream->Stream.pBuffer[v26];
        v45 = v27;
        pAltStream->Stream.Pos = v26 + 2;
        v42 = (float)v27;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  TextHeight = %g\n", v42);
      }
    }
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "end text records\n");
  if ( !EntryCount && v49 )
    Scaleform::GFx::Resource::Release(v49);
}
