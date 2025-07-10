Scaleform::GFx::LogState *__thiscall Scaleform::GFx::LogState::`scalar deleting destructor'(
        Scaleform::GFx::LogState *this,
        char a2)
{
  Scaleform::Log *pObject; // ecx

  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::LogState_vtbl *)&Scaleform::GFx::LogState::`vftable'{for `Scaleform::GFx::State'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState>_vtbl *)&Scaleform::GFx::LogState::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LogState>'};
  pObject = this->pLog.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::LogState_vtbl *)&Scaleform::GFx::State::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
