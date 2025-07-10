void __thiscall Scaleform::GFx::Text::StyleManager::ClearStyle(
        Scaleform::GFx::Text::StyleManager *this,
        Scaleform::Render::Text::StyleManagerBase::KeyType type,
        char *name,
        Scaleform::String len)
{
  unsigned int HeapTypeBits; // eax
  void *v6; // esi

  HeapTypeBits = len.HeapTypeBits;
  if ( len.pData == (Scaleform::String::DataDesc *)-1 )
    HeapTypeBits = strlen(name);
  Scaleform::String::String(&len, name, HeapTypeBits);
  Scaleform::GFx::Text::StyleManager::ClearStyle(this, type, &len);
  v6 = (void *)(len.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((len.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
}
