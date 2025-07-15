int __thiscall Scaleform::GFx::StaticTextSnapshotData::HitTestTextNearPos(
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
  int v18; // esi
  float v20; // [esp+8h] [ebp-B0h]
  float v21; // [esp+8h] [ebp-B0h]
  float v22; // [esp+8h] [ebp-B0h]
  float OffsetX; // [esp+8h] [ebp-B0h]
  float v24; // [esp+8h] [ebp-B0h]
  Scaleform::GFx::StaticTextSnapshotData *v25; // [esp+Ch] [ebp-ACh]
  int v26; // [esp+Ch] [ebp-ACh]
  float v27; // [esp+10h] [ebp-A8h]
  int v28; // [esp+10h] [ebp-A8h]
  float v29; // [esp+14h] [ebp-A4h]
  float v30; // [esp+14h] [ebp-A4h]
  Scaleform::GFx::StaticTextCharacter *v31; // [esp+18h] [ebp-A0h]
  int v32; // [esp+1Ch] [ebp-9Ch]
  int v33; // [esp+20h] [ebp-98h]
  Scaleform::Render::Point<float> p; // [esp+24h] [ebp-94h] BYREF
  Scaleform::Render::Point<float> result; // [esp+2Ch] [ebp-8Ch] BYREF
  float v36; // [esp+34h] [ebp-84h]
  Scaleform::Render::Point<float> v37; // [esp+38h] [ebp-80h] BYREF
  float v38; // [esp+40h] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::Iterator v39; // [esp+44h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v40; // [esp+58h] [ebp-60h] BYREF

  v36 = 3.4028235e38;
  v4 = 0;
  v29 = 0.0;
  v27 = 0.0;
  v25 = this;
  v31 = 0;
  p.x = x;
  v32 = 0;
  v33 = 0;
  p.y = y;
  if ( !this->StaticTextCharRefs.Data.Size )
    return -1;
  while ( 1 )
  {
    pObject = this->StaticTextCharRefs.Data.Data[v4].pChar.pObject;
    v6 = (Scaleform::Render::Matrix2x4<float> *)pObject->GetMatrix(pObject);
    Scaleform::Render::Matrix2x4<float>::TransformByInverse(v6, &result, &p);
    v7 = result.y;
    if ( pObject->TextGlyphRecords.Geom.VisibleRect.x2 >= (double)result.x
      && pObject->TextGlyphRecords.Geom.VisibleRect.x1 <= (double)result.x
      && pObject->TextGlyphRecords.Geom.VisibleRect.y2 >= v7
      && pObject->TextGlyphRecords.Geom.VisibleRect.y1 <= v7 )
    {
      break;
    }
    Scaleform::GFx::ClosestPointOnRectangle(&pObject->TextGlyphRecords.Geom.VisibleRect, &result, &v37);
    v20 = v37.x - result.x;
    v38 = v37.y - result.y;
    v21 = v38 * v38 + v20 * v20;
    v22 = sqrt(v21);
    if ( closedist <= (double)v22 || v36 <= (double)v22 )
    {
      pObject = v31;
    }
    else
    {
      v36 = v22;
      v31 = pObject;
      v29 = v37.x;
      v33 = v32;
      v27 = v37.y;
    }
    v32 += v25->StaticTextCharRefs.Data.Data[v4++].CharCount;
    if ( v4 >= v25->StaticTextCharRefs.Data.Size )
      goto LABEL_13;
    this = v25;
  }
  v29 = result.x;
  v33 = v32;
  v27 = result.y;
LABEL_13:
  if ( !pObject )
    return -1;
  v30 = v29 - pObject->TextGlyphRecords.Geom.VisibleRect.x1;
  p.x = v30;
  p.y = v27 - pObject->TextGlyphRecords.Geom.VisibleRect.y1;
  Scaleform::Render::Text::LineBuffer::FindLineAtOffset(&pObject->TextGlyphRecords, &v39, &p);
  if ( !v39.pLineBuffer )
    return -1;
  if ( v39.CurrentPos >= v39.pLineBuffer->Lines.Data.Size )
    return -1;
  if ( (v39.CurrentPos & 0x80000000) != 0 )
    return -1;
  v8 = v39.pLineBuffer->Lines.Data.Data[v39.CurrentPos];
  OffsetX = (float)v8->Data32.OffsetX;
  v9 = v30;
  v10 = OffsetX;
  if ( OffsetX > (double)v30 )
    return -1;
  v26 = (v8->MemSize & 0x80000000) == 0 ? v8->Data32.Width : v8->Data8.Width;
  if ( (double)v26 + v10 < v9 )
    return -1;
  v28 = 0;
  if ( (v8->MemSize & 0x80000000) == 0 )
    GlyphsCount = v8->Data32.GlyphsCount;
  else
    GlyphsCount = v8->Data8.GlyphsCount;
  v12 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v8->Data8.Leading + 1);
  if ( (v8->MemSize & 0x80000000) == 0 )
    v12 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v8->Data8 + 38);
  FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v8);
  Scaleform::Render::Text::LineBuffer::GlyphIterator::GlyphIterator(&v40, v12, GlyphsCount, FormatData);
  v14 = 0;
  while ( v40.pGlyphs && v40.pGlyphs < v40.pEndGlyphs )
  {
    Advance = v40.pGlyphs->Advance;
    if ( (v40.pGlyphs->Flags & 0x40) != 0 )
      Advance = -Advance;
    v28 += Advance;
    v24 = v9 - v10;
    if ( v24 < (double)v28 )
      break;
    v14 += v40.pGlyphs->LenAndFontSize >> 12;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v40);
  }
  MemSize = v8->MemSize;
  TextPos = v8->Data32.TextPos;
  if ( MemSize < 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  v18 = v33 + v14 + TextPos;
  if ( v40.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(v40.pImage.pObject);
  if ( v40.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v40.pFontHandle.pObject);
  return v18;
}
