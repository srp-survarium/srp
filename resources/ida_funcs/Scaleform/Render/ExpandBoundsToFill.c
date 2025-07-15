void __cdecl Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(
        const Scaleform::Render::ShapeDataInterface *shape,
        const Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::Rect<float> *bounds,
        Scaleform::Render::BoundEdges edgesToCheck)
{
  unsigned int v4; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  bool v6; // zf
  unsigned int styles[3]; // [esp+10h] [ebp-5Ch] BYREF
  float coord[6]; // [esp+1Ch] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+34h] [ebp-38h] BYREF

  v4 = shape->GetStartingPos(shape);
  pos.Sfactor = 1.0;
  pos.Pos = v4;
  ReadPathInfo = shape->ReadPathInfo;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  if ( ReadPathInfo(shape, &pos, coord, styles) )
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
        v6 = styles[0] == styles[1];
      }
      else
      {
        v6 = (styles[0] == 0) == (styles[1] == 0);
      }
      if ( !v6 )
      {
LABEL_11:
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          shape,
          *(float *)&trans,
          &pos,
          COERCE_FLOAT(coord),
          bounds);
        continue;
      }
LABEL_5:
      shape->SkipPathData(shape, &pos);
    }
    while ( shape->ReadPathInfo(shape, &pos, coord, styles) );
  }
}
