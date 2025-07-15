int __thiscall Scaleform::Render::Text::ParagraphFormat::IsLeftAlignment(
        Scaleform::Render::Text::ParagraphFormat *this)
{
  int result; // eax

  result = 1;
  if ( (this->PresentMask & 1) == 0 || (this->PresentMask & 0x600) != 0 )
    return 0;
  return result;
}
