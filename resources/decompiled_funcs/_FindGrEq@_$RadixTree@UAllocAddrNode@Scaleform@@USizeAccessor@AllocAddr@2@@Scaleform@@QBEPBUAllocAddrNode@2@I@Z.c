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
  const Scaleform::AllocAddrNode *rst; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  rst = 0;
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
      rst = v7;
    if ( !result )
    {
      for ( j = rst; j; j = j->SizeChild[j->SizeChild[0] == 0] )
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
