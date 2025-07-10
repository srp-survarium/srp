void __cdecl Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::Graphics,8,Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double v7; // [esp+60h] [ebp-90h]
  double v8; // [esp+68h] [ebp-88h]
  double v9; // [esp+70h] [ebp-80h]
  double v10; // [esp+78h] [ebp-78h]
  double v11; // [esp+80h] [ebp-70h]
  Scaleform::GFx::AS3::DefArgs6<double,double,double,double,double,double> def_ags; // [esp+88h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::UnboxArgV6<Scaleform::GFx::AS3::Value const ,double,double,double,double,double,double> args; // [esp+B8h] [ebp-38h] BYREF

  v6 = obj->value.VS._1;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  v7 = Scaleform::GFx::NumberUtil::NaN();
  v10 = Scaleform::GFx::NumberUtil::NaN();
  v11 = Scaleform::GFx::NumberUtil::NaN();
  v8 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = v8;
  def_ags._2 = v11;
  def_ags._3 = v10;
  def_ags._4 = v7;
  def_ags._5 = v9;
  Scaleform::GFx::AS3::UnboxArgV6<Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>::UnboxArgV6<Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Graphics *, const Scaleform::GFx::AS3::Value *, long double, long double, long double, long double, long double, long double))Scaleform::GFx::AS3::ThunkFunc6<Scaleform::GFx::AS3::Instances::fl_display::Graphics,8,Scaleform::GFx::AS3::Value const,double,double,double,double,double,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)(dword_AAE2F4 + v6.VInt),
      args.r,
      args.a0,
      args.a1,
      args.a2,
      args.a3,
      args.a4,
      args.a5);
}
