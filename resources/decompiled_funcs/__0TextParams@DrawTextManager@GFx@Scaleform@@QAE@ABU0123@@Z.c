void __thiscall Scaleform::GFx::DrawTextManager::TextParams::TextParams(
        Scaleform::GFx::DrawTextManager::TextParams *this,
        const Scaleform::GFx::DrawTextManager::TextParams *__that)
{
  this->TextColor.Raw = __that->TextColor.Raw;
  this->HAlignment = __that->HAlignment;
  this->VAlignment = __that->VAlignment;
  this->FontStyle = __that->FontStyle;
  this->FontSize = __that->FontSize;
  Scaleform::String::String(&this->FontName, &__that->FontName);
  this->Underline = __that->Underline;
  this->Multiline = __that->Multiline;
  this->WordWrap = __that->WordWrap;
}
