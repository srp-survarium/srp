BOOL __thiscall Scaleform::Render::StrokeVertex::Distance(
        Scaleform::Render::StrokeVertex *this,
        const Scaleform::Render::StrokeVertex *val)
{
  float v3; // [esp+4h] [ebp-4h]
  float v4; // [esp+Ch] [ebp+4h]
  float v5; // [esp+Ch] [ebp+4h]
  float v6; // [esp+Ch] [ebp+4h]

  v3 = val->x - this->x;
  v4 = val->y - this->y;
  v5 = v4 * v4 + v3 * v3;
  v6 = sqrt(v5);
  this->dist = v6;
  return v6 > 0.0;
}
