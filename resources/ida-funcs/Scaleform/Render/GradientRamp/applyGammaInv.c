unsigned __int8 __cdecl Scaleform::Render::GradientRamp::applyGammaInv(unsigned __int16 v, float gamma)
{
  float v3; // [esp+Ch] [ebp+4h]
  float v4; // [esp+Ch] [ebp+4h]
  float v5; // [esp+Ch] [ebp+4h]

  v3 = (double)v / 65535.0;
  v4 = pow(v3, gamma);
  v5 = v4 * 255.0 + 0.5;
  return (int)floor(v5);
}
