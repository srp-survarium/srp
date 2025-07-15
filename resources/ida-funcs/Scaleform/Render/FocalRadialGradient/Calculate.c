double __thiscall Scaleform::Render::FocalRadialGradient::Calculate(
        Scaleform::Render::FocalRadialGradient *this,
        float x,
        float y)
{
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+0h] [ebp-4h]
  float v7; // [esp+0h] [ebp-4h]
  float v8; // [esp+8h] [ebp+4h]
  float v10; // [esp+Ch] [ebp+8h]

  v8 = x - this->FocusX;
  v10 = y - this->FocusY;
  v4 = v8 * this->FocusY - this->FocusX * v10;
  v5 = (v8 * v8 + v10 * v10) * this->Radius2 - v4 * v4;
  v6 = fabs(v5);
  v7 = sqrt(v6);
  return (float)((v7 + this->FocusX * v8 + v10 * this->FocusY) * this->Multiplier);
}
