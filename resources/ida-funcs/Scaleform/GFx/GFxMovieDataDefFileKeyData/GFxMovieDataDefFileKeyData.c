void __thiscall Scaleform::GFx::GFxMovieDataDefFileKeyData::GFxMovieDataDefFileKeyData(
        Scaleform::GFx::GFxMovieDataDefFileKeyData *this,
        const __m128i *pfilename,
        __int64 modifyTime,
        Scaleform::GFx::Resource *pfileOpener,
        Scaleform::GFx::Resource *pimageCreator)
{
  Scaleform::String *p_FileName; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v8; // ecx

  this->__vftable = (Scaleform::GFx::GFxMovieDataDefFileKeyData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  p_FileName = &this->FileName;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::GFxMovieDataDefFileKeyData_vtbl *)&Scaleform::GFx::GFxMovieDataDefFileKeyData::`vftable';
  Scaleform::String::String(&this->FileName);
  this->pFileOpener.pObject = 0;
  this->pImageCreator.pObject = 0;
  Scaleform::String::operator=(p_FileName, pfilename);
  this->ModifyTime = modifyTime;
  if ( pfileOpener )
    Scaleform::RefCountImpl::AddRef(pfileOpener);
  pObject = (Scaleform::RefCountVImpl *)this->pFileOpener.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFileOpener.pObject = (Scaleform::GFx::FileOpener *)pfileOpener;
  if ( pimageCreator )
    Scaleform::RefCountImpl::AddRef(pimageCreator);
  v8 = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  this->pImageCreator.pObject = (Scaleform::GFx::ImageCreator *)pimageCreator;
}
