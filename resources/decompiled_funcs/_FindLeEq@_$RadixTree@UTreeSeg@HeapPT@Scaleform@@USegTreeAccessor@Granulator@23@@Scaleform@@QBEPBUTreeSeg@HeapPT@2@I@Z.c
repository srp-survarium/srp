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
