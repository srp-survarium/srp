const Scaleform::GFx::AS3::Abc::Multiname *__thiscall Scaleform::GFx::AS3::VMAbcFile::GetMultiname(
        Scaleform::GFx::AS3::VMAbcFile *this,
        unsigned int ind)
{
  return &this->File.pObject->Const_Pool.const_multiname.Data.Data[ind];
}
