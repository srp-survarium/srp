void __thiscall Scaleform::GFx::StaticTextSnapshotData::Add(
        Scaleform::GFx::StaticTextSnapshotData *this,
        Scaleform::GFx::StaticTextCharacter *pstChar)
{
  Scaleform::GFx::StaticTextCharacter *v2; // edx
  Scaleform::GFx::StaticTextSnapshotData *v3; // ebp
  signed int CurrentPos; // ecx
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
  bool bfirst; // [esp+Fh] [ebp-89h]
  float xoffset; // [esp+10h] [ebp-88h]
  int xoffseta; // [esp+10h] [ebp-88h]
  float lineXOffset; // [esp+14h] [ebp-84h]
  Scaleform::GFx::StaticTextCharacter *cRef_4; // [esp+20h] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator glyphIt; // [esp+24h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::Iterator iter; // [esp+84h] [ebp-14h]

  v2 = pstChar;
  v3 = this;
  if ( pstChar )
    ++pstChar->RefCount;
  CurrentPos = 0;
  xoffset = 0.0;
  cRef_4 = 0;
  bfirst = 1;
  iter.CurrentPos = 0;
  while ( v2 != (Scaleform::GFx::StaticTextCharacter *)-128
       && CurrentPos < v2->TextGlyphRecords.Lines.Data.Size
       && CurrentPos >= 0 )
  {
    v5 = v2->TextGlyphRecords.Lines.Data.Data[CurrentPos];
    if ( bfirst )
    {
      xoffset = (float)v5->Data32.OffsetX;
    }
    else
    {
      lineXOffset = (float)v5->Data32.OffsetX;
      if ( xoffset == lineXOffset )
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
    glyphIt.HighlighterIter.CurDesc.StartPos = -1;
    glyphIt.HighlighterIter.CurDesc.Offset = -1;
    glyphIt.pEndGlyphs = &v7[GlyphsCount];
    glyphIt.HighlighterIter.CurDesc.Length = 0;
    memset(&glyphIt.HighlighterIter.CurDesc.AdjStartPos, 0, 25);
    glyphIt.HighlighterIter.NumGlyphs = 0;
    glyphIt.HighlighterIter.CurAdjStartPos = 0;
    memset(&glyphIt.ColorV, 0, 32);
    glyphIt.pGlyphs = v7;
    glyphIt.pNextFormatData = FormatData;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&glyphIt);
    pObject = glyphIt.pFontHandle.pObject;
    if ( glyphIt.pFontHandle.pObject && (v10 = glyphIt.pFontHandle.pObject->pFont.pObject) != 0 )
    {
      while ( glyphIt.pGlyphs && glyphIt.pGlyphs < glyphIt.pEndGlyphs )
      {
        LOWORD(v12) = glyphIt.pGlyphs->Index;
        if ( glyphIt.pGlyphs->Index == 0xFFFF )
          v12 = -1;
        else
          v12 = (unsigned __int16)v12;
        v13 = v10->GetCharValue(v10, v12);
        if ( v13 != -1 )
        {
          cRef_4 = (Scaleform::GFx::StaticTextCharacter *)((char *)cRef_4 + 1);
          Scaleform::String::AppendChar(&this->SnapshotString, v13);
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&glyphIt);
      }
      bfirst = 0;
      if ( glyphIt.pImage.pObject )
        Scaleform::RefCountNTSImpl::Release(glyphIt.pImage.pObject);
      v11 = (Scaleform::RefCountVImpl *)glyphIt.pFontHandle.pObject;
      if ( glyphIt.pFontHandle.pObject )
        goto LABEL_34;
    }
    else
    {
      if ( glyphIt.pImage.pObject )
      {
        Scaleform::RefCountNTSImpl::Release(glyphIt.pImage.pObject);
        pObject = glyphIt.pFontHandle.pObject;
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
    if ( iter.CurrentPos < pstChar->TextGlyphRecords.Lines.Data.Size )
      ++iter.CurrentPos;
    CurrentPos = iter.CurrentPos;
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
    xoffseta = -1;
    do
    {
      if ( *p_pObject )
      {
        Scaleform::RefCountNTSImpl::Release(*p_pObject);
        v2 = pstChar;
      }
      p_pObject -= 2;
      --xoffseta;
    }
    while ( xoffseta );
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
    v18[1] = cRef_4;
  }
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release(v2);
}
