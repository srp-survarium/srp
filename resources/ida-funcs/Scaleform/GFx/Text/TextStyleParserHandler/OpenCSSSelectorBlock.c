void __thiscall Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::OpenCSSSelectorBlock(
        Scaleform::GFx::Text::TextStyleParserHandler<wchar_t> *this,
        Scaleform::Render::Text::Style *name,
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *pdata)
{
  unsigned int pHeap; // eax
  int v5; // edi
  const wchar_t *v6; // edx
  Scaleform::String *pManager; // eax
  const Scaleform::GFx::Text::StyleKey *v8; // esi
  Scaleform::GFx::Text::StyleManager *v9; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeHashF> >::TableType *pTable; // edi
  signed int v11; // eax
  int v12; // eax
  Scaleform::Render::Text::Style **v13; // eax
  Scaleform::Render::Text::Style *v14; // eax
  Scaleform::MemoryHeap *v15; // edi
  Scaleform::Render::Text::Style *v16; // eax
  Scaleform::Render::Text::Style *v17; // eax
  unsigned int HashValue; // eax
  Scaleform::GFx::Text::StyleManager *v19; // ecx
  unsigned int Size; // eax
  unsigned int v21; // esi
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // edx
  Scaleform::Render::Text::Style **v23; // esi
  void *v24; // esi
  Scaleform::String keystr; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Render::Text::Style *v26; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey> >::NodeRef key; // [esp+18h] [ebp-8h] BYREF
  Scaleform::Render::Text::Style *pstyle; // [esp+24h] [ebp+4h]

  Scaleform::String::String(&keystr);
  pHeap = (unsigned int)name->mTextFormat.FontList.pHeap;
  v5 = 0;
  if ( pHeap && (v6 = (const wchar_t *)name->mTextFormat.FontList.pData, *v6 == 46) )
  {
    v5 = 1;
    Scaleform::String::AppendString(&keystr, (wchar_t *)v6 + 1, pHeap - 1);
  }
  else
  {
    Scaleform::String::AppendString(
      &keystr,
      (wchar_t *)name->mTextFormat.FontList.pData,
      (int)name->mTextFormat.FontList.pHeap);
  }
  pManager = (Scaleform::String *)this->pManager;
  v8 = (const Scaleform::GFx::Text::StyleKey *)&pManager[2];
  pManager[2].HeapTypeBits = v5;
  Scaleform::String::operator=(pManager + 3, &keystr);
  v8->HashValue = Scaleform::String::BernsteinHashFunction(
                    (char *)((keystr.HeapTypeBits & 0xFFFFFFFC) + 8),
                    *(_DWORD *)(keystr.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
                    0x1505u)
                + v8->Type;
  v9 = this->pManager;
  pTable = v9->Styles.mHash.pTable;
  if ( pTable
    && (v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF>>::findIndexCore<Scaleform::GFx::Text::StyleKey>(
                &v9->Styles.mHash,
                v8,
                v8->HashValue & pTable->SizeMask),
        v11 >= 0)
    && (v12 = (int)(&pTable[1].SizeMask + 5 * v11)) != 0
    && (v13 = (Scaleform::Render::Text::Style **)(v12 + 12)) != 0
    && (v14 = *v13, (pstyle = v14) != 0) )
  {
    Scaleform::Render::Text::Style::Reset(v14);
  }
  else
  {
    v15 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v9);
    v16 = (Scaleform::Render::Text::Style *)v15->Alloc(v15, 60u, 0);
    if ( v16 )
    {
      Scaleform::Render::Text::Style::Style(v16, v15);
      pstyle = v17;
    }
    else
    {
      pstyle = 0;
    }
    v26 = pstyle;
    HashValue = v8->HashValue;
    v19 = this->pManager;
    key.pSecond = &v26;
    key.pFirst = v8;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeRef>(
      &v19->Styles.mHash,
      &v19->Styles,
      &key,
      HashValue);
  }
  Size = pdata->Size;
  v21 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v21 >= pdata->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        pdata,
        pdata,
        v21 + (v21 >> 2));
  }
  else if ( v21 < pdata->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      pdata,
      pdata,
      v21);
  }
  Data = pdata->Data;
  pdata->Size = v21;
  v23 = (Scaleform::Render::Text::Style **)&Data[v21 - 1];
  if ( v23 )
    *v23 = pstyle;
  v24 = (void *)(keystr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((keystr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v24);
}
