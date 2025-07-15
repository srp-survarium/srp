void __thiscall Scaleform::Render::StrokeScaler::AddVertex(Scaleform::Render::StrokeScaler *this, float x, float y)
{
  double v3; // st7
  Scaleform::Render::Stroker *Str; // ecx
  float v6; // [esp+4h] [ebp-4h]
  float xa; // [esp+Ch] [ebp+4h]
  float xb; // [esp+Ch] [ebp+4h]

  v3 = x;
  Str = this->Str;
  this->LastX = x;
  this->LastY = y;
  xa = y * this->ScaleY;
  v6 = xa;
  xb = v3 * this->ScaleX;
  ((void (__thiscall *)(Scaleform::Render::Stroker *, _DWORD, _DWORD))Str->AddVertex)(Str, LODWORD(xb), LODWORD(v6));
}
