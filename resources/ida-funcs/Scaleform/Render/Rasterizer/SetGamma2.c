void __thiscall Scaleform::Render::Rasterizer::SetGamma2(Scaleform::Render::Rasterizer *this, float g)
{
  Scaleform::Render::Rasterizer::setGamma(this, 1, g);
  this->Gamma2 = g;
}
