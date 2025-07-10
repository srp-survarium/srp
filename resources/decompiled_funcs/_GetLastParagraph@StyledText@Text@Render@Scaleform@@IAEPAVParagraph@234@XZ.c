Scaleform::Render::Text::Paragraph *__thiscall Scaleform::Render::Text::StyledText::GetLastParagraph(
        Scaleform::Render::Text::StyledText *this)
{
  signed int Size; // edx
  signed int v2; // eax

  Size = this->Paragraphs.Data.Size;
  v2 = Size - 1;
  if ( Size - 1 < 0 || v2 >= Size )
    return 0;
  else
    return this->Paragraphs.Data.Data[v2].pPara;
}
