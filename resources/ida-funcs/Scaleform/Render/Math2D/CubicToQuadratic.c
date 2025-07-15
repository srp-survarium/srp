void __cdecl Scaleform::Render::Math2D::CubicToQuadratic<Scaleform::Render::Math2D::QuadCurvePath>(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        Scaleform::Render::Math2D::QuadCurvePath *path)
{
  double v9; // st6
  double v10; // st4
  double v11; // st3
  double v12; // st2
  double v13; // st7
  double v14; // rt1
  double v15; // st2
  double v16; // st6
  double v17; // st4
  double v18; // st5
  int v19; // edi
  double v20; // st6
  BOOL v21; // ecx
  double v22; // st7
  BOOL v23; // eax
  float *p_x4; // esi
  float y4a; // [esp+1Ch] [ebp-ACh]
  float y4b; // [esp+1Ch] [ebp-ACh]
  float v27; // [esp+30h] [ebp-98h]
  float v28; // [esp+30h] [ebp-98h]
  float v29; // [esp+30h] [ebp-98h]
  float v30; // [esp+30h] [ebp-98h]
  float v31; // [esp+30h] [ebp-98h]
  float v32; // [esp+34h] [ebp-94h]
  float v33; // [esp+34h] [ebp-94h]
  float v34; // [esp+34h] [ebp-94h]
  float v35; // [esp+38h] [ebp-90h]
  float v36; // [esp+38h] [ebp-90h]
  float v37; // [esp+3Ch] [ebp-8Ch]
  float v38; // [esp+3Ch] [ebp-8Ch]
  float v39; // [esp+40h] [ebp-88h]
  float v40; // [esp+44h] [ebp-84h]
  Scaleform::Render::Math2D::CubicCurveCoord c; // [esp+48h] [ebp-80h] BYREF
  Scaleform::Render::Math2D::CubicCurveCoord c1; // [esp+68h] [ebp-60h] BYREF
  Scaleform::Render::Math2D::CubicCurveCoord c2; // [esp+88h] [ebp-40h] BYREF
  Scaleform::Render::Math2D::CubicCurveCoord v44; // [esp+A8h] [ebp-20h] BYREF

  v9 = x2 * 3.0;
  v10 = x3 * 3.0;
  v37 = v9 - x1 - v10 + x4;
  v11 = y2 * 3.0;
  v12 = y3 * 3.0;
  v35 = v11 - y1 - v12 + y4;
  v13 = x1 * 3.0;
  v14 = v12;
  v32 = v10 + v13 - x2 * 6.0;
  v15 = y1 * 3.0;
  v40 = v14 + v15 - y2 * 6.0;
  v27 = v9 - v13;
  v39 = v11 - v15;
  v16 = v32;
  v17 = v35;
  v18 = v37;
  v38 = v32 * v35 - v40 * v37;
  v36 = -1.0;
  v33 = -1.0;
  if ( v38 != 0.0 )
  {
    v34 = (v17 * v27 - v18 * v39) * -0.5 / v38;
    v28 = v34 * v34 - (v40 * v27 - v16 * v39) / (3.0 * v38);
    v29 = sqrt(v28);
    v36 = v34 - v29;
    v33 = v34 + v29;
  }
  c.x1 = x1;
  v19 = 1;
  c.y1 = y1;
  c.x2 = x2;
  c.y2 = y2;
  c.x3 = x3;
  c.y3 = y3;
  c.x4 = x4;
  c.y4 = y4;
  v20 = v33;
  v21 = v33 > 0.0 && v20 < 1.0;
  v22 = v36;
  v23 = v36 > 0.0 && v22 < 1.0;
  switch ( v23 + 2 * v21 )
  {
    case 0:
      qmemcpy(&c1, &c, sizeof(c1));
      v19 = 1;
      break;
    case 1:
      goto LABEL_16;
    case 2:
      v22 = v33;
LABEL_16:
      y4a = v22;
      Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&c, y4a, &c1, &c2);
      v19 = 2;
      break;
    case 3:
      if ( v20 < v22 )
      {
        v30 = v36;
        v36 = v33;
        v33 = v30;
        v22 = v36;
      }
      y4b = v22;
      Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&c, y4b, &c1, &c2);
      v31 = (v33 - v36) / (1.0 - v36);
      Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&c2, v31, &c2, &v44);
      v19 = 3;
      break;
    default:
      break;
  }
  p_x4 = &c1.x4;
  do
  {
    Scaleform::Render::Math2D::SubdivideCubicToQuads<Scaleform::Render::Math2D::QuadCurvePath>(
      *(p_x4 - 6),
      *(p_x4 - 5),
      *(p_x4 - 4),
      *(p_x4 - 3),
      *(p_x4 - 2),
      *(p_x4 - 1),
      *p_x4,
      p_x4[1],
      path);
    p_x4 += 8;
    --v19;
  }
  while ( v19 );
}
