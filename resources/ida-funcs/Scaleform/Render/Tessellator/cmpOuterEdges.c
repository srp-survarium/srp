BOOL __cdecl Scaleform::Render::Tessellator::cmpOuterEdges(
        const Scaleform::Render::Tessellator::StrokerEdgeType *a1,
        const Scaleform::Render::Tessellator::StrokerEdgeType *a2)
{
  unsigned int v2; // edx
  unsigned int v3; // esi
  bool v4; // cf

  v2 = *(_DWORD *)a1->node1;
  v3 = *(_DWORD *)a2->node1;
  v4 = v2 < v3;
  if ( v2 == v3 )
    return *(_DWORD *)(a1->node1 + 4) < *(_DWORD *)(a2->node1 + 4);
  return v4;
}
