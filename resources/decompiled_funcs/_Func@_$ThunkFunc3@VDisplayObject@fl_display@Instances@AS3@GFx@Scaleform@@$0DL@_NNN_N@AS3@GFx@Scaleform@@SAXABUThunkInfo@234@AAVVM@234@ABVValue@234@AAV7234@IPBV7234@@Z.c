void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,59,bool,double,double,bool>::Func(
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
  bool r; // cl
  double v10; // [esp+24h] [ebp-48h]
  Scaleform::GFx::AS3::DefArgs3<double,double,bool> def_ags; // [esp+2Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<bool,double,double,bool> args; // [esp+44h] [ebp-28h] BYREF

  v6 = obj->value.VS._1;
  v10 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._0 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._1 = v10;
  def_ags._2 = 0;
  Scaleform::GFx::AS3::UnboxArgV2<bool,double,double>::UnboxArgV2<bool,double,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  v7 = !vm->HandleException;
  args.a2 = 0;
  if ( v7 )
  {
    if ( argc > 2 )
      args.a2 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 2);
    if ( !vm->HandleException )
      ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, bool *, long double, long double, bool))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject,59,bool,double,double,bool>::Method)(
        (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)(dword_AAE71C + v6.VInt),
        &args.r,
        args.a0,
        args.a1,
        args.a2);
  }
  if ( !args.Vm->HandleException )
  {
    v8 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v10) = r;
    v8->value.VNumber = v10;
  }
}
