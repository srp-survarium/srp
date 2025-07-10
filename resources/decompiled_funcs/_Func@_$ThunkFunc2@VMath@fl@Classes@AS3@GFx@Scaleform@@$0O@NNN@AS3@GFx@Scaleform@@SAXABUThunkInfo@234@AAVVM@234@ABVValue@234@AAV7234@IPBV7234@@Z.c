void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Math,14,double,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::Value *v7; // eax
  Scaleform::GFx::AS3::Value *v8; // eax
  double v9; // [esp+18h] [ebp-38h]
  long double r; // [esp+18h] [ebp-38h]
  long double v11; // [esp+18h] [ebp-38h]
  Scaleform::GFx::AS3::DefArgs2<double,double> def_ags; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<double,double,double> args; // [esp+30h] [ebp-20h] BYREF

  v6 = obj->value.VS._1;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = v9;
  Scaleform::GFx::AS3::UnboxArgV2<double,double,double>::UnboxArgV2<double,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( vm->HandleException )
  {
    if ( !args.Vm->HandleException )
    {
      v7 = args.Result;
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      v7->value.VNumber = r;
    }
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double, long double))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Math,14,double,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(dword_AAD1AC + v6.VInt),
      &args.r,
      args.a0,
      args.a1);
    if ( !args.Vm->HandleException )
    {
      v8 = args.Result;
      v11 = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      v8->value.VNumber = v11;
    }
  }
}
