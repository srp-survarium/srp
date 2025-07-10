bool __thiscall Scaleform::Render::Text::Paragraph::HasNewLine(Scaleform::Render::Text::Paragraph *this)
{
  unsigned int Size; // eax
  wchar_t *pText; // ecx
  unsigned int v3; // edx
  wchar_t *v4; // eax
  wchar_t v5; // ax

  Size = this->Text.Size;
  if ( !Size )
    return 0;
  pText = this->Text.pText;
  v3 = Size - 1;
  if ( pText && v3 < Size )
    v4 = &pText[v3];
  else
    v4 = 0;
  v5 = *v4;
  return v5 == 13 || v5 == 10;
}
