void __cdecl Scaleform::GFx::ZLibFreeFunc(void *__formal, void *address)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, address);
}
