char __cdecl Scaleform::Render::HitTestFillAndStrokes<Scaleform::Render::TransformerBase>(
        const Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::TransformerBase *trans,
        float x,
        float y,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  if ( Scaleform::Render::HitTestFill<Scaleform::Render::TransformerBase>(shape, trans, x, y) )
    return 1;
  if ( !shape->GetStrokeStyleCount(shape) )
    return 0;
  shape->Rewind(shape);
  return Scaleform::Render::HitTestShapeStrokes<Scaleform::Render::TransformerBase>(
           shape,
           (Scaleform::Render::ShapePosInfo *)trans,
           x,
           y,
           gen,
           tol);
}
