void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,13,unsigned long,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV1<unsigned long,unsigned long> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.Result = result;
  args.r = 0;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *, unsigned int *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager,13,unsigned long,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::FocusManager *)(v6.VInt + dword_AAEBC4),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 3;
      args.Result->value.VS._1.VInt = r;
      args.Result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)args.Result;
    }
  }
}
