BOOL __cdecl Scaleform::Render::Scale9GridTess::cmpSlopes(
        const Scaleform::Render::Tessellator::IntersectionType *a,
        const Scaleform::Render::Tessellator::IntersectionType *b)
{
  return b->y > (double)a->y;
}
