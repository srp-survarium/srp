void __thiscall Scaleform::GFx::Text::StyleManager::ClearStyle(
        Scaleform::GFx::Text::StyleManager *this,
        Scaleform::Render::Text::StyleManagerBase::KeyType type,
        const Scaleform::String *name)
{
  Scaleform::GFx::Text::StyleKey *p_TempKey; // esi
  unsigned int v5; // edx
  Scaleform::HashUncachedLH<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>,325> *p_Styles; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> >::TableType *pTable; // edi
  signed int v8; // eax
  int v9; // eax
  int *v10; // eax
  int v11; // edi

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
  if ( pTable )
  {
    v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF>>::findIndexCore<Scaleform::GFx::Text::StyleKey>(
           &p_Styles->mHash,
           p_TempKey,
           v5 & pTable->SizeMask);
    if ( v8 >= 0 )
    {
      v9 = (int)(&pTable[1].SizeMask + 5 * v8);
      if ( v9 )
      {
        v10 = (int *)(v9 + 12);
        if ( v10 )
        {
          v11 = *v10;
          if ( *v10 )
          {
            Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)(v11 + 40));
            Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)v11);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v11);
          }
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::Text::StyleKey>(
            &p_Styles->mHash,
            p_TempKey);
        }
      }
    }
  }
}


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
