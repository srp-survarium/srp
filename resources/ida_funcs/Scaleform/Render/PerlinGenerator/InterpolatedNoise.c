double __thiscall Scaleform::Render::PerlinGenerator::InterpolatedNoise(
        Scaleform::Render::PerlinGenerator *this,
        float x,
        float y)
{
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // ebp
  float v9; // [esp+0h] [ebp-14h]
  double integer_Y; // [esp+4h] [ebp-10h]
  double integer_Ya; // [esp+4h] [ebp-10h]
  double v12; // [esp+Ch] [ebp-8h]
  float integer_X; // [esp+18h] [ebp+4h]
  float integer_Xa; // [esp+18h] [ebp+4h]
  float integer_Xb; // [esp+18h] [ebp+4h]
  float integer_Xc; // [esp+18h] [ebp+4h]
  float integer_Xd; // [esp+18h] [ebp+4h]
  float integer_Xe; // [esp+18h] [ebp+4h]
  float ya; // [esp+1Ch] [ebp+8h]
  float yb; // [esp+1Ch] [ebp+8h]
  float yc; // [esp+1Ch] [ebp+8h]
  float yd; // [esp+1Ch] [ebp+8h]

  v4 = (int)x;
  integer_X = x - (double)v4;
  v5 = (int)y;
  v6 = v5;
  integer_Xa = integer_X * 3.141592741012573;
  integer_Xb = cos(integer_Xa);
  integer_Xc = (1.0 - integer_Xb) * 0.5;
  v9 = integer_Xc;
  ya = y - (double)v5;
  yb = ya * 3.141592741012573;
  yc = cos(yb);
  v7 = v5 + 1;
  yd = (1.0 - yc) * 0.5;
  integer_Y = Scaleform::Render::PerlinGenerator::SmoothNoise(this, v4, v5) * (1.0 - integer_Xc);
  integer_Xd = Scaleform::Render::PerlinGenerator::SmoothNoise(this, v4 + 1, v6) * integer_Xc + integer_Y;
  v12 = integer_Xd * (1.0 - yd);
  integer_Ya = Scaleform::Render::PerlinGenerator::SmoothNoise(this, v4, v7) * (1.0 - v9);
  integer_Xe = Scaleform::Render::PerlinGenerator::SmoothNoise(this, v4 + 1, v7) * v9 + integer_Ya;
  return (float)(integer_Xe * yd + v12);
}
