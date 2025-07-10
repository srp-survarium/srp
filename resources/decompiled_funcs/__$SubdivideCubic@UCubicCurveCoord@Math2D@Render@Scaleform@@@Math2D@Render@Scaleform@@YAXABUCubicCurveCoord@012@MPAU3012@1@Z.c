void __cdecl Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(
        const Scaleform::Render::Math2D::CubicCurveCoord *c,
        float t,
        Scaleform::Render::Math2D::CubicCurveCoord *c1,
        Scaleform::Render::Math2D::CubicCurveCoord *c2)
{
  double v5; // st7
  double v6; // st5
  double v7; // st3
  double v8; // st6
  double v9; // st4
  double v10; // st3
  double v11; // st2
  double v12; // st7
  float y34; // [esp+0h] [ebp-18h]
  float y23; // [esp+4h] [ebp-14h]
  float y23a; // [esp+4h] [ebp-14h]
  float y123; // [esp+8h] [ebp-10h]
  float y123a; // [esp+8h] [ebp-10h]
  float y123b; // [esp+8h] [ebp-10h]
  float x34; // [esp+Ch] [ebp-Ch]
  float x34a; // [esp+Ch] [ebp-Ch]
  float x1234; // [esp+10h] [ebp-8h]
  float x1234a; // [esp+10h] [ebp-8h]
  float y1; // [esp+14h] [ebp-4h]
  float x234; // [esp+1Ch] [ebp+4h]
  float x234a; // [esp+1Ch] [ebp+4h]
  float y234; // [esp+20h] [ebp+8h]
  float y234a; // [esp+20h] [ebp+8h]

  y1 = c->y1;
  v5 = t;
  y234 = (c->x2 - c->x1) * t + c->x1;
  y123 = (c->y2 - y1) * v5 + y1;
  x234 = (c->x3 - c->x2) * v5 + c->x2;
  y23 = (c->y3 - c->y2) * v5 + c->y2;
  x34 = (c->x4 - c->x3) * v5 + c->x3;
  y34 = (c->y4 - c->y3) * v5 + c->y3;
  v6 = y234;
  x1234 = (x234 - y234) * v5 + y234;
  v7 = y123;
  y123a = (y23 - y123) * v5 + y123;
  v8 = x34;
  x234a = x234 + (x34 - x234) * v5;
  v9 = v7;
  y234a = y23 + (y34 - y23) * v5;
  v10 = x1234;
  x1234a = (x234a - x1234) * v5 + x1234;
  v11 = v5 * (y234a - y123a) + y123a;
  v12 = y123a;
  x34a = v11;
  y123b = c->x4;
  y23a = c->y4;
  c1->x1 = c->x1;
  c1->y1 = y1;
  c1->x2 = v6;
  c1->y2 = v9;
  c1->x3 = v10;
  c1->y3 = v12;
  c1->x4 = x1234a;
  c1->y4 = x34a;
  c2->x1 = x1234a;
  c2->y1 = x34a;
  c2->x2 = x234a;
  c2->y2 = y234a;
  c2->x3 = v8;
  c2->y3 = y34;
  c2->x4 = y123b;
  c2->y4 = y23a;
}
