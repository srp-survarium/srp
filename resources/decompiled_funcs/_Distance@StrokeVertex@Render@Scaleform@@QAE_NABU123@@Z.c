BOOL __thiscall Scaleform::Render::StrokeVertex::Distance(
        Scaleform::Render::StrokeVertex *this,
        const Scaleform::Render::StrokeVertex *val)
{
  float v3; // [esp+4h] [ebp-4h]
  float vala; // [esp+Ch] [ebp+4h]
  float valb; // [esp+Ch] [ebp+4h]
  float valc; // [esp+Ch] [ebp+4h]

  v3 = val->x - this->x;
  vala = val->y - this->y;
  valb = vala * vala + v3 * v3;
  valc = sqrt(valb);
  this->dist = valc;
  return valc > 0.0;
}
