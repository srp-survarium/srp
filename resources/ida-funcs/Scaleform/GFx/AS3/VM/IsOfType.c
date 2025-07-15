char __thiscall Scaleform::GFx::AS3::VM::IsOfType(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Value *v,
        const char *type_name,
        Scaleform::GFx::ASStringNode *appDomain)
{
  char v4; // bl
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::StringDataPtr qname; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+10h] [ebp-18h] BYREF

  v4 = 0;
  qname.pStr = type_name;
  if ( type_name )
    qname.Size = strlen(type_name);
  else
    qname.Size = 0;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, this, (Scaleform::GFx::ASStringNode *)&qname);
  v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, &mn, appDomain);
  if ( v6 && Scaleform::GFx::AS3::VM::IsOfType(this, v, (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v6) )
    v4 = 1;
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  return v4;
}


char __thiscall Scaleform::GFx::AS3::VM::IsOfType(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::fl::Object *ctr)
{
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // esi
  bool v6; // c0
  bool v7; // c3
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // eax
  Scaleform::GFx::AS3::Value::V1U v9; // ecx
  Scaleform::GFx::AS3::Class *Class; // eax
  double r; // [esp+18h] [ebp-8h] BYREF

  TraitsType = ctr->TraitsType;
  switch ( v->Flags & 0x1F )
  {
    case 1u:
      return TraitsType == Traits_Boolean || ctr == this->TraitsObject.pObject;
    case 2u:
      if ( TraitsType == Traits_UInt )
        return v->value.VS._1.VInt >= 0;
      if ( TraitsType == Traits_Number )
        return 1;
      return TraitsType == Traits_SInt || ctr == this->TraitsObject.pObject;
    case 3u:
      if ( TraitsType == Traits_SInt )
        return v->value.VS._1.VInt <= 0x7FFFFFFFu;
      if ( TraitsType == Traits_Number )
        return 1;
      return TraitsType == Traits_UInt || ctr == this->TraitsObject.pObject;
    case 4u:
      if ( 0.0 != modf(v->value.VNumber, &r) )
        return TraitsType == Traits_Number || ctr == this->TraitsObject.pObject;
      if ( TraitsType == Traits_UInt )
      {
        if ( r >= 0.0 )
        {
          v6 = r < 4294967295.0;
          v7 = r == 4294967295.0;
          goto LABEL_22;
        }
        return 0;
      }
      if ( TraitsType == Traits_SInt )
      {
        if ( r >= -2147483648.0 )
        {
          v6 = r < 2147483647.0;
          v7 = r == 2147483647.0;
LABEL_22:
          if ( v6 || v7 )
            return 1;
        }
        return 0;
      }
      return TraitsType == Traits_Number || ctr == this->TraitsObject.pObject;
    case 0xAu:
      if ( !v->value.VS._1.VInt )
        return 0;
      return TraitsType == Traits_String || ctr == this->TraitsObject.pObject;
    case 0xBu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      goto $LN5_138;
    case 0xCu:
      if ( !v->value.VS._1.VInt )
        return 0;
$LN5_138:
      ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this, v);
      return Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(ctr, ClassTraits);
    case 0xDu:
      v9 = v->value.VS._1;
      if ( !v9.VInt )
        return 0;
      Class = Scaleform::GFx::AS3::Traits::GetClass(*(Scaleform::GFx::AS3::Traits **)(v9.VInt + 20));
      return Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
               ctr,
               (const Scaleform::GFx::AS3::ClassTraits::Traits *)Class->pTraits.pObject);
    default:
      return 0;
  }
}
