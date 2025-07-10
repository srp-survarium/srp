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
