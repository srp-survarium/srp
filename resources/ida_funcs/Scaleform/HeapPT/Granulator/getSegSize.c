unsigned int __thiscall Scaleform::HeapPT::Granulator::getSegSize(
        Scaleform::HeapPT::Granulator *this,
        const Scaleform::HeapPT::TreeSeg *seg)
{
  unsigned __int16 HeadBytes; // si
  unsigned int Size; // eax

  HeadBytes = seg->HeadBytes;
  if ( HeadBytes )
    Size = this->Allocator.MinSize - HeadBytes + HeadBytes + seg->Size;
  else
    Size = seg->Size;
  return (seg->Buffer == (unsigned __int8 *)seg->Headers + this->HdrPageSize ? this->HdrPageSize : 0) + Size;
}
