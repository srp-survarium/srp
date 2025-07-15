void __thiscall Scaleform::Render::Rasterizer::LineTo(Scaleform::Render::Rasterizer *this, float x, float y)
{
  int v4; // edi
  int v5; // ebx

  this->LastXf = x;
  this->LastYf = y;
  v4 = (int)(x * 256.0);
  v5 = (int)(256.0 * y);
  Scaleform::Render::Rasterizer::line(this, this->LastX, this->LastY, v4, v5);
  this->LastX = v4;
  this->LastY = v5;
}
