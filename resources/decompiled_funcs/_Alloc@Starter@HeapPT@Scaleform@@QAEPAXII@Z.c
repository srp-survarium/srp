// attributes: thunk
unsigned __int8 *__thiscall Scaleform::HeapPT::Starter::Alloc(
        Scaleform::HeapPT::Starter *this,
        unsigned int size,
        Scaleform::HeapPT::TreeSeg *alignSize)
{
  return Scaleform::HeapPT::Granulator::Alloc(&this->Allocator, size, alignSize);
}
