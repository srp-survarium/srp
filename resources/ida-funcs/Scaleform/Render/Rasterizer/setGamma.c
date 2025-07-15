void __thiscall Scaleform::Render::Rasterizer::setGamma(Scaleform::Render::Rasterizer *this, int idx, float g)
{
  double v3; // st7
  int v4; // esi
  unsigned __int8 *v5; // edi
  int v6; // [esp+8h] [ebp-4h]
  float v7; // [esp+10h] [ebp+4h]
  float v8; // [esp+10h] [ebp+4h]

  v3 = 255.0;
  v4 = 0;
  v6 = 0;
  v5 = this->GammaLut[idx];
  do
  {
    v7 = (double)v6 / v3;
    v8 = pow(v7, g);
    ++v4;
    v3 = 255.0;
    v5[v4 - 1] = (int)(v8 * 255.0 + 0.5);
    v6 = v4;
  }
  while ( v4 < 256 );
}
