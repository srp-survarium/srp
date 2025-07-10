void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,17,bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  bool v7; // zf
  Scaleform::GFx::AS3::Value *v8; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v10; // [esp+18h] [ebp-40h]
  Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double,bool> def_ags; // [esp+20h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double,bool> args; // [esp+38h] [ebp-20h] BYREF

  v6 = obj->value.VS._1;
  def_ags._0 = 0;
  def_ags._1 = Scaleform::GFx::NumberUtil::NaN();
  def_ags._2 = 0;
  Scaleform::GFx::AS3::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double>::UnboxArgV2<bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double>(
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
      args.a2 = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)&argv[2]);
    if ( !vm->HandleException )
      ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double, bool))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,17,bool,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *,double,bool>::Method)(
        (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC8B4 + v6.VInt),
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
    v10.VS._1.VBool = r;
    v8->value = v10;
  }
}
