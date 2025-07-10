BOOL __cdecl Scaleform::Render::Tessellator::cmpStrokerEdges(
        const Scaleform::Render::Tessellator::StrokerEdgeType *a,
        const Scaleform::Render::Tessellator::StrokerEdgeType *b)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  bool v4; // cf

  v2 = a->node1 & 0xFFFFFFF;
  v3 = b->node1 & 0xFFFFFFF;
  v4 = v2 < v3;
  if ( v2 == v3 )
    return (a->node2 & 0xFFFFFFF) < (b->node2 & 0xFFFFFFF);
  return v4;
}
