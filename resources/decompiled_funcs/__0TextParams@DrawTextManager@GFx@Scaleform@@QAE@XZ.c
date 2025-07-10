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
  Scaleform::String::operator=(p_FontName, "Times New Roman");
  this->Multiline = 1;
  this->WordWrap = 1;
  this->Underline = 0;
}
