double __thiscall Scaleform::Render::FocalRadialGradient::Calculate(
        Scaleform::Render::FocalRadialGradient *this,
        float x,
        float y)
{
  float d2; // [esp+0h] [ebp-4h]
  float d2a; // [esp+0h] [ebp-4h]
  float d2b; // [esp+0h] [ebp-4h]
  float d2c; // [esp+0h] [ebp-4h]
  float xa; // [esp+8h] [ebp+4h]
  float dy; // [esp+Ch] [ebp+8h]

  xa = x - this->FocusX;
  dy = y - this->FocusY;
  d2 = xa * this->FocusY - this->FocusX * dy;
  d2a = (xa * xa + dy * dy) * this->Radius2 - d2 * d2;
  d2b = fabs(d2a);
  d2c = sqrt(d2b);
  return (float)((d2c + this->FocusX * xa + dy * this->FocusY) * this->Multiplier);
}
