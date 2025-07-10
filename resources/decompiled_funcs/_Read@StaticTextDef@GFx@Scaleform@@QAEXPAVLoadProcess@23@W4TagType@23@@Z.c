void __thiscall Scaleform::GFx::StaticTextDef::Read(
        Scaleform::GFx::StaticTextDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // ecx
  int v6; // ecx
  unsigned int Pos; // eax
  unsigned __int8 v8; // cl
  int v9; // edx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pBuffer; // ecx
  int v12; // eax
  unsigned int v13; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // ecx
  int v15; // ebx
  int v16; // edx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // ecx
  Scaleform::GFx::ResourceId v19; // ebx
  Scaleform::GFx::Resource *v20; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // ecx
  int v22; // edx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v24; // ecx
  int v25; // eax
  unsigned int v26; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v27; // ecx
  int v28; // eax
  unsigned int v29; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // ecx
  Scaleform::GFx::StaticTextRecord *v31; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v32; // ecx
  Scaleform::GFx::StaticTextRecord *v33; // edi
  bool v34; // zf
  Scaleform::GFx::Resource *pResource; // ecx
  Scaleform::GFx::ResourceHandle::HandleType HType; // eax
  unsigned int v37; // ecx
  double CumulativeAdvance; // st7
  int v39; // [esp+18h] [ebp-88h]
  bool lastRecordWasStyleChange; // [esp+67h] [ebp-39h]
  bool hasFont; // [esp+68h] [ebp-38h]
  bool hasColor; // [esp+69h] [ebp-37h]
  bool hasXOffset; // [esp+6Ah] [ebp-36h]
  bool hasYOffset; // [esp+6Bh] [ebp-35h]
  float textHeight; // [esp+70h] [ebp-30h]
  Scaleform::Render::Color color; // [esp+74h] [ebp-2Ch] BYREF
  int fontId; // [esp+78h] [ebp-28h]
  int v49; // [esp+7Ch] [ebp-24h]
  int AdvanceBits; // [esp+80h] [ebp-20h]
  int GlyphBits; // [esp+84h] [ebp-1Ch]
  Scaleform::GFx::ResourcePtr<Scaleform::GFx::FontResource> pfont; // [esp+88h] [ebp-18h]
  Scaleform::Render::Point<float> offset; // [esp+90h] [ebp-10h]
  Scaleform::GFx::ResourceHandle hres; // [esp+98h] [ebp-8h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &this->TextRect);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v4);
  Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &this->MatrixPriv);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v5);
  v6 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v6 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  v8 = pAltStream->Stream.pBuffer[Pos++];
  v9 = pAltStream->Stream.DataSize - Pos;
  pAltStream->Stream.Pos = Pos;
  GlyphBits = v8;
  pAltStream->Stream.UnusedBits = 0;
  if ( v9 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  v10 = pAltStream->Stream.Pos;
  pBuffer = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pAltStream->Stream.pBuffer;
  LOBYTE(pBuffer) = *((_BYTE *)&pBuffer->__vftable + v10);
  pAltStream->Stream.Pos = v10 + 1;
  AdvanceBits = (unsigned __int8)pBuffer;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(pBuffer);
  lastRecordWasStyleChange = 0;
  textHeight = 0.0;
  fontId = 0;
  offset.y = 0.0;
  pfont.HType = RH_Pointer;
  offset.x = 0.0;
  pfont.BindIndex = 0;
  while ( 1 )
  {
    v12 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v12 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    v13 = pAltStream->Stream.Pos;
    v14 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pAltStream->Stream.pBuffer;
    LOBYTE(v14) = *((_BYTE *)&v14->__vftable + v13);
    v15 = (unsigned __int8)v14;
    pAltStream->Stream.Pos = v13 + 1;
    if ( !(_BYTE)v14 )
      break;
    if ( lastRecordWasStyleChange )
    {
      lastRecordWasStyleChange = 0;
      v31 = Scaleform::GFx::StaticTextRecordList::AddRecord(&this->TextRecords);
      v33 = v31;
      if ( v31 )
      {
        v34 = pfont.HType == RH_Pointer;
        v31->Offset = offset;
        if ( v34 && pfont.BindIndex )
          Scaleform::RefCountImpl::AddRef(pfont.pResource);
        if ( v33->pFont.HType == RH_Pointer )
        {
          pResource = v33->pFont.pResource;
          if ( pResource )
            Scaleform::GFx::Resource::Release(pResource);
        }
        HType = pfont.HType;
        v33->pFont.BindIndex = pfont.BindIndex;
        v37 = AdvanceBits;
        v33->pFont.HType = HType;
        v33->TextHeight = textHeight;
        LOWORD(HType) = fontId;
        v33->ColorV = color;
        v39 = GlyphBits;
        v33->FontId = HType;
        Scaleform::GFx::StaticTextRecord::Read(v33, &pAltStream->Stream, v15, v39, v37);
        CumulativeAdvance = Scaleform::GFx::StaticTextRecord::GetCumulativeAdvance(v33);
        offset.x = CumulativeAdvance + offset.x;
      }
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v32);
    }
    else
    {
      hasFont = ((int)(unsigned __int8)v14 >> 3) & 1;
      hasColor = ((int)(unsigned __int8)v14 >> 2) & 1;
      lastRecordWasStyleChange = 1;
      hasYOffset = ((int)(unsigned __int8)v14 >> 1) & 1;
      hasXOffset = (unsigned __int8)v14 & 1;
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v14);
      if ( hasFont )
      {
        v16 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v16 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v17 = pAltStream->Stream.Pos;
        v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v17];
        v19.Id = (unsigned __int16)v18;
        pAltStream->Stream.Pos = v17 + 2;
        fontId = (unsigned __int16)v18;
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v18);
        hres.HType = RH_Pointer;
        hres.BindIndex = 0;
        Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
          p->pLoadData.pObject,
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&hres,
          v19);
        v20 = hres.pResource;
        if ( hres.HType == RH_Pointer && hres.BindIndex )
        {
          Scaleform::RefCountImpl::AddRef(hres.pResource);
          v20 = hres.pResource;
        }
        if ( pfont.HType == RH_Pointer && pfont.BindIndex )
        {
          Scaleform::GFx::Resource::Release(pfont.pResource);
          v20 = hres.pResource;
        }
        pfont.HType = hres.HType;
        pfont.BindIndex = (unsigned int)v20;
        if ( hres.HType == RH_Pointer && v20 )
          Scaleform::GFx::Resource::Release(v20);
      }
      if ( hasColor )
      {
        if ( tagType == Tag_DefineText )
          Scaleform::GFx::Stream::ReadRgb(&pAltStream->Stream, &color);
        else
          Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, &color);
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v21);
      }
      if ( hasXOffset )
      {
        v22 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v22 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v23 = pAltStream->Stream.Pos;
        v24 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v23];
        v49 = (__int16)v24;
        pAltStream->Stream.Pos = v23 + 2;
        offset.x = (float)(__int16)v24;
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v24);
      }
      if ( hasYOffset )
      {
        v25 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v25 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v26 = pAltStream->Stream.Pos;
        v27 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v26];
        v49 = (__int16)v27;
        pAltStream->Stream.Pos = v26 + 2;
        offset.y = (float)(__int16)v27;
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v27);
      }
      if ( hasFont )
      {
        v28 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v28 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v29 = pAltStream->Stream.Pos;
        v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v29];
        v49 = (unsigned __int16)v30;
        pAltStream->Stream.Pos = v29 + 2;
        textHeight = (float)(unsigned __int16)v30;
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v30);
      }
    }
  }
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v14);
  if ( pfont.HType == RH_Pointer && pfont.BindIndex )
    Scaleform::GFx::Resource::Release(pfont.pResource);
}
