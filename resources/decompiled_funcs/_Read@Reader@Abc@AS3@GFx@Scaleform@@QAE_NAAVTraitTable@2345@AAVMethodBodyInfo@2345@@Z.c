bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo *obj)
{
  const unsigned __int8 **p_CP; // edi

  p_CP = &this->CP;
  obj->method_info_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  obj->max_stack = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  obj->local_reg_count = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  obj->init_scope_depth = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  return Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->max_scope_depth)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->code)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->exception)
      && Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, (int)t, &obj->obj_traits)
      && obj->method_info_ind >= 0;
}
