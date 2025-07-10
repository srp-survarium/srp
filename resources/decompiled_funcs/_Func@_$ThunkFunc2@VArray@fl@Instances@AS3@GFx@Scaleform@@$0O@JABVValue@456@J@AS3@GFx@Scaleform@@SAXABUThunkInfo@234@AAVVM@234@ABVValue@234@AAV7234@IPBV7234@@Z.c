void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,14,long,Scaleform::GFx::AS3::Value const &,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,long> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *v9; // eax
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,long> *p_def_ags; // ecx
  bool v11; // zf
  int r; // ecx
  Scaleform::GFx::AS3::Value v13; // [esp+8h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<long,Scaleform::GFx::AS3::Value const &,long> args; // [esp+18h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::AS3::Value const &,long> def_ags; // [esp+2Ch] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v13 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v13.Flags;
  }
  def_ags._0.value.VNumber = v13.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v13.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v13);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v13);
    LOWORD(Flags) = v13.Flags;
  }
  def_ags._1 = 0x7FFFFFFF;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v13);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
  }
  v9 = result;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  p_def_ags = argv;
  if ( !argc )
    p_def_ags = &def_ags;
  v11 = !vm->HandleException;
  args.a0 = &p_def_ags->_0;
  args.a1 = def_ags._1;
  if ( v11 )
  {
    if ( argc > 1 )
    {
      Scaleform::GFx::AS3::Value::Convert2Int32(
        (Scaleform::GFx::AS3::Value *)&argv->_1,
        (Scaleform::GFx::AS3::CheckResult *)&obj,
        &args.a1);
      v9 = args.Result;
    }
    v11 = !vm->HandleException;
  }
  if ( v11 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Array *, int *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,14,long,Scaleform::GFx::AS3::Value const &,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::Array *)(dword_AAD034 + v6.VInt),
      &args.r,
      args.a0,
      args.a1);
    if ( args.Vm->HandleException )
      goto LABEL_27;
    v9 = args.Result;
  }
  else if ( args.Vm->HandleException )
  {
    goto LABEL_27;
  }
  r = args.r;
  v9->Flags = v9->Flags & 0xFFFFFFE0 | 2;
  v9->value.VS._1.VInt = r;
  v9->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13.Bonus.pWeakProxy;
LABEL_27:
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}
