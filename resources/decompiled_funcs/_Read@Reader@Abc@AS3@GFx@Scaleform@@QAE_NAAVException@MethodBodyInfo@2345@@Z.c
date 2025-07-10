char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *obj)
{
  const unsigned __int8 **p_CP; // esi
  unsigned int v3; // eax
  int i; // ebp
  int count; // [esp+10h] [ebp-1Ch]
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo info; // [esp+18h] [ebp-14h] BYREF

  p_CP = &this->CP;
  v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  count = v3;
  if ( v3 > obj->info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->info.Data,
      obj,
      v3);
  for ( i = 0; i < count; ++i )
  {
    Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo::ExceptionInfo(&info);
    info.from = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
    info.to = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
    info.target = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
    info.exc_type_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, (int *)&info.var_name_ind) )
      return 0;
    Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &obj->info.Data,
      &info);
  }
  return 1;
}
