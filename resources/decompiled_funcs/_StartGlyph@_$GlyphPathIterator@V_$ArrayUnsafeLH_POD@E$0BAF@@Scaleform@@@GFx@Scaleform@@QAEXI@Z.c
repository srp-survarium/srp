void __thiscall Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::StartGlyph(
        Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int pos)
{
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax

  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(this, pos);
  v3 = &this->Data.Data->Data[this->Pos];
  v4 = *v3;
  if ( (v4 & 1) != 0 )
  {
    this->NumContours = (v4 >> 1) | (v3[1] << 7);
    this->Pos += 2;
  }
  else
  {
    this->NumContours = v4 >> 1;
    ++this->Pos;
  }
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::readPathHeader(this);
}
