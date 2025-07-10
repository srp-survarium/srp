char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, int *v)
{
  *v = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  return 1;
}
