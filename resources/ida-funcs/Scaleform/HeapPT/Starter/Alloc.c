// attributes: thunk
Scaleform::HeapPT::DualTNode *__thiscall Scaleform::HeapPT::Starter::Alloc(
        Scaleform::HeapPT::Starter *this,
        unsigned int size,
        unsigned int alignSize)
{
  return Scaleform::HeapPT::Granulator::Alloc(&this->Allocator, size, alignSize);
}
