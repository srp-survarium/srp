void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,8,Scaleform::GFx::AS3::Value const,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,double> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.r = result;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, const Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,8,Scaleform::GFx::AS3::Value const,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(dword_AAC9BC + v6.VInt),
      args.r,
      args.a0);
}
