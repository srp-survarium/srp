BOOL __thiscall Scaleform::Render::Text::TextFilter::operator==(
        Scaleform::Render::Text::TextFilter *this,
        const Scaleform::Render::Text::TextFilter *f)
{
  return f->BlurX == this->BlurX
      && f->BlurY == this->BlurY
      && f->BlurStrength == this->BlurStrength
      && Scaleform::Render::BlurFilterParams::EqualsAll(&this->ShadowParams, &f->ShadowParams)
      && this->ShadowFlags == f->ShadowFlags
      && this->ShadowAlpha == f->ShadowAlpha
      && f->ShadowAngle == this->ShadowAngle
      && f->ShadowDistance == this->ShadowDistance
      && f->ShadowAngle == this->ShadowAngle;
}
