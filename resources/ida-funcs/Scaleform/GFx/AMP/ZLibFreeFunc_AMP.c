void __cdecl Scaleform::GFx::AMP::ZLibFreeFunc_AMP(void *__formal, void *address)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, address);
}
