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
  double v10; // [esp+4h] [ebp-10h]
  double v11; // [esp+4h] [ebp-10h]
  double v12; // [esp+Ch] [ebp-8h]
  float v13; // [esp+18h] [ebp+4h]
  float v14; // [esp+18h] [ebp+4h]
  float v15; // [esp+18h] [ebp+4h]
  float v16; // [esp+18h] [ebp+4h]
  float v17; // [esp+18h] [ebp+4h]
  float v18; // [esp+18h] [ebp+4h]
  float v19; // [esp+1Ch] [ebp+8h]
  float v20; // [esp+1Ch] [ebp+8h]
  float v21; // [esp+1Ch] [ebp+8h]
  float v22; // [esp+1Ch] [ebp+8h]

  v4 = (int)x;
  v13 = x - (double)v4;
  v5 = (int)y;
  v6 = v5;
  v14 = v13 * 3.141592741012573;
  v15 = cos(v14);
  v16 = (1.0 - v15) * 0.5;
  v9 = v16;
  v19 = y - (double)v5;
  v20 = v19 * 3.141592741012573;
  v21 = cos(v20);
  v7 = v5 + 1;
  v22 = (1.0 - v21) * 0.5;
  v10 = Scaleform::Render::PerlinGenerator::SmoothNoise(this, v4, v5) * (1.0 - v16);
  v17 = Scaleform::Render::PerlinGenerator::SmoothNoise(this, v4 + 1, v6) * v16 + v10;
  v12 = v17 * (1.0 - v22);
  v11 = Scaleform::Render::PerlinGenerator::SmoothNoise(this, v4, v7) * (1.0 - v9);
  v18 = Scaleform::Render::PerlinGenerator::SmoothNoise(this, v4 + 1, v7) * v9 + v11;
  return (float)(v18 * v22 + v12);
}
