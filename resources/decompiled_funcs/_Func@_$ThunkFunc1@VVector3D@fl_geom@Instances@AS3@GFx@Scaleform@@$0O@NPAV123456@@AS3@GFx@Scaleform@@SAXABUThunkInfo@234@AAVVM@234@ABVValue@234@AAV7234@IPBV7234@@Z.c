void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,14,double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  unsigned int Flags; // ecx
  unsigned int v9; // edx
  Scaleform::GFx::AS3::Value to; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::Vector3DTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *, long double *, Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D,14,double,Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *)(v6.VInt + dword_AAC9EC),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    Flags = args.Result->Flags;
    *(double *)&to.Flags = args.r;
    v9 = to.Flags;
    args.Result->Flags = Flags & 0xFFFFFFE0 | 4;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = v9;
  }
}
