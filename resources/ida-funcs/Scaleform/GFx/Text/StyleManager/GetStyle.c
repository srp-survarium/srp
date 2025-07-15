const Scaleform::Render::Text::Style *__thiscall Scaleform::GFx::Text::StyleManager::GetStyle(
        Scaleform::GFx::Text::StyleManager *this,
        Scaleform::Render::Text::StyleManagerBase::KeyType type,
        const Scaleform::String *name)
{
  Scaleform::GFx::Text::StyleKey *p_TempKey; // esi
  unsigned int v5; // edx
  Scaleform::HashUncachedLH<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>,325> *p_Styles; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> >::TableType *pTable; // edi
  signed int v8; // eax
  int v9; // eax
  int v10; // eax

  p_TempKey = &this->TempKey;
  this->TempKey.Type = type;
  Scaleform::String::operator=(&this->TempKey.Value, name);
  v5 = Scaleform::String::BernsteinHashFunction(
         (char *)((name->HeapTypeBits & 0xFFFFFFFC) + 8),
         *(_DWORD *)(name->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
         0x1505u)
     + p_TempKey->Type;
  p_Styles = &this->Styles;
  p_TempKey->HashValue = v5;
  pTable = this->Styles.mHash.pTable;
  if ( pTable
    && (v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF>>::findIndexCore<Scaleform::GFx::Text::StyleKey>(
               &p_Styles->mHash,
               p_TempKey,
               v5 & pTable->SizeMask),
        v8 >= 0)
    && (v9 = (int)(&pTable[1].SizeMask + 5 * v8)) != 0
    && (v10 = v9 + 12) != 0 )
  {
    return *(const Scaleform::Render::Text::Style **)v10;
  }
  else
  {
    return 0;
  }
}


const Scaleform::Render::Text::Style *__thiscall Scaleform::GFx::Text::StyleManager::GetStyle(
        Scaleform::GFx::Text::StyleManager *this,
        Scaleform::Render::Text::StyleManagerBase::KeyType type,
        const __m128i *name,
        Scaleform::String len)
{
  unsigned int HeapTypeBits; // eax
  const Scaleform::Render::Text::Style *v6; // eax
  void *v7; // esi
  const Scaleform::Render::Text::Style *v8; // edi

  HeapTypeBits = len.HeapTypeBits;
  if ( len.pData == (Scaleform::String::DataDesc *)-1 )
    HeapTypeBits = strlen(name->m128i_i8);
  Scaleform::String::String(&len, name, HeapTypeBits);
  v6 = this->GetStyle(this, type, &len);
  v7 = (void *)(len.HeapTypeBits & 0xFFFFFFFC);
  v8 = v6;
  if ( InterlockedExchangeAdd((volatile LONG *)((len.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  return v8;
}


const Scaleform::Render::Text::Style *__thiscall Scaleform::GFx::Text::StyleManager::GetStyle(
        Scaleform::GFx::Text::StyleManager *this,
        Scaleform::Render::Text::StyleManagerBase::KeyType type,
        wchar_t *name,
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
