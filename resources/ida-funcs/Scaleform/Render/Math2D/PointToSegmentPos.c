double __cdecl Scaleform::Render::Math2D::PointToSegmentPos(float x1, float y1, float x2, float y2, float x, float y)
{
  double v6; // st7
  double v7; // st3
  float v9; // [esp+4h] [ebp+4h]
  float v10; // [esp+Ch] [ebp+Ch]

  v6 = x1;
  v10 = x2 - x1;
  v9 = y2 - y1;
  v7 = v9;
  if ( v10 == 0.0 && 0.0 == v7 )
    return 0.0;
  return (float)((v9 * (y - y1) + v10 * (x - v6)) / (v10 * v10 + v7 * v7));
}


double __cdecl Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
        const Scaleform::Render::Point<float> *v1,
        const Scaleform::Render::Point<float> *v2,
        const Scaleform::Render::Point<float> *v)
{
  return Scaleform::Render::Math2D::PointToSegmentPos(v1->x, v1->y, v2->x, v2->y, v->x, v->y);
}
