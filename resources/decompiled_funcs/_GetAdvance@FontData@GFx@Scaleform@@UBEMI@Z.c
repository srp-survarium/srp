double __thiscall Scaleform::GFx::FontData::GetAdvance(Scaleform::GFx::FontData *this, unsigned int glyphIndex)
{
  unsigned int Size; // eax
  double result; // st7

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    goto LABEL_5;
  Size = this->AdvanceTable.Data.Size;
  if ( !Size )
  {
    if ( !Logged )
      Logged = 1;
LABEL_5:
    this->GetNominalGlyphWidth(this);
    return result;
  }
  if ( glyphIndex >= Size )
    return 0.0;
  else
    return this->AdvanceTable.Data.Data[glyphIndex].Advance;
}
