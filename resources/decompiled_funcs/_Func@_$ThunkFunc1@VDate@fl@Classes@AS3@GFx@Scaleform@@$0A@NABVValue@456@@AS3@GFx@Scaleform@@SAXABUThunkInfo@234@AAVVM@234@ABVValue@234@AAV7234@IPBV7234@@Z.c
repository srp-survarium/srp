void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Date,0,double,Scaleform::GFx::AS3::Value const &>::Func(
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
  double v9; // st7
  bool v11; // zf
  Scaleform::GFx::AS3::Value *v12; // eax
  unsigned int v13; // edx
  Scaleform::GFx::AS3::Value::Extra v14; // ecx
  Scaleform::GFx::AS3::Value *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // edx
  Scaleform::GFx::AS3::Value::Extra v18; // ecx
  Scaleform::GFx::AS3::Value v19; // [esp+8h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<double,Scaleform::GFx::AS3::Value const &> args; // [esp+28h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v19 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v19.Flags;
  }
  def_ags._0.value.VNumber = v19.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v19.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v19);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v19);
    LOWORD(Flags) = v19.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v19);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
  }
  args.Vm = vm;
  args.Result = result;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  args.r = v9;
  if ( !argc )
    argv = &def_ags;
  v11 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v11 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Date *, long double *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Date,0,double,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Date *)(v6.VInt + dword_AAD64C),
      &args.r,
      &argv->_0);
    if ( !args.Vm->HandleException )
    {
      v15 = args.Result;
      v16 = args.Result->Flags;
      *(double *)&v19.Flags = args.r;
      v17 = v19.Flags;
      args.Result->Flags = v16 & 0xFFFFFFE0 | 4;
      v18.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v19.Bonus;
      v15->value.VS._1.VInt = v17;
      v15->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v18.pWeakProxy;
    }
    if ( (def_ags._0.Flags & 0x1F) > 9 )
    {
      if ( (def_ags._0.Flags & 0x200) != 0 )
        goto LABEL_22;
LABEL_27:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
    }
  }
  else
  {
    if ( !args.Vm->HandleException )
    {
      v12 = args.Result;
      *(double *)&v19.Flags = v9;
      v13 = v19.Flags;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v19.Bonus;
      v12->value.VS._1.VInt = v13;
      v12->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14.pWeakProxy;
    }
    if ( (def_ags._0.Flags & 0x1F) > 9 )
    {
      if ( (def_ags._0.Flags & 0x200) != 0 )
      {
LABEL_22:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
        return;
      }
      goto LABEL_27;
    }
  }
}
