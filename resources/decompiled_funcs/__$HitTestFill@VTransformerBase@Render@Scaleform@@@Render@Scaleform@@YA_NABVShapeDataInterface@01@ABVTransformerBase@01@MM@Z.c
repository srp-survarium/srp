char __cdecl Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(
        const Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::TransformerBase *trans,
        float x,
        float y)
{
  unsigned int v5; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  int v7; // ebp
  Scaleform::Render::ShapePathType v8; // eax
  Scaleform::Render::PathEdgeType v9; // eax
  double v10; // st7
  double v11; // st6
  double v12; // st4
  double v13; // st7
  double v14; // st5
  double v15; // st6
  double v16; // st5
  double v17; // rt1
  double v18; // st6
  double v19; // st7
  double v20; // rt2
  double v21; // st6
  int v22; // eax
  float y2; // [esp+6Ch] [ebp-68h]
  float y2a; // [esp+6Ch] [ebp-68h]
  float x2; // [esp+70h] [ebp-64h]
  float x1; // [esp+74h] [ebp-60h]
  unsigned int styles[3]; // [esp+78h] [ebp-5Ch] BYREF
  float coord[6]; // [esp+84h] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+9Ch] [ebp-38h] BYREF
  float y1; // [esp+D8h] [ebp+4h]
  float y1a; // [esp+D8h] [ebp+4h]
  float y1b; // [esp+D8h] [ebp+4h]

  v5 = shape->GetStartingPos(shape);
  pos.Sfactor = 1.0;
  pos.Pos = v5;
  ReadPathInfo = shape->ReadPathInfo;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  v7 = 0;
  v8 = ReadPathInfo(shape, &pos, coord, styles);
  if ( v8 == Shape_EndShape )
    return v7 != 0;
  while ( v8 != Shape_NewLayer )
  {
LABEL_5:
    if ( (styles[0] == 0) == (styles[1] == 0) )
    {
      shape->SkipPathData(shape, &pos);
    }
    else
    {
      trans->Transform(trans, coord, &coord[1]);
      y1 = coord[0];
      y2 = coord[1];
      v9 = shape->ReadEdge(shape, &pos, coord);
      if ( v9 )
      {
        while ( v9 != Edge_LineTo )
        {
          if ( v9 == Edge_QuadTo )
          {
            trans->Transform(trans, coord, &coord[1]);
            trans->Transform(trans, &coord[2], &coord[3]);
            v22 = Scaleform::Render::Math2D::CheckQuadraticIntersection(
                    v7,
                    y1,
                    y2,
                    coord[0],
                    coord[1],
                    coord[2],
                    coord[3],
                    x,
                    y);
            y1 = coord[2];
            v19 = coord[3];
            goto LABEL_20;
          }
          if ( v9 == Edge_CubicTo )
          {
            trans->Transform(trans, coord, &coord[1]);
            trans->Transform(trans, &coord[2], &coord[3]);
            trans->Transform(trans, &coord[4], &coord[5]);
            v22 = Scaleform::Render::Math2D::CheckCubicIntersection(
                    v7,
                    y1,
                    y2,
                    coord[0],
                    coord[1],
                    coord[2],
                    coord[3],
                    coord[4],
                    coord[5],
                    x,
                    y);
            y1 = coord[4];
            v19 = coord[5];
LABEL_20:
            v7 = v22;
LABEL_21:
            y2 = v19;
          }
          v9 = shape->ReadEdge(shape, &pos, coord);
          if ( v9 == Edge_EndPath )
            goto LABEL_25;
        }
        trans->Transform(trans, coord, &coord[1]);
        v10 = y1;
        x1 = y1;
        v11 = y2;
        y1a = y2;
        x2 = coord[0];
        y2a = coord[1];
        if ( coord[1] >= v11 )
        {
          v15 = coord[1];
          v13 = coord[0];
        }
        else
        {
          x1 = coord[0];
          v12 = v10;
          v13 = coord[0];
          x2 = v12;
          y1a = coord[1];
          v14 = v11;
          v15 = coord[1];
          y2a = v14;
        }
        v16 = y;
        if ( y1a > (double)y || y2a <= v16 || (y1b = (x - x2) * (y2a - y1a) - (x2 - x1) * (v16 - y2a), y1b <= 0.0) )
        {
          v20 = v15;
          v21 = v13;
          v19 = v20;
          y1 = v21;
        }
        else
        {
          v17 = v15;
          v18 = v13;
          v19 = v17;
          v7 ^= 1u;
          y1 = v18;
        }
        goto LABEL_21;
      }
    }
LABEL_25:
    v8 = shape->ReadPathInfo(shape, &pos, coord, styles);
    if ( v8 == Shape_EndShape )
      return v7 != 0;
  }
  if ( !v7 )
  {
    v7 = 0;
    goto LABEL_5;
  }
  return 1;
}
