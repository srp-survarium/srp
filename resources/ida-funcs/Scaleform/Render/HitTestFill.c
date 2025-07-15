bool __cdecl Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(
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
  float y1; // [esp+6Ch] [ebp-68h]
  float v25; // [esp+6Ch] [ebp-68h]
  float v26; // [esp+70h] [ebp-64h]
  float v27; // [esp+74h] [ebp-60h]
  _DWORD v28[3]; // [esp+78h] [ebp-5Ch] BYREF
  float x2; // [esp+84h] [ebp-50h] BYREF
  float y2; // [esp+88h] [ebp-4Ch] BYREF
  float x3; // [esp+8Ch] [ebp-48h] BYREF
  float y3; // [esp+90h] [ebp-44h] BYREF
  float v33; // [esp+94h] [ebp-40h] BYREF
  float v34; // [esp+98h] [ebp-3Ch] BYREF
  _DWORD v35[13]; // [esp+9Ch] [ebp-38h] BYREF
  int v36; // [esp+D0h] [ebp-4h]
  float x1; // [esp+D8h] [ebp+4h]
  float v38; // [esp+D8h] [ebp+4h]
  float v39; // [esp+D8h] [ebp+4h]

  v5 = shape->GetStartingPos(shape);
  *(float *)&v35[12] = 1.0;
  v35[0] = v5;
  ReadPathInfo = shape->ReadPathInfo;
  memset(&v35[1], 0, 44);
  LOBYTE(v36) = 0;
  v7 = 0;
  v8 = ReadPathInfo(shape, (Scaleform::Render::ShapePosInfo *)v35, &x2, v28);
  if ( v8 == Shape_EndShape )
    return v7 != 0;
  while ( v8 != Shape_NewLayer )
  {
LABEL_5:
    if ( (v28[0] == 0) == (v28[1] == 0) )
    {
      shape->SkipPathData(shape, (Scaleform::Render::ShapePosInfo *)v35);
    }
    else
    {
      trans->Transform(trans, &x2, &y2);
      x1 = x2;
      y1 = y2;
      v9 = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)v35, &x2);
      if ( v9 )
      {
        while ( v9 != Edge_LineTo )
        {
          if ( v9 == Edge_QuadTo )
          {
            trans->Transform(trans, &x2, &y2);
            trans->Transform(trans, &x3, &y3);
            v22 = Scaleform::Render::Math2D::CheckQuadraticIntersection(v7, x1, y1, x2, y2, x3, y3, x, y);
            x1 = x3;
            v19 = y3;
            goto LABEL_20;
          }
          if ( v9 == Edge_CubicTo )
          {
            trans->Transform(trans, &x2, &y2);
            trans->Transform(trans, &x3, &y3);
            trans->Transform(trans, &v33, &v34);
            v22 = Scaleform::Render::Math2D::CheckCubicIntersection(v7, x1, y1, x2, y2, x3, y3, v33, v34, x, y);
            x1 = v33;
            v19 = v34;
LABEL_20:
            v7 = v22;
LABEL_21:
            y1 = v19;
          }
          v9 = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)v35, &x2);
          if ( v9 == Edge_EndPath )
            goto LABEL_25;
        }
        trans->Transform(trans, &x2, &y2);
        v10 = x1;
        v27 = x1;
        v11 = y1;
        v38 = y1;
        v26 = x2;
        v25 = y2;
        if ( y2 >= v11 )
        {
          v15 = y2;
          v13 = x2;
        }
        else
        {
          v27 = x2;
          v12 = v10;
          v13 = x2;
          v26 = v12;
          v38 = y2;
          v14 = v11;
          v15 = y2;
          v25 = v14;
        }
        v16 = y;
        if ( v38 > (double)y || v25 <= v16 || (v39 = (x - v26) * (v25 - v38) - (v26 - v27) * (v16 - v25), v39 <= 0.0) )
        {
          v20 = v15;
          v21 = v13;
          v19 = v20;
          x1 = v21;
        }
        else
        {
          v17 = v15;
          v18 = v13;
          v19 = v17;
          v7 ^= 1u;
          x1 = v18;
        }
        goto LABEL_21;
      }
    }
LABEL_25:
    v8 = shape->ReadPathInfo(shape, (Scaleform::Render::ShapePosInfo *)v35, &x2, v28);
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


bool __cdecl Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
        const Scaleform::Render::ShapeDataInterface *shape,
        const Scaleform::Render::Matrix2x4<float> *trans,
        float x,
        float y)
{
  unsigned int v5; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  int v7; // ebp
  Scaleform::Render::ShapePathType v8; // eax
  Scaleform::Render::ShapeDataInterface_vtbl *v9; // edx
  Scaleform::Render::PathEdgeType (__thiscall *ReadEdge)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *); // edx
  Scaleform::Render::PathEdgeType v11; // eax
  double v12; // st7
  double v13; // st6
  double v14; // st4
  double v15; // st7
  double v16; // st5
  double v17; // st6
  double v18; // st5
  double v19; // rtt
  double v20; // st6
  double v21; // st7
  double v22; // rt0
  double v23; // st6
  int v24; // eax
  float y1; // [esp+4Ch] [ebp-68h]
  float v27; // [esp+4Ch] [ebp-68h]
  float v28; // [esp+50h] [ebp-64h]
  float v29; // [esp+54h] [ebp-60h]
  float v30; // [esp+54h] [ebp-60h]
  float v31; // [esp+54h] [ebp-60h]
  float v32; // [esp+54h] [ebp-60h]
  float v33; // [esp+54h] [ebp-60h]
  float v34; // [esp+54h] [ebp-60h]
  float v35; // [esp+54h] [ebp-60h]
  float v36[3]; // [esp+58h] [ebp-5Ch] BYREF
  float x2; // [esp+64h] [ebp-50h] BYREF
  float y2; // [esp+68h] [ebp-4Ch]
  float x3; // [esp+6Ch] [ebp-48h]
  float y3; // [esp+70h] [ebp-44h]
  float v41; // [esp+74h] [ebp-40h]
  float v42; // [esp+78h] [ebp-3Ch]
  _DWORD v43[13]; // [esp+7Ch] [ebp-38h] BYREF
  int v44; // [esp+B0h] [ebp-4h]
  float v45; // [esp+B8h] [ebp+4h]
  float x1; // [esp+B8h] [ebp+4h]
  float v47; // [esp+B8h] [ebp+4h]
  float v48; // [esp+B8h] [ebp+4h]

  v5 = shape->GetStartingPos(shape);
  *(float *)&v43[12] = 1.0;
  v43[0] = v5;
  ReadPathInfo = shape->ReadPathInfo;
  memset(&v43[1], 0, 44);
  LOBYTE(v44) = 0;
  v7 = 0;
  v8 = ReadPathInfo(shape, (Scaleform::Render::ShapePosInfo *)v43, &x2, (unsigned int *)v36);
  if ( v8 == Shape_EndShape )
    return v7 != 0;
  while ( v8 != Shape_NewLayer )
  {
LABEL_5:
    v9 = shape->__vftable;
    if ( (LODWORD(v36[0]) == 0) == (LODWORD(v36[1]) == 0) )
    {
      v9->SkipPathData(shape, (Scaleform::Render::ShapePosInfo *)v43);
    }
    else
    {
      ReadEdge = v9->ReadEdge;
      v45 = x2;
      x2 = x2 * trans->M[0][0] + y2 * trans->M[0][1] + trans->M[0][3];
      y2 = y2 * trans->M[1][1] + trans->M[1][0] * v45 + trans->M[1][3];
      x1 = x2;
      y1 = y2;
      v11 = ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)v43, &x2);
      if ( v11 )
      {
        while ( v11 != Edge_LineTo )
        {
          if ( v11 == Edge_QuadTo )
          {
            v31 = x2;
            x2 = x2 * trans->M[0][0] + y2 * trans->M[0][1] + trans->M[0][3];
            y2 = y2 * trans->M[1][1] + trans->M[1][0] * v31 + trans->M[1][3];
            v32 = x3;
            x3 = x3 * trans->M[0][0] + y3 * trans->M[0][1] + trans->M[0][3];
            y3 = y3 * trans->M[1][1] + trans->M[1][0] * v32 + trans->M[1][3];
            v24 = Scaleform::Render::Math2D::CheckQuadraticIntersection(v7, x1, y1, x2, y2, x3, y3, x, y);
            x1 = x3;
            v21 = y3;
            goto LABEL_20;
          }
          if ( v11 == Edge_CubicTo )
          {
            v33 = x2;
            x2 = x2 * trans->M[0][0] + y2 * trans->M[0][1] + trans->M[0][3];
            y2 = y2 * trans->M[1][1] + trans->M[1][0] * v33 + trans->M[1][3];
            v34 = x3;
            x3 = x3 * trans->M[0][0] + y3 * trans->M[0][1] + trans->M[0][3];
            y3 = y3 * trans->M[1][1] + trans->M[1][0] * v34 + trans->M[1][3];
            v35 = v41;
            v41 = v41 * trans->M[0][0] + v42 * trans->M[0][1] + trans->M[0][3];
            v42 = v42 * trans->M[1][1] + trans->M[1][0] * v35 + trans->M[1][3];
            v24 = Scaleform::Render::Math2D::CheckCubicIntersection(v7, x1, y1, x2, y2, x3, y3, v41, v42, x, y);
            x1 = v41;
            v21 = v42;
LABEL_20:
            v7 = v24;
LABEL_21:
            y1 = v21;
          }
          v11 = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)v43, &x2);
          if ( v11 == Edge_EndPath )
            goto LABEL_25;
        }
        v29 = x2;
        x2 = x2 * trans->M[0][0] + y2 * trans->M[0][1] + trans->M[0][3];
        y2 = y2 * trans->M[1][1] + trans->M[1][0] * v29 + trans->M[1][3];
        v12 = x1;
        v30 = x1;
        v13 = y1;
        v47 = y1;
        v28 = x2;
        v27 = y2;
        if ( y2 >= v13 )
        {
          v17 = y2;
          v15 = x2;
        }
        else
        {
          v30 = x2;
          v14 = v12;
          v15 = x2;
          v28 = v14;
          v47 = y2;
          v16 = v13;
          v17 = y2;
          v27 = v16;
        }
        v18 = y;
        if ( v47 > (double)y || v27 <= v18 || (v48 = (x - v28) * (v27 - v47) - (v28 - v30) * (v18 - v27), v48 <= 0.0) )
        {
          v22 = v17;
          v23 = v15;
          v21 = v22;
          x1 = v23;
        }
        else
        {
          v19 = v17;
          v20 = v15;
          v21 = v19;
          v7 ^= 1u;
          x1 = v20;
        }
        goto LABEL_21;
      }
    }
LABEL_25:
    v8 = shape->ReadPathInfo(shape, (Scaleform::Render::ShapePosInfo *)v43, &x2, (unsigned int *)v36);
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
