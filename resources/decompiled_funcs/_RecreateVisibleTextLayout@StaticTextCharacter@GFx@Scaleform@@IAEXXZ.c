void __thiscall Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(
        Scaleform::GFx::StaticTextCharacter *this)
{
  Scaleform::Render::TreeText *RenderNode; // edi
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *pHighlight; // ecx
  Scaleform::Render::TextFieldParam params; // [esp+C80h] [ebp-64Ch] BYREF
  Scaleform::Render::TextLayout::Builder b; // [esp+CACh] [ebp-620h] BYREF

  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TextLayout::Builder::Builder(&b, Scaleform::Memory::pGlobalHeap);
  pHighlight = this->pHighlight;
  if ( pHighlight && !pHighlight->HighlightManager.Valid )
  {
    Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(&pHighlight->HighlightManager, 0);
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
  if ( (this->pDef.pObject->Flags & 1) != 0 )
  {
    params.TextParam.Flags |= 3u;
    params.ShadowParam.Flags |= 3u;
  }
  Scaleform::Render::Text::LineBuffer::CreateVisibleTextLayout(
    &this->TextGlyphRecords,
    &b,
    &this->pHighlight->HighlightManager,
    &params);
  b.Bounds.x1 = this->TextGlyphRecords.Geom.VisibleRect.x1;
  b.Bounds.y1 = this->TextGlyphRecords.Geom.VisibleRect.y1;
  b.Bounds.x2 = this->TextGlyphRecords.Geom.VisibleRect.x2;
  b.Bounds.y2 = this->TextGlyphRecords.Geom.VisibleRect.y2;
  Scaleform::Render::TreeText::SetLayout(RenderNode, &b);
  Scaleform::Render::TextLayout::Builder::~Builder(&b);
}
