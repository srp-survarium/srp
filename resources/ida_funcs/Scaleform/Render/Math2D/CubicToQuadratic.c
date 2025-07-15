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
  float v25; // [esp+1Ch] [ebp-ACh]
  float v26; // [esp+1Ch] [ebp-ACh]
  float t; // [esp+30h] [ebp-98h]
  float ta; // [esp+30h] [ebp-98h]
  float tb; // [esp+30h] [ebp-98h]
  float td; // [esp+30h] [ebp-98h]
  float te; // [esp+30h] [ebp-98h]
  float tca; // [esp+34h] [ebp-94h]
  float tc; // [esp+34h] [ebp-94h]
  float tcb; // [esp+34h] [ebp-94h]
  float aya; // [esp+38h] [ebp-90h]
  float ay; // [esp+38h] [ebp-90h]
  float dena; // [esp+3Ch] [ebp-8Ch]
  float den; // [esp+3Ch] [ebp-8Ch]
  float cy; // [esp+40h] [ebp-88h]
  float by; // [esp+44h] [ebp-84h]
  Scaleform::Render::Math2D::CubicCurveCoord cc; // [esp+48h] [ebp-80h] BYREF
  Scaleform::Render::Math2D::CubicCurveCoord sc[3]; // [esp+68h] [ebp-60h] BYREF

  v9 = x2 * 3.0;
  v10 = x3 * 3.0;
  dena = v9 - x1 - v10 + x4;
  v11 = y2 * 3.0;
  v12 = y3 * 3.0;
  aya = v11 - y1 - v12 + y4;
  v13 = x1 * 3.0;
  v14 = v12;
  tca = v10 + v13 - x2 * 6.0;
  v15 = y1 * 3.0;
  by = v14 + v15 - y2 * 6.0;
  t = v9 - v13;
  cy = v11 - v15;
  v16 = tca;
  v17 = aya;
  v18 = dena;
  den = tca * aya - by * dena;
  ay = -1.0;
  tc = -1.0;
  if ( den != 0.0 )
  {
    tcb = (v17 * t - v18 * cy) * -0.5 / den;
    ta = tcb * tcb - (by * t - v16 * cy) / (3.0 * den);
    tb = sqrt(ta);
    ay = tcb - tb;
    tc = tcb + tb;
  }
  cc.x1 = x1;
  v19 = 1;
  cc.y1 = y1;
  cc.x2 = x2;
  cc.y2 = y2;
  cc.x3 = x3;
  cc.y3 = y3;
  cc.x4 = x4;
  cc.y4 = y4;
  v20 = tc;
  v21 = tc > 0.0 && v20 < 1.0;
  v22 = ay;
  v23 = ay > 0.0 && v22 < 1.0;
  switch ( v23 + 2 * v21 )
  {
    case 0:
      qmemcpy(sc, &cc, 0x20u);
      v19 = 1;
      break;
    case 1:
      goto LABEL_16;
    case 2:
      v22 = tc;
LABEL_16:
      v25 = v22;
      Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&cc, v25, sc, &sc[1]);
      v19 = 2;
      break;
    case 3:
      if ( v20 < v22 )
      {
        td = ay;
        ay = tc;
        tc = td;
        v22 = ay;
      }
      v26 = v22;
      Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&cc, v26, sc, &sc[1]);
      te = (tc - ay) / (1.0 - ay);
      Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(&sc[1], te, &sc[1], &sc[2]);
      v19 = 3;
      break;
    default:
      break;
  }
  p_x4 = &sc[0].x4;
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
