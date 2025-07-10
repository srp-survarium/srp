void *__cdecl Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(unsigned int sz)
{
  return Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, sz, 0);
}
