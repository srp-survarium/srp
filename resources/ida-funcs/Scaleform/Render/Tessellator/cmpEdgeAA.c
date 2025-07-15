BOOL __cdecl Scaleform::Render::Tessellator::cmpEdgeAA(
        const Scaleform::Render::Tessellator::TmpEdgeAAType *a,
        const Scaleform::Render::Tessellator::TmpEdgeAAType *b)
{
  if ( b->slope == a->slope )
    return a->style < b->style;
  else
    return b->slope > (double)a->slope;
}
