void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,39,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value v10; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v10 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v10.Flags;
  }
  def_ags._0.value.VNumber = v10.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v10.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v10);
    LOWORD(Flags) = v10.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( !argc )
    argv = &def_ags;
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,39,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD724 + v6.VInt),
      result,
      &argv->_0);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}
