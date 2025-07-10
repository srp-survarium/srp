void *__cdecl Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(unsigned int sz)
{
  return Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, sz, 0);
}
