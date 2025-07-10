Scaleform::AllocAddrNode *__thiscall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Insert(
        Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor> *this,
        Scaleform::AllocAddrNode *node)
{
  Scaleform::AllocAddrNode *result; // eax
  unsigned int Addr; // ebx
  unsigned int v4; // esi
  Scaleform::AllocAddrNode **v5; // edx

  node->AddrChild[1] = 0;
  node->AddrChild[0] = 0;
  node->AddrParent = 0;
  result = this->Root;
  if ( this->Root )
  {
    Addr = node->Addr;
    v4 = Addr;
    if ( result->Addr != Addr )
    {
      while ( 1 )
      {
        v5 = &result->AddrChild[v4 >> 31];
        v4 *= 2;
        if ( !*v5 )
          break;
        result = *v5;
        if ( (*v5)->Addr == Addr )
          return result;
      }
      *v5 = node;
      node->AddrParent = result;
      return 0;
    }
  }
  else
  {
    this->Root = node;
    node->AddrParent = (Scaleform::AllocAddrNode *)this;
  }
  return result;
}
