void __thiscall Scaleform::Render::BlurFilterImpl::SetAngleDistance(
        Scaleform::Render::BlurFilterImpl *this,
        float angle,
        float distance)
{
  float v3; // [esp+0h] [ebp-8h]
  Scaleform::Render::Point<float> v4; // [esp+0h] [ebp-8h]
  float v5; // [esp+Ch] [ebp+4h]

  this->Angle = angle;
  this->Distance = distance;
  v3 = cos(angle);
  v4.x = v3 * distance;
  v5 = sin(angle);
  v4.y = v5 * distance;
  this->Params.Offset = v4;
}
