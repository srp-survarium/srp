Scaleform::Render::Text::TextFilter *__thiscall Scaleform::Render::Text::TextFilter::operator=(
        Scaleform::Render::Text::TextFilter *this,
        const Scaleform::Render::Text::TextFilter *__that)
{
  Scaleform::Render::Text::TextFilter *result; // eax
  float __thata; // [esp+4h] [ebp+4h]

  result = this;
  result->BlurX = __that->BlurX;
  result->BlurY = __that->BlurY;
  result->BlurStrength = __that->BlurStrength;
  result->ShadowParams.Mode = __that->ShadowParams.Mode;
  result->ShadowParams.Passes = __that->ShadowParams.Passes;
  result->ShadowParams.BlurX = __that->ShadowParams.BlurX;
  result->ShadowParams.BlurY = __that->ShadowParams.BlurY;
  __thata = __that->ShadowParams.Offset.y;
  result->ShadowParams.Offset.x = __that->ShadowParams.Offset.x;
  result->ShadowParams.Offset.y = __thata;
  result->ShadowParams.Strength = __that->ShadowParams.Strength;
  *(_QWORD *)&result->ShadowParams.Colors[0].Channels.Blue = *(_QWORD *)&__that->ShadowParams.Colors[0].Channels.Blue;
  result->ShadowFlags = __that->ShadowFlags;
  result->ShadowAngle = __that->ShadowAngle;
  result->ShadowDistance = __that->ShadowDistance;
  result->ShadowAlpha = __that->ShadowAlpha;
  return result;
}


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
