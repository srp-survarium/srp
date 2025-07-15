void __userpurge Scaleform::GFx::AS2::KeyCtorFunction::KeyCtorFunction(
        Scaleform::GFx::AS2::KeyCtorFunction *this@<ecx>,
        unsigned __int8 *a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::KeyCtorFunction::State *States; // eax
  int i; // ecx
  unsigned __int8 *v8; // [esp-4h] [ebp-20h]
  int v9; // [esp+0h] [ebp-1Ch]
  int v10; // [esp+0h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value v11; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::KeyCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFunction = Scaleform::GFx::AS2::MouseCtorFunction::GlobalCtor;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
  this->Scaleform::GFx::KeyboardState::IListener::__vftable = (Scaleform::GFx::KeyboardState::IListener_vtbl *)&Scaleform::GFx::AMP::ConnStatusInterface::`vftable';
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::KeyCtorFunction_vtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::KeyboardState::IListener::__vftable = (Scaleform::GFx::KeyboardState::IListener_vtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable';
  States = this->States;
  for ( i = 15; i >= 0; --i )
  {
    States->LastKeyCode = 0;
    States->LastAsciiCode = 0;
    States->LastWcharCode = 0;
    ++States;
  }
  this->pMovieRoot = proot;
  if ( this != (Scaleform::GFx::AS2::KeyCtorFunction *)-16 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      a2,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      &this->Scaleform::GFx::AS2::ObjectInterface,
      psc,
      GAS_AsBcFunctionTable,
      1u,
      v9);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (int)psc,
    (int)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (int)a2,
    v9);
  v11.T.Type = 4;
  v11.NV.Int32Value = 8;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "BACKSPACE",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 20;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "CAPSLOCK",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 17;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "CONTROL",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 46;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "DELETEKEY",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 40;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "DOWN",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 35;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "END",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 13;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "ENTER",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 27;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "ESCAPE",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 36;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "HOME",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 45;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "INSERT",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 37;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "LEFT",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 34;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "PGDN",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 33;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "PGUP",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 39;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "RIGHT",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 16;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "SHIFT",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 32;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "SPACE",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 9;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "TAB",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  v11.T.Type = 4;
  v11.NV.Int32Value = 38;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "UP",
    &v11);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    v8,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::KeyCtorFunction::StaticFunctionTable,
    0,
    v10);
  Scaleform::GFx::MovieImpl::SetKeyboardListener(
    proot,
    (Scaleform::GFx::MovieImpl *)&this->Scaleform::GFx::KeyboardState::IListener);
}
