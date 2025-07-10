void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,12,bool,Scaleform::GFx::AS3::Value const &>::Func(
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
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::Extra v13; // edx
  Scaleform::GFx::AS3::Value v14; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v14 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v14.Flags;
  }
  def_ags._0.value.VNumber = v14.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v14.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v14);
    LOWORD(Flags) = v14.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
  }
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XMLList *, bool *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XMLList,12,bool,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)(dword_AAD1CC + v6.VInt),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v11 = args.Result;
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v14.Bonus;
      LOBYTE(v14.Flags) = r;
      v11->value.VS._1.VInt = v14.Flags;
      v11->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13.pWeakProxy;
    }
  }
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}
