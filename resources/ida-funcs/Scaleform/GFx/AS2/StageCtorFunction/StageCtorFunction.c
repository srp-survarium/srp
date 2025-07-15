void __userpurge Scaleform::GFx::AS2::StageCtorFunction::StageCtorFunction(
        Scaleform::GFx::AS2::StageCtorFunction *this@<ecx>,
        unsigned __int8 *a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::MovieImpl *movieRoot)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::MovieImpl *v7; // eax
  const Scaleform::GFx::ASString *p_pMovieImpl; // [esp-10h] [ebp-2Ch]
  const Scaleform::GFx::ASString *p_pASSupport; // [esp-10h] [ebp-2Ch]
  int v10; // [esp+0h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value v11; // [esp+Ch] [ebp-10h] BYREF

  v4 = psc;
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StageCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFunction = Scaleform::GFx::AS2::MouseCtorFunction::GlobalCtor;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v4->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v4,
    Prototype);
  v7 = movieRoot;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StageCtorFunction_vtbl *)&Scaleform::GFx::AS2::StageCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::StageCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pMovieRoot = v7;
  if ( this != (Scaleform::GFx::AS2::StageCtorFunction *)-16 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      a2,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      &this->Scaleform::GFx::AS2::ObjectInterface,
      v4,
      GAS_AsBcFunctionTable,
      1u,
      v10);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (int)&this->Scaleform::GFx::AS2::ObjectInterface,
    (int)v4,
    v4,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (int)a2,
    v10);
  p_pMovieImpl = (const Scaleform::GFx::ASString *)&v4->pContext->pMovieRoot->pASMovieRoot.pObject[33].pMovieImpl;
  LOBYTE(psc) = 0;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v4,
    p_pMovieImpl,
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  p_pASSupport = (const Scaleform::GFx::ASString *)&v4->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport;
  LOBYTE(psc) = 0;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    v4,
    p_pASSupport,
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&psc);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)v4,
    "scaleMode",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)v4,
    "align",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 2;
  v11.V.BooleanValue = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)v4,
    "showMenu",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}
