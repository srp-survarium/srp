Scaleform::HeapPT::DualTNode *__thiscall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Insert(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *this,
        Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::DualTNode *result; // eax
  unsigned int Size; // ebx
  unsigned int v4; // esi
  Scaleform::HeapPT::DualTNode **v5; // edx

  node->Child[1] = 0;
  node->Child[0] = 0;
  node->Parent = 0;
  result = this->Root;
  if ( this->Root )
  {
    Size = node->Size;
    v4 = Size;
    if ( result->Size != Size )
    {
      while ( 1 )
      {
        v5 = &result->Child[v4 >> 31];
        v4 *= 2;
        if ( !*v5 )
          break;
        result = *v5;
        if ( (*v5)->Size == Size )
          return result;
      }
      *v5 = node;
      node->Parent = result;
      return 0;
    }
  }
  else
  {
    this->Root = node;
    node->Parent = (Scaleform::HeapPT::DualTNode *)this;
  }
  return result;
}
