void __cdecl Scaleform::Render::Math2D::SubdivideCubicToQuads<Scaleform::Render::Math2D::QuadCurvePath>(
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
  double v9; // st7
  double v10; // st6
  double v11; // st4
  double v12; // st2
  float v13; // [esp+30h] [ebp-5Ch]
  float v14; // [esp+34h] [ebp-58h]
  float v15; // [esp+38h] [ebp-54h]
  float v16; // [esp+3Ch] [ebp-50h]
  float v17; // [esp+40h] [ebp-4Ch]
  float v18; // [esp+40h] [ebp-4Ch]
  float v19; // [esp+44h] [ebp-48h]
  float v20; // [esp+44h] [ebp-48h]
  float x; // [esp+48h] [ebp-44h] BYREF
  float y; // [esp+4Ch] [ebp-40h] BYREF
  float v23; // [esp+50h] [ebp-3Ch]
  float v24; // [esp+54h] [ebp-38h]
  float epsilon; // [esp+58h] [ebp-34h]
  double v26; // [esp+5Ch] [ebp-30h]
  double v27; // [esp+64h] [ebp-28h]
  float v28; // [esp+6Ch] [ebp-20h]
  float v29; // [esp+70h] [ebp-1Ch]
  double v30; // [esp+74h] [ebp-18h]
  Scaleform::Render::Math2D::QuadCoord val; // [esp+7Ch] [ebp-10h] BYREF

  while ( 1 )
  {
    *(float *)&v26 = x2 - x1;
    *(float *)&v27 = y2 - y1;
    v28 = x3 - x2;
    v29 = y3 - y2;
    v24 = x4 - x3;
    epsilon = y4 - y3;
    v30 = v29;
    *(double *)&val.cx = v28;
    v9 = *(float *)&v27;
    v10 = *(float *)&v26;
    v26 = epsilon;
    v27 = v24;
    v29 = v9 * v9 + v10 * v10;
    v29 = sqrt(v29);
    v28 = v29;
    v29 = *(double *)&val.cx * *(double *)&val.cx + v30 * v30;
    v29 = sqrt(v29);
    *(double *)&val.cx = v29 + v28;
    v29 = v24 * v24 + epsilon * epsilon;
    v29 = sqrt(v29);
    v29 = v29 + *(double *)&val.cx;
    epsilon = v29 * 0.004999999888241291;
    if ( !Scaleform::Render::Math2D::Intersection(x1, y1, x2, y2, x3, y3, x4, y4, &x, &y, epsilon) )
    {
      x = (x2 + x3) * 0.5;
      y = (y2 + y3) * 0.5;
    }
    v29 = (x + x1) * 0.5;
    v11 = v29;
    v29 = (x + x4) * 0.5;
    v24 = (v11 + v29) * 0.5;
    v29 = (y + y1) * 0.5;
    v12 = v29;
    v29 = (y + y4) * 0.5;
    v23 = (v12 + v29) * 0.5;
    *(float *)&v27 = (x1 + x2) * 0.5;
    *(float *)&v26 = (y1 + y2) * 0.5;
    v17 = (x2 + x3) * 0.5;
    v19 = (y2 + y3) * 0.5;
    v29 = (x3 + x4) * 0.5;
    v28 = (y3 + y4) * 0.5;
    v14 = (v17 + *(float *)&v27) * 0.5;
    v13 = (v19 + *(float *)&v26) * 0.5;
    v16 = (v17 + v29) * 0.5;
    v15 = (v28 + v19) * 0.5;
    v20 = (v16 + v14) * 0.5;
    v18 = 0.5 * (v15 + v13);
    *(float *)&v30 = fabs(Scaleform::Render::Math2D::LinePointDistance(x1, y1, x4, y4, v24, v23));
    val.cx = *(float *)&v30;
    *(float *)&v30 = fabs(Scaleform::Render::Math2D::LinePointDistance(x1, y1, x4, y4, v20, v18));
    val.cx = val.cx - *(float *)&v30;
    val.cx = fabs(val.cx);
    *(float *)&v30 = val.cx;
    val.cx = fabs(Scaleform::Render::Math2D::LinePointDistance(v14, v13, v16, v15, v24, v23));
    val.cx = val.cx + *(float *)&v30;
    if ( epsilon > (double)val.cx )
      break;
    Scaleform::Render::Math2D::SubdivideCubicToQuads<Scaleform::Render::Math2D::QuadCurvePath>(
      x1,
      y1,
      *(float *)&v27,
      *(float *)&v26,
      v14,
      v13,
      v20,
      v18,
      path);
    y3 = v28;
    x3 = v29;
    y2 = v15;
    x2 = v16;
    y1 = 0.5 * (v15 + v13);
    x1 = (v16 + v14) * 0.5;
  }
  val.cx = x;
  val.cy = y;
  val.ax = x4;
  val.ay = y4;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Math2D::QuadCoord,32,2>::PushBack(&path->Quads, &val);
}
