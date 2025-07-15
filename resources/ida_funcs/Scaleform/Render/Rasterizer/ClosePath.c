void __thiscall Scaleform::Render::Rasterizer::ClosePath(Scaleform::Render::Rasterizer *this)
{
  int LastX; // eax
  int StartX; // ecx
  int StartY; // eax

  LastX = this->LastX;
  StartX = this->StartX;
  if ( LastX != StartX || this->LastY != this->StartY )
  {
    Scaleform::Render::Rasterizer::line(this, LastX, this->LastY, StartX, this->StartY);
    StartY = this->StartY;
    this->LastX = this->StartX;
    this->LastY = StartY;
  }
}
