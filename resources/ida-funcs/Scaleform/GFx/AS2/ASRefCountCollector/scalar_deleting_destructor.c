Scaleform::GFx::AS2::ASRefCountCollector *__thiscall Scaleform::GFx::AS2::ASRefCountCollector::`scalar deleting destructor'(
        Scaleform::GFx::AS2::ASRefCountCollector *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS2::ASRefCountCollector_vtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::`vftable';
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, 0);
  this->ListRoot.Scaleform::GFx::AS2::RefCountCollector<323>::__vftable = (Scaleform::GFx::AS2::RefCountCollector<323>::Root_vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable';
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease(&this->Roots);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
