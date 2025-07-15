void __cdecl Scaleform::Render::Math2D::PointOnCubicCurve(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        float t,
        float *x,
        float *y)
{
  double v11; // st6
  double v12; // st5
  double v13; // st4
  double v14; // st3
  float v15; // [esp+4h] [ebp+4h]
  float v16; // [esp+4h] [ebp+4h]
  float v17; // [esp+Ch] [ebp+Ch]
  float v18; // [esp+Ch] [ebp+Ch]
  float v19; // [esp+Ch] [ebp+Ch]
  float v20; // [esp+Ch] [ebp+Ch]
  float v21; // [esp+Ch] [ebp+Ch]
  float v22; // [esp+10h] [ebp+10h]
  float v23; // [esp+24h] [ebp+24h]
  float v24; // [esp+24h] [ebp+24h]

  v11 = t;
  v15 = x1 + (x2 - x1) * t;
  v12 = y2;
  v22 = (y2 - y1) * t + y1;
  v17 = x2 + (x3 - x2) * t;
  v23 = v12 + (y3 - v12) * t;
  v13 = v17;
  v16 = (v17 - v15) * v11 + v15;
  v14 = v23;
  v24 = (v23 - v22) * v11 + v22;
  v18 = x3 + (x4 - x3) * v11;
  v19 = v13 + (v18 - v13) * v11;
  *x = (v19 - v16) * v11 + v16;
  v20 = y3 + (y4 - y3) * v11;
  v21 = v14 + (v20 - v14) * v11;
  *y = v11 * (v21 - v24) + v24;
}
