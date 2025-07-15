void __thiscall Scaleform::Render::Text::TextFilter::UpdateShadowOffset(Scaleform::Render::Text::TextFilter *this)
{
  float ShadowAngle; // [esp+4h] [ebp-14h]
  float ShadowDistance; // [esp+8h] [ebp-10h]
  float v3; // [esp+Ch] [ebp-Ch]
  float v4; // [esp+Ch] [ebp-Ch]
  Scaleform::Render::Point<float> v5; // [esp+10h] [ebp-8h]

  ShadowAngle = this->ShadowAngle;
  ShadowDistance = this->ShadowDistance;
  v3 = cos(ShadowAngle);
  v5.x = v3 * ShadowDistance;
  v4 = sin(ShadowAngle);
  v5.y = v4 * ShadowDistance;
  this->ShadowParams.Offset = v5;
}
