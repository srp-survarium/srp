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
