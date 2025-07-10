bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::HasCode *obj)
{
  obj->method_info_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  return Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, (int)t, &obj->obj_traits) && obj->method_info_ind >= 0;
}
