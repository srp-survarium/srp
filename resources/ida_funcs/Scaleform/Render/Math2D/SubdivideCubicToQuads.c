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
  float y123; // [esp+30h] [ebp-5Ch]
  float x123; // [esp+34h] [ebp-58h]
  float y234; // [esp+38h] [ebp-54h]
  float x234; // [esp+3Ch] [ebp-50h]
  float y1234a; // [esp+40h] [ebp-4Ch]
  float y1234; // [esp+40h] [ebp-4Ch]
  float y23a; // [esp+44h] [ebp-48h]
  float y23; // [esp+44h] [ebp-48h]
  float xc; // [esp+48h] [ebp-44h] BYREF
  float yc; // [esp+4Ch] [ebp-40h] BYREF
  float yq; // [esp+50h] [ebp-3Ch]
  float xq; // [esp+54h] [ebp-38h]
  float tolerance; // [esp+58h] [ebp-34h]
  double y12; // [esp+5Ch] [ebp-30h]
  double x12; // [esp+64h] [ebp-28h]
  float y34; // [esp+6Ch] [ebp-20h]
  float x34; // [esp+70h] [ebp-1Ch]
  double v30; // [esp+74h] [ebp-18h]
  Scaleform::Render::Math2D::QuadCoord val; // [esp+7Ch] [ebp-10h] BYREF

  while ( 1 )
  {
    *(float *)&y12 = x2 - x1;
    *(float *)&x12 = y2 - y1;
    y34 = x3 - x2;
    x34 = y3 - y2;
    xq = x4 - x3;
    tolerance = y4 - y3;
    v30 = x34;
    *(double *)&val.cx = y34;
    v9 = *(float *)&x12;
    v10 = *(float *)&y12;
    y12 = tolerance;
    x12 = xq;
    x34 = v9 * v9 + v10 * v10;
    x34 = sqrt(x34);
    y34 = x34;
    x34 = *(double *)&val.cx * *(double *)&val.cx + v30 * v30;
    x34 = sqrt(x34);
    *(double *)&val.cx = x34 + y34;
    x34 = xq * xq + tolerance * tolerance;
    x34 = sqrt(x34);
    x34 = x34 + *(double *)&val.cx;
    tolerance = x34 * 0.004999999888241291;
    if ( !Scaleform::Render::Math2D::Intersection(x1, y1, x2, y2, x3, y3, x4, y4, &xc, &yc, tolerance) )
    {
      xc = (x2 + x3) * 0.5;
      yc = (y2 + y3) * 0.5;
    }
    x34 = (xc + x1) * 0.5;
    v11 = x34;
    x34 = (xc + x4) * 0.5;
    xq = (v11 + x34) * 0.5;
    x34 = (yc + y1) * 0.5;
    v12 = x34;
    x34 = (yc + y4) * 0.5;
    yq = (v12 + x34) * 0.5;
    *(float *)&x12 = (x1 + x2) * 0.5;
    *(float *)&y12 = (y1 + y2) * 0.5;
    y1234a = (x2 + x3) * 0.5;
    y23a = (y2 + y3) * 0.5;
    x34 = (x3 + x4) * 0.5;
    y34 = (y3 + y4) * 0.5;
    x123 = (y1234a + *(float *)&x12) * 0.5;
    y123 = (y23a + *(float *)&y12) * 0.5;
    x234 = (y1234a + x34) * 0.5;
    y234 = (y34 + y23a) * 0.5;
    y23 = (x234 + x123) * 0.5;
    y1234 = 0.5 * (y234 + y123);
    *(float *)&v30 = fabs(Scaleform::Render::Math2D::LinePointDistance(x1, y1, x4, y4, xq, yq));
    val.cx = *(float *)&v30;
    *(float *)&v30 = fabs(Scaleform::Render::Math2D::LinePointDistance(x1, y1, x4, y4, y23, y1234));
    val.cx = val.cx - *(float *)&v30;
    val.cx = fabs(val.cx);
    *(float *)&v30 = val.cx;
    val.cx = fabs(Scaleform::Render::Math2D::LinePointDistance(x123, y123, x234, y234, xq, yq));
    val.cx = val.cx + *(float *)&v30;
    if ( tolerance > (double)val.cx )
      break;
    Scaleform::Render::Math2D::SubdivideCubicToQuads<Scaleform::Render::Math2D::QuadCurvePath>(
      x1,
      y1,
      *(float *)&x12,
      *(float *)&y12,
      x123,
      y123,
      y23,
      y1234,
      path);
    y3 = y34;
    x3 = x34;
    y2 = y234;
    x2 = x234;
    y1 = 0.5 * (y234 + y123);
    x1 = (x234 + x123) * 0.5;
  }
  val.cx = xc;
  val.cy = yc;
  val.ax = x4;
  val.ay = y4;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Math2D::QuadCoord,32,2>::PushBack(&path->Quads, &val);
}
