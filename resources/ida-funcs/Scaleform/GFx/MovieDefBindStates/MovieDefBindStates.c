void __thiscall Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(
        Scaleform::GFx::MovieDefBindStates *this,
        Scaleform::GFx::MovieDefBindStates *pother)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::GFx::Resource *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::GFx::Resource *v7; // ecx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::GFx::Resource *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::Resource *v11; // ecx
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::GFx::Resource *v13; // ecx
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::GFx::Resource *v15; // ecx
  Scaleform::RefCountVImpl *v16; // ecx

  this->__vftable = (Scaleform::GFx::MovieDefBindStates_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::MovieDefBindStates_vtbl *)&Scaleform::GFx::MovieDefBindStates::`vftable';
  this->pFileOpener.pObject = 0;
  this->pURLBulider.pObject = 0;
  this->pImageCreator.pObject = 0;
  this->pImageFileHandlerRegistry.pObject = 0;
  this->pImportVisitor.pObject = 0;
  this->pFontPackParams.pObject = 0;
  this->pFontCompactorParams.pObject = 0;
  this->pImagePackParams.pObject = 0;
  pObject = (Scaleform::GFx::Resource *)pother->pFileOpener.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pFileOpener.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->pFileOpener.pObject = pother->pFileOpener.pObject;
  v5 = (Scaleform::GFx::Resource *)pother->pURLBulider.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::AddRef(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pURLBulider.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pURLBulider.pObject = pother->pURLBulider.pObject;
  v7 = (Scaleform::GFx::Resource *)pother->pImageCreator.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::AddRef(v7);
  v8 = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  this->pImageCreator.pObject = pother->pImageCreator.pObject;
  v9 = (Scaleform::GFx::Resource *)pother->pImportVisitor.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::AddRef(v9);
  v10 = (Scaleform::RefCountVImpl *)this->pImportVisitor.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->pImportVisitor.pObject = pother->pImportVisitor.pObject;
  v11 = (Scaleform::GFx::Resource *)pother->pFontPackParams.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::AddRef(v11);
  v12 = (Scaleform::RefCountVImpl *)this->pFontPackParams.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->pFontPackParams.pObject = pother->pFontPackParams.pObject;
  v13 = (Scaleform::GFx::Resource *)pother->pFontCompactorParams.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::AddRef(v13);
  v14 = (Scaleform::RefCountVImpl *)this->pFontCompactorParams.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  this->pFontCompactorParams.pObject = pother->pFontCompactorParams.pObject;
  v15 = (Scaleform::GFx::Resource *)pother->pImagePackParams.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::AddRef(v15);
  v16 = (Scaleform::RefCountVImpl *)this->pImagePackParams.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  this->pImagePackParams.pObject = pother->pImagePackParams.pObject;
}


void __thiscall Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(
        Scaleform::GFx::MovieDefBindStates *this,
        Scaleform::GFx::StateBag *psharedState)
{
  void (__thiscall *GetStatesAddRef)(Scaleform::GFx::StateBag *, Scaleform::GFx::State **, const Scaleform::GFx::State::StateType *, unsigned int); // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::FileOpener *v5; // ebx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::GFx::URLBuilder *v7; // ebx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::GFx::ImageCreator *v9; // ebx
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::ImportVisitor *v11; // ebx
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::GFx::FontPackParams *v13; // ebx
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::GFx::FontCompactorParams *v15; // ebx
  Scaleform::RefCountVImpl *v16; // ecx
  Scaleform::GFx::ImagePackParamsBase *v17; // ebx
  Scaleform::GFx::FileOpener *v18; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::URLBuilder *v19; // [esp+10h] [ebp-18h]
  Scaleform::GFx::ImageCreator *v20; // [esp+14h] [ebp-14h]
  Scaleform::GFx::ImportVisitor *v21; // [esp+18h] [ebp-10h]
  Scaleform::GFx::FontPackParams *v22; // [esp+1Ch] [ebp-Ch]
  Scaleform::GFx::FontCompactorParams *v23; // [esp+20h] [ebp-8h]
  Scaleform::GFx::ImagePackParamsBase *v24; // [esp+24h] [ebp-4h]

  this->__vftable = (Scaleform::GFx::MovieDefBindStates_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::MovieDefBindStates_vtbl *)&Scaleform::GFx::MovieDefBindStates::`vftable';
  this->pFileOpener.pObject = 0;
  this->pURLBulider.pObject = 0;
  this->pImageCreator.pObject = 0;
  this->pImageFileHandlerRegistry.pObject = 0;
  this->pImportVisitor.pObject = 0;
  this->pFontPackParams.pObject = 0;
  this->pFontCompactorParams.pObject = 0;
  this->pImagePackParams.pObject = 0;
  GetStatesAddRef = psharedState->GetStatesAddRef;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  GetStatesAddRef(psharedState, &v18, (const Scaleform::GFx::State::StateType *)"\t", 7u);
  pObject = (Scaleform::RefCountVImpl *)this->pFileOpener.pObject;
  v5 = v18;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFileOpener.pObject = v5;
  v6 = (Scaleform::RefCountVImpl *)this->pURLBulider.pObject;
  v7 = v19;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pURLBulider.pObject = v7;
  v8 = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  v9 = v20;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  this->pImageCreator.pObject = v9;
  v10 = (Scaleform::RefCountVImpl *)this->pImportVisitor.pObject;
  v11 = v21;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->pImportVisitor.pObject = v11;
  v12 = (Scaleform::RefCountVImpl *)this->pFontPackParams.pObject;
  v13 = v22;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->pFontPackParams.pObject = v13;
  v14 = (Scaleform::RefCountVImpl *)this->pFontCompactorParams.pObject;
  v15 = v23;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  this->pFontCompactorParams.pObject = v15;
  v16 = (Scaleform::RefCountVImpl *)this->pImagePackParams.pObject;
  v17 = v24;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  this->pImagePackParams.pObject = v17;
}
