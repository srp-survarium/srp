void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,3,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *v7; // eax
  bool r; // cl
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *> args; // [esp+1Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Vm = vm;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_geom::PointTI, &to, argv);
    args.a0 = (Scaleform::GFx::AS3::Instances::fl_geom::Point *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_geom::Point *, bool *, Scaleform::GFx::AS3::Instances::fl_geom::Point *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::Point,3,bool,Scaleform::GFx::AS3::Instances::fl_geom::Point *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_geom::Point *)(dword_AAC714 + v6.VInt),
      &args.r,
      args.a0);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(to.Flags) = r;
    Flags = to.Flags;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)to.Bonus.pWeakProxy;
    v7->value.VS._1.VInt = Flags;
  }
}
