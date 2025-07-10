void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,8,Scaleform::GFx::AS3::Value const,double,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v6; // zf
  Scaleform::GFx::AS3::CheckResult v7; // [esp+4Bh] [ebp-4Dh] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *_this; // [esp+4Ch] [ebp-4Ch]
  double v9; // [esp+50h] [ebp-48h]
  double v10; // [esp+58h] [ebp-40h]
  Scaleform::GFx::AS3::DefArgs3<double,double,double> def_ags; // [esp+60h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const ,double,double,double> args; // [esp+78h] [ebp-20h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)obj->value.VS._1.VInt;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  v10 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = v10;
  def_ags._2 = v9;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,double,double>::UnboxArgV2<Scaleform::GFx::AS3::Value const,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  v6 = !vm->HandleException;
  args.a2 = v9;
  if ( v6 )
  {
    if ( argc > 2 )
      Scaleform::GFx::AS3::Value::Convert2Number(argv + 2, &v7, &args.a2);
    if ( !vm->HandleException )
      ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *, const Scaleform::GFx::AS3::Value *, long double, long double, long double))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D,8,Scaleform::GFx::AS3::Value const,double,double,double>::Method)(
        (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)((char *)_this + dword_AACA94),
        args.r,
        args.a0,
        args.a1,
        args.a2);
  }
}
