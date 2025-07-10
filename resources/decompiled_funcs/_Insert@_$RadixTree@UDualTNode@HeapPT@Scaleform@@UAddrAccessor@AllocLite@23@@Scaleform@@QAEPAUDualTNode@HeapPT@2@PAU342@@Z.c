Scaleform::HeapPT::DualTNode *__thiscall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Insert(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this,
        Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::DualTNode *result; // eax
  unsigned int v3; // edi
  Scaleform::HeapPT::DualTNode **v4; // esi

  node->AddrChild[1] = 0;
  node->AddrChild[0] = 0;
  node->AddrParent = 0;
  result = this->Root;
  if ( this->Root )
  {
    v3 = (unsigned int)node;
    if ( result != node )
    {
      while ( 1 )
      {
        v4 = &result->AddrChild[v3 >> 31];
        v3 *= 2;
        if ( !*v4 )
          break;
        result = *v4;
        if ( *v4 == node )
          return result;
      }
      *v4 = node;
      node->AddrParent = result;
      return 0;
    }
  }
  else
  {
    this->Root = node;
    node->AddrParent = (Scaleform::HeapPT::DualTNode *)this;
  }
  return result;
}
