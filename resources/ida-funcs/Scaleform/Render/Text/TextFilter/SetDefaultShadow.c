void __thiscall Scaleform::Render::Text::TextFilter::SetDefaultShadow(Scaleform::Render::Text::TextFilter *this)
{
  this->BlurX = 0.0;
  this->ShadowParams.Mode = 0;
  this->BlurY = 0.0;
  this->BlurStrength = 1.0;
  this->ShadowParams.BlurX = 0.0;
  this->ShadowParams.BlurY = 0.0;
  this->ShadowParams.Strength = 1.0;
  this->ShadowParams.Colors[0].Raw = 0;
  this->ShadowFlags = 128;
  this->ShadowAngle = 0.78539819;
  this->ShadowAlpha = -1;
  this->ShadowDistance = 4.0;
  Scaleform::Render::Text::TextFilter::UpdateShadowOffset(this);
}
