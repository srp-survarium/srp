void __thiscall Scaleform::GFx::AS2::GASPrototypeBase::Init(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Object *pthis,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  const Scaleform::GFx::AS2::FunctionRef *v5; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::AS2::FunctionObject *v8; // eax
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface *v10; // edi
  Scaleform::GFx::ASMovieRootBase *pObject; // ebx
  void (__thiscall **p_SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, int, const Scaleform::GFx::AS2::FunctionRef **); // esi
  int v13; // eax
  Scaleform::GFx::AS2::Value v14; // [esp+10h] [ebp-10h] BYREF

  v5 = constructor;
  Function = constructor->Function;
  v14.T.Type = 8;
  v14.V.FunctionValue.Flags = 0;
  v14.NV.Int32Value = (int)Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  pLocalFrame = v5->pLocalFrame;
  v14.V.FunctionValue.pLocalFrame = 0;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v14.V.FunctionValue, pLocalFrame, v5->Flags & 1);
  Scaleform::GFx::AS2::GASPrototypeBase::SetConstructor(this, pthis, psc, &v14);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  v8 = this->Constructor.Function;
  pContext = psc->pContext;
  LOBYTE(constructor) = 3;
  v10 = &v8->Scaleform::GFx::AS2::ObjectInterface;
  pObject = pContext->pMovieRoot->pASMovieRoot.pObject;
  p_SetMemberRaw = (void (__thiscall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::Ptr<Scaleform::GFx::ASSupport> *, int, const Scaleform::GFx::AS2::FunctionRef **))&v8->SetMemberRaw;
  Scaleform::GFx::AS2::Value::Value(&v14, pthis);
  (*p_SetMemberRaw)(v10, psc, &pObject[23].pASSupport, v13, &constructor);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
}
