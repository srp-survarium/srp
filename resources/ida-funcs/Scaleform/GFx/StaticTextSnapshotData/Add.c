void __thiscall Scaleform::GFx::StaticTextSnapshotData::Add(
        Scaleform::GFx::StaticTextSnapshotData *this,
        Scaleform::GFx::StaticTextCharacter *pstChar)
{
  Scaleform::GFx::StaticTextCharacter *v2; // edx
  Scaleform::GFx::StaticTextSnapshotData *v3; // ebp
  int v4; // ecx
  Scaleform::Render::Text::LineBuffer::Line *v5; // esi
  unsigned int GlyphsCount; // ebp
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v7; // edi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // eax
  Scaleform::Render::Text::FontHandle *pObject; // eax
  Scaleform::Render::Font *v10; // esi
  Scaleform::RefCountVImpl *v11; // ecx
  int v12; // eax
  unsigned int v13; // eax
  unsigned int Size; // eax
  unsigned int v15; // esi
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  Scaleform::GFx::StaticTextSnapshotData::CharRef *Data; // eax
  Scaleform::GFx::StaticTextCharacter **v18; // esi
  char v19; // [esp+Fh] [ebp-89h]
  float OffsetX; // [esp+10h] [ebp-88h]
  int v21; // [esp+10h] [ebp-88h]
  float v22; // [esp+14h] [ebp-84h]
  Scaleform::GFx::StaticTextCharacter *v24; // [esp+20h] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator v25; // [esp+24h] [ebp-74h] BYREF
  unsigned int v26; // [esp+8Ch] [ebp-Ch]

  v2 = pstChar;
  v3 = this;
  if ( pstChar )
    ++pstChar->RefCount;
  v4 = 0;
  OffsetX = 0.0;
  v24 = 0;
  v19 = 1;
  v26 = 0;
  while ( v2 != (Scaleform::GFx::StaticTextCharacter *)-128 && v4 < v2->TextGlyphRecords.Lines.Data.Size && v4 >= 0 )
  {
    v5 = v2->TextGlyphRecords.Lines.Data.Data[v4];
    if ( v19 )
    {
      OffsetX = (float)v5->Data32.OffsetX;
    }
    else
    {
      v22 = (float)v5->Data32.OffsetX;
      if ( OffsetX == v22 )
        Scaleform::String::AppendChar(&v3->SnapshotString, 0xAu);
    }
    if ( (v5->MemSize & 0x80000000) == 0 )
      GlyphsCount = v5->Data32.GlyphsCount;
    else
      GlyphsCount = v5->Data8.GlyphsCount;
    v7 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v5->Data8.Leading + 1);
    if ( (v5->MemSize & 0x80000000) == 0 )
      v7 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v5->Data8 + 38);
    FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v5);
    v25.HighlighterIter.CurDesc.StartPos = -1;
    v25.HighlighterIter.CurDesc.Offset = -1;
    v25.pEndGlyphs = &v7[GlyphsCount];
    v25.HighlighterIter.CurDesc.Length = 0;
    memset(&v25.HighlighterIter.CurDesc.AdjStartPos, 0, 25);
    v25.HighlighterIter.NumGlyphs = 0;
    v25.HighlighterIter.CurAdjStartPos = 0;
    memset(&v25.ColorV, 0, 32);
    v25.pGlyphs = v7;
    v25.pNextFormatData = FormatData;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v25);
    pObject = v25.pFontHandle.pObject;
    if ( v25.pFontHandle.pObject && (v10 = v25.pFontHandle.pObject->pFont.pObject) != 0 )
    {
      while ( v25.pGlyphs && v25.pGlyphs < v25.pEndGlyphs )
      {
        LOWORD(v12) = v25.pGlyphs->Index;
        if ( v25.pGlyphs->Index == 0xFFFF )
          v12 = -1;
        else
          v12 = (unsigned __int16)v12;
        v13 = v10->GetCharValue(v10, v12);
        if ( v13 != -1 )
        {
          v24 = (Scaleform::GFx::StaticTextCharacter *)((char *)v24 + 1);
          Scaleform::String::AppendChar(&this->SnapshotString, v13);
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v25);
      }
      v19 = 0;
      if ( v25.pImage.pObject )
        Scaleform::RefCountNTSImpl::Release(v25.pImage.pObject);
      v11 = (Scaleform::RefCountVImpl *)v25.pFontHandle.pObject;
      if ( v25.pFontHandle.pObject )
        goto LABEL_34;
    }
    else
    {
      if ( v25.pImage.pObject )
      {
        Scaleform::RefCountNTSImpl::Release(v25.pImage.pObject);
        pObject = v25.pFontHandle.pObject;
      }
      if ( pObject )
      {
        v11 = (Scaleform::RefCountVImpl *)pObject;
LABEL_34:
        Scaleform::RefCountImpl::Release(v11);
      }
    }
    v3 = this;
    v2 = pstChar;
    if ( v26 < pstChar->TextGlyphRecords.Lines.Data.Size )
      ++v26;
    v4 = v26;
  }
  Size = v3->StaticTextCharRefs.Data.Size;
  v15 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v15 >= v3->StaticTextCharRefs.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)v3,
        v3,
        v15 + (v15 >> 2));
LABEL_47:
      v2 = pstChar;
    }
  }
  else
  {
    p_pObject = &v3->StaticTextCharRefs.Data.Data[Size - 1].pChar.pObject;
    v21 = -1;
    do
    {
      if ( *p_pObject )
      {
        Scaleform::RefCountNTSImpl::Release(*p_pObject);
        v2 = pstChar;
      }
      p_pObject -= 2;
      --v21;
    }
    while ( v21 );
    if ( v15 < v3->StaticTextCharRefs.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)v3,
        v3,
        v15);
      goto LABEL_47;
    }
  }
  Data = v3->StaticTextCharRefs.Data.Data;
  v3->StaticTextCharRefs.Data.Size = v15;
  v18 = &Data[v15 - 1].pChar.pObject;
  if ( v18 )
  {
    if ( v2 )
      ++v2->RefCount;
    *v18 = v2;
    v18[1] = v24;
  }
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release(v2);
}
