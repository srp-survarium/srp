Scaleform::Render::ShapePathType __usercall Scaleform::Render::AddStrokeToSorter<Scaleform::Render::TransformerBase>@<eax>(
        float *a1@<edi>,
        unsigned int *a2@<esi>,
        const Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *pos,
        unsigned int strokeStyleIdx,
        Scaleform::Render::ShapePosInfo *trans,
        Scaleform::Render::StrokeGenerator *gen,
        int a8,
        Scaleform::Render::StrokeSorter *a9)
{
  void (__thiscall *Clear)(struct Scaleform::Render::StrokeSorter *); // edx
  Scaleform::Render::StrokeSorter *p_mStrokeSorter; // ebp
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  Scaleform::Render::ShapePosInfo *v13; // esi
  Scaleform::Render::PathEdgeType i; // eax
  Scaleform::Render::ShapeDataInterface_vtbl *v15; // eax
  Scaleform::Render::ShapePathType (__thiscall *v16)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  unsigned int styles[3]; // [esp+60h] [ebp-5Ch] BYREF
  float coord[6]; // [esp+6Ch] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo prevPos; // [esp+84h] [ebp-38h] BYREF
  Scaleform::Render::ShapePathType pathType; // [esp+C0h] [ebp+4h]
  Scaleform::Render::StrokeSorter *gena; // [esp+D0h] [ebp+14h]

  Clear = gen->mStrokeSorter.Clear;
  p_mStrokeSorter = &gen->mStrokeSorter;
  gena = &gen->mStrokeSorter;
  Clear(gena);
  ReadPathInfo = shape->ReadPathInfo;
  qmemcpy(&prevPos, pos, sizeof(prevPos));
  pathType = ReadPathInfo(shape, pos, coord, styles);
  if ( pathType )
  {
    do
    {
      if ( styles[2] == strokeStyleIdx )
      {
        (*(void (__thiscall **)(Scaleform::Render::ShapePosInfo *, float *, float *, float *, unsigned int *))(trans->Pos + 4))(
          trans,
          coord,
          &coord[1],
          a1,
          a2);
        Scaleform::Render::StrokeSorter::AddVertexNV(a9, coord[2], coord[3], 1u);
        v13 = trans;
        for ( i = shape->ReadEdge(shape, trans, &coord[2]); i; i = shape->ReadEdge(shape, trans, &coord[2]) )
        {
          switch ( i )
          {
            case Edge_LineTo:
              (*(void (__thiscall **)(Scaleform::Render::ShapePosInfo *, float *, float *))(trans->Pos + 4))(
                trans,
                &coord[2],
                &coord[3]);
              Scaleform::Render::StrokeSorter::AddVertexNV(a9, coord[2], coord[3], 1u);
              break;
            case Edge_QuadTo:
              (*(void (__thiscall **)(Scaleform::Render::ShapePosInfo *, float *, float *))(trans->Pos + 4))(
                trans,
                &coord[2],
                &coord[3]);
              (*(void (__thiscall **)(Scaleform::Render::ShapePosInfo *, float *, float *))(trans->Pos + 4))(
                trans,
                &coord[4],
                &coord[5]);
              Scaleform::Render::StrokeSorter::AddQuad(a9, coord[2], coord[3], coord[4], coord[5]);
              break;
            case Edge_CubicTo:
              (*(void (__thiscall **)(Scaleform::Render::ShapePosInfo *, float *, float *))(trans->Pos + 4))(
                trans,
                &coord[2],
                &coord[3]);
              (*(void (__thiscall **)(Scaleform::Render::ShapePosInfo *, float *, float *))(trans->Pos + 4))(
                trans,
                &coord[4],
                &coord[5]);
              (*(void (__thiscall **)(Scaleform::Render::ShapePosInfo *, Scaleform::Render::ShapePosInfo *, int *))(trans->Pos + 4))(
                trans,
                &prevPos,
                &prevPos.StartX);
              Scaleform::Render::StrokeSorter::AddCubic(
                a9,
                coord[2],
                coord[3],
                coord[4],
                coord[5],
                *(float *)&prevPos.Pos,
                *(float *)&prevPos.StartX);
              break;
          }
        }
        a9->FinalizePath(a9, 0, 0, 0, 0);
      }
      else
      {
        ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))shape->SkipPathData)(
          shape,
          pos,
          a1,
          a2);
        v13 = trans;
      }
      v15 = shape->__vftable;
      qmemcpy(&prevPos.StartY, v13, sizeof(Scaleform::Render::ShapePosInfo));
      a2 = &styles[2];
      a1 = &coord[2];
      v16 = v15->ReadPathInfo;
      HIBYTE(styles[1]) = 0;
      pathType = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *))v16)(
                   shape,
                   trans);
    }
    while ( pathType );
    p_mStrokeSorter = gena;
  }
  qmemcpy(pos, &prevPos, sizeof(Scaleform::Render::ShapePosInfo));
  Scaleform::Render::StrokeSorter::Sort(p_mStrokeSorter);
  return pathType;
}
