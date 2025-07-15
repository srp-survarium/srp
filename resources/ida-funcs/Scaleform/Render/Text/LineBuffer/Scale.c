void __thiscall Scaleform::Render::Text::LineBuffer::Scale(
        Scaleform::Render::Text::LineBuffer *this,
        float scaleFactor)
{
  signed int v2; // eax
  double v3; // st7
  Scaleform::Render::Text::LineBuffer::Line *v4; // esi
  bool v5; // bl
  int v6; // eax
  int v7; // edi
  int v8; // eax
  bool v9; // bl
  double v10; // st6
  char *v11; // ecx
  unsigned int GlyphsCount; // eax
  char *v13; // ecx
  unsigned int v14; // edx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v15; // esi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // esi
  unsigned __int16 *p_Flags; // edi
  int v18; // eax
  int v19; // eax
  double v20; // st6
  unsigned int Delta; // eax
  int Leading; // [esp+14h] [ebp-84h]
  int Width; // [esp+14h] [ebp-84h]
  int Height; // [esp+14h] [ebp-84h]
  float v25; // [esp+14h] [ebp-84h]
  float v26; // [esp+14h] [ebp-84h]
  float v27; // [esp+14h] [ebp-84h]
  int v28; // [esp+14h] [ebp-84h]
  float v29; // [esp+14h] [ebp-84h]
  float v30; // [esp+18h] [ebp-80h]
  int BaseLineOffset; // [esp+18h] [ebp-80h]
  float v32; // [esp+18h] [ebp-80h]
  float v33; // [esp+18h] [ebp-80h]
  Scaleform::Render::Text::LineBuffer *v34; // [esp+1Ch] [ebp-7Ch]
  float v35; // [esp+20h] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator v36; // [esp+24h] [ebp-74h] BYREF
  unsigned int i; // [esp+8Ch] [ebp-Ch]

  v2 = 0;
  v34 = this;
  for ( i = 0; ; v2 = i )
  {
    v3 = scaleFactor;
    if ( !this || v2 >= this->Lines.Data.Size || v2 < 0 )
      break;
    v4 = this->Lines.Data.Data[v2];
    v5 = (v4->MemSize & 0x80000000) != 0;
    if ( (v4->MemSize & 0x80000000) == 0 )
      Leading = v4->Data32.Leading;
    else
      Leading = v4->Data8.Leading;
    v35 = (double)Leading * v3;
    if ( (v4->MemSize & 0x80000000) == 0 )
      Width = v4->Data32.Width;
    else
      Width = v4->Data8.Width;
    v30 = (double)Width * v3;
    if ( (v4->MemSize & 0x80000000) == 0 )
      Height = v4->Data32.Height;
    else
      Height = v4->Data8.Height;
    v25 = (double)Height * v3;
    v6 = (int)v35;
    if ( (v4->MemSize & 0x80000000) == 0 )
      v4->Data32.Leading = v6;
    else
      v4->Data8.Leading = v6;
    v7 = (int)v25;
    v8 = (int)v30;
    if ( v5 )
    {
      v4->Data8.Width = v8;
      v4->Data8.Height = v7;
    }
    else
    {
      v4->Data32.Width = v8;
      v4->Data32.Height = v7;
    }
    v9 = (v4->MemSize & 0x80000000) != 0;
    if ( (v4->MemSize & 0x80000000) == 0 )
      BaseLineOffset = v4->Data32.BaseLineOffset;
    else
      BaseLineOffset = v4->Data8.BaseLineOffset;
    v26 = (float)BaseLineOffset;
    v27 = v26 * v3;
    v10 = v27;
    if ( (v4->MemSize & 0x80000000) == 0 )
      v4->Data32.BaseLineOffset = (int)v10;
    else
      v4->Data8.BaseLineOffset = (int)v10;
    v4->Data32.OffsetX = (int)((double)v4->Data32.OffsetX * v3);
    v4->Data32.OffsetY = (int)(v3 * (double)v4->Data32.OffsetY);
    v11 = &v4->Data8.Leading + 1;
    if ( v9 )
    {
      GlyphsCount = v4->Data8.GlyphsCount;
    }
    else
    {
      GlyphsCount = v4->Data32.GlyphsCount;
      v11 = (char *)&v4->Data8 + 38;
    }
    v13 = &v11[8 * GlyphsCount];
    if ( v9 )
      v14 = v4->Data8.GlyphsCount;
    else
      v14 = v4->Data32.GlyphsCount;
    if ( v9 )
      v15 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v4->Data8.Leading + 1);
    else
      v15 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v4->Data8 + 38);
    v36.HighlighterIter.CurDesc.StartPos = -1;
    v36.HighlighterIter.CurDesc.Length = 0;
    v36.HighlighterIter.CurDesc.Offset = -1;
    memset(&v36.HighlighterIter.CurDesc.AdjStartPos, 0, 25);
    v36.HighlighterIter.NumGlyphs = 0;
    v36.HighlighterIter.CurAdjStartPos = 0;
    memset(&v36.ColorV, 0, 28);
    v36.pGlyphs = v15;
    v36.pEndGlyphs = &v15[v14];
    v36.pNextFormatData = (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned int)(v13 + 3) & 0xFFFFFFFC);
LABEL_37:
    v36.Delta = 0;
LABEL_38:
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v36);
    pGlyphs = v36.pGlyphs;
    while ( pGlyphs && pGlyphs < v36.pEndGlyphs )
    {
      p_Flags = &pGlyphs->Flags;
      v28 = (pGlyphs->Flags & 0x40) != 0 ? -pGlyphs->Advance : pGlyphs->Advance;
      v32 = (double)v28 * scaleFactor;
      v18 = (int)v32;
      if ( v18 < 0 )
      {
        *p_Flags |= 0x40u;
        pGlyphs->Advance = -(__int16)v18;
      }
      else
      {
        pGlyphs->Advance = v18;
        *p_Flags &= ~0x40u;
      }
      v19 = pGlyphs->LenAndFontSize & 0xFFF;
      v20 = (*(_BYTE *)p_Flags & 0x10) != 0 ? (double)(unsigned int)v19 * 0.0625 : (double)(unsigned int)v19;
      v29 = v20;
      v33 = scaleFactor * v29;
      Scaleform::Render::Text::LineBuffer::GlyphEntry::SetFontSize(pGlyphs, v33);
      pGlyphs = v36.pGlyphs;
      if ( !v36.pGlyphs )
        break;
      if ( v36.pGlyphs < v36.pEndGlyphs )
      {
        Delta = v36.Delta;
        if ( !v36.Delta )
        {
          Delta = v36.pGlyphs->LenAndFontSize >> 12;
          v36.Delta = Delta;
        }
        ++v36.pGlyphs;
        if ( (v36.pGlyphs->LenAndFontSize & 0xF000) != 0
          && Delta
          && !Scaleform::Render::Text::HighlighterPosIterator::IsFinished(&v36.HighlighterIter) )
        {
          Scaleform::Render::Text::HighlighterPosIterator::operator+=(&v36.HighlighterIter, v36.Delta);
          goto LABEL_37;
        }
        goto LABEL_38;
      }
    }
    if ( v36.pImage.pObject )
      Scaleform::RefCountNTSImpl::Release(v36.pImage.pObject);
    if ( v36.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v36.pFontHandle.pObject);
    this = v34;
    if ( i < v34->Lines.Data.Size )
      ++i;
  }
  this->Geom.Flags |= 1u;
}
