const Scaleform::AllocAddrNode *__thiscall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindGrEq(
        Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor> *this,
        unsigned int key)
{
  const Scaleform::AllocAddrNode *result; // eax
  const Scaleform::AllocAddrNode *v3; // ebp
  unsigned int v4; // edi
  unsigned int i; // ebx
  unsigned int v6; // ecx
  const Scaleform::AllocAddrNode *v7; // ecx
  const Scaleform::AllocAddrNode *j; // ecx
  const Scaleform::AllocAddrNode *v9; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  v9 = 0;
  for ( i = key; ; i *= 2 )
  {
    v6 = result->Addr - key;
    if ( result->Addr >= key && v6 < v4 )
    {
      v3 = result;
      v4 = result->Addr - key;
      if ( !v6 )
        break;
    }
    v7 = result->AddrChild[1];
    result = result->AddrChild[i >> 31];
    if ( v7 && v7 != result )
      v9 = v7;
    if ( !result )
    {
      for ( j = v9; j; j = j->AddrChild[j->AddrChild[0] == 0] )
      {
        if ( j->Addr >= key && j->Addr - key < v4 )
        {
          v4 = j->Addr - key;
          v3 = j;
        }
      }
      return v3;
    }
  }
  return result;
}


const Scaleform::AllocAddrNode *__thiscall Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::FindGrEq(
        Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *this,
        unsigned int key)
{
  const Scaleform::AllocAddrNode *result; // eax
  const Scaleform::AllocAddrNode *v3; // ebp
  unsigned int v4; // edi
  unsigned int i; // ebx
  unsigned int v6; // ecx
  const Scaleform::AllocAddrNode *v7; // ecx
  const Scaleform::AllocAddrNode *j; // ecx
  const Scaleform::AllocAddrNode *v9; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  v9 = 0;
  for ( i = key; ; i *= 2 )
  {
    v6 = result->Size - key;
    if ( result->Size >= key && v6 < v4 )
    {
      v3 = result;
      v4 = result->Size - key;
      if ( !v6 )
        break;
    }
    v7 = result->SizeChild[1];
    result = result->SizeChild[i >> 31];
    if ( v7 && v7 != result )
      v9 = v7;
    if ( !result )
    {
      for ( j = v9; j; j = j->SizeChild[j->SizeChild[0] == 0] )
      {
        if ( j->Size >= key && j->Size - key < v4 )
        {
          v4 = j->Size - key;
          v3 = j;
        }
      }
      return v3;
    }
  }
  return result;
}


const Scaleform::HeapPT::DualTNode *__thiscall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *this,
        unsigned int key)
{
  const Scaleform::HeapPT::DualTNode *result; // eax
  const Scaleform::HeapPT::DualTNode *v3; // ebp
  unsigned int v4; // edx
  unsigned int i; // edi
  char *v6; // ecx
  const Scaleform::HeapPT::DualTNode *v7; // ecx
  const Scaleform::HeapPT::DualTNode *j; // eax
  const Scaleform::HeapPT::DualTNode *v9; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  v9 = 0;
  for ( i = key; ; i *= 2 )
  {
    v6 = (char *)result - key;
    if ( (unsigned int)result >= key && (unsigned int)v6 < v4 )
    {
      v3 = result;
      v4 = (unsigned int)result - key;
      if ( !v6 )
        break;
    }
    v7 = result->AddrChild[1];
    result = result->AddrChild[i >> 31];
    if ( v7 && v7 != result )
      v9 = v7;
    if ( !result )
    {
      for ( j = v9; j; j = j->AddrChild[j->AddrChild[0] == 0] )
      {
        if ( (unsigned int)j >= key && (unsigned int)j - key < v4 )
        {
          v4 = (unsigned int)j - key;
          v3 = j;
        }
      }
      return v3;
    }
  }
  return result;
}


const Scaleform::HeapPT::DualTNode *__thiscall Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
        Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *this,
        unsigned int key)
{
  const Scaleform::HeapPT::DualTNode *result; // eax
  const Scaleform::HeapPT::DualTNode *v3; // ebp
  unsigned int v4; // edi
  unsigned int i; // ebx
  unsigned int v6; // ecx
  const Scaleform::HeapPT::DualTNode *v7; // ecx
  const Scaleform::HeapPT::DualTNode *j; // ecx
  const Scaleform::HeapPT::DualTNode *v9; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  v9 = 0;
  for ( i = key; ; i *= 2 )
  {
    v6 = result->Size - key;
    if ( result->Size >= key && v6 < v4 )
    {
      v3 = result;
      v4 = result->Size - key;
      if ( !v6 )
        break;
    }
    v7 = result->Child[1];
    result = result->Child[i >> 31];
    if ( v7 && v7 != result )
      v9 = v7;
    if ( !result )
    {
      for ( j = v9; j; j = j->Child[j->Child[0] == 0] )
      {
        if ( j->Size >= key && j->Size - key < v4 )
        {
          v4 = j->Size - key;
          v3 = j;
        }
      }
      return v3;
    }
  }
  return result;
}


const Scaleform::HeapMH::NodeMH *__thiscall Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
        Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor> *this,
        unsigned int key)
{
  const Scaleform::HeapMH::NodeMH *result; // eax
  const Scaleform::HeapMH::NodeMH *v3; // ebp
  unsigned int v4; // edx
  unsigned int i; // edi
  char *v6; // ecx
  const Scaleform::HeapMH::NodeMH *v7; // ecx
  const Scaleform::HeapMH::NodeMH *j; // eax
  const Scaleform::HeapMH::NodeMH *v9; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  v9 = 0;
  for ( i = key; ; i *= 2 )
  {
    v6 = (char *)result - key;
    if ( (unsigned int)result >= key && (unsigned int)v6 < v4 )
    {
      v3 = result;
      v4 = (unsigned int)result - key;
      if ( !v6 )
        break;
    }
    v7 = result->Child[1];
    result = result->Child[i >> 31];
    if ( v7 && v7 != result )
      v9 = v7;
    if ( !result )
    {
      for ( j = v9; j; j = j->Child[j->Child[0] == 0] )
      {
        if ( (unsigned int)j >= key && (unsigned int)j - key < v4 )
        {
          v4 = (unsigned int)j - key;
          v3 = j;
        }
      }
      return v3;
    }
  }
  return result;
}
