void __thiscall Scaleform::GFx::StaticTextSnapshotData::SetSelectColor(
        Scaleform::GFx::StaticTextSnapshotData *this,
        const Scaleform::Render::Color *color)
{
  unsigned int v3; // edi
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *pHighlight; // ecx

  v3 = 0;
  for ( this->SelectColor = *color; v3 < this->StaticTextCharRefs.Data.Size; ++v3 )
  {
    pHighlight = this->StaticTextCharRefs.Data.Data[v3].pChar.pObject->pHighlight;
    if ( pHighlight )
      Scaleform::Render::Text::Highlighter::SetSelectColor(&pHighlight->HighlightManager, &this->SelectColor);
  }
}
