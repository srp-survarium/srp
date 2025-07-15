void __thiscall Scaleform::GFx::AS2::MovieRoot::RegisterAuxASClasses(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::State *v2; // eax
  Scaleform::RefCountVImpl *v3; // ebx
  Scaleform::GFx::State *v4; // eax
  Scaleform::RefCountVImpl *v5; // edi
  int v6; // eax
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+10h] [ebp-8h] BYREF

  sc.pContext = this->pGlobalContext.pObject;
  sc.SWFVersion = 8;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<23,Scaleform::GFx::AS2::XmlCtorFunction>(
    sc.pContext,
    &sc,
    sc.pContext->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<24,Scaleform::GFx::AS2::XmlNodeCtorFunction>(
    this->pGlobalContext.pObject,
    &sc,
    this->pGlobalContext.pObject->pGlobal.pObject);
  v2 = this->pMovieImpl->pStateBag.pObject->GetStateAddRef(
         &this->pMovieImpl->pStateBag.pObject->Scaleform::GFx::StateBag,
         29);
  v3 = (Scaleform::RefCountVImpl *)v2;
  if ( v2 )
    ((void (__thiscall *)(Scaleform::GFx::State *, Scaleform::GFx::AS2::GlobalContext *, Scaleform::GFx::AS2::ASStringContext *))v2->__vftable[3].~Scaleform::GFx::State)(
      v2,
      this->pGlobalContext.pObject,
      &sc);
  v4 = this->pMovieImpl->pStateBag.pObject->GetStateAddRef(
         &this->pMovieImpl->pStateBag.pObject->Scaleform::GFx::StateBag,
         30);
  v5 = (Scaleform::RefCountVImpl *)v4;
  if ( v4 )
  {
    if ( ((int (__thiscall *)(Scaleform::GFx::State *))v4->__vftable[1].~Scaleform::GFx::State)(v4) )
    {
      v6 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v5->AddRef)(v5);
      (*(void (__thiscall **)(int, Scaleform::GFx::AS2::GlobalContext *, Scaleform::GFx::AS2::ASStringContext *))(*(_DWORD *)v6 + 8))(
        v6,
        this->pGlobalContext.pObject,
        &sc);
    }
    Scaleform::RefCountImpl::Release(v5);
  }
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
}
