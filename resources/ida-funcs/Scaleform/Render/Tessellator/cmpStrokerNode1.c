BOOL __cdecl Scaleform::Render::Tessellator::cmpStrokerNode1(
        const Scaleform::Render::Tessellator::StrokerEdgeType *e,
        unsigned int node)
{
  return (e->node1 & 0xFFFFFFF) < (node & 0xFFFFFFF);
}
