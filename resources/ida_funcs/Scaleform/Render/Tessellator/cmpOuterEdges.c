BOOL __cdecl Scaleform::Render::Tessellator::cmpOuterEdges(
        const Scaleform::Render::Tessellator::OuterEdgeType *a,
        const Scaleform::Render::Tessellator::OuterEdgeType *b)
{
  Scaleform::Render::Tessellator::MonoVertexType *cntVer; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v3; // esi
  bool v4; // cf

  cntVer = a->edge->cntVer;
  v3 = b->edge->cntVer;
  v4 = cntVer < v3;
  if ( cntVer == v3 )
    return a->edge->rayVer < b->edge->rayVer;
  return v4;
}
