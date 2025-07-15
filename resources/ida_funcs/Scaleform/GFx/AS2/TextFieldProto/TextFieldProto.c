void __thiscall Scaleform::GFx::AS2::TextFieldProto::TextFieldProto(
        Scaleform::GFx::AS2::TextFieldProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  unsigned __int8 *v5; // ebx
  Scaleform::GFx::Text::IMEStyle *DefaultStyles; // eax
  int v7; // [esp+0h] [ebp-74h]
  int v8; // [esp+0h] [ebp-74h]
  int v9; // [esp+4h] [ebp-70h]
  int v10; // [esp+4h] [ebp-70h]
  Scaleform::GFx::AS2::Value val; // [esp+10h] [ebp-64h] BYREF
  Scaleform::GFx::Text::IMEStyle result; // [esp+20h] [ebp-54h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
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
  LOBYTE(constructor) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    (int)v5,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    GAS_TextFieldFunctionTable,
    (Scaleform::GFx::ASStringNode *)&constructor,
    v7,
    v9);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "scroll",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  LOBYTE(v5) = 5;
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "hscroll",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "maxscroll",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "maxhscroll",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "background",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "backgroundColor",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "border",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "borderColor",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "bottomScroll",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "mouseWheelEnabled",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "antiAliasType",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "autoSize",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "condenseWhite",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "embedFonts",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "html",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "htmlText",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "length",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "maxChars",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "multiline",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "password",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 1;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "restrict",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "selectable",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "styleSheet",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "tabIndex",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "text",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "textColor",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "textHeight",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "textWidth",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "type",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "variable",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 2;
  val.T.Type = 10;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "wordWrap",
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  LOBYTE(constructor) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    (int)v5,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    GAS_TextFieldExtFunctionTable,
    (Scaleform::GFx::ASStringNode *)&constructor,
    v8,
    v10);
  DefaultStyles = Scaleform::GFx::Text::CompositionString::GetDefaultStyles(&result);
  Scaleform::GFx::AS2::TextFieldObject::SetIMECompositionStringStyles(this, DefaultStyles);
}
