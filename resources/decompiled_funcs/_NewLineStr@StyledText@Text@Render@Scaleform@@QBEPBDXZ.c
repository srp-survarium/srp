const char *__thiscall Scaleform::Render::Text::StyledText::NewLineStr(Scaleform::Render::Text::StyledText *this)
{
  const char *result; // eax

  result = "\r";
  if ( (this->RTFlags & 2) == 0 )
    return "\n";
  return result;
}
