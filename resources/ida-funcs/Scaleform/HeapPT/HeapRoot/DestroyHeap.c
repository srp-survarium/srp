void __thiscall Scaleform::HeapPT::HeapRoot::DestroyHeap(
        Scaleform::HeapPT::HeapRoot *this,
        Scaleform::MemoryHeapPT *heap)
{
  Scaleform::HeapPT::AllocEngine::FreeAll(heap->pEngine);
  ((void (__thiscall *)(Scaleform::MemoryHeapPT *, _DWORD))heap->~Scaleform::MemoryHeap)(heap, 0);
  Scaleform::HeapPT::Bookkeeper::Free(&this->AllocBookkeeper, (unsigned int)heap, heap->SelfSize);
}
