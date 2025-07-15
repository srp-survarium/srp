void __thiscall Scaleform::Render::Rasterizer::SetGamma1(Scaleform::Render::Rasterizer *this, float g)
{
  Scaleform::Render::Rasterizer::setGamma(this, 0, g);
  this->Gamma1 = g;
}
