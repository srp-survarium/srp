double __thiscall Scaleform::GFx::FontData::GetGlyphHeight(Scaleform::GFx::FontData *this, unsigned int glyphIndex)
{
  unsigned int Size; // edx
  double result; // st7

  if ( (unsigned __int16)glyphIndex == 0xFFFF || (Size = this->AdvanceTable.Data.Size) == 0 )
  {
    this->GetNominalGlyphHeight(this);
  }
  else if ( glyphIndex >= Size )
  {
    return 0.0;
  }
  else
  {
    return (float)((double)this->AdvanceTable.Data.Data[glyphIndex].Height / 20.0);
  }
  return result;
}
