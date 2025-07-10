void __thiscall Scaleform::GFx::AS2::FunctionObject::SetPrototype(
        Scaleform::GFx::AS2::FunctionObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v3; // ebp
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // ebx
  Scaleform::GFx::AS2::ObjectInterface *v6; // esi
  const Scaleform::GFx::AS2::Value *v7; // eax
  char v8; // [esp+13h] [ebp-11h] BYREF
  Scaleform::GFx::AS2::Value v9; // [esp+14h] [ebp-10h] BYREF

  v3 = this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
  pContext = psc->pContext;
  v8 = 0;
  pObject = pContext->pMovieRoot->pASMovieRoot.pObject;
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  Scaleform::GFx::AS2::Value::Value(&v9, pprototype);
  v3->SetMemberRaw(
    v6,
    psc,
    (const Scaleform::GFx::ASString *)&pObject[23].pASSupport,
    v7,
    (const Scaleform::GFx::AS2::PropFlags *)&v8);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
}
