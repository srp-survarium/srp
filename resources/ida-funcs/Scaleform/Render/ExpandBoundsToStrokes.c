void __cdecl Scaleform::Render::ExpandBoundsToStrokes<Scaleform::Render::Matrix2x4<float>>(
        const Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol,
        Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::ShapeDataInterface_vtbl *v5; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  Scaleform::Render::ShapePosInfo pos; // [esp+Ch] [ebp-94h] BYREF
  unsigned int styles[3]; // [esp+44h] [ebp-5Ch] BYREF
  float coord[6]; // [esp+50h] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo prevPos; // [esp+68h] [ebp-38h] BYREF

  pos.Pos = shape->GetStartingPos(shape);
  pos.Sfactor = 1.0;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  v5 = shape->__vftable;
  qmemcpy(&prevPos, &pos, sizeof(prevPos));
  if ( v5->ReadPathInfo(shape, &pos, coord, styles) )
  {
    do
    {
      qmemcpy(&pos, &prevPos, sizeof(pos));
      Scaleform::Render::ExpandBoundsToLayerStrokes<Scaleform::Render::Matrix2x4<float>>(
        shape,
        &pos,
        trans,
        gen,
        tol,
        bounds);
      ReadPathInfo = shape->ReadPathInfo;
      qmemcpy(&prevPos, &pos, sizeof(prevPos));
    }
    while ( ReadPathInfo(shape, &pos, coord, styles) );
  }
}
