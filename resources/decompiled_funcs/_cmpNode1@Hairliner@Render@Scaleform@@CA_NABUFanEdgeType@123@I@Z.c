BOOL __cdecl Scaleform::Render::Hairliner::cmpNode1(const Scaleform::Render::Hairliner::FanEdgeType *a, unsigned int b)
{
  return (a->node1 & 0x7FFFFFFF) < b;
}
