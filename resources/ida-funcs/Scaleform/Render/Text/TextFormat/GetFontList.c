Scaleform::StringDH *__thiscall Scaleform::Render::Text::TextFormat::GetFontList(
        Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::StringDH *result; // eax

  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    Scaleform::String::String(&emptyStr);
    atexit(Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
  }
  result = &this->FontList;
  if ( (this->PresentMask & 4) == 0 )
    return (Scaleform::StringDH *)&emptyStr;
  return result;
}
