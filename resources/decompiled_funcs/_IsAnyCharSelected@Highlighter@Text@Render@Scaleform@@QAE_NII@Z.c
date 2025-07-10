char __thiscall Scaleform::Render::Text::Highlighter::IsAnyCharSelected(
        Scaleform::Render::Text::Highlighter *this,
        unsigned int selectStart,
        unsigned int selectEnd)
{
  unsigned int Size; // edi
  int v4; // edx
  Scaleform::Render::Text::HighlightDesc *i; // ecx
  unsigned int StartPos; // eax

  Size = this->Highlighters.Data.Size;
  v4 = 0;
  if ( !Size )
    return 0;
  for ( i = this->Highlighters.Data.Data; ; ++i )
  {
    StartPos = i->StartPos;
    if ( i->StartPos > selectStart )
      goto LABEL_6;
    if ( selectStart < StartPos + i->Length )
      return 1;
    if ( StartPos >= selectStart )
    {
LABEL_6:
      if ( StartPos < selectEnd )
        break;
    }
    if ( ++v4 >= Size )
      return 0;
  }
  return 1;
}
