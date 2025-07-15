void __thiscall Scaleform::GFx::AMP::ServerState::~ServerState(Scaleform::GFx::AMP::ServerState *this)
{
  volatile LONG *v2; // edi
  volatile LONG *v3; // edi
  volatile LONG *v4; // edi
  volatile LONG *v5; // edi
  volatile LONG *v6; // edi

  Scaleform::ConstructorMov<Scaleform::String>::DestructArray(this->Locales.Data.Data, this->Locales.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Locales.Data.Data);
  v2 = (volatile LONG *)(this->CurrentLocale.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  v3 = (volatile LONG *)(this->StrokeType.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (volatile LONG *)(this->AaMode.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  v5 = (volatile LONG *)(this->ConnectedFile.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
  v6 = (volatile LONG *)(this->ConnectedApp.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v6 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->Scaleform::RefCountBase<Scaleform::GFx::AMP::ServerState,578>);
}
