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
  const Scaleform::HeapPT::DualTNode *rst; // [esp+10h] [ebp-4h]

  result = this->Root;
  v3 = 0;
  v4 = -1;
  if ( !this->Root )
    return v3;
  rst = 0;
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
      rst = v7;
    if ( !result )
    {
      for ( j = rst; j; j = j->AddrChild[j->AddrChild[0] == 0] )
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
