unsigned int __thiscall Scaleform::GFx::StaticTextSnapshotData::HitTestTextNearPos(
        Scaleform::GFx::StaticTextSnapshotData *this,
        float x,
        float y,
        float closedist)
{
  unsigned int v4; // ebx
  Scaleform::GFx::StaticTextCharacter *pObject; // edi
  Scaleform::Render::Matrix2x4<float> *v6; // eax
  double v7; // st6
  Scaleform::Render::Text::LineBuffer::Line *v8; // esi
  double v9; // st7
  double v10; // st6
  unsigned int GlyphsCount; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v12; // edi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // eax
  int v14; // edi
  int Advance; // eax
  int MemSize; // ecx
  int TextPos; // esi
  unsigned int v18; // esi
  float xoffInLinea; // [esp+8h] [ebp-B0h]
  float xoffInLineb; // [esp+8h] [ebp-B0h]
  float xoffInLine; // [esp+8h] [ebp-B0h]
  float xoffInLinec; // [esp+8h] [ebp-B0h]
  float xoffInLined; // [esp+8h] [ebp-B0h]
  Scaleform::GFx::StaticTextSnapshotData *v25; // [esp+Ch] [ebp-ACh]
  int v26; // [esp+Ch] [ebp-ACh]
  int xoffset; // [esp+10h] [ebp-A8h]
  int xoffseta; // [esp+10h] [ebp-A8h]
  float fixedX; // [esp+14h] [ebp-A4h]
  float fixedXa; // [esp+14h] [ebp-A4h]
  Scaleform::GFx::StaticTextCharacter *pclosestChar; // [esp+18h] [ebp-A0h]
  unsigned int tempBaseIdx; // [esp+1Ch] [ebp-9Ch]
  unsigned int baseIdx; // [esp+20h] [ebp-98h]
  Scaleform::Render::Point<float> cpb; // [esp+24h] [ebp-94h] BYREF
  Scaleform::Render::Point<float> result; // [esp+2Ch] [ebp-8Ch] BYREF
  float minDist; // [esp+34h] [ebp-84h]
  Scaleform::Render::Point<float> rp; // [esp+38h] [ebp-80h] BYREF
  float v38; // [esp+40h] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::Iterator it; // [esp+44h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+58h] [ebp-60h] BYREF

  minDist = 3.4028235e38;
  v4 = 0;
  fixedX = 0.0;
  *(float *)&xoffset = 0.0;
  v25 = this;
  pclosestChar = 0;
  cpb.x = x;
  tempBaseIdx = 0;
  baseIdx = 0;
  cpb.y = y;
  if ( !this->StaticTextCharRefs.Data.Size )
    return -1;
  while ( 1 )
  {
    pObject = this->StaticTextCharRefs.Data.Data[v4].pChar.pObject;
    v6 = (Scaleform::Render::Matrix2x4<float> *)pObject->GetMatrix(pObject);
    Scaleform::Render::Matrix2x4<float>::TransformByInverse(v6, &result, &cpb);
    v7 = result.y;
    if ( pObject->TextGlyphRecords.Geom.VisibleRect.x2 >= (double)result.x
      && pObject->TextGlyphRecords.Geom.VisibleRect.x1 <= (double)result.x
      && pObject->TextGlyphRecords.Geom.VisibleRect.y2 >= v7
      && pObject->TextGlyphRecords.Geom.VisibleRect.y1 <= v7 )
    {
      break;
    }
    Scaleform::GFx::ClosestPointOnRectangle(&pObject->TextGlyphRecords.Geom.VisibleRect, &result, &rp);
    xoffInLinea = rp.x - result.x;
    v38 = rp.y - result.y;
    xoffInLineb = v38 * v38 + xoffInLinea * xoffInLinea;
    xoffInLine = sqrt(xoffInLineb);
    if ( closedist <= (double)xoffInLine || minDist <= (double)xoffInLine )
    {
      pObject = pclosestChar;
    }
    else
    {
      minDist = xoffInLine;
      pclosestChar = pObject;
      fixedX = rp.x;
      baseIdx = tempBaseIdx;
      xoffset = SLODWORD(rp.y);
    }
    tempBaseIdx += v25->StaticTextCharRefs.Data.Data[v4++].CharCount;
    if ( v4 >= v25->StaticTextCharRefs.Data.Size )
      goto LABEL_13;
    this = v25;
  }
  fixedX = result.x;
  baseIdx = tempBaseIdx;
  xoffset = SLODWORD(result.y);
LABEL_13:
  if ( !pObject )
    return -1;
  fixedXa = fixedX - pObject->TextGlyphRecords.Geom.VisibleRect.x1;
  cpb.x = fixedXa;
  cpb.y = *(float *)&xoffset - pObject->TextGlyphRecords.Geom.VisibleRect.y1;
  Scaleform::Render::Text::LineBuffer::FindLineAtOffset(&pObject->TextGlyphRecords, &it, &cpb);
  if ( !it.pLineBuffer )
    return -1;
  if ( it.CurrentPos >= it.pLineBuffer->Lines.Data.Size )
    return -1;
  if ( (it.CurrentPos & 0x80000000) != 0 )
    return -1;
  v8 = it.pLineBuffer->Lines.Data.Data[it.CurrentPos];
  xoffInLinec = (float)v8->Data32.OffsetX;
  v9 = fixedXa;
  v10 = xoffInLinec;
  if ( xoffInLinec > (double)fixedXa )
    return -1;
  v26 = (v8->MemSize & 0x80000000) == 0 ? v8->Data32.Width : v8->Data8.Width;
  if ( (double)v26 + v10 < v9 )
    return -1;
  xoffseta = 0;
  if ( (v8->MemSize & 0x80000000) == 0 )
    GlyphsCount = v8->Data32.GlyphsCount;
  else
    GlyphsCount = v8->Data8.GlyphsCount;
  v12 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v8->Data8.Leading + 1);
  if ( (v8->MemSize & 0x80000000) == 0 )
    v12 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v8->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v8);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(&git, v12, GlyphsCount, FormatData);
  v14 = 0;
  while ( git.pGlyphs && git.pGlyphs < git.pEndGlyphs )
  {
    Advance = git.pGlyphs->Advance;
    if ( (git.pGlyphs->Flags & 0x40) != 0 )
      Advance = -Advance;
    xoffseta += Advance;
    xoffInLined = v9 - v10;
    if ( xoffInLined < (double)xoffseta )
      break;
    v14 += git.pGlyphs->LenAndFontSize >> 12;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
  }
  MemSize = v8->MemSize;
  TextPos = v8->Data32.TextPos;
  if ( MemSize < 0 )
  {
    TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
    if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
      TextPos = -1;
  }
  v18 = baseIdx + v14 + TextPos;
  if ( git.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(git.pImage.pObject);
  if ( git.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
  return v18;
}
