void __thiscall Scaleform::Render::Text::LineBuffer::Scale(
        Scaleform::Render::Text::LineBuffer *this,
        float scaleFactor)
{
  signed int CurrentPos; // eax
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
  int newH; // [esp+14h] [ebp-84h]
  int newHa; // [esp+14h] [ebp-84h]
  int newHb; // [esp+14h] [ebp-84h]
  float newHc; // [esp+14h] [ebp-84h]
  float newHe; // [esp+14h] [ebp-84h]
  float newHf; // [esp+14h] [ebp-84h]
  int newHd; // [esp+14h] [ebp-84h]
  float newHg; // [esp+14h] [ebp-84h]
  float newW; // [esp+18h] [ebp-80h]
  int newWa; // [esp+18h] [ebp-80h]
  float newWb; // [esp+18h] [ebp-80h]
  float newWc; // [esp+18h] [ebp-80h]
  Scaleform::Render::Text::LineBuffer *v34; // [esp+1Ch] [ebp-7Ch]
  float newLeading; // [esp+20h] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+24h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::Iterator it; // [esp+84h] [ebp-14h]

  CurrentPos = 0;
  v34 = this;
  for ( it.CurrentPos = 0; ; CurrentPos = it.CurrentPos )
  {
    v3 = scaleFactor;
    if ( !this || CurrentPos >= this->Lines.Data.Size || CurrentPos < 0 )
      break;
    v4 = this->Lines.Data.Data[CurrentPos];
    v5 = (v4->MemSize & 0x80000000) != 0;
    if ( (v4->MemSize & 0x80000000) == 0 )
      newH = v4->Data32.Leading;
    else
      newH = v4->Data8.Leading;
    newLeading = (double)newH * v3;
    if ( (v4->MemSize & 0x80000000) == 0 )
      newHa = v4->Data32.Width;
    else
      newHa = v4->Data8.Width;
    newW = (double)newHa * v3;
    if ( (v4->MemSize & 0x80000000) == 0 )
      newHb = v4->Data32.Height;
    else
      newHb = v4->Data8.Height;
    newHc = (double)newHb * v3;
    v6 = (int)newLeading;
    if ( (v4->MemSize & 0x80000000) == 0 )
      v4->Data32.Leading = v6;
    else
      v4->Data8.Leading = v6;
    v7 = (int)newHc;
    v8 = (int)newW;
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
      newWa = v4->Data32.BaseLineOffset;
    else
      newWa = v4->Data8.BaseLineOffset;
    newHe = (float)newWa;
    newHf = newHe * v3;
    v10 = newHf;
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
    git.HighlighterIter.CurDesc.StartPos = -1;
    git.HighlighterIter.CurDesc.Length = 0;
    git.HighlighterIter.CurDesc.Offset = -1;
    memset(&git.HighlighterIter.CurDesc.AdjStartPos, 0, 25);
    git.HighlighterIter.NumGlyphs = 0;
    git.HighlighterIter.CurAdjStartPos = 0;
    memset(&git.ColorV, 0, 28);
    git.pGlyphs = v15;
    git.pEndGlyphs = &v15[v14];
    git.pNextFormatData = (Scaleform::Render::Text::LineBuffer::FormatDataEntry *)((unsigned int)(v13 + 3) & 0xFFFFFFFC);
LABEL_37:
    git.Delta = 0;
LABEL_38:
    Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&git);
    pGlyphs = git.pGlyphs;
    while ( pGlyphs && pGlyphs < git.pEndGlyphs )
    {
      p_Flags = &pGlyphs->Flags;
      newHd = (pGlyphs->Flags & 0x40) != 0 ? -pGlyphs->Advance : pGlyphs->Advance;
      newWb = (double)newHd * scaleFactor;
      v18 = (int)newWb;
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
      newHg = v20;
      newWc = scaleFactor * newHg;
      Scaleform::Render::Text::LineBuffer::GlyphEntry::SetFontSize(pGlyphs, newWc);
      pGlyphs = git.pGlyphs;
      if ( !git.pGlyphs )
        break;
      if ( git.pGlyphs < git.pEndGlyphs )
      {
        Delta = git.Delta;
        if ( !git.Delta )
        {
          Delta = git.pGlyphs->LenAndFontSize >> 12;
          git.Delta = Delta;
        }
        ++git.pGlyphs;
        if ( (git.pGlyphs->LenAndFontSize & 0xF000) != 0
          && Delta
          && !Scaleform::Render::Text::HighlighterPosIterator::IsFinished(&git.HighlighterIter) )
        {
          Scaleform::Render::Text::HighlighterPosIterator::operator+=(&git.HighlighterIter, git.Delta);
          goto LABEL_37;
        }
        goto LABEL_38;
      }
    }
    if ( git.pImage.pObject )
      Scaleform::RefCountNTSImpl::Release(git.pImage.pObject);
    if ( git.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
    this = v34;
    if ( it.CurrentPos < v34->Lines.Data.Size )
      ++it.CurrentPos;
  }
  this->Geom.Flags |= 1u;
}
