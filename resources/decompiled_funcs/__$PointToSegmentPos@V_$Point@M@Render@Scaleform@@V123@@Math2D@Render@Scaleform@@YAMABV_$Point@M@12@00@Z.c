double __cdecl Scaleform::Render::Math2D::PointToSegmentPos<Scaleform::Render::Point<float>,Scaleform::Render::Point<float>>(
        const Scaleform::Render::Point<float> *v1,
        const Scaleform::Render::Point<float> *v2,
        const Scaleform::Render::Point<float> *v)
{
  return Scaleform::Render::Math2D::PointToSegmentPos(v1->x, v1->y, v2->x, v2->y, v->x, v->y);
}
