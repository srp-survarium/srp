void __thiscall Scaleform::GFx::ImportData::AddSymbol(
        Scaleform::GFx::ImportData *this,
        const __m128i *psymbolName,
        int characterId,
        unsigned int bindIndex)
{
  Scaleform::GFx::ImportData::Symbol *v5; // esi
  void *v6; // esi
  unsigned int v7; // [esp-4h] [ebp-14h]
  Scaleform::String src; // [esp+4h] [ebp-Ch] BYREF
  int v9; // [esp+8h] [ebp-8h]
  unsigned int v10; // [esp+Ch] [ebp-4h]

  Scaleform::String::String(&src);
  Scaleform::String::operator=(&src, psymbolName);
  v7 = this->Imports.Data.Size + 1;
  v9 = characterId;
  v10 = bindIndex;
  Scaleform::ArrayDataBase<Scaleform::GFx::ImportData::Symbol,Scaleform::AllocatorLH<Scaleform::GFx::ImportData::Symbol,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Imports.Data,
    this,
    v7);
  v5 = &this->Imports.Data.Data[this->Imports.Data.Size - 1];
  if ( v5 )
  {
    Scaleform::String::String(&v5->SymbolName, &src);
    v5->CharacterId = v9;
    v5->BindIndex = v10;
  }
  v6 = (void *)(src.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
}
