void __thiscall Scaleform::Render::Text::LineBuffer::GlyphEntry::SetAdvance(
        Scaleform::Render::Text::LineBuffer::GlyphEntry *this,
        int v)
{
  if ( v < 0 )
  {
    this->Flags |= 0x40u;
    this->Advance = -(__int16)v;
  }
  else
  {
    this->Advance = v;
    this->Flags &= ~0x40u;
  }
}
