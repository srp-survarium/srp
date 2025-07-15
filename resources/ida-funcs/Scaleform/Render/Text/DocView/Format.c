void __thiscall Scaleform::Render::Text::DocView::Format(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // esi
  unsigned int v3; // eax
  bool v4; // zf
  unsigned __int8 Flags; // cl
  Scaleform::Log *v6; // edx
  int v7; // ebx
  Scaleform::Render::Text::LineBuffer *v8; // ecx
  Scaleform::Render::Text::Paragraph *v9; // esi
  Scaleform::Render::Text::LineBuffer::Line *v10; // eax
  unsigned int UniqueId; // edi
  unsigned int v12; // esi
  unsigned __int16 v13; // dx
  Scaleform::Render::Text::EditorKitBase *v14; // eax
  int v15; // eax
  Scaleform::Render::Text::LineBuffer::Line *v16; // esi
  unsigned int ParagraphId; // edi
  bool v18; // al
  unsigned int TextPosAndLength_high; // ecx
  int Width; // eax
  Scaleform::Render::Text::DocView *v21; // ebx
  Scaleform::Render::Text::EditorKitBase *v22; // ecx
  unsigned int Height; // eax
  unsigned int v24; // ecx
  int Leading; // eax
  int MemSize; // edi
  double v27; // st6
  double v28; // st7
  signed int v29; // eax
  int v30; // eax
  double v31; // st7
  double v32; // st7
  unsigned int v33; // ecx
  unsigned int TextPos; // esi
  unsigned int v35; // edi
  unsigned int v36; // eax
  int j; // esi
  int *v38; // edx
  int v39; // edx
  unsigned int v40; // edi
  unsigned int GlyphsCount; // esi
  unsigned __int16 v42; // ax
  unsigned int v43; // esi
  int i; // edx
  int *v45; // eax
  int v46; // eax
  Scaleform::Render::Text::DocView *v47; // edi
  int ParaWidth; // eax
  Scaleform::Render::Text::EditorKitBase *v49; // ecx
  Scaleform::Render::Text::DocView *v50; // ecx
  unsigned int v51; // eax
  unsigned int v52; // edx
  bool ForceVerticalCenterAutoSize; // bl
  unsigned int AlignProps; // eax
  unsigned __int8 v55; // dl
  int v56; // esi
  int v57; // eax
  double v58; // st6
  double v59; // st5
  double v60; // st7
  double v61; // st6
  Scaleform::Render::Text::DocView *v62; // ebx
  int v63; // eax
  double v64; // st6
  double v65; // st7
  unsigned int MaxVScroll; // eax
  int TextHeight; // eax
  double v68; // st7
  double y2; // st7
  double v70; // st5
  int v71; // esi
  int v72; // esi
  double v73; // st7
  unsigned int BottomVScroll; // eax
  double v75; // st7
  int v76; // edi
  double v77; // st6
  Scaleform::Render::Text::LineBuffer::Line *v78; // ecx
  bool v79; // al
  float v80; // edx
  int v81; // eax
  double v82; // st5
  double v83; // st6
  double v84; // rtt
  double v85; // st6
  float x2; // ecx
  Scaleform::Render::Text::DocView *v87; // edx
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // ebx
  int *v89; // esi
  int v90; // edi
  double v91; // st5
  double v92; // st5
  int v93; // eax
  int v94; // ecx
  int v95; // eax
  double v96; // st5
  double v97; // st5
  int v98; // ecx
  int v99; // eax
  Scaleform::Render::Text::DocView *v100; // edi
  unsigned int MaxHScrollValue; // eax
  unsigned int v102; // esi
  unsigned int v103; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v104; // ecx
  Scaleform::Render::Text::DocView::DocumentListener *v105; // ecx
  Scaleform::Render::Text::DocView::DocumentListener *v106; // ecx
  Scaleform::Render::Text::EditorKitBase *v107; // ecx
  double TextWidth; // st7
  double v109; // st7
  Scaleform::Render::Text::EditorKitBase *v110; // ecx
  Scaleform::Render::Text::CompositionStringBase *v111; // eax
  Scaleform::Render::Text::LineBuffer::Line **Data; // edx
  Scaleform::Render::Text::LineBuffer::Line *v113; // eax
  int v115; // eax
  Scaleform::Render::Text::TextFormat *v116; // eax
  Scaleform::Render::Text::TextFormat *v117; // esi
  Scaleform::Render::Text::TextFormat *v118; // eax
  Scaleform::Render::Text::TextFormat *v119; // esi
  Scaleform::Render::Text::TextFormat *v120; // eax
  Scaleform::Render::Text::TextFormat *v121; // esi
  Scaleform::Render::Text::TextFormat *v122; // eax
  Scaleform::Render::Text::TextFormat *v123; // esi
  Scaleform::Render::Text::TextFormat *v124; // eax
  Scaleform::Render::Text::TextFormat *v125; // esi
  Scaleform::Render::Text::TextFormat *v126; // eax
  Scaleform::Render::Text::TextFormat *v127; // esi
  Scaleform::Render::Text::TextFormat *v128; // eax
  Scaleform::Render::Text::TextFormat *v129; // esi
  Scaleform::Render::Text::TextFormat *v130; // eax
  Scaleform::Render::Text::TextFormat *v131; // esi
  float scaleFactor; // [esp+0h] [ebp-9E4h]
  float v133; // [esp+1Ch] [ebp-9C8h]
  float v134; // [esp+1Ch] [ebp-9C8h]
  float v135; // [esp+1Ch] [ebp-9C8h]
  float v136; // [esp+1Ch] [ebp-9C8h]
  float v137; // [esp+1Ch] [ebp-9C8h]
  float v138; // [esp+1Ch] [ebp-9C8h]
  float v139; // [esp+1Ch] [ebp-9C8h]
  float v140; // [esp+1Ch] [ebp-9C8h]
  float v141; // [esp+1Ch] [ebp-9C8h]
  float v142; // [esp+1Ch] [ebp-9C8h]
  float v143; // [esp+1Ch] [ebp-9C8h]
  int MinLineHeight; // [esp+1Ch] [ebp-9C8h]
  float v145; // [esp+1Ch] [ebp-9C8h]
  Scaleform::Render::Text::Paragraph *v146; // [esp+20h] [ebp-9C4h]
  float v147; // [esp+20h] [ebp-9C4h]
  float v148; // [esp+20h] [ebp-9C4h]
  Scaleform::Render::Rect<float> rect; // [esp+24h] [ebp-9C0h] BYREF
  int v150; // [esp+3Ch] [ebp-9A8h]
  Scaleform::Render::Text::DocView *pdoc; // [esp+40h] [ebp-9A4h]
  float v152; // [esp+44h] [ebp-9A0h]
  int v153; // [esp+48h] [ebp-99Ch]
  char v154; // [esp+4Fh] [ebp-995h]
  float v155; // [esp+50h] [ebp-994h]
  float v156; // [esp+54h] [ebp-990h]
  float v157; // [esp+58h] [ebp-98Ch]
  float v158; // [esp+5Ch] [ebp-988h]
  Scaleform::Render::Text::LineBuffer *v159[2]; // [esp+60h] [ebp-984h] BYREF
  unsigned int lineIdx; // [esp+68h] [ebp-97Ch]
  float v161; // [esp+6Ch] [ebp-978h]
  bool v162; // [esp+70h] [ebp-974h]
  Scaleform::Render::Rect<float> v163; // [esp+74h] [ebp-970h] BYREF
  Scaleform::Render::Text::ParagraphFormatter v164; // [esp+94h] [ebp-950h] BYREF

  rect.x1 = this->ViewRect.x1;
  pdoc = this;
  rect.y1 = this->ViewRect.y1;
  rect.x2 = this->ViewRect.x2;
  rect.y2 = this->ViewRect.y2;
  rect.x1 = rect.x1 + 40.0;
  rect.x2 = rect.x2 - 40.0;
  rect.y1 = rect.y1 + 40.0;
  rect.y2 = rect.y2 - 40.0;
  this->mLineBuffer.Geom.VisibleRect = rect;
  pObject = this->pDocument.pObject;
  if ( !pObject )
    return;
  *(float *)&v3 = COERCE_FLOAT(Scaleform::Render::Text::DocView::GetMaxHScrollValue(this));
  v4 = (this->AlignProps & 0x30) == 0;
  v157 = *(float *)&v3;
  v155 = *(float *)&this->MaxVScroll.Value;
  if ( !v4 )
    this->RTFlags |= 2u;
  Flags = this->mLineBuffer.Geom.Flags;
  v6 = this->pLog.pObject;
  v161 = 0.0;
  v162 = (Flags & 4) != 0;
  LODWORD(rect.x1) = &pObject->Paragraphs;
  rect.y1 = 0.0;
  v159[0] = &this->mLineBuffer;
  v159[1] = 0;
  lineIdx = 0;
  Scaleform::Render::Text::ParagraphFormatter::ParagraphFormatter(&v164, this, v6);
  v150 = 0;
  v153 = 0;
LABEL_5:
  v7 = lineIdx;
  v8 = v159[0];
LABEL_6:
  while ( LODWORD(rect.x1) && rect.y1 >= 0.0 && SLODWORD(rect.y1) < *(_DWORD *)(LODWORD(rect.x1) + 4) )
  {
    v9 = *(Scaleform::Render::Text::Paragraph **)(*(_DWORD *)LODWORD(rect.x1) + 4 * LODWORD(rect.y1));
    v146 = v9;
    if ( !v8 || v7 >= v8->Lines.Data.Size || v7 < 0 )
      goto LABEL_118;
    v10 = v8->Lines.Data.Data[v7];
    if ( (pdoc->RTFlags & 2) == 0 )
    {
      UniqueId = v9->UniqueId;
      v12 = (v10->MemSize & 0x80000000) == 0 ? v10->Data32.ParagraphId : v10->Data32.GlyphsCount;
      if ( UniqueId == v12 )
      {
        v13 = (v10->MemSize & 0x80000000) == 0 ? v10->Data32.ParagraphModId : v10->Data8.ParagraphModId;
        if ( v146->ModCounter == v13 )
        {
          v14 = pdoc->pEditorKit.pObject;
          if ( v14 )
          {
            *(float *)&v15 = COERCE_FLOAT(v14->TextPos2GlyphOffset(v14, v146->StartIndex));
            v7 = lineIdx;
            v8 = v159[0];
            v152 = *(float *)&v15;
          }
          else
          {
            v152 = *(float *)&v146->StartIndex;
          }
          while ( 1 )
          {
            if ( !v8
              || v7 >= v8->Lines.Data.Size
              || v7 < 0
              || ((v16 = v8->Lines.Data.Data[v7], (v16->MemSize & 0x80000000) == 0)
                ? (ParagraphId = v16->Data32.ParagraphId)
                : (ParagraphId = v16->Data32.GlyphsCount),
                  v146->UniqueId != ParagraphId) )
            {
              if ( SLODWORD(rect.y1) < *(_DWORD *)(LODWORD(rect.x1) + 4) )
                ++LODWORD(rect.y1);
              goto LABEL_6;
            }
            if ( (v16->MemSize & 0x80000000) == 0 )
              *(float *)&v16->Data32.TextPos = v152;
            else
              v16->Data32.TextPos ^= (LODWORD(v152) ^ v16->Data32.TextPos) & 0xFFFFFF;
            v18 = (v16->MemSize & 0x80000000) != 0;
            v158 = *(float *)&v16->Data32.OffsetX;
            v156 = *(float *)&v16->Data32.OffsetY;
            if ( v18 )
              TextPosAndLength_high = HIBYTE(v16->Data8.TextPosAndLength);
            else
              TextPosAndLength_high = v16->Data32.TextLength;
            LODWORD(v152) += TextPosAndLength_high;
            v16->Data32.OffsetY = v164.NextOffsetY;
            if ( v18 )
              Width = v16->Data8.Width;
            else
              Width = v16->Data32.Width;
            if ( Width >= v150 )
              v150 = Width;
            v21 = pdoc;
            if ( Scaleform::Render::Text::Paragraph::GetLength(v146)
              || (v22 = pdoc->pEditorKit.pObject) != 0 && !v22->IsReadOnly(v22) )
            {
              if ( (v16->MemSize & 0x80000000) == 0 )
                Height = v16->Data32.Height;
              else
                Height = v16->Data8.Height;
              v153 = v164.NextOffsetY + Height;
            }
            if ( (v16->MemSize & 0x80000000) == 0 )
              v24 = v16->Data32.Height;
            else
              v24 = v16->Data8.Height;
            if ( (v16->MemSize & 0x80000000) == 0 )
              Leading = v16->Data32.Leading;
            else
              Leading = v16->Data8.Leading;
            v164.NextOffsetY += v24 + Leading;
            if ( (pdoc->Flags & 1) != 0 )
            {
              MemSize = v16->MemSize;
              if ( ((v16->MemSize >> 28) & 3) == 1 )
              {
                v135 = pdoc->mLineBuffer.Geom.VisibleRect.x2 - pdoc->mLineBuffer.Geom.VisibleRect.x1;
                v31 = v135;
                if ( v135 <= 0.0 )
                  v32 = v31 - 0.5;
                else
                  v32 = v31 + 0.5;
                if ( MemSize >= 0 )
                  v33 = v16->Data32.Width;
                else
                  v33 = v16->Data8.Width;
                v30 = (int)((int)v32 - v33) < 0 ? 0 : (int)v32 - v33;
                goto LABEL_72;
              }
              if ( ((v16->MemSize >> 28) & 3) == 2 )
              {
                v133 = pdoc->mLineBuffer.Geom.VisibleRect.x2 - pdoc->mLineBuffer.Geom.VisibleRect.x1;
                v134 = v133 * 0.5;
                v27 = v134;
                if ( v134 <= 0.0 )
                  v28 = v27 - 0.5;
                else
                  v28 = v27 + 0.5;
                if ( MemSize >= 0 )
                  v29 = v16->Data32.Width;
                else
                  v29 = v16->Data8.Width;
                v30 = ((int)v28 - v29 / 2) & (((int)v28 - v29 / 2 < 0) - 1);
LABEL_72:
                v16->Data32.OffsetX = v30;
                v164.NeedRecenterLines = 1;
              }
            }
            if ( LODWORD(v158) != v16->Data32.OffsetX || LODWORD(v156) != v16->Data32.OffsetY )
              v21->mLineBuffer.Geom.Flags |= 1u;
            v7 = lineIdx;
            v8 = v159[0];
            if ( lineIdx < v159[0]->Lines.Data.Size )
              v7 = ++lineIdx;
          }
        }
      }
    }
    TextPos = v10->Data32.TextPos;
    if ( (v10->MemSize & 0x80000000) == 0 || (TextPos &= 0xFFFFFFu, TextPos != 0xFFFFFF) )
    {
      if ( TextPos != -1 )
      {
        v40 = v146->UniqueId;
        if ( (v10->MemSize & 0x80000000) == 0 )
          GlyphsCount = v10->Data32.ParagraphId;
        else
          GlyphsCount = v10->Data32.GlyphsCount;
        if ( v40 == GlyphsCount )
        {
          v42 = (v10->MemSize & 0x80000000) == 0 ? v10->Data32.ParagraphModId : v10->Data8.ParagraphModId;
          if ( v146->ModCounter != v42 )
          {
            v43 = 0;
            for ( i = v7; i < v8->Lines.Data.Size && i >= 0; ++i )
            {
              v45 = (int *)v8->Lines.Data.Data[i];
              v46 = *v45 >= 0 ? v45[7] : v45[1];
              v7 = lineIdx;
              if ( v46 != v40 )
                break;
              ++v43;
            }
            if ( v7 < v8->Lines.Data.Size )
              Scaleform::Render::Text::LineBuffer::RemoveLines(v8, v7, v43);
            pdoc->mLineBuffer.Geom.Flags |= 1u;
          }
        }
        v9 = v146;
LABEL_118:
        v164.pLinesIter = (Scaleform::Render::Text::LineBuffer::Iterator *)v159;
        v164.ParaYOffset = v164.NextOffsetY;
        Scaleform::Render::Text::ParagraphFormatter::Format(&v164, v9);
        v47 = pdoc;
        ParaWidth = v164.ParaWidth;
        pdoc->mLineBuffer.Geom.Flags |= 1u;
        if ( ParaWidth >= v150 )
          v150 = ParaWidth;
        if ( Scaleform::Render::Text::Paragraph::GetLength(v9)
          || (v49 = v47->pEditorKit.pObject) != 0 && !v49->IsReadOnly(v49) )
        {
          v153 = v164.ParaYOffset + v164.ParaHeight;
        }
        if ( SLODWORD(rect.y1) < *(_DWORD *)(LODWORD(rect.x1) + 4) )
          ++LODWORD(rect.y1);
        goto LABEL_5;
      }
    }
    v35 = 0;
    if ( (v10->MemSize & 0x80000000) == 0 )
      v36 = v10->Data32.ParagraphId;
    else
      v36 = v10->Data32.GlyphsCount;
    for ( j = v7; j < v8->Lines.Data.Size && j >= 0; ++j )
    {
      v38 = (int *)v8->Lines.Data.Data[j];
      v39 = *v38 >= 0 ? v38[7] : v38[1];
      v7 = lineIdx;
      if ( v39 != v36 )
        break;
      ++v35;
    }
    if ( v35 )
    {
      if ( v7 < v8->Lines.Data.Size )
      {
        Scaleform::Render::Text::LineBuffer::RemoveLines(v8, v7, v35);
        v7 = lineIdx;
        v8 = v159[0];
      }
      pdoc->mLineBuffer.Geom.Flags |= 1u;
    }
  }
  if ( v8 && v7 < v8->Lines.Data.Size && v7 >= 0 )
  {
    Scaleform::Render::Text::LineBuffer::RemoveLines(v8, v7, pdoc->mLineBuffer.Lines.Data.Size - v7);
    pdoc->mLineBuffer.Geom.Flags |= 1u;
  }
  v50 = pdoc;
  v51 = v153;
  v52 = v150;
  ++pdoc->FormatCounter;
  v50->RTFlags &= 0xFCu;
  ForceVerticalCenterAutoSize = v164.ForceVerticalCenterAutoSize;
  v50->TextHeight = v51;
  AlignProps = v50->AlignProps;
  v50->TextWidth = v52;
  v55 = v50->Flags;
  v56 = (AlignProps >> 2) & 3;
  v154 = 0;
  if ( (v55 & 1) != 0 || (v55 & 2) != 0 || ForceVerticalCenterAutoSize )
  {
    rect.x1 = pdoc->ViewRect.x1;
    rect.y1 = pdoc->ViewRect.y1;
    rect.x2 = pdoc->ViewRect.x2;
    rect.y2 = pdoc->ViewRect.y2;
    if ( (v55 & 1) == 0 )
    {
LABEL_140:
      if ( (v55 & 2) == 0 && !ForceVerticalCenterAutoSize )
      {
LABEL_151:
        if ( pdoc->ViewRect.x1 != rect.x1
          || pdoc->ViewRect.x2 != rect.x2
          || pdoc->ViewRect.y1 != rect.y1
          || pdoc->ViewRect.y2 != rect.y2 )
        {
          Scaleform::Render::Text::DocView::SetViewRect(pdoc, &rect, UseInternally);
        }
        goto LABEL_156;
      }
      v138 = (double)(unsigned int)v153 + 80.0;
      v60 = v138;
      if ( v56 )
      {
        if ( v56 != 3 )
        {
          if ( v56 != 2 )
          {
LABEL_150:
            v154 = 1;
            rect.y2 = v60 + rect.y1;
            goto LABEL_151;
          }
          v61 = rect.y2 - v60;
LABEL_149:
          rect.y1 = v61;
          goto LABEL_150;
        }
      }
      else if ( !ForceVerticalCenterAutoSize )
      {
        v154 = 1;
        rect.y2 = v60 + rect.y1;
        goto LABEL_151;
      }
      v139 = rect.y2 - rect.y1;
      v61 = rect.y1 + v139 * 0.5 - 0.5 * v60;
      goto LABEL_149;
    }
    v57 = (AlignProps & 3) - 1;
    v136 = (double)(unsigned int)v150 + 80.0;
    v58 = v136;
    if ( v57 )
    {
      if ( v57 != 1 )
      {
LABEL_139:
        rect.x2 = v58 + rect.x1;
        goto LABEL_140;
      }
      v137 = rect.x2 - rect.x1;
      v59 = rect.x1 + v137 * 0.5 - 0.5 * v58;
    }
    else
    {
      v59 = rect.x2 - v58;
    }
    rect.x1 = v59;
    goto LABEL_139;
  }
LABEL_156:
  v62 = pdoc;
  v63 = (pdoc->AlignProps >> 4) & 3;
  if ( !v63 )
    goto LABEL_183;
  v4 = (pdoc->Flags & 4) == 0;
  rect.x1 = pdoc->ViewRect.x1;
  rect.y1 = pdoc->ViewRect.y1;
  rect.x2 = pdoc->ViewRect.x2;
  rect.y2 = pdoc->ViewRect.y2;
  rect.x1 = rect.x1 + 40.0;
  rect.x2 = rect.x2 - 40.0;
  rect.y1 = rect.y1 + 40.0;
  rect.y2 = rect.y2 - 40.0;
  if ( v4 && !v56 )
    v56 = 3;
  v147 = 1.0;
  v152 = 1.0;
  if ( v63 == 1 )
  {
    v140 = (float)v150;
    v156 = rect.x2 - rect.x1;
    if ( v156 < (double)v140 )
      v147 = v156 / v140;
    v141 = (float)v153;
    v156 = rect.y2 - rect.y1;
    if ( v156 < (double)v141 )
      v152 = v156 / v141;
    if ( v147 > (double)v152 )
      v147 = v152;
    goto LABEL_176;
  }
  if ( v63 == 2 )
  {
    v152 = 3.4028235e38;
    v148 = 3.4028235e38;
    if ( v150 >= 20 )
    {
      v142 = rect.x2 - rect.x1;
      v148 = v142 / (double)v150;
    }
    if ( v153 >= 20 )
    {
      v143 = rect.y2 - rect.y1;
      v152 = v143 / (double)v153;
    }
    v64 = v152;
    if ( v148 <= (double)v152 )
      v64 = v148;
    v147 = v64;
    if ( v147 != 3.402823466385289e38 )
    {
LABEL_176:
      if ( 1.0 == v147 )
        goto LABEL_183;
      MinLineHeight = Scaleform::Render::Text::LineBuffer::GetMinLineHeight(&pdoc->mLineBuffer);
      if ( MinLineHeight > 0 )
      {
        v145 = (float)MinLineHeight;
        if ( v145 * v147 >= 120.0 )
        {
          v65 = v147;
          goto LABEL_182;
        }
        v147 = 120.0 / v145;
      }
      v65 = v147;
LABEL_182:
      v62->TextWidth = (__int64)((double)v150 * v65);
      *(_QWORD *)&rect.x1 = (__int64)((double)v153 * v65);
      v62->TextHeight = LODWORD(rect.x1);
      scaleFactor = v65;
      Scaleform::Render::Text::LineBuffer::Scale(&v62->mLineBuffer, scaleFactor);
    }
  }
LABEL_183:
  LOBYTE(v150) = 0;
  MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(v62);
  if ( v62->mLineBuffer.Geom.FirstVisibleLinePos <= MaxVScroll )
  {
    if ( MaxVScroll != LODWORD(v155) )
      LOBYTE(v150) = 1;
  }
  else
  {
    Scaleform::Render::Text::DocView::SetVScrollOffset(v62, MaxVScroll);
  }
  if ( v154 || !v56 || (v62->Flags & 2) != 0 )
  {
    v73 = 0.5;
    goto LABEL_223;
  }
  TextHeight = v62->TextHeight;
  rect.x1 = v62->ViewRect.x1;
  rect.y1 = v62->ViewRect.y1;
  rect.x2 = v62->ViewRect.x2;
  rect.y2 = v62->ViewRect.y2;
  rect.x1 = rect.x1 + 40.0;
  rect.x2 = rect.x2 - 40.0;
  rect.y1 = rect.y1 + 40.0;
  rect.y2 = rect.y2 - 40.0;
  v163.x1 = v62->mLineBuffer.Geom.VisibleRect.x1;
  v163.y1 = v62->mLineBuffer.Geom.VisibleRect.y1;
  v163.x2 = v62->mLineBuffer.Geom.VisibleRect.x2;
  v163.y2 = v62->mLineBuffer.Geom.VisibleRect.y2;
  v68 = (double)(int)v62->TextHeight;
  if ( TextHeight < 0 )
    v68 = v68 + 4294967300.0;
  v155 = v68;
  y2 = rect.y2;
  v156 = rect.y2 - rect.y1;
  v70 = v155;
  if ( v156 <= (double)v155 )
  {
    v163.y1 = rect.y1;
    if ( v56 == 3 || v56 == 2 )
    {
      v158 = 0.0;
      BottomVScroll = Scaleform::Render::Text::DocView::GetBottomVScroll(v62);
      v75 = v156;
      v76 = BottomVScroll;
      v153 = 0;
      while ( 1 )
      {
        v77 = v158;
        if ( v62 == (Scaleform::Render::Text::DocView *)-48 || v76 >= v62->mLineBuffer.Lines.Data.Size || v76 < 0 )
          break;
        v78 = v62->mLineBuffer.Lines.Data.Data[v76];
        v79 = (v78->MemSize & 0x80000000) != 0;
        if ( (v78->MemSize & 0x80000000) == 0 )
          v80 = *(float *)&v78->Data32.Height;
        else
          LODWORD(v80) = v78->Data8.Height;
        v152 = v80;
        if ( v153 )
        {
          if ( v79 )
            v81 = v78->Data8.Leading;
          else
            v81 = v78->Data32.Leading;
          LODWORD(v152) += v81;
        }
        v82 = (double)SLODWORD(v152) + v77;
        if ( v82 > v75 )
          break;
        --v76;
        ++v153;
        v158 = v82;
      }
      if ( v56 != 2 )
      {
        v163.y1 = v75 * 0.5 - v77 * 0.5 + rect.y1;
        v83 = 0.5;
        y2 = rect.y2;
        goto LABEL_221;
      }
      y2 = rect.y2;
      v163.y1 = rect.y2 - v77;
    }
    v83 = 0.5;
LABEL_221:
    v62->mLineBuffer.Geom.VisibleRect.x1 = rect.x1;
    v62->mLineBuffer.Geom.VisibleRect.y1 = v163.y1;
    v62->mLineBuffer.Geom.VisibleRect.x2 = rect.x2;
    v84 = v83;
    v85 = y2;
    v73 = v84;
    v62->mLineBuffer.Geom.VisibleRect.y2 = v85;
    goto LABEL_223;
  }
  v71 = v56 - 1;
  if ( !v71 )
  {
    Scaleform::Render::Rect<float>::operator=(&v163, &rect);
    goto LABEL_199;
  }
  v72 = v71 - 1;
  if ( !v72 )
  {
    v163.y1 = y2 - v70;
    goto LABEL_199;
  }
  if ( v72 != 1 )
  {
LABEL_199:
    v73 = 0.5;
    goto LABEL_200;
  }
  v73 = 0.5;
  v163.y1 = rect.y1 + v156 * 0.5 - v70 * 0.5;
LABEL_200:
  v62->mLineBuffer.Geom.VisibleRect = v163;
LABEL_223:
  if ( v164.NeedRecenterLines )
  {
    v163.x2 = 0.0;
    x2 = 0.0;
    v87 = v62;
    while ( 1 )
    {
      p_mLineBuffer = &v87->mLineBuffer;
      if ( v87 == (Scaleform::Render::Text::DocView *)-48 || LODWORD(x2) >= v87->mLineBuffer.Lines.Data.Size || x2 < 0.0 )
        goto LABEL_247;
      v89 = (int *)p_mLineBuffer->Lines.Data.Data[LODWORD(x2)];
      v90 = *v89;
      if ( (((unsigned int)*v89 >> 28) & 3) == 1 )
        break;
      if ( (((unsigned int)*v89 >> 28) & 3) == 2 )
      {
        v155 = v87->mLineBuffer.Geom.VisibleRect.x2 - v87->mLineBuffer.Geom.VisibleRect.x1;
        v155 = v155 * v73;
        v91 = v155;
        if ( v155 <= 0.0 )
          v92 = v91 - v73;
        else
          v92 = v91 + v73;
        if ( v90 >= 0 )
          v93 = v89[5];
        else
          v93 = *((unsigned __int16 *)v89 + 10);
        v94 = (int)v92 - v93 / 2;
        v95 = (v94 < 0) - 1;
LABEL_244:
        v87 = pdoc;
        v99 = v94 & v95;
        x2 = v163.x2;
        v89[3] = v99;
      }
      if ( LODWORD(x2) < p_mLineBuffer->Lines.Data.Size )
      {
        ++LODWORD(x2);
        v163.x2 = x2;
      }
    }
    v155 = v87->mLineBuffer.Geom.VisibleRect.x2 - v87->mLineBuffer.Geom.VisibleRect.x1;
    v96 = v155;
    if ( v155 <= 0.0 )
      v97 = v96 - v73;
    else
      v97 = v96 + v73;
    if ( v90 >= 0 )
      v98 = v89[5];
    else
      v98 = *((unsigned __int16 *)v89 + 10);
    v95 = (int)v97 - v98;
    v94 = (v95 < 0) - 1;
    goto LABEL_244;
  }
LABEL_247:
  v100 = pdoc;
  if ( (pdoc->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(pdoc);
    v100->RTFlags &= 0xFCu;
  }
  MaxHScrollValue = Scaleform::Render::Text::DocView::GetMaxHScrollValue(v100);
  v102 = MaxHScrollValue;
  if ( v100->mLineBuffer.Geom.HScrollOffset <= MaxHScrollValue )
  {
    if ( MaxHScrollValue != LODWORD(v157) )
      LOBYTE(v150) = 1;
  }
  else
  {
    if ( (v100->RTFlags & 3) != 0 )
    {
      Scaleform::Render::Text::DocView::Format(v100);
      v100->RTFlags &= 0xFCu;
    }
    v103 = Scaleform::Render::Text::DocView::GetMaxHScrollValue(v100);
    if ( v102 > v103 )
      v102 = v103;
    if ( v100->mLineBuffer.Geom.HScrollOffset != v102 )
    {
      Scaleform::Render::Text::LineBuffer::SetHScrollOffset(&v100->mLineBuffer, v102);
      v104 = v100->pDocumentListener.pObject;
      if ( v104 )
        v104->View_OnHScroll(v104, v100, v102);
    }
  }
  v105 = v100->pDocumentListener.pObject;
  if ( v105 )
  {
    if ( (_BYTE)v150 && (v105->HandlersMask & 4) != 0 )
      v105->View_OnMaxScrollChanged(v105, v100);
    v106 = v100->pDocumentListener.pObject;
    if ( (v106->HandlersMask & 8) != 0 )
      v106->View_OnChanged(v106, v100);
  }
  v107 = v100->pEditorKit.pObject;
  if ( v107 && !v107->IsReadOnly(v107)
    || (TextWidth = (double)v100->TextWidth, v157 = v100->ViewRect.x2 - v100->ViewRect.x1, v157 < TextWidth)
    || (v109 = (double)v100->TextHeight, v157 = v100->ViewRect.y2 - v100->ViewRect.y1, v157 < v109)
    || v100->mLineBuffer.Geom.HScrollOffset )
  {
    v100->mLineBuffer.Geom.Flags &= ~0x20u;
  }
  else
  {
    v100->mLineBuffer.Geom.Flags |= 0x20u;
  }
  if ( v100->pHighlight )
  {
    v110 = v100->pEditorKit.pObject;
    if ( v110 )
      v111 = v110->GetCompositionString(v110);
    else
      v111 = 0;
    Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&v100->pHighlight->HighlightManager, v111);
  }
  v100->RTFlags &= ~0x20u;
  if ( v100->mLineBuffer.Lines.Data.Size )
  {
    Data = v100->mLineBuffer.Lines.Data.Data;
    v113 = *Data;
    if ( ((*Data)->MemSize & 0x80000000) == 0 ? v113->Data32.GlyphsCount : v113->Data8.GlyphsCount )
    {
      v115 = (v113->MemSize & 0x80000000) == 0 ? (int)&v113->Data8 + 38 : (int)(&v113->Data8.Leading + 1);
      if ( (*(_WORD *)(v115 + 6) & 0x2000) != 0
        && (*(_DWORD *)(*(_DWORD *)(Scaleform::Render::Text::LineBuffer::Line::GetFormatData(*Data)->ColorV + 24) + 20)
          & 0x8000) != 0 )
      {
        v100->RTFlags |= 0x20u;
      }
    }
  }
  if ( v164.pDynLine )
    Scaleform::Render::Text::LineBuffer::TextLineAllocator::FreeLine(
      &v164.pDocView->mLineBuffer.LineAllocator,
      v164.pDynLine);
  if ( v164.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.pFontHandle.pObject);
  v116 = v164.WordWrapPoint.CharInfoHolder.pFormat.pObject;
  if ( v164.WordWrapPoint.CharInfoHolder.pFormat.pObject )
  {
    --v164.WordWrapPoint.CharInfoHolder.pFormat.pObject->RefCount;
    v117 = v116;
    if ( !v116->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v116);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v117);
    }
  }
  v118 = v164.WordWrapPoint.CharIter.PlaceHolder.pFormat.pObject;
  if ( v164.WordWrapPoint.CharIter.PlaceHolder.pFormat.pObject )
  {
    --v164.WordWrapPoint.CharIter.PlaceHolder.pFormat.pObject->RefCount;
    v119 = v118;
    if ( !v118->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v118);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v119);
    }
  }
  if ( v164.WordWrapPoint.pComposStr.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.WordWrapPoint.pComposStr.pObject);
  if ( v164.WordWrapPoint.pLastFont.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.WordWrapPoint.pLastFont.pObject);
  v120 = v164.HalfPoint.CharInfoHolder.pFormat.pObject;
  if ( v164.HalfPoint.CharInfoHolder.pFormat.pObject )
  {
    --v164.HalfPoint.CharInfoHolder.pFormat.pObject->RefCount;
    v121 = v120;
    if ( !v120->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v120);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v121);
    }
  }
  v122 = v164.HalfPoint.CharIter.PlaceHolder.pFormat.pObject;
  if ( v164.HalfPoint.CharIter.PlaceHolder.pFormat.pObject )
  {
    --v164.HalfPoint.CharIter.PlaceHolder.pFormat.pObject->RefCount;
    v123 = v122;
    if ( !v122->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v122);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v123);
    }
  }
  if ( v164.HalfPoint.pComposStr.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.HalfPoint.pComposStr.pObject);
  if ( v164.HalfPoint.pLastFont.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.HalfPoint.pLastFont.pObject);
  v124 = v164.StartPoint.CharInfoHolder.pFormat.pObject;
  if ( v164.StartPoint.CharInfoHolder.pFormat.pObject )
  {
    --v164.StartPoint.CharInfoHolder.pFormat.pObject->RefCount;
    v125 = v124;
    if ( !v124->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v124);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v125);
    }
  }
  v126 = v164.StartPoint.CharIter.PlaceHolder.pFormat.pObject;
  if ( v164.StartPoint.CharIter.PlaceHolder.pFormat.pObject )
  {
    --v164.StartPoint.CharIter.PlaceHolder.pFormat.pObject->RefCount;
    v127 = v126;
    if ( !v126->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v126);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v127);
    }
  }
  if ( v164.StartPoint.pComposStr.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.StartPoint.pComposStr.pObject);
  if ( v164.StartPoint.pLastFont.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.StartPoint.pLastFont.pObject);
  if ( v164.FindFontInfo.pCurrentFont.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.FindFontInfo.pCurrentFont.pObject);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,78>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>,Scaleform::HashNode<Scaleform::Render::Text::TextFormat const *,Scaleform::Ptr<Scaleform::Render::Text::FontHandle>,Scaleform::IdentityHash<Scaleform::Render::Text::TextFormat const *>>::NodeHashF>>::Clear(&v164.FontCache.mHash);
  v128 = v164.LineCursor.CharInfoHolder.pFormat.pObject;
  if ( v164.LineCursor.CharInfoHolder.pFormat.pObject )
  {
    --v164.LineCursor.CharInfoHolder.pFormat.pObject->RefCount;
    v129 = v128;
    if ( !v128->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v128);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v129);
    }
  }
  v130 = v164.LineCursor.CharIter.PlaceHolder.pFormat.pObject;
  if ( v164.LineCursor.CharIter.PlaceHolder.pFormat.pObject )
  {
    --v164.LineCursor.CharIter.PlaceHolder.pFormat.pObject->RefCount;
    v131 = v130;
    if ( !v130->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v130);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v131);
    }
  }
  if ( v164.LineCursor.pComposStr.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.LineCursor.pComposStr.pObject);
  if ( v164.LineCursor.pLastFont.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v164.LineCursor.pLastFont.pObject);
}
