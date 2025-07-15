Scaleform::GFx::AMP::SendThreadCallback *__thiscall Scaleform::GFx::AMP::SendThreadCallback::`vector deleting destructor'(
        Scaleform::GFx::AMP::SendThreadCallback *this,
        char a2)
{
  this->Scaleform::RefCountBase<Scaleform::GFx::AMP::SendThreadCallback,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AMP::SendThreadCallback_vtbl *)&Scaleform::GFx::AMP::SendThreadCallback::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::AMP::SendThreadCallback,579>'};
  this->Scaleform::GFx::AMP::SendInterface::__vftable = (Scaleform::GFx::AMP::SendInterface_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::GFx::AMP::SendThreadCallback *__thiscall Scaleform::GFx::AMP::SendThreadCallback::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::GFx::AMP::SendThreadCallback::`vector deleting destructor'(
           (Scaleform::GFx::AMP::SendThreadCallback *)(this - 8),
           a2);
}
