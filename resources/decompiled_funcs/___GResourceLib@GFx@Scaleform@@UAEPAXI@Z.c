Scaleform::GFx::ResourceLib *__thiscall Scaleform::GFx::ResourceLib::`scalar deleting destructor'(
        Scaleform::GFx::ResourceLib *this,
        char a2)
{
  Scaleform::GFx::ResourceWeakLib *pWeakLib; // ecx

  pWeakLib = this->pWeakLib;
  this->__vftable = (Scaleform::GFx::ResourceLib_vtbl *)&Scaleform::GFx::ResourceLib::`vftable';
  if ( pWeakLib )
  {
    Scaleform::GFx::ResourceWeakLib::UnpinAll(pWeakLib);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pWeakLib);
  }
  Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::Clear(&this->PinSet);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
