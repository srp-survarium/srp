bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::Instance *obj)
{
  const unsigned __int8 **p_CP; // esi
  unsigned __int8 v5; // cl
  bool v6; // sf
  bool v7; // al

  p_CP = &this->CP;
  obj->name_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  obj->super_name_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  v5 = *(*p_CP)++;
  v6 = obj->name_ind < 0;
  obj->flags = v5;
  v7 = !v6 && obj->super_name_ind >= 0;
  if ( (v5 & 8) != 0 )
  {
    if ( !v7 )
      return 0;
    obj->protected_namespace_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  }
  else if ( !v7 )
  {
    return 0;
  }
  return Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->implemented_interfaces)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, t, obj);
}
