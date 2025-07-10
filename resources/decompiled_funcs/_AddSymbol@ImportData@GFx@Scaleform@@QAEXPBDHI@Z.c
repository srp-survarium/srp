void __thiscall Scaleform::GFx::ImportData::AddSymbol(
        Scaleform::GFx::ImportData *this,
        char *psymbolName,
        int characterId,
        unsigned int bindIndex)
{
  Scaleform::GFx::ImportData::Symbol *v5; // esi
  void *v6; // esi
  unsigned int v7; // [esp-4h] [ebp-14h]
  Scaleform::GFx::ImportData::Symbol s; // [esp+4h] [ebp-Ch] BYREF

  Scaleform::String::String(&s.SymbolName);
  Scaleform::String::operator=(&s.SymbolName, psymbolName);
  v7 = this->Imports.Data.Size + 1;
  s.CharacterId = characterId;
  s.BindIndex = bindIndex;
  Scaleform::ArrayDataBase<Scaleform::GFx::ImportData::Symbol,Scaleform::AllocatorLH<Scaleform::GFx::ImportData::Symbol,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Imports.Data,
    this,
    v7);
  v5 = &this->Imports.Data.Data[this->Imports.Data.Size - 1];
  if ( v5 )
  {
    Scaleform::String::String(&v5->SymbolName, &s.SymbolName);
    v5->CharacterId = s.CharacterId;
    v5->BindIndex = s.BindIndex;
  }
  v6 = (void *)(s.SymbolName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((s.SymbolName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
}
