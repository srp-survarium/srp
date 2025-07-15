void __cdecl Scaleform::Render::Math2D::SubdivideQuadCurve<Scaleform::Render::Math2D::QuadCoordType>(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float t,
        Scaleform::Render::Math2D::QuadCoordType *c1,
        Scaleform::Render::Math2D::QuadCoordType *c2)
{
  double v9; // st5
  double v10; // st6
  double v11; // st4
  double v12; // st3
  double v13; // st2
  double v14; // st6
  float y23; // [esp+4h] [ebp+4h]
  float x23; // [esp+Ch] [ebp+Ch]
  float y123; // [esp+10h] [ebp+10h]
  float y123a; // [esp+10h] [ebp+10h]
  float x12; // [esp+1Ch] [ebp+1Ch]
  float x12a; // [esp+1Ch] [ebp+1Ch]

  v9 = x1;
  v10 = t;
  x12 = (x2 - x1) * t + x1;
  v11 = y2;
  y123 = (y2 - y1) * v10 + y1;
  x23 = x2 + (x3 - x2) * v10;
  y23 = v11 + (y3 - v11) * v10;
  v12 = x12;
  x12a = (x23 - x12) * v10 + x12;
  v13 = v10 * (y23 - y123) + y123;
  v14 = y123;
  y123a = v13;
  c1->x1 = v9;
  c1->y1 = y1;
  c1->x2 = v12;
  c1->y2 = v14;
  c1->x3 = x12a;
  c1->y3 = y123a;
  c2->x1 = x12a;
  c2->y1 = y123a;
  c2->x2 = x23;
  c2->y2 = y23;
  c2->x3 = x3;
  c2->y3 = y3;
}
