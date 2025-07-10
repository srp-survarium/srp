Scaleform::Render::UserDataState::Data *__thiscall Scaleform::Render::UserDataState::Data::`scalar deleting destructor'(
        Scaleform::Render::UserDataState::Data *this,
        char a2)
{
  volatile LONG *v3; // esi

  v3 = (volatile LONG *)(this->RendererString.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->Scaleform::RefCountBase<Scaleform::Render::UserDataState::Data,2>);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this);
  return this;
}
