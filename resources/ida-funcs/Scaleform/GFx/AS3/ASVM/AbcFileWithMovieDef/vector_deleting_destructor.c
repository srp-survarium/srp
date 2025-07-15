Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *__thiscall Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::`vector deleting destructor'(
        Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::MovieDefImpl *v4; // ecx

  this->__vftable = (Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef_vtbl *)&Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pAbcData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pDefImpl.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  Scaleform::GFx::AS3::Abc::File::~File(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
