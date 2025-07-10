void __thiscall Scaleform::Render::Stroker::ClosePath(Scaleform::Render::Stroker *this)
{
  unsigned int Size; // eax
  unsigned int v3; // eax

  Size = this->Path.Path.Size;
  if ( Size > 1
    && !Scaleform::Render::StrokeVertex::Distance(
          &this->Path.Path.Pages[(Size - 1) >> 4][(Size - 1) & 0xF],
          *(const Scaleform::Render::StrokeVertex **)this->Path.Path.Pages) )
  {
    v3 = this->Path.Path.Size;
    if ( v3 )
      this->Path.Path.Size = v3 - 1;
  }
  this->Closed = 1;
}
