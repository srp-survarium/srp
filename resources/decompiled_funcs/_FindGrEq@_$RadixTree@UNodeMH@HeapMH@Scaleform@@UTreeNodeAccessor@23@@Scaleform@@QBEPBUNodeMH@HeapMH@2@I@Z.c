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
  const Scaleform::HeapMH::NodeMH *rst; // [esp+10h] [ebp-4h]

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
    v7 = result->Child[1];
    result = result->Child[i >> 31];
    if ( v7 && v7 != result )
      rst = v7;
    if ( !result )
    {
      for ( j = rst; j; j = j->Child[j->Child[0] == 0] )
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
