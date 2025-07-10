void __thiscall Scaleform::GFx::StaticTextSnapshotData::Visit(
        Scaleform::GFx::StaticTextSnapshotData *this,
        Scaleform::GFx::StaticTextSnapshotData::GlyphVisitor *pvisitor,
        unsigned int start,
        unsigned int end)
{
  Scaleform::GFx::StaticTextCharacter *pObject; // edi
  float *v5; // eax
  Scaleform::Render::Text::LineBuffer *p_TextGlyphRecords; // edi
  double v7; // st7
  double v8; // st5
  double v9; // st7
  int v10; // eax
  Scaleform::Render::Text::LineBuffer::Line *v11; // ecx
  bool v12; // dl
  int Leading; // eax
  unsigned int GlyphsCount; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v15; // edi
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // eax
  unsigned int ColorV; // edx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // ecx
  unsigned int v19; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v20; // eax
  int v21; // eax
  double v22; // st7
  float *v23; // eax
  int v24; // eax
  unsigned int v25; // [esp+BB8h] [ebp-ECh]
  float v26; // [esp+BB8h] [ebp-ECh]
  float radians; // [esp+BB8h] [ebp-ECh]
  float v28; // [esp+BB8h] [ebp-ECh]
  float v29; // [esp+BB8h] [ebp-ECh]
  unsigned int v30; // [esp+BBCh] [ebp-E8h]
  Scaleform::Render::Font *v31; // [esp+BBCh] [ebp-E8h]
  float OffsetX; // [esp+BC0h] [ebp-E4h]
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v33; // [esp+BC0h] [ebp-E4h]
  int Advance; // [esp+BC0h] [ebp-E4h]
  float v35; // [esp+BC4h] [ebp-E0h]
  int v36; // [esp+BC8h] [ebp-DCh]
  unsigned int v37; // [esp+BCCh] [ebp-D8h]
  Scaleform::GFx::StaticTextSnapshotData *v38; // [esp+BD0h] [ebp-D4h]
  Scaleform::Render::Matrix2x4<float> v39; // [esp+BD4h] [ebp-D0h] BYREF
  float v40; // [esp+BFCh] [ebp-A8h]
  unsigned int Size; // [esp+C00h] [ebp-A4h]
  float *v42; // [esp+C04h] [ebp-A0h]
  float v43; // [esp+C08h] [ebp-9Ch]
  float v44; // [esp+C0Ch] [ebp-98h]
  Scaleform::Render::Text::LineBuffer *v45; // [esp+C10h] [ebp-94h]
  unsigned int v46; // [esp+C18h] [ebp-8Ch]
  Scaleform::Render::Rect<float> r; // [esp+C24h] [ebp-80h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v48; // [esp+C34h] [ebp-70h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+C94h] [ebp-10h] BYREF

  v38 = this;
  if ( pvisitor )
  {
    v25 = 0;
    v36 = 0;
    Size = this->StaticTextCharRefs.Data.Size;
    if ( Size )
    {
      while ( 1 )
      {
        v35 = 0.0;
        pObject = this->StaticTextCharRefs.Data.Data[v36].pChar.pObject;
        v5 = (float *)pObject->GetMatrix(pObject);
        p_TextGlyphRecords = &pObject->TextGlyphRecords;
        v7 = v5[1] * 0.0;
        v42 = v5;
        v8 = *v5;
        v45 = p_TextGlyphRecords;
        v40 = v7 + v8 * 0.0 + v5[3];
        v9 = 0.0 * v5[4] + v5[5] * 0.0 + v5[7];
        v10 = 0;
        v46 = 0;
        v43 = v9;
        while ( p_TextGlyphRecords && v10 < p_TextGlyphRecords->Lines.Data.Size && v10 >= 0 )
        {
          v11 = p_TextGlyphRecords->Lines.Data.Data[v10];
          v12 = (v11->MemSize & 0x80000000) != 0;
          v37 = 0;
          OffsetX = (float)v11->Data32.OffsetX;
          if ( v35 > (double)OffsetX )
            v35 = (float)v11->Data32.OffsetX;
          if ( (v11->MemSize & 0x80000000) == 0 )
            Leading = v11->Data32.Leading;
          else
            Leading = v11->Data8.Leading;
          v44 = (float)(v11->Data32.OffsetY + Leading);
          if ( v12 )
            GlyphsCount = v11->Data8.GlyphsCount;
          else
            GlyphsCount = v11->Data32.GlyphsCount;
          v30 = GlyphsCount;
          v15 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v11->Data8.Leading + 1);
          if ( !v12 )
            v15 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v11->Data8 + 38);
          FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v11);
          v48.HighlighterIter.CurDesc.StartPos = -1;
          v48.HighlighterIter.CurDesc.Offset = -1;
          v48.HighlighterIter.CurDesc.Length = 0;
          memset(&v48.HighlighterIter.CurDesc.AdjStartPos, 0, 25);
          v48.HighlighterIter.NumGlyphs = 0;
          v48.HighlighterIter.CurAdjStartPos = 0;
          memset(&v48.ColorV, 0, 32);
          v48.pGlyphs = v15;
          v48.pEndGlyphs = &v15[v30];
          v48.pNextFormatData = FormatData;
          Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&v48);
          if ( v48.pFontHandle.pObject )
            v31 = v48.pFontHandle.pObject->pFont.pObject;
          else
            v31 = 0;
          ColorV = v48.ColorV;
          pvisitor->pFont = v31;
          pvisitor->ColorValue.Raw = ColorV;
          while ( 1 )
          {
            pGlyphs = v48.pGlyphs;
            if ( !v48.pGlyphs || v48.pGlyphs >= v48.pEndGlyphs )
              break;
            v19 = v25;
            v20 = v48.pGlyphs;
            v33 = v48.pGlyphs;
            if ( v25 >= start && v25 < end )
            {
              pvisitor->RunIdx = v37;
              v21 = pGlyphs->LenAndFontSize & 0xFFF;
              if ( (pGlyphs->Flags & 0x10) != 0 )
                v22 = (double)(unsigned int)v21 * 0.0625;
              else
                v22 = (double)(unsigned int)v21;
              v23 = v42;
              v26 = v22;
              pvisitor->Height = v26;
              v39.M[0][0] = 1.0;
              v39.M[0][1] = 0.0;
              v39.M[0][2] = 0.0;
              v39.M[0][3] = 0.0;
              v39.M[1][0] = 0.0;
              v39.M[1][2] = 0.0;
              v39.M[1][3] = 0.0;
              v39.M[1][1] = 1.0;
              radians = atan2(v23[4], *v23);
              Scaleform::Render::Matrix2x4<float>::AppendRotation(&v39, radians);
              v28 = v40 + v35;
              v39.M[0][3] = v28 + v39.M[0][3];
              v29 = v43 + v44;
              v39.M[1][3] = v29 + v39.M[1][3];
              pvisitor->Matrix = v39;
              LOWORD(v24) = v33->Index;
              r.x1 = 0.0;
              r.y1 = 0.0;
              r.x2 = 0.0;
              r.y2 = 0.0;
              if ( (_WORD)v24 == 0xFFFF )
                v24 = -1;
              else
                v24 = (unsigned __int16)v24;
              v31->GetGlyphBounds(v31, v24, &r);
              Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v39, &pr, (__m128 *)&r);
              pvisitor->Corners = pr;
              pvisitor->bSelected = Scaleform::GFx::StaticTextSnapshotData::IsSelected(v38, v19, v19 + 1);
              pvisitor->OnVisit(pvisitor);
              ++v37;
              v20 = v33;
            }
            if ( (v20->Flags & 0x40) != 0 )
              Advance = -v20->Advance;
            else
              Advance = v20->Advance;
            v25 = v19 + 1;
            v35 = (double)Advance + v35;
            Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v48);
          }
          if ( v48.pImage.pObject )
            Scaleform::RefCountNTSImpl::Release(v48.pImage.pObject);
          if ( v48.pFontHandle.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v48.pFontHandle.pObject);
          p_TextGlyphRecords = v45;
          if ( v46 < v45->Lines.Data.Size )
            ++v46;
          v10 = v46;
        }
        if ( ++v36 >= Size )
          break;
        this = v38;
      }
    }
  }
}
