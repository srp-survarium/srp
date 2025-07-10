void __thiscall Scaleform::Render::Rasterizer::MoveTo(Scaleform::Render::Rasterizer *this, float x, float y)
{
  int v3; // eax
  int v4; // eax

  this->LastXf = x;
  this->LastYf = y;
  v3 = (int)(x * 256.0);
  this->LastX = v3;
  this->StartX = v3;
  v4 = (int)(256.0 * y);
  this->LastY = v4;
  this->StartY = v4;
}
