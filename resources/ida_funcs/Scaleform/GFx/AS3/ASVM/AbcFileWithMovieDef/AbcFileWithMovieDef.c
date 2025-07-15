void __thiscall Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::AbcFileWithMovieDef(
        Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::Resource *data)
{
  Scaleform::GFx::AS3::Abc::File::File(this);
  this->__vftable = (Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef_vtbl *)&Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::`vftable';
  if ( pdefImpl )
    Scaleform::RefCountImpl::AddRef(pdefImpl);
  this->pDefImpl.pObject = pdefImpl;
  if ( data )
    Scaleform::RefCountImpl::AddRef(data);
  this->pAbcData.pObject = (Scaleform::GFx::AS3::AbcDataBuffer *)data;
}
