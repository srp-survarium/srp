void __cdecl Scaleform::linearizeTree(
        Scaleform::AllocAddrNode *root,
        Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *nodes)
{
  Scaleform::AllocAddrNode *i; // esi

  for ( i = root; i; i = i->AddrChild[1] )
  {
    Scaleform::linearizeTree(i->AddrChild[0], nodes);
    i->pPrev = nodes->Root.pPrev;
    i->pNext = (Scaleform::AllocAddrNode *)nodes;
    nodes->Root.pPrev->pNext = i;
    nodes->Root.pPrev = i;
  }
}
