void __cdecl Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        const Scaleform::Render::ShapeDataInterface *shape,
        float trans,
        Scaleform::Render::ShapePosInfo *pos,
        float coord,
        Scaleform::Render::Rect<float> *bounds)
{
  float *v5; // esi
  float *v6; // edi
  Scaleform::Render::Rect<float> *v7; // ebx
  Scaleform::Render::Rect<float> *v8; // ecx
  double v9; // st6
  double v10; // st7
  const Scaleform::Render::ShapeDataInterface *v11; // ebp
  Scaleform::Render::PathEdgeType (__thiscall *ReadEdge)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *); // edx
  int v13; // eax
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st7
  double v18; // st5
  double v19; // st6
  double v20; // st5
  double v21; // st6
  double v22; // st6
  double v23; // st6
  double v24; // st5
  double v25; // st5
  double v26; // st4
  double v27; // st4
  double v28; // st7
  double v29; // st6
  double v30; // st7
  double v31; // st6
  double v32; // st7
  double v33; // st6
  float x1; // [esp+10h] [ebp-50h]
  float x1a; // [esp+10h] [ebp-50h]
  float y1; // [esp+14h] [ebp-4Ch]
  float v37; // [esp+44h] [ebp-1Ch] BYREF
  float t; // [esp+48h] [ebp-18h]
  float y; // [esp+4Ch] [ebp-14h] BYREF
  float x; // [esp+50h] [ebp-10h] BYREF
  float t1; // [esp+54h] [ebp-Ch] BYREF
  float t2; // [esp+58h] [ebp-8h] BYREF
  float v43; // [esp+5Ch] [ebp-4h]

  v5 = (float *)LODWORD(coord);
  v6 = (float *)LODWORD(trans);
  coord = *(float *)LODWORD(coord);
  v7 = bounds;
  t2 = v5[1];
  v8 = bounds;
  v9 = coord;
  v10 = t2;
  *v5 = *(float *)(LODWORD(trans) + 4) * t2 + *(float *)LODWORD(trans) * coord + *(float *)(LODWORD(trans) + 12);
  v5[1] = v10 * v6[5] + v9 * v6[4] + v6[7];
  Scaleform::Render::Rect<float>::ExpandToPoint(v8, *v5, v5[1]);
  v11 = shape;
  coord = *v5;
  ReadEdge = shape->ReadEdge;
  trans = v5[1];
  v13 = ReadEdge(shape, pos, v5);
  if ( v13 )
  {
    while ( 1 )
    {
      v14 = 0.0;
      if ( v13 == 1 )
        break;
      if ( v13 == 2 )
      {
        t = *v5;
        v43 = v5[1];
        v18 = t;
        v19 = v43;
        *v5 = v6[1] * v43 + *v6 * t + v6[3];
        v5[1] = v19 * v6[5] + v18 * v6[4] + v6[7];
        v43 = v5[2];
        t = v5[3];
        v20 = v43;
        v21 = t;
        v5[2] = v6[1] * t + *v6 * v43 + v6[3];
        v5[3] = v21 * v6[5] + v20 * v6[4] + v6[7];
        v43 = *v5;
        v22 = v43;
        v43 = v22 + v22 - coord - v5[2];
        if ( v43 == 0.0 )
        {
          v23 = coord;
          v24 = -1.0;
        }
        else
        {
          v24 = (v22 - coord) / v43;
          v23 = coord;
        }
        t = v24;
        if ( t <= 0.0 || t >= 1.0 )
        {
          v25 = trans;
        }
        else
        {
          x1 = v23;
          Scaleform::Render::Math2D::PointOnQuadCurve(x1, trans, *v5, v5[1], v5[2], v5[3], t, &x, &y);
          Scaleform::Render::Rect<float>::ExpandToPoint(v7, x, y);
          v14 = 0.0;
          v25 = trans;
          v23 = coord;
        }
        coord = v5[1];
        v26 = coord;
        coord = v26 + v26 - v25 - v5[3];
        if ( coord == v14 )
          v27 = -1.0;
        else
          v27 = (v26 - v25) / coord;
        t = v27;
        if ( t > v14 && t < 1.0 )
        {
          y1 = v25;
          x1a = v23;
          Scaleform::Render::Math2D::PointOnQuadCurve(x1a, y1, *v5, v5[1], v5[2], v5[3], t, &x, &y);
          Scaleform::Render::Rect<float>::ExpandToPoint(v7, x, y);
        }
        Scaleform::Render::Rect<float>::ExpandToPoint(v7, v5[2], v5[3]);
        coord = v5[2];
        v17 = v5[3];
        goto LABEL_33;
      }
      if ( v13 == 3 )
      {
        t = *v5;
        v43 = v5[1];
        v28 = v43;
        v29 = t;
        *v5 = *v6 * t + v43 * v6[1] + v6[3];
        v5[1] = v28 * v6[5] + v29 * v6[4] + v6[7];
        t = v5[2];
        v43 = v5[3];
        v30 = v43;
        v31 = t;
        v5[2] = *v6 * t + v43 * v6[1] + v6[3];
        v5[3] = v30 * v6[5] + v31 * v6[4] + v6[7];
        t = v5[3];
        v43 = v5[4];
        v32 = v43;
        v33 = t;
        v5[3] = *v6 * t + v43 * v6[1] + v6[3];
        v5[4] = v32 * v6[5] + v33 * v6[4] + v6[7];
        Scaleform::Render::Math2D::CubicCurveExtremum(coord, *v5, v5[2], v5[4], &t1, &t2);
        if ( t1 > 0.0 && t1 < 1.0 )
        {
          Scaleform::Render::Math2D::PointOnCubicCurve(
            coord,
            trans,
            *v5,
            v5[1],
            v5[2],
            v5[3],
            v5[4],
            v5[5],
            t1,
            &v37,
            (float *)&shape);
          Scaleform::Render::Rect<float>::ExpandToPoint(v7, v37, *(float *)&shape);
        }
        if ( t2 > 0.0 && t2 < 1.0 )
        {
          Scaleform::Render::Math2D::PointOnCubicCurve(
            coord,
            trans,
            *v5,
            v5[1],
            v5[2],
            v5[3],
            v5[4],
            v5[5],
            t2,
            &v37,
            (float *)&shape);
          Scaleform::Render::Rect<float>::ExpandToPoint(v7, v37, *(float *)&shape);
        }
        Scaleform::Render::Math2D::CubicCurveExtremum(trans, v5[1], v5[3], v5[5], &t1, &t2);
        if ( t1 > 0.0 && t1 < 1.0 )
        {
          Scaleform::Render::Math2D::PointOnCubicCurve(
            coord,
            trans,
            *v5,
            v5[1],
            v5[2],
            v5[3],
            v5[4],
            v5[5],
            t1,
            &v37,
            (float *)&shape);
          Scaleform::Render::Rect<float>::ExpandToPoint(v7, v37, *(float *)&shape);
        }
        if ( t2 > 0.0 && t2 < 1.0 )
        {
          Scaleform::Render::Math2D::PointOnCubicCurve(
            coord,
            trans,
            *v5,
            v5[1],
            v5[2],
            v5[3],
            v5[4],
            v5[5],
            t2,
            &v37,
            (float *)&shape);
          Scaleform::Render::Rect<float>::ExpandToPoint(v7, v37, *(float *)&shape);
        }
        Scaleform::Render::Rect<float>::ExpandToPoint(v7, v5[4], v5[5]);
        coord = v5[4];
        v17 = v5[5];
        goto LABEL_33;
      }
LABEL_34:
      v13 = v11->ReadEdge(v11, pos, v5);
      if ( !v13 )
        return;
    }
    coord = *v5;
    trans = v5[1];
    v15 = coord;
    v16 = trans;
    *v5 = v6[1] * trans + *v6 * coord + v6[3];
    v5[1] = v16 * v6[5] + v15 * v6[4] + v6[7];
    Scaleform::Render::Rect<float>::ExpandToPoint(v7, *v5, v5[1]);
    coord = *v5;
    v17 = v5[1];
LABEL_33:
    trans = v17;
    goto LABEL_34;
  }
}
