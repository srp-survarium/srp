Scaleform::Render::Rect<float> *__cdecl Scaleform::Render::ComputeBoundsFill<Scaleform::Render::Matrix2x4<float>>(
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::ShapeDataInterface *shape,
        const Scaleform::Render::Matrix2x4<float> *trans,
        Scaleform::Render::BoundEdges edgesToCheck)
{
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  Scaleform::Render::ExpandBoundsToFill<Scaleform::Render::Matrix2x4<float>>(shape, trans, result, edgesToCheck);
  return result;
}
