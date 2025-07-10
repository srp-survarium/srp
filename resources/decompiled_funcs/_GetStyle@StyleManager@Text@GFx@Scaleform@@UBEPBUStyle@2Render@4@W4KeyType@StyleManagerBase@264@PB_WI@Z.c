const Scaleform::Render::Text::Style *__thiscall Scaleform::GFx::Text::StyleManager::GetStyle(
        Scaleform::GFx::Text::StyleManager *this,
        Scaleform::Render::Text::StyleManagerBase::KeyType type,
        const wchar_t *name,
        Scaleform::String len)
{
  int pData; // edi
  const Scaleform::Render::Text::Style *v6; // eax
  void *v7; // esi
  const Scaleform::Render::Text::Style *v8; // edi

  pData = (int)len.pData;
  if ( len.pData == (Scaleform::String::DataDesc *)-1 )
    pData = Scaleform::SFwcslen(name);
  Scaleform::String::String(&len);
  Scaleform::String::AppendString(&len, name, pData);
  v6 = this->GetStyle(this, type, &len);
  v7 = (void *)(len.HeapTypeBits & 0xFFFFFFFC);
  v8 = v6;
  if ( InterlockedExchangeAdd((volatile LONG *)((len.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  return v8;
}
