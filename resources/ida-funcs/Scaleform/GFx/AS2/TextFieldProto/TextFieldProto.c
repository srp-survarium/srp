void __userpurge Scaleform::GFx::AS2::TextFieldProto::TextFieldProto(
        Scaleform::GFx::AS2::TextFieldProto *this@<ecx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        Scaleform::GFx::ASStringNode constructor)
{
  unsigned __int8 *v5; // ebx
  Scaleform::GFx::Text::IMEStyle *DefaultStyles; // eax
  int v7; // [esp+0h] [ebp-74h]
  int v8; // [esp+0h] [ebp-74h]
  int v9; // [esp+4h] [ebp-70h]
  int v10; // [esp+4h] [ebp-70h]
  Scaleform::GFx::AS2::Value v11; // [esp+10h] [ebp-64h] BYREF
  Scaleform::GFx::Text::IMEStyle result; // [esp+20h] [ebp-54h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    (const Scaleform::GFx::AS2::FunctionRef *)constructor.pData);
  v5 = (unsigned __int8 *)&this->Scaleform::GFx::AS2::GASPrototypeBase;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::TextFieldObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::TextFieldProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::TextFieldObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::`vftable';
  if ( this != (Scaleform::GFx::AS2::TextFieldProto *)-16 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      v5,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      &this->Scaleform::GFx::AS2::ObjectInterface,
      psc,
      GAS_AsBcFunctionTable,
      1u,
      v7);
  LOBYTE(constructor.pData) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    (int)v5,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    GAS_TextFieldFunctionTable,
    &constructor,
    v7,
    v9);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "scroll",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  LOBYTE(v5) = 5;
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "hscroll",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "maxscroll",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "maxhscroll",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "background",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "backgroundColor",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "border",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "borderColor",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "bottomScroll",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "mouseWheelEnabled",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "antiAliasType",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "autoSize",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "condenseWhite",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "embedFonts",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "html",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "htmlText",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "length",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "maxChars",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "multiline",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "password",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "restrict",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "selectable",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "styleSheet",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "tabIndex",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "text",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "textColor",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "textHeight",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "textWidth",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "type",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "variable",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 2;
  v11.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "wordWrap",
    &v11,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  LOBYTE(constructor.pData) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    (int)v5,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    GAS_TextFieldExtFunctionTable,
    &constructor,
    v8,
    v10);
  DefaultStyles = Scaleform::GFx::Text::CompositionString::GetDefaultStyles(&result);
  Scaleform::GFx::AS2::TextFieldObject::SetIMECompositionStringStyles(this, DefaultStyles);
}
