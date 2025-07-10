void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::Graphics,14,Scaleform::GFx::AS3::Value const,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double v7; // [esp+18h] [ebp-30h]
  Scaleform::GFx::AS3::DefArgs2<double,double> def_ags; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,double,double> args; // [esp+30h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  v7 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = v7;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,double,double>::UnboxArgV2<Scaleform::GFx::AS3::Value const,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Graphics *, const Scaleform::GFx::AS3::Value *, long double, long double))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::Graphics,14,Scaleform::GFx::AS3::Value const,double,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)(dword_AAE314 + v6.VInt),
      args.r,
      args.a0,
      args.a1);
}
