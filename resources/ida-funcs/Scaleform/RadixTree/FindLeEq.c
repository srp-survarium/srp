const Scaleform::AllocAddrNode *__thiscall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(
        Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor> *this,
        unsigned int key)
{
  const Scaleform::AllocAddrNode *result; // eax
  const Scaleform::AllocAddrNode *v3; // ebp
  unsigned int v4; // edi
  unsigned int i; // ebx
  unsigned int Addr; // edx
  unsigned int v7; // ecx
  const Scaleform::AllocAddrNode *v8; // ecx
  const Scaleform::AllocAddrNode *j; // ecx
  unsigned int v10; // edx
  const Scaleform::AllocAddrNode *lst; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  lst = 0;
  for ( i = key; ; i *= 2 )
  {
    Addr = result->Addr;
    v7 = key - Addr;
    if ( Addr <= key && v7 < v4 )
    {
      v3 = result;
      v4 = key - Addr;
      if ( !v7 )
        break;
    }
    v8 = result->AddrChild[0];
    result = result->AddrChild[i >> 31];
    if ( v8 && v8 != result )
      lst = v8;
    if ( !result )
    {
      for ( j = lst; j; j = j->AddrChild[j->AddrChild[1] != 0] )
      {
        v10 = j->Addr;
        if ( v10 <= key && key - v10 < v4 )
        {
          v4 = key - v10;
          v3 = j;
        }
      }
      return v3;
    }
  }
  return result;
}


const Scaleform::HeapPT::DualTNode *__thiscall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this,
        unsigned int key)
{
  const Scaleform::HeapPT::DualTNode *result; // eax
  const Scaleform::HeapPT::DualTNode *v3; // ebp
  unsigned int v4; // edx
  unsigned int i; // edi
  unsigned int v6; // ecx
  const Scaleform::HeapPT::DualTNode *v7; // ecx
  unsigned int v8; // eax
  const Scaleform::HeapPT::DualTNode *lst; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  lst = 0;
  for ( i = key; ; i *= 2 )
  {
    v6 = key - (_DWORD)result;
    if ( (unsigned int)result <= key && v6 < v4 )
    {
      v3 = result;
      v4 = key - (_DWORD)result;
      if ( !v6 )
        break;
    }
    v7 = result->AddrChild[0];
    result = result->AddrChild[i >> 31];
    if ( v7 && v7 != result )
      lst = v7;
    if ( !result )
    {
      v8 = (unsigned int)lst;
      if ( lst )
      {
        do
        {
          if ( v8 <= key && key - v8 < v4 )
          {
            v4 = key - v8;
            v3 = (const Scaleform::HeapPT::DualTNode *)v8;
          }
          v8 = *(_DWORD *)(v8 + 4 * (*(_DWORD *)(v8 + 28) != 0) + 24);
        }
        while ( v8 );
      }
      return v3;
    }
  }
  return result;
}


const Scaleform::HeapPT::TreeSeg *__thiscall Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
        Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor> *this,
        unsigned int key)
{
  const Scaleform::HeapPT::TreeSeg *result; // eax
  const Scaleform::HeapPT::TreeSeg *v3; // ebp
  unsigned int v4; // edi
  unsigned int i; // ebx
  unsigned __int8 *Buffer; // edx
  unsigned int v7; // ecx
  const Scaleform::HeapPT::TreeSeg *v8; // ecx
  const Scaleform::HeapPT::TreeSeg *j; // ecx
  unsigned int v10; // edx
  const Scaleform::HeapPT::TreeSeg *lst; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  lst = 0;
  for ( i = key; ; i *= 2 )
  {
    Buffer = result->Buffer;
    v7 = key - (_DWORD)Buffer;
    if ( (unsigned int)Buffer <= key && v7 < v4 )
    {
      v3 = result;
      v4 = key - (_DWORD)Buffer;
      if ( !v7 )
        break;
    }
    v8 = result->AddrChild[0];
    result = result->AddrChild[i >> 31];
    if ( v8 && v8 != result )
      lst = v8;
    if ( !result )
    {
      for ( j = lst; j; j = j->AddrChild[j->AddrChild[1] != 0] )
      {
        v10 = (unsigned int)j->Buffer;
        if ( v10 <= key && key - v10 < v4 )
        {
          v4 = key - v10;
          v3 = j;
        }
      }
      return v3;
    }
  }
  return result;
}
