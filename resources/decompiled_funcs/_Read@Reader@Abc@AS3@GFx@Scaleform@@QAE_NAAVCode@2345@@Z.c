char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::Code *obj)
{
  obj->code.Data = this->CP;
  this->CP += Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  return 1;
}
