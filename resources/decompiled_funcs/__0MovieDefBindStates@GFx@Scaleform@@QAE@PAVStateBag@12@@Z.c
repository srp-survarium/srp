void __thiscall Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(
        Scaleform::GFx::MovieDefBindStates *this,
        Scaleform::GFx::StateBag *psharedState)
{
  void (__thiscall *GetStatesAddRef)(Scaleform::GFx::StateBag *, Scaleform::GFx::State **, const Scaleform::GFx::State::StateType *, unsigned int); // eax
  Scaleform::GFx::FileOpener *pObject; // ecx
  Scaleform::GFx::FileOpener *v5; // ebx
  Scaleform::GFx::URLBuilder *v6; // ecx
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
  Scaleform::GFx::State *pstates[7]; // [esp+Ch] [ebp-1Ch] BYREF

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
  memset(pstates, 0, sizeof(pstates));
  GetStatesAddRef(psharedState, pstates, (const Scaleform::GFx::State::StateType *)"\t", 7u);
  pObject = this->pFileOpener.pObject;
  v5 = (Scaleform::GFx::FileOpener *)pstates[0];
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->pFileOpener.pObject = v5;
  v6 = this->pURLBulider.pObject;
  v7 = (Scaleform::GFx::URLBuilder *)pstates[1];
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
  this->pURLBulider.pObject = v7;
  v8 = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  v9 = (Scaleform::GFx::ImageCreator *)pstates[2];
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  this->pImageCreator.pObject = v9;
  v10 = (Scaleform::RefCountVImpl *)this->pImportVisitor.pObject;
  v11 = (Scaleform::GFx::ImportVisitor *)pstates[3];
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->pImportVisitor.pObject = v11;
  v12 = (Scaleform::RefCountVImpl *)this->pFontPackParams.pObject;
  v13 = (Scaleform::GFx::FontPackParams *)pstates[4];
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->pFontPackParams.pObject = v13;
  v14 = (Scaleform::RefCountVImpl *)this->pFontCompactorParams.pObject;
  v15 = (Scaleform::GFx::FontCompactorParams *)pstates[5];
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  this->pFontCompactorParams.pObject = v15;
  v16 = (Scaleform::RefCountVImpl *)this->pImagePackParams.pObject;
  v17 = (Scaleform::GFx::ImagePackParamsBase *)pstates[6];
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  this->pImagePackParams.pObject = v17;
}
