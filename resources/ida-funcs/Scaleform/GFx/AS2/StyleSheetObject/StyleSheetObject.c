void __thiscall Scaleform::GFx::AS2::StyleSheetObject::StyleSheetObject(
        Scaleform::GFx::AS2::StyleSheetObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StyleSheetObject_vtbl *)&Scaleform::GFx::AS2::StyleSheetObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::StyleSheetObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->CSS.__vftable = (Scaleform::GFx::Text::StyleManager_vtbl *)&Scaleform::GFx::Text::StyleManager::`vftable';
  this->CSS.Styles.mHash.pTable = 0;
  this->CSS.TempKey.Type = CSS_None;
  Scaleform::StringLH::StringLH(&this->CSS.TempKey.Value);
  this->CSS.State = Ready;
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    pprototype);
}


void __userpurge Scaleform::GFx::AS2::StyleSheetObject::StyleSheetObject(
        Scaleform::GFx::AS2::StyleSheetObject *this@<ecx>,
        int a2@<edi>,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v5; // [esp-4h] [ebp-10h]
  int v6; // [esp+0h] [ebp-Ch]

  v5 = a2;
  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StyleSheetObject_vtbl *)&Scaleform::GFx::AS2::StyleSheetObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::StyleSheetObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->CSS.__vftable = (Scaleform::GFx::Text::StyleManager_vtbl *)&Scaleform::GFx::Text::StyleManager::`vftable';
  this->CSS.Styles.mHash.pTable = 0;
  this->CSS.TempKey.Type = CSS_None;
  Scaleform::StringLH::StringLH(&this->CSS.TempKey.Value);
  this->CSS.State = Ready;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_StyleSheet);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
  if ( this != (Scaleform::GFx::AS2::StyleSheetObject *)-16 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (unsigned __int8 *)&penv->StringContext,
      (Scaleform::GFx::AS2::LocalFrame **)penv,
      &this->Scaleform::GFx::AS2::ObjectInterface,
      &penv->StringContext,
      GAS_AsBcFunctionTable,
      1u,
      a2);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (int)&this->Scaleform::GFx::AS2::ObjectInterface,
    (int)this,
    &penv->StringContext,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    v5,
    v6);
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(
    penv,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &this->Scaleform::GFx::AS2::ObjectInterface);
}
