void __cdecl Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(
        const Scaleform::Render::ShapeDataInterface *shape,
        const Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::Rect<float> *bounds,
        Scaleform::Render::BoundEdges edgesToCheck)
{
  unsigned int v4; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  bool v6; // zf
  int v7; // [esp+10h] [ebp-5Ch] BYREF
  int v8; // [esp+14h] [ebp-58h]
  float v9[6]; // [esp+1Ch] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo v10; // [esp+34h] [ebp-38h] BYREF

  v4 = shape->GetStartingPos(shape);
  v10.Sfactor = 1.0;
  v10.Pos = v4;
  ReadPathInfo = shape->ReadPathInfo;
  memset(&v10.StartX, 0, 44);
  v10.Initialized = 0;
  if ( ReadPathInfo(shape, &v10, v9, (unsigned int *)&v7) )
  {
    do
    {
      if ( edgesToCheck )
      {
        if ( edgesToCheck != Bound_FillEdges )
        {
          if ( edgesToCheck == Bound_AllEdges )
            goto LABEL_11;
          goto LABEL_5;
        }
        v6 = v7 == v8;
      }
      else
      {
        v6 = (v7 == 0) == (v8 == 0);
      }
      if ( !v6 )
      {
LABEL_11:
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          shape,
          *(float *)&trans,
          &v10,
          COERCE_FLOAT(v9),
          bounds);
        continue;
      }
LABEL_5:
      shape->SkipPathData(shape, &v10);
    }
    while ( shape->ReadPathInfo(shape, &v10, v9, (unsigned int *)&v7) );
  }
}
