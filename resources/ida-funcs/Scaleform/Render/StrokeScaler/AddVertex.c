void __thiscall Scaleform::Render::StrokeScaler::AddVertex(Scaleform::Render::StrokeScaler *this, float x, float y)
{
  double v3; // st7
  Scaleform::Render::Stroker *Str; // ecx
  float v6; // [esp+4h] [ebp-4h]
  float v7; // [esp+Ch] [ebp+4h]
  float v8; // [esp+Ch] [ebp+4h]

  v3 = x;
  Str = this->Str;
  this->LastX = x;
  this->LastY = y;
  v7 = y * this->ScaleY;
  v6 = v7;
  v8 = v3 * this->ScaleX;
  ((void (__thiscall *)(Scaleform::Render::Stroker *, _DWORD, _DWORD))Str->AddVertex)(Str, LODWORD(v8), LODWORD(v6));
}
