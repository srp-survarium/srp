void __cdecl Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,24,Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v6; // zf
  Scaleform::GFx::AS3::DefArgs5<long,unsigned long,unsigned long,unsigned long,bool> def_ags; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const ,long,unsigned long,unsigned long,unsigned long,bool> args; // [esp+24h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *_this; // [esp+4Ch] [ebp+Ch]

  _this = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)obj->pNext;
  def_ags._0 = 0;
  def_ags._1 = 0;
  def_ags._2 = 255;
  def_ags._3 = 7;
  def_ags._4 = 0;
  Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long>::UnboxArgV4<Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  args.a4 = 0;
  v6 = !vm->HandleException;
  if ( !vm->HandleException )
  {
    if ( argc > 4 )
      args.a4 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 4);
    v6 = !vm->HandleException;
  }
  if ( v6 )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, const Scaleform::GFx::AS3::Value *, int, unsigned int, unsigned int, unsigned int, bool))Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,24,Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)((char *)_this + dword_AAE934),
      args.r,
      args.a0,
      args.a1,
      args.a2,
      args.a3,
      args.a4);
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,2,Scaleform::GFx::AS3::Value const,double,double,double,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v6; // zf
  Scaleform::GFx::AS3::CheckResult v7; // [esp+43h] [ebp-65h] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix *_this; // [esp+44h] [ebp-64h]
  double v9; // [esp+48h] [ebp-60h]
  Scaleform::GFx::AS3::DefArgs5<double,double,double,double,double> def_ags; // [esp+50h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const ,double,double,double,double,double> args; // [esp+78h] [ebp-30h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)obj->value.VS._1.VInt;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = v9;
  def_ags._2 = 0.0;
  def_ags._3 = 0.0;
  def_ags._4 = 0.0;
  Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,double,double,double,double>::UnboxArgV4<Scaleform::GFx::AS3::Value const,double,double,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  v6 = !vm->HandleException;
  args.a4 = 0.0;
  if ( v6 )
  {
    if ( argc > 4 )
      Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &v7, &args.a4);
    if ( !vm->HandleException )
      ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, const Scaleform::GFx::AS3::Value *, long double, long double, long double, long double, long double))Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,2,Scaleform::GFx::AS3::Value const,double,double,double,double,double>::Method)(
        (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)((char *)_this + dword_AAC86C),
        args.r,
        args.a0,
        args.a1,
        args.a2,
        args.a3,
        args.a4);
  }
}


void __cdecl Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,3,Scaleform::GFx::AS3::Value const,double,double,double,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v6; // zf
  Scaleform::GFx::AS3::CheckResult v7; // [esp+43h] [ebp-65h] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix *_this; // [esp+44h] [ebp-64h]
  double v9; // [esp+48h] [ebp-60h]
  Scaleform::GFx::AS3::DefArgs5<double,double,double,double,double> def_ags; // [esp+50h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const ,double,double,double,double,double> args; // [esp+78h] [ebp-30h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)obj->value.VS._1.VInt;
  v9 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = v9;
  def_ags._2 = 0.0;
  def_ags._3 = 0.0;
  def_ags._4 = 0.0;
  Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,double,double,double,double>::UnboxArgV4<Scaleform::GFx::AS3::Value const,double,double,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  v6 = !vm->HandleException;
  args.a4 = 0.0;
  if ( v6 )
  {
    if ( argc > 4 )
      Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &v7, &args.a4);
    if ( !vm->HandleException )
      ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Matrix *, const Scaleform::GFx::AS3::Value *, long double, long double, long double, long double, long double))Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_geom::Matrix,3,Scaleform::GFx::AS3::Value const,double,double,double,double,double>::Method)(
        (Scaleform::GFx::AS3::Instances::fl_geom::Matrix *)((char *)_this + dword_AAC93C),
        args.r,
        args.a0,
        args.a1,
        args.a2,
        args.a3,
        args.a4);
  }
}
