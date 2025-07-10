void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,15,bool,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  double v9; // [esp+18h] [ebp-38h]
  Scaleform::GFx::AS3::DefArgs2<double,double> def_ags; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<bool,double,double> args; // [esp+30h] [ebp-20h] BYREF

  v6 = obj->value.VS._1;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = v9;
  Scaleform::GFx::AS3::UnboxArgV2<bool,double,double>::UnboxArgV2<bool,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool *, long double, long double))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,15,bool,double,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)(v6.VInt + dword_AAC774),
      &args.r,
      args.a0,
      args.a1);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v9) = r;
    v7->value.VNumber = v9;
  }
}
