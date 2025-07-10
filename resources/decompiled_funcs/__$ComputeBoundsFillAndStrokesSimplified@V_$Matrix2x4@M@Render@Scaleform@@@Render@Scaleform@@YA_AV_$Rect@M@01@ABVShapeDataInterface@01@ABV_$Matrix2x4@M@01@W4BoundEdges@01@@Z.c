Scaleform::Render::Rect<float> *__cdecl Scaleform::Render::ComputeBoundsFillAndStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::ShapeDataInterface *shape,
        Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::BoundEdges edgesToCheck)
{
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(shape, trans, result, edgesToCheck);
  if ( shape->GetStrokeStyleCount(shape) )
  {
    shape->Rewind(shape);
    Scaleform::Render::ExpandBoundsToStrokesSimplified<Scaleform::Render::Matrix2x4<float>>(shape, trans, result);
  }
  return result;
}
