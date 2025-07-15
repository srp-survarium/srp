void *__cdecl Scaleform::GFx::ZLibAllocFunc(void *opaque, unsigned int items, unsigned int size)
{
  return Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, opaque, size * items, 0);
}
