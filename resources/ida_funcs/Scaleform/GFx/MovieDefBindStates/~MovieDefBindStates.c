void __thiscall Scaleform::GFx::MovieDefBindStates::~MovieDefBindStates(Scaleform::GFx::MovieDefBindStates *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::GFx::URLBuilder *v8; // ecx
  Scaleform::GFx::FileOpener *v9; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pImagePackParams.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::RefCountVImpl *)this->pFontCompactorParams.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::RefCountVImpl *)this->pFontPackParams.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->pImportVisitor.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pImageFileHandlerRegistry.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v7 = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = this->pURLBulider.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
  v9 = this->pFileOpener.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
