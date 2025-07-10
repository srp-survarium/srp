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
