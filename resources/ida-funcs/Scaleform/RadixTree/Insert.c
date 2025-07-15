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


Scaleform::HeapPT::TreeSeg *__thiscall Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::Insert(
        Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *this,
        Scaleform::HeapPT::TreeSeg *node)
{
  Scaleform::HeapPT::TreeSeg *result; // eax
  unsigned __int8 *Buffer; // ebx
  unsigned int v4; // esi
  Scaleform::HeapPT::TreeSeg **v5; // edx

  node->AddrChild[1] = 0;
  node->AddrChild[0] = 0;
  node->AddrParent = 0;
  result = this->Root;
  if ( this->Root )
  {
    Buffer = node->Buffer;
    v4 = (unsigned int)Buffer;
    if ( result->Buffer != Buffer )
    {
      while ( 1 )
      {
        v5 = &result->AddrChild[v4 >> 31];
        v4 *= 2;
        if ( !*v5 )
          break;
        result = *v5;
        if ( (*v5)->Buffer == Buffer )
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
    node->AddrParent = (Scaleform::HeapPT::TreeSeg *)this;
  }
  return result;
}
