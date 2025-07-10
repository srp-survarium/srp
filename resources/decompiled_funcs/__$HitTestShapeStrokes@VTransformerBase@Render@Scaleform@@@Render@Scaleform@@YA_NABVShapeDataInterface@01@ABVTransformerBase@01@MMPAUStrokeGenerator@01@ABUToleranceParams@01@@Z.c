char __cdecl Scaleform::Render::HitTestShapeStrokes<Scaleform::Render::TransformerBase>(
        const Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::ShapePosInfo *trans,
        float x,
        float y,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  Scaleform::Render::ShapeDataInterface_vtbl *v6; // eax
  Scaleform::Render::ShapeDataInterface_vtbl *v7; // eax
  Scaleform::Render::ShapePosInfo pos; // [esp+2Ch] [ebp-94h] BYREF
  unsigned int styles[3]; // [esp+64h] [ebp-5Ch] BYREF
  float coord[6]; // [esp+70h] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo prevPos; // [esp+88h] [ebp-38h] BYREF

  pos.Pos = shape->GetStartingPos(shape);
  pos.Sfactor = 1.0;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  v6 = shape->__vftable;
  qmemcpy(&prevPos, &pos, sizeof(prevPos));
  if ( v6->ReadPathInfo(shape, &pos, coord, styles) == Shape_EndShape )
    return 0;
  while ( 1 )
  {
    qmemcpy(&pos, &prevPos, sizeof(pos));
    if ( Scaleform::Render::HitTestLayerStrokes<Scaleform::Render::TransformerBase>(shape, &pos, trans, x, y, gen, tol) )
      break;
    v7 = shape->__vftable;
    qmemcpy(&prevPos, &pos, sizeof(prevPos));
    if ( v7->ReadPathInfo(shape, &pos, coord, styles) == Shape_EndShape )
      return 0;
  }
  return 1;
}
