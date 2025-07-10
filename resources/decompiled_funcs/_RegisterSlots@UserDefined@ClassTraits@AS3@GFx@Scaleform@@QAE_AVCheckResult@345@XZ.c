Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ClassTraits::UserDefined::RegisterSlots(
        Scaleform::GFx::AS3::ClassTraits::UserDefined *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::VMAbcFile *pObject; // ebx
  Scaleform::GFx::AS3::Abc::StaticInfo *p_stat_info; // edi
  unsigned int v5; // eax
  bool v6; // zf
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  Scaleform::GFx::AS3::CheckResult v8; // [esp+Fh] [ebp-1h] BYREF

  pObject = this->File.pObject;
  p_stat_info = &this->class_info->stat_info;
  v5 = this->GetFixedMemSize(this);
  v6 = !Scaleform::GFx::AS3::Traits::AddSlots(this, &v8, p_stat_info, pObject, v5)->Result;
  v7 = result;
  result->Result = !v6;
  return v7;
}
