unsigned __int8 __cdecl Scaleform::Render::GradientRamp::applyGammaInv(unsigned __int16 v, float gamma)
{
  float va; // [esp+Ch] [ebp+4h]
  float vb; // [esp+Ch] [ebp+4h]
  float vc; // [esp+Ch] [ebp+4h]

  va = (double)v / 65535.0;
  vb = pow(va, gamma);
  vc = vb * 255.0 + 0.5;
  return (int)floor(vc);
}
