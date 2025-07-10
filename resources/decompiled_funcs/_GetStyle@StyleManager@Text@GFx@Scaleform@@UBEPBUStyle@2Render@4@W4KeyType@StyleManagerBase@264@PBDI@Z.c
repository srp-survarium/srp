const Scaleform::Render::Text::Style *__thiscall Scaleform::GFx::Text::StyleManager::GetStyle(
        Scaleform::GFx::Text::StyleManager *this,
        Scaleform::Render::Text::StyleManagerBase::KeyType type,
        char *name,
        Scaleform::String len)
{
  unsigned int HeapTypeBits; // eax
  const Scaleform::Render::Text::Style *v6; // eax
  void *v7; // esi
  const Scaleform::Render::Text::Style *v8; // edi

  HeapTypeBits = len.HeapTypeBits;
  if ( len.pData == (Scaleform::String::DataDesc *)-1 )
    HeapTypeBits = strlen(name);
  Scaleform::String::String(&len, name, HeapTypeBits);
  v6 = this->GetStyle(this, type, &len);
  v7 = (void *)(len.HeapTypeBits & 0xFFFFFFFC);
  v8 = v6;
  if ( InterlockedExchangeAdd((volatile LONG *)((len.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  return v8;
}
