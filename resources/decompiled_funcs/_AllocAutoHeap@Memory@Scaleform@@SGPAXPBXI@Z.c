void *__stdcall Scaleform::Memory::AllocAutoHeap(const void *p, unsigned int size)
{
  return Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, p, size, 0);
}
