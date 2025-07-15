void __thiscall Scaleform::Render::Text::DocView::CreateVisibleTextLayout(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::TextLayout::Builder *bld)
{
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // eax
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx
  Scaleform::Render::Text::CompositionStringBase *v5; // eax
  signed __int8 Flags; // cl
  unsigned __int16 v7; // ax
  __int16 v8; // ax
  unsigned __int8 FlagsEx; // cl
  __int16 v10; // ax
  unsigned __int16 v11; // ax
  double Outline; // st7
  Scaleform::Render::Text::EditorKitBase *v14; // ecx
  Scaleform::Render::Text::DocView::HighlightDescLoc *v15; // [esp-8h] [ebp-44h]
  float y2; // [esp+8h] [ebp-34h]
  float x2; // [esp+Ch] [ebp-30h]
  Scaleform::Render::TextFieldParam params; // [esp+10h] [ebp-2Ch] BYREF
  float blda; // [esp+40h] [ebp+4h]

  pHighlight = this->pHighlight;
  if ( pHighlight && !pHighlight->HighlightManager.Valid )
  {
    pObject = this->pEditorKit.pObject;
    if ( pObject )
      v5 = pObject->GetCompositionString(pObject);
    else
      v5 = 0;
    Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&this->pHighlight->HighlightManager, v5);
    this->pHighlight->HighlightManager.Valid = 1;
  }
  params.ShadowOffsetX = 0.0;
  params.ShadowOffsetY = 0.0;
  params.TextParam.BlurStrength = 16;
  memset(&params.ShadowParam, 0, 14);
  params.ShadowColor = 0;
  memset(&params, 0, 14);
  params.ShadowParam.BlurStrength = 16;
  Scaleform::Render::Text::LoadTextFieldParamFromTextFilter(&params, &this->Filter);
  Flags = this->Flags;
  v7 = params.TextParam.Flags;
  if ( (Flags & 0x40) != 0 )
  {
    v7 = params.TextParam.Flags | 1;
    params.ShadowParam.Flags |= 1u;
    params.TextParam.Flags |= 1u;
  }
  if ( Flags < 0 )
  {
    v7 |= 2u;
    params.ShadowParam.Flags |= 2u;
    params.TextParam.Flags = v7;
  }
  if ( (this->RTFlags & 0x20) != 0 )
    v8 = params.TextParam.Flags & 0xFEF8 | 0x101;
  else
    v8 = v7 & 0xFEFF;
  FlagsEx = this->FlagsEx;
  if ( (FlagsEx & 1) != 0 )
    v10 = v8 | 8;
  else
    v10 = v8 & 0xFFF7;
  if ( (FlagsEx & 2) != 0 )
    v11 = v10 | 0x10;
  else
    v11 = v10 & 0xFFEF;
  Outline = this->Outline;
  params.TextParam.Flags = v11;
  v15 = this->pHighlight;
  params.TextParam.Flags = v11 & 0xFFF | ((unsigned __int16)(int)Outline << 12);
  Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(&this->mLineBuffer, bld, &v15->HighlightManager, &params);
  if ( HIBYTE(this->BorderColor) || HIBYTE(this->BackgroundColor) )
    Scaleform::Render::TextLayout::Builder::SetBackground(bld, this->BackgroundColor, this->BorderColor);
  v14 = this->pEditorKit.pObject;
  if ( v14 )
    v14->AddDrawCursorInfo(v14, bld);
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  blda = this->ViewRect.y1;
  x2 = this->ViewRect.x2;
  y2 = this->ViewRect.y2;
  bld->Bounds.x1 = this->ViewRect.x1;
  bld->Bounds.y1 = blda;
  bld->Bounds.x2 = x2;
  bld->Bounds.y2 = y2;
}
