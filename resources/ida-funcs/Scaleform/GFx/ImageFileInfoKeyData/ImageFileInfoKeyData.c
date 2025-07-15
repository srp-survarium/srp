void __thiscall Scaleform::GFx::ImageFileInfoKeyData::ImageFileInfoKeyData(
        Scaleform::GFx::ImageFileInfoKeyData *this,
        Scaleform::GFx::ImageFileInfo *pfileInfo,
        Scaleform::GFx::Resource *pfileOpener,
        Scaleform::GFx::Resource *pimageCreator,
        Scaleform::MemoryHeap *pimageHeap)
{
  Scaleform::GFx::ImageFileInfo *pObject; // ecx
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::RefCountVImpl *v8; // ecx

  this->__vftable = (Scaleform::GFx::ImageFileInfoKeyData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::ImageFileInfoKeyData_vtbl *)&Scaleform::GFx::ImageFileInfoKeyData::`vftable';
  this->pFileOpener.pObject = 0;
  this->pImageCreator.pObject = 0;
  this->pFileInfo.pObject = 0;
  if ( pfileInfo )
    ++pfileInfo->RefCount;
  pObject = this->pFileInfo.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pFileInfo.pObject = pfileInfo;
  if ( pfileOpener )
    Scaleform::RefCountImpl::AddRef(pfileOpener);
  v7 = (Scaleform::RefCountVImpl *)this->pFileOpener.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  this->pFileOpener.pObject = (Scaleform::GFx::FileOpener *)pfileOpener;
  if ( pimageCreator )
    Scaleform::RefCountImpl::AddRef(pimageCreator);
  v8 = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  this->pImageCreator.pObject = (Scaleform::GFx::ImageCreator *)pimageCreator;
  this->pImageHeap = pimageHeap;
}
