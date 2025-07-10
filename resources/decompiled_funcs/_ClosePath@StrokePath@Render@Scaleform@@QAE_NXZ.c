bool __thiscall Scaleform::Render::StrokePath::ClosePath(Scaleform::Render::StrokePath *this)
{
  unsigned int Size; // eax
  unsigned int v3; // eax

  Size = this->Path.Size;
  if ( Size <= 1
    || Scaleform::Render::StrokeVertex::Distance(
         &this->Path.Pages[(Size - 1) >> 4][(Size - 1) & 0xF],
         *(const Scaleform::Render::StrokeVertex **)this->Path.Pages) )
  {
    return 0;
  }
  v3 = this->Path.Size;
  if ( v3 )
    this->Path.Size = v3 - 1;
  return this->Path.Size > 2;
}
