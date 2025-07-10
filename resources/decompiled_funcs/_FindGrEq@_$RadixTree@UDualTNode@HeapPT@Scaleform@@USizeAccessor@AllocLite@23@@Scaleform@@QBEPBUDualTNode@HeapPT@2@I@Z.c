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
  const Scaleform::HeapPT::DualTNode *rst; // [esp+10h] [ebp-4h]

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
    v7 = result->Child[1];
    result = result->Child[i >> 31];
    if ( v7 && v7 != result )
      rst = v7;
    if ( !result )
    {
      for ( j = rst; j; j = j->Child[j->Child[0] == 0] )
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
