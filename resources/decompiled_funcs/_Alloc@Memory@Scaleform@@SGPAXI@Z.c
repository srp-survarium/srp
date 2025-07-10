void *__stdcall Scaleform::Memory::Alloc(unsigned int size)
{
  return Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, size, 0);
}
