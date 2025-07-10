unsigned int __thiscall Scaleform::Render::Text::Paragraph::GetLength(Scaleform::Render::Text::Paragraph *this)
{
  unsigned int result; // eax
  wchar_t *pText; // ecx
  unsigned int v3; // edx
  wchar_t *v4; // ecx

  result = this->Text.Size;
  if ( result )
  {
    pText = this->Text.pText;
    v3 = result - 1;
    if ( pText && v3 < result )
      v4 = &pText[v3];
    else
      v4 = 0;
    if ( !*v4 )
      --result;
  }
  return result;
}
