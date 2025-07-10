int __thiscall Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(Scaleform::Render::Text::LineBuffer *this)
{
  signed int FirstVisibleLinePos; // edx
  int result; // eax
  unsigned int Size; // esi

  FirstVisibleLinePos = this->Geom.FirstVisibleLinePos;
  result = 0;
  if ( FirstVisibleLinePos )
  {
    Size = this->Lines.Data.Size;
    if ( FirstVisibleLinePos < Size && FirstVisibleLinePos >= 0 )
    {
      if ( Size )
        return this->Lines.Data.Data[FirstVisibleLinePos]->Data32.OffsetY - (*this->Lines.Data.Data)->Data32.OffsetY;
    }
  }
  return result;
}
