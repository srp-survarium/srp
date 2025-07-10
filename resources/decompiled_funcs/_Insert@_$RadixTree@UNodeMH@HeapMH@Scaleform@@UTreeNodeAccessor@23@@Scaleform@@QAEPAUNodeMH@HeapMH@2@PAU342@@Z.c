Scaleform::HeapMH::NodeMH *__thiscall Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Insert(
        Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor> *this,
        Scaleform::HeapMH::NodeMH *node)
{
  Scaleform::HeapMH::NodeMH *result; // eax
  unsigned int v3; // edi
  Scaleform::HeapMH::NodeMH **v4; // esi

  node->Child[1] = 0;
  node->Child[0] = 0;
  node->Parent = 0;
  result = this->Root;
  if ( this->Root )
  {
    v3 = (unsigned int)node;
    if ( result != node )
    {
      while ( 1 )
      {
        v4 = &result->Child[v3 >> 31];
        v3 *= 2;
        if ( !*v4 )
          break;
        result = *v4;
        if ( *v4 == node )
          return result;
      }
      *v4 = node;
      node->Parent = result;
      return 0;
    }
  }
  else
  {
    this->Root = node;
    node->Parent = (Scaleform::HeapMH::NodeMH *)this;
  }
  return result;
}
