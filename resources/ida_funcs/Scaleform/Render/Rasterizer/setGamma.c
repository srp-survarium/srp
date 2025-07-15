void __thiscall Scaleform::Render::Rasterizer::setGamma(Scaleform::Render::Rasterizer *this, int idx, float g)
{
  double v3; // st7
  int v4; // esi
  unsigned __int8 *v5; // edi
  int i; // [esp+8h] [ebp-4h]
  float idxa; // [esp+10h] [ebp+4h]
  float idxb; // [esp+10h] [ebp+4h]

  v3 = 255.0;
  v4 = 0;
  i = 0;
  v5 = this->GammaLut[idx];
  do
  {
    idxa = (double)i / v3;
    idxb = pow(idxa, g);
    ++v4;
    v3 = 255.0;
    v5[v4 - 1] = (int)(idxb * 255.0 + 0.5);
    i = v4;
  }
  while ( v4 < 256 );
}
