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
  float v15; // [esp+4h] [ebp+4h]
  float v16; // [esp+Ch] [ebp+Ch]
  float v17; // [esp+10h] [ebp+10h]
  float v18; // [esp+10h] [ebp+10h]
  float v19; // [esp+1Ch] [ebp+1Ch]
  float v20; // [esp+1Ch] [ebp+1Ch]

  v9 = x1;
  v10 = t;
  v19 = (x2 - x1) * t + x1;
  v11 = y2;
  v17 = (y2 - y1) * v10 + y1;
  v16 = x2 + (x3 - x2) * v10;
  v15 = v11 + (y3 - v11) * v10;
  v12 = v19;
  v20 = (v16 - v19) * v10 + v19;
  v13 = v10 * (v15 - v17) + v17;
  v14 = v17;
  v18 = v13;
  c1->x1 = v9;
  c1->y1 = y1;
  c1->x2 = v12;
  c1->y2 = v14;
  c1->x3 = v20;
  c1->y3 = v18;
  c2->x1 = v20;
  c2->y1 = v18;
  c2->x2 = v16;
  c2->y2 = v15;
  c2->x3 = x3;
  c2->y3 = y3;
}
