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


void __thiscall Scaleform::GFx::DrawTextManager::TextParams::TextParams(
        Scaleform::GFx::DrawTextManager::TextParams *this)
{
  Scaleform::String *p_FontName; // edi

  p_FontName = &this->FontName;
  Scaleform::String::String(&this->FontName);
  this->FontSize = 12.0;
  this->TextColor.Raw = -16777216;
  this->HAlignment = Align_Center;
  this->VAlignment = VAlign_Top;
  this->FontStyle = Normal;
  Scaleform::String::operator=(p_FontName, (const __m128i *)"Times New Roman");
  this->Multiline = 1;
  this->WordWrap = 1;
  this->Underline = 0;
}
