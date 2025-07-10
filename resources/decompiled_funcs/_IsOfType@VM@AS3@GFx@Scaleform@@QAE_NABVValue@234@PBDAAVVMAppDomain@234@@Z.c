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
