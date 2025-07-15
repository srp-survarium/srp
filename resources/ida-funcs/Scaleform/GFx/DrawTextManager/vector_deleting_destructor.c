Scaleform::GFx::DrawTextManager *__thiscall Scaleform::GFx::DrawTextManager::`vector deleting destructor'(
        Scaleform::GFx::DrawTextManager *this,
        char a2)
{
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // edi

  pImpl = this->pImpl;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::DrawTextManager_vtbl *)&Scaleform::GFx::DrawTextManager::`vftable'{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>'};
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::DrawTextManager::`vftable'{for `Scaleform::GFx::StateBag'};
  if ( pImpl )
  {
    Scaleform::GFx::DrawTextManagerImpl::~DrawTextManagerImpl(pImpl);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImpl);
  }
  this->pHeap->Release(this->pHeap);
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::GFx::DrawTextManager *__thiscall Scaleform::GFx::DrawTextManager::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::GFx::DrawTextManager::`vector deleting destructor'(
           (Scaleform::GFx::DrawTextManager *)(this - 8),
           a2);
}
