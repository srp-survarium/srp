Scaleform::AllocAddrNode *__thiscall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Insert(
        Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *this,
        Scaleform::AllocAddrNode *node)
{
  Scaleform::AllocAddrNode *result; // eax
  unsigned int Size; // ebx
  unsigned int v4; // esi
  Scaleform::AllocAddrNode **v5; // edx

  node->SizeChild[1] = 0;
  node->SizeChild[0] = 0;
  node->SizeParent = 0;
  result = this->Root;
  if ( this->Root )
  {
    Size = node->Size;
    v4 = Size;
    if ( result->Size != Size )
    {
      while ( 1 )
      {
        v5 = &result->SizeChild[v4 >> 31];
        v4 *= 2;
        if ( !*v5 )
          break;
        result = *v5;
        if ( (*v5)->Size == Size )
          return result;
      }
      *v5 = node;
      node->SizeParent = result;
      return 0;
    }
  }
  else
  {
    this->Root = node;
    node->SizeParent = (Scaleform::AllocAddrNode *)this;
  }
  return result;
}
