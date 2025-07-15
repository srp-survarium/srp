BOOL __cdecl Scaleform::Render::Hairliner::cmpEdges(
        const Scaleform::Render::Hairliner::FanEdgeType *a,
        const Scaleform::Render::Hairliner::FanEdgeType *b)
{
  if ( a->node1 == b->node1 )
    return b->slope > (double)a->slope;
  else
    return a->node1 < b->node1;
}
