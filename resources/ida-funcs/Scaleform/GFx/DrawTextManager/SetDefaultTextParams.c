void __thiscall Scaleform::GFx::DrawTextManager::SetDefaultTextParams(
        Scaleform::GFx::DrawTextManager *this,
        const Scaleform::GFx::DrawTextManager::TextParams *params)
{
  Scaleform::GFx::DrawTextManager::TextParams *p_DefaultTextParams; // esi

  p_DefaultTextParams = &this->pImpl->DefaultTextParams;
  p_DefaultTextParams->TextColor.Raw = params->TextColor.Raw;
  p_DefaultTextParams->HAlignment = params->HAlignment;
  p_DefaultTextParams->VAlignment = params->VAlignment;
  p_DefaultTextParams->FontStyle = params->FontStyle;
  p_DefaultTextParams->FontSize = params->FontSize;
  Scaleform::String::operator=(&p_DefaultTextParams->FontName, &params->FontName);
  p_DefaultTextParams->Underline = params->Underline;
  p_DefaultTextParams->Multiline = params->Multiline;
  p_DefaultTextParams->WordWrap = params->WordWrap;
}
