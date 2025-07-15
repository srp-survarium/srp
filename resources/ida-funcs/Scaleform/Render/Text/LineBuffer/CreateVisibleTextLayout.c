void __thiscall Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(
        Scaleform::Render::Text::LineBuffer *this,
        Scaleform::Render::TextLayout::Builder *bld,
        Scaleform::Render::Text::Highlighter *phighlighter,
        const Scaleform::Render::TextFieldParam *textFieldParam)
{
  signed int FirstVisibleLinePos; // eax
  int v6; // ecx
  unsigned int Size; // edx
  double v8; // st7
  char v9; // al
  unsigned __int8 Flags; // al
  Scaleform::Render::TextLayout::Builder *v11; // ebx
  unsigned int v12; // esi
  Scaleform::Render::Text::LineBuffer *v13; // ecx
  Scaleform::Render::Text::LineBuffer::Line *v14; // esi
  int MemSize; // eax
  double ScreenWidth; // st7
  int v17; // eax
  bool v18; // al
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // ecx
  unsigned __int16 v20; // dx
  int Advance; // eax
  Scaleform::Render::Text::ImageDesc *pObject; // esi
  Scaleform::Render::Font *v23; // edi
  int v24; // eax
  double v25; // st6
  double v26; // st7
  double v27; // st6
  Scaleform::Render::Image *v28; // edi
  double v29; // st7
  double v30; // st6
  unsigned int ColorV; // esi
  Scaleform::Render::TextUnderlineStyle v32; // eax
  Scaleform::Render::Text::LineBuffer::Line *v33; // ebx
  bool v34; // cl
  unsigned int v35; // eax
  unsigned int Delta; // eax
  Scaleform::Render::TextUnderlineStyle v37; // eax
  Scaleform::Render::Text::LineBuffer *v38; // esi
  float scaleX; // [esp+Ch] [ebp-190h]
  float scaleXa; // [esp+Ch] [ebp-190h]
  float scaleXb; // [esp+Ch] [ebp-190h]
  float scaleY; // [esp+10h] [ebp-18Ch]
  float scaleYa; // [esp+10h] [ebp-18Ch]
  float scaleYb; // [esp+10h] [ebp-18Ch]
  float y; // [esp+18h] [ebp-184h]
  bool HasUnderlineHighlight; // [esp+33h] [ebp-169h]
  float y2; // [esp+34h] [ebp-168h]
  float v48; // [esp+34h] [ebp-168h]
  float v49; // [esp+34h] [ebp-168h]
  float v50; // [esp+34h] [ebp-168h]
  float v51; // [esp+34h] [ebp-168h]
  float v52; // [esp+34h] [ebp-168h]
  float v53; // [esp+34h] [ebp-168h]
  unsigned int Height; // [esp+34h] [ebp-168h]
  float v55; // [esp+34h] [ebp-168h]
  float v56; // [esp+34h] [ebp-168h]
  char v57; // [esp+43h] [ebp-159h]
  signed int OffsetY; // [esp+44h] [ebp-158h]
  float v59; // [esp+44h] [ebp-158h]
  unsigned int v60; // [esp+44h] [ebp-158h]
  float v61; // [esp+48h] [ebp-154h]
  float v62; // [esp+48h] [ebp-154h]
  float v63; // [esp+48h] [ebp-154h]
  float y1; // [esp+48h] [ebp-154h]
  float x1; // [esp+4Ch] [ebp-150h]
  int BaseLineOffset; // [esp+4Ch] [ebp-150h]
  int v67; // [esp+4Ch] [ebp-150h]
  float v68; // [esp+4Ch] [ebp-150h]
  char v69; // [esp+53h] [ebp-149h]
  Scaleform::Render::Text::LineBuffer *v70; // [esp+54h] [ebp-148h]
  signed int glyphIndex; // [esp+58h] [ebp-144h]
  unsigned int glyphIndexa; // [esp+58h] [ebp-144h]
  int v73; // [esp+5Ch] [ebp-140h]
  float OffsetX; // [esp+60h] [ebp-13Ch]
  float v75; // [esp+60h] [ebp-13Ch]
  float v76; // [esp+64h] [ebp-138h]
  float v77; // [esp+64h] [ebp-138h]
  float v78; // [esp+64h] [ebp-138h]
  float v79; // [esp+68h] [ebp-134h]
  float x; // [esp+68h] [ebp-134h]
  float v81; // [esp+68h] [ebp-134h]
  unsigned int color; // [esp+6Ch] [ebp-130h]
  Scaleform::Render::Text::HighlightInfo::UnderlineStyle UnderlineStyle; // [esp+70h] [ebp-12Ch]
  int v84; // [esp+74h] [ebp-128h]
  float v85; // [esp+78h] [ebp-124h]
  Scaleform::Render::Rect<float> v86; // [esp+7Ch] [ebp-120h] BYREF
  float v87; // [esp+90h] [ebp-10Ch]
  float v88; // [esp+94h] [ebp-108h]
  float v89; // [esp+98h] [ebp-104h]
  float v90; // [esp+9Ch] [ebp-100h]
  float v91; // [esp+A0h] [ebp-FCh]
  float v92; // [esp+A4h] [ebp-F8h]
  float v93; // [esp+A8h] [ebp-F4h]
  double v94; // [esp+ACh] [ebp-F0h]
  Scaleform::Render::Font *v95; // [esp+B8h] [ebp-E4h]
  unsigned int v96; // [esp+BCh] [ebp-E0h]
  unsigned __int16 *p_Flags; // [esp+C0h] [ebp-DCh]
  Scaleform::Render::Text::LineBuffer::Line *v98[2]; // [esp+C4h] [ebp-D8h]
  double v99; // [esp+CCh] [ebp-D0h]
  Scaleform::Render::Text::LineBuffer::GlyphIterator result; // [esp+D4h] [ebp-C8h] BYREF
  signed int v101; // [esp+140h] [ebp-5Ch]
  float v102; // [esp+148h] [ebp-54h]
  Scaleform::Render::Rect<float> r; // [esp+14Ch] [ebp-50h] BYREF
  float v104[6]; // [esp+15Ch] [ebp-40h] BYREF
  float HScrollOffset; // [esp+174h] [ebp-28h]
  float v106; // [esp+17Ch] [ebp-20h]
  float v107; // [esp+184h] [ebp-18h]
  float v108; // [esp+190h] [ebp-Ch]
  float v109; // [esp+194h] [ebp-8h]

  FirstVisibleLinePos = this->Geom.FirstVisibleLinePos;
  v6 = 0;
  v70 = this;
  if ( FirstVisibleLinePos )
  {
    Size = this->Lines.Data.Size;
    if ( FirstVisibleLinePos < Size && FirstVisibleLinePos >= 0 && Size )
      v6 = this->Lines.Data.Data[FirstVisibleLinePos]->Data32.OffsetY - (*this->Lines.Data.Data)->Data32.OffsetY;
  }
  v101 = FirstVisibleLinePos;
  v87 = -(double)(unsigned int)v6;
  v8 = 0.0;
  v9 = this->Geom.Flags >> 2;
  v104[0] = 0.0;
  v104[1] = 0.0;
  v104[2] = 0.0;
  LOBYTE(v102) = v9 & 1;
  v104[3] = 0.0;
  HasUnderlineHighlight = 0;
  if ( phighlighter )
  {
    v8 = 0.0;
    HasUnderlineHighlight = Scaleform::Render::Text::Highlighter::HasUnderlineHighlight(phighlighter);
  }
  Flags = this->Geom.Flags;
  *(float *)&v98[1] = v8;
  v96 = 0;
  v95 = 0;
  v11 = bld;
  if ( (Flags & 0x24) != 0 || !Scaleform::Render::Text::LineBuffer::IsPartiallyVisible(this, v87) )
  {
    v57 = 0;
  }
  else
  {
    Scaleform::Render::TextLayout::Builder::SetClipBox(bld, &this->Geom.VisibleRect);
    v57 = 1;
  }
LABEL_12:
  v12 = v101;
  v13 = v70;
  if ( v101 < v70->Lines.Data.Size
    && v101 >= 0
    && (LOBYTE(v102) || Scaleform::Render::Text::LineBuffer::IsLineVisible(v70, v101, v87)) )
  {
    v14 = v13->Lines.Data.Data[v12];
    MemSize = v14->MemSize;
    OffsetY = v14->Data32.OffsetY;
    OffsetX = (float)v14->Data32.OffsetX;
    v98[0] = v14;
    v76 = (float)OffsetY;
    x1 = v13->Geom.VisibleRect.x1;
    *(float *)&v94 = v13->Geom.VisibleRect.y1;
    v75 = x1 + OffsetX;
    v77 = *(float *)&v94 + v76;
    if ( MemSize >= 0 )
      BaseLineOffset = v14->Data32.BaseLineOffset;
    else
      BaseLineOffset = v14->Data8.BaseLineOffset;
    v59 = (float)BaseLineOffset;
    v78 = v59 + v87 + v77;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v14, &result, phighlighter);
    ScreenWidth = 0.0;
    v69 = 1;
    v86.x1 = 0.0;
    v60 = 0;
    v86.y1 = 0.0;
    UnderlineStyle = Underline_None;
    v86.x2 = 0.0;
    color = 0;
    v86.y2 = 0.0;
    v84 = 0;
    v17 = v14->MemSize;
    v88 = 0.0;
    v89 = 0.0;
    v18 = v17 < 0;
    if ( v18 )
      glyphIndex = v14->Data8.Height;
    else
      glyphIndex = v14->Data32.Height;
    if ( v18 )
      v67 = v14->Data8.BaseLineOffset;
    else
      v67 = v14->Data32.BaseLineOffset;
    pGlyphs = result.pGlyphs;
    v61 = (float)v67;
    v68 = (double)glyphIndex - v61;
    while ( 1 )
    {
      if ( !pGlyphs || pGlyphs >= result.pEndGlyphs )
      {
LABEL_110:
        if ( color )
        {
          switch ( UnderlineStyle )
          {
            case Underline_Thick:
              v37 = TextUnderline_Thick;
              break;
            case Underline_Dotted:
              v37 = TextUnderline_Dotted;
              break;
            case Underline_DottedThick:
              v37 = TextUnderline_DottedThick;
              break;
            case Underline_DitheredSingle:
              v37 = TextUnderline_Dithered;
              break;
            case Underline_DitheredThick:
              v37 = TextUnderline_DitheredThick;
              break;
            default:
              v37 = TextUnderline_Single;
              break;
          }
          v38 = v70;
          v55 = v68 * 0.5 + v89;
          scaleXb = v55;
          v56 = v88 - (double)v70->Geom.HScrollOffset;
          scaleYb = (float)v84;
          Scaleform::Render::TextLayout::Builder::AddUnderline(v11, v56, scaleXb, scaleYb, v37, color);
        }
        else
        {
          v38 = v70;
        }
        if ( v60 )
        {
          HScrollOffset = (float)v38->Geom.HScrollOffset;
          v106 = -HScrollOffset;
          v86.x1 = v106 + v86.x1;
          v86.x2 = v106 + v86.x2;
          v86.y1 = v86.y1 + -0.0;
          v86.y2 = v86.y2 + -0.0;
          Scaleform::Render::TextLayout::Builder::AddSelection(v11, &v86, v60);
        }
        if ( result.pImage.pObject )
          Scaleform::RefCountNTSImpl::Release(result.pImage.pObject);
        if ( result.pFontHandle.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pFontHandle.pObject);
        if ( v101 < v38->Lines.Data.Size )
          ++v101;
        goto LABEL_12;
      }
      v20 = pGlyphs->Flags;
      p_Flags = &pGlyphs->Flags;
      Advance = pGlyphs->Advance;
      if ( (v20 & 0x40) != 0 )
        Advance = -Advance;
      v73 = Advance;
      if ( pGlyphs->Index == 0xFFFF )
        glyphIndexa = -1;
      else
        glyphIndexa = pGlyphs->Index;
      pObject = 0;
      v85 = -1.0;
      v23 = 0;
      LODWORD(v94) = result.SelectionColor;
      if ( result.pImage.pObject )
      {
        pObject = result.pImage.pObject;
        ScreenWidth = result.pImage.pObject->ScreenWidth;
      }
      else
      {
        v24 = pGlyphs->LenAndFontSize & 0xFFF;
        if ( (v20 & 0x10) != 0 )
          v25 = (double)(unsigned int)v24 * 0.0625;
        else
          v25 = (double)(unsigned int)v24;
        v62 = v25;
        v85 = v62 * 20.0;
        if ( result.pFontHandle.pObject )
          v23 = result.pFontHandle.pObject->pFont.pObject;
        else
          v23 = 0;
        if ( (v70->Geom.Flags & 4) == 0 )
        {
          v79 = v85 * 0.0009765625;
          ScreenWidth = v23->GetGlyphBounds(v23, glyphIndexa, (Scaleform::Render::Rect<float> *)v104)->x2 * v79;
          pGlyphs = result.pGlyphs;
        }
      }
      v63 = ScreenWidth;
      x = v75 - (double)v70->Geom.HScrollOffset;
      v26 = v63;
      v27 = x;
      if ( (v70->Geom.Flags & 4) == 0 )
      {
        if ( glyphIndexa != -1 && v70->Geom.VisibleRect.x1 >= v27 + v26 )
          goto LABEL_100;
        v11 = bld;
        if ( (int)v27 >= (int)v70->Geom.VisibleRect.x2 )
          goto LABEL_110;
      }
      if ( result.UnderlineStyle )
      {
        if ( (*((_BYTE *)p_Flags + 1) & 1) == 0 )
          HasUnderlineHighlight = 1;
      }
      else
      {
        HasUnderlineHighlight = 0;
      }
      if ( v69 )
      {
        Scaleform::Render::TextLayout::Builder::SetNewLine(v11, x, v78);
        v26 = v63;
        v69 = 0;
        v27 = x;
      }
      if ( !v57
        && (v70->Geom.Flags & 0x24) == 0
        && (v70->Geom.VisibleRect.x1 > v27 && v70->Geom.VisibleRect.x1 < v27 + v26
         || v70->Geom.VisibleRect.x2 > v27 && v70->Geom.VisibleRect.x2 < v26 + v27) )
      {
        v57 = 1;
        v81 = v70->Geom.VisibleRect.x1;
        y1 = v70->Geom.VisibleRect.y1;
        *(float *)&v99 = v70->Geom.VisibleRect.x2;
        y2 = v70->Geom.VisibleRect.y2;
        v11->ClipBox.x1 = v81;
        v11->ClipBox.y1 = y1;
        v11->ClipBox.x2 = *(float *)&v99;
        v11->ClipBox.y2 = y2;
      }
      if ( pObject )
      {
        v28 = pObject->pImage.pObject;
        if ( v28 )
        {
          v29 = pObject->Matrix.M[1][1];
          v30 = pObject->Matrix.M[0][1];
          v94 = pObject->Matrix.M[1][0];
          v99 = pObject->Matrix.M[0][0];
          y = (float)v73;
          v48 = v29 * v29 + v30 * v30;
          v49 = sqrt(v48);
          scaleY = v49;
          v50 = v99 * v99 + v94 * v94;
          v51 = sqrt(v50);
          Scaleform::Render::TextLayout::Builder::AddImage(v11, v28, v51, scaleY, pObject->BaseLineY, y);
        }
        else
        {
          Scaleform::LogDebugMessage(
            (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
            "An image in TextLayout is NULL");
        }
        pGlyphs = result.pGlyphs;
      }
      else
      {
        ColorV = result.ColorV;
        if ( result.ColorV != v96 )
          Scaleform::Render::TextLayout::Builder::ChangeColor(v11, result.ColorV);
        if ( v23 != v95 || *(float *)&v98[1] != v85 )
        {
          Scaleform::Render::TextLayout::Builder::ChangeFont(v11, v23, v85);
          Scaleform::Render::TextLayout::Builder::AddRefCntData(v11, result.pFontHandle.pObject);
        }
        if ( color == result.UnderlineColor && UnderlineStyle == result.UnderlineStyle )
        {
          if ( result.UnderlineColor )
            v84 += v73;
        }
        else
        {
          if ( color )
          {
            switch ( UnderlineStyle )
            {
              case Underline_Thick:
                v32 = TextUnderline_Thick;
                break;
              case Underline_Dotted:
                v32 = TextUnderline_Dotted;
                break;
              case Underline_DottedThick:
                v32 = TextUnderline_DottedThick;
                break;
              case Underline_DitheredSingle:
                v32 = TextUnderline_Dithered;
                break;
              case Underline_DitheredThick:
                v32 = TextUnderline_DitheredThick;
                break;
              default:
                v32 = TextUnderline_Single;
                break;
            }
            v52 = v68 * 0.5 + v89;
            scaleX = v52;
            v53 = v88 - (double)v70->Geom.HScrollOffset;
            scaleYa = (float)v84;
            Scaleform::Render::TextLayout::Builder::AddUnderline(v11, v53, scaleX, scaleYa, v32, color);
          }
          v88 = v75;
          v84 = v73;
          v89 = v78;
        }
        if ( result.SelectionColor || v60 )
        {
          v33 = v98[0];
          v92 = (float)v73;
          Height = Scaleform::Render::Text::LineBuffer::Line::GetHeight(v98[0]);
          v93 = (float)(int)(Scaleform::Render::Text::LineBuffer::Line::GetNonNegLeading(v33) + Height);
          v108 = v78 - Scaleform::Render::Text::LineBuffer::Line::GetBaseLineOffset(v33);
          v90 = v75 + 0.0;
          v92 = v75 + v92;
          v91 = v108 + 0.0;
          v93 = v108 + v93;
          if ( LODWORD(v94) == v60 )
          {
            if ( LODWORD(v94) )
              Scaleform::Render::Rect<float>::Union(&v86, v90, v91, v92, v93);
            v11 = bld;
          }
          else
          {
            if ( v60 )
            {
              v107 = (float)v70->Geom.HScrollOffset;
              v11 = bld;
              v109 = -v107;
              r.x1 = v109 + v86.x1;
              r.x2 = v109 + v86.x2;
              r.y1 = v86.y1 + -0.0;
              r.y2 = v86.y2 + -0.0;
              Scaleform::Render::TextLayout::Builder::AddSelection(bld, &r, v60);
            }
            else
            {
              v11 = bld;
            }
            v86.x1 = v90;
            v86.y1 = v91;
            v86.x2 = v92;
            v86.y2 = v93;
          }
        }
        if ( result.pFontHandle.pObject )
        {
          v34 = result.pFontHandle.pObject->OverridenFontFlags & 1;
          v35 = (result.pFontHandle.pObject->OverridenFontFlags >> 1) & 0xFFFFFF01;
        }
        else
        {
          v34 = 0;
          LOBYTE(v35) = 0;
        }
        scaleXa = (float)v73;
        Scaleform::Render::TextLayout::Builder::AddChar(v11, glyphIndexa, scaleXa, (*p_Flags & 0x200) != 0, v35, v34);
        *(float *)&v98[1] = v85;
        v60 = LODWORD(v94);
        pGlyphs = result.pGlyphs;
        v96 = ColorV;
        v95 = v23;
        if ( HasUnderlineHighlight )
        {
          color = result.UnderlineColor;
          UnderlineStyle = result.UnderlineStyle;
        }
        else
        {
          color = 0;
          UnderlineStyle = Underline_None;
        }
      }
LABEL_100:
      if ( pGlyphs && pGlyphs < result.pEndGlyphs )
      {
        Delta = result.Delta;
        if ( !result.Delta )
        {
          Delta = pGlyphs->LenAndFontSize >> 12;
          result.Delta = Delta;
        }
        result.pGlyphs = pGlyphs + 1;
        if ( (pGlyphs[1].LenAndFontSize & 0xF000) != 0
          && Delta
          && !Scaleform::Render::Text::HighlighterPosIterator::IsFinished(&result.HighlighterIter) )
        {
          Scaleform::Render::Text::HighlighterPosIterator::operator+=(&result.HighlighterIter, result.Delta);
          result.Delta = 0;
        }
        Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(&result);
        pGlyphs = result.pGlyphs;
      }
      v75 = (double)v73 + v75;
      ScreenWidth = 0.0;
    }
  }
  qmemcpy(v11, textFieldParam, 0x2Cu);
}
