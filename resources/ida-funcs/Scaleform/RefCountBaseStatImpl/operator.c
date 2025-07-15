void *__cdecl Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(unsigned int sz)
{
  return Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, sz, 0);
}


void *__cdecl Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(
        unsigned int sz,
        Scaleform::MemAddressStub *adr)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = 2;
  return Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, adr, sz, &v3);
}


void *__cdecl Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,78>::operator new(
        unsigned int sz,
        Scaleform::MemAddressStub *adr)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = 78;
  return Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, adr, sz, &v3);
}


void *__cdecl Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(unsigned int sz)
{
  return Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, sz, 0);
}
