int __thiscall Scaleform::Render::Text::ParagraphFormat::IsCenterAlignment(
        Scaleform::Render::Text::ParagraphFormat *this)
{
  int result; // eax

  result = 1;
  if ( (this->PresentMask & 1) == 0 || (this->PresentMask & 0x600) != 0x600 )
    return 0;
  return result;
}
