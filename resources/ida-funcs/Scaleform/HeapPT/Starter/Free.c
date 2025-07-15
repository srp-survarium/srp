// attributes: thunk
void __thiscall Scaleform::HeapPT::Starter::Free(
        Scaleform::HeapPT::Starter *this,
        Scaleform::HeapPT::DualTNode *ptr,
        unsigned int size,
        unsigned int alignSize)
{
  Scaleform::HeapPT::Granulator::Free(&this->Allocator, ptr, size, alignSize);
}
