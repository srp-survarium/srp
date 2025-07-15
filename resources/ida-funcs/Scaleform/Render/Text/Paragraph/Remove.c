void __thiscall Scaleform::Render::Text::Paragraph::Remove(
        Scaleform::Render::Text::Paragraph *this,
        unsigned int startPos,
        unsigned int endPos)
{
  unsigned int v4; // ebx
  unsigned int Size; // eax

  if ( endPos == -1 )
  {
    v4 = -1;
  }
  else
  {
    v4 = endPos - startPos;
    if ( endPos == startPos )
      return;
  }
  Size = this->Text.Size;
  if ( startPos < Size )
  {
    if ( v4 + startPos < Size )
    {
      memmove(
        (unsigned __int8 *)&this->Text.pText[startPos],
        (unsigned __int8 *)&this->Text.pText[v4 + startPos],
        2 * (Size - v4 - startPos));
      this->Text.Size -= v4;
    }
    else
    {
      this->Text.Size = startPos;
    }
  }
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
    &this->FormatInfo,
    startPos,
    v4);
  Scaleform::Render::Text::Paragraph::SetTermNullFormat(this);
  ++this->ModCounter;
}
