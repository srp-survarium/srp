BOOL __cdecl Scaleform::Render::Tessellator::cmpStrokerEdges(
        const Scaleform::Render::Tessellator::StrokerEdgeType *a1,
        const Scaleform::Render::Tessellator::StrokerEdgeType *a2)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  bool v4; // cf

  v2 = a1->node1 & 0xFFFFFFF;
  v3 = a2->node1 & 0xFFFFFFF;
  v4 = v2 < v3;
  if ( v2 == v3 )
    return (a1->node2 & 0xFFFFFFF) < (a2->node2 & 0xFFFFFFF);
  return v4;
}
