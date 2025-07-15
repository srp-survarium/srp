void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,6,double,double,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  bool v7; // zf
  Scaleform::GFx::AS3::Value *v8; // eax
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::Value::V1U v10; // edx
  Scaleform::GFx::AS3::Value::V2U v11; // ecx
  Scaleform::GFx::AS3::Value *v12; // eax
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::V1U v14; // ecx
  Scaleform::GFx::AS3::Value::V2U v15; // edx
  Scaleform::GFx::AS3::CheckResult v16; // [esp+4Fh] [ebp-49h] BYREF
  long double r; // [esp+50h] [ebp-48h]
  Scaleform::GFx::AS3::DefArgs3<double,double,double> def_ags; // [esp+58h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<double,double,double,double> args; // [esp+70h] [ebp-28h] BYREF

  v6 = obj->value.VS._1;
  r = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = r;
  def_ags._2 = 0.0;
  Scaleform::GFx::AS3::UnboxArgV2<double,double,double>::UnboxArgV2<double,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  v7 = !vm->HandleException;
  args.a2 = 0.0;
  if ( !v7 )
    goto LABEL_11;
  if ( argc > 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 2, &v16, &args.a2);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, long double *, long double, long double, long double))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,6,double,double,double,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)(dword_8F1364 + v6.VInt),
      &args.r,
      args.a0,
      args.a1,
      args.a2);
    if ( !args.Vm->HandleException )
    {
      v12 = args.Result;
      Flags = args.Result->Flags;
      r = args.r;
      v14 = LODWORD(r);
      args.Result->Flags = Flags & 0xFFFFFFE0 | 4;
      v15.VObj = *(Scaleform::GFx::AS3::Object **)((char *)&r + 4);
      v12->value.VS._1 = v14;
      v12->value.VS._2 = v15;
    }
  }
  else
  {
LABEL_11:
    if ( !args.Vm->HandleException )
    {
      v8 = args.Result;
      v9 = args.Result->Flags;
      r = args.r;
      v10 = LODWORD(r);
      args.Result->Flags = v9 & 0xFFFFFFE0 | 4;
      v11.VObj = *(Scaleform::GFx::AS3::Object **)((char *)&r + 4);
      v8->value.VS._1 = v10;
      v8->value.VS._2 = v11;
    }
  }
}
