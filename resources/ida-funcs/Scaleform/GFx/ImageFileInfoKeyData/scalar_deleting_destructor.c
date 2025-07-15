Scaleform::GFx::ImageFileInfoKeyData *__thiscall Scaleform::GFx::ImageFileInfoKeyData::`scalar deleting destructor'(
        Scaleform::GFx::ImageFileInfoKeyData *this,
        char a2)
{
  Scaleform::GFx::ImageFileInfo *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx

  pObject = this->pFileInfo.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->pFileOpener.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
