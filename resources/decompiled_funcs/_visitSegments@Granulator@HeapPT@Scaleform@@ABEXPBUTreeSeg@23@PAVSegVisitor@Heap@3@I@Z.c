void __thiscall Scaleform::HeapPT::Granulator::visitSegments(
        Scaleform::HeapPT::Granulator *this,
        const Scaleform::HeapPT::TreeSeg *node,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned int cat)
{
  const Scaleform::HeapPT::TreeSeg *v4; // esi
  unsigned int v6; // ebp
  unsigned __int8 *Buffer; // ecx
  unsigned int v8; // eax

  v4 = node;
  if ( node )
  {
    v6 = cat;
    do
    {
      Scaleform::HeapPT::Granulator::visitSegments(this, v4->AddrChild[0], visitor, v6);
      Buffer = v4->Buffer;
      v8 = Buffer == (unsigned __int8 *)v4->Headers + this->HdrPageSize ? this->HdrPageSize : 0;
      v6 = cat;
      visitor->Visit(visitor, cat, 0, (unsigned int)&Buffer[-v8 + 4095] & 0xFFFFF000, (v8 + v4->Size) & 0xFFFFF000);
      v4 = v4->AddrChild[1];
    }
    while ( v4 );
  }
}
