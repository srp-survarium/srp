Scaleform::GFx::FontManagerStates *__thiscall Scaleform::GFx::FontManagerStates::`vector deleting destructor'(
        Scaleform::GFx::FontManagerStates *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pTranslator.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pFontProvider.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->pFontMap.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pFontLib.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::GFx::FontManagerStates::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::GFx::FontManagerStates::`vector deleting destructor'(
           (Scaleform::GFx::FontManagerStates *)(this - 8),
           a2);
}
