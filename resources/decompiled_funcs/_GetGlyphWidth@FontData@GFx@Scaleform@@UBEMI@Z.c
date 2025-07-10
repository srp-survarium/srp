double __thiscall Scaleform::GFx::FontData::GetGlyphWidth(Scaleform::GFx::FontData *this, unsigned int glyphIndex)
{
  double result; // st7
  float w; // [esp+4h] [ebp+4h]

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    this->GetNominalGlyphWidth(this);
  }
  else if ( glyphIndex >= this->AdvanceTable.Data.Size
         || (w = (double)this->AdvanceTable.Data.Data[glyphIndex].Width / 20.0, result = w, w == 0.0) )
  {
    this->GetAdvance(this, glyphIndex);
  }
  return result;
}
