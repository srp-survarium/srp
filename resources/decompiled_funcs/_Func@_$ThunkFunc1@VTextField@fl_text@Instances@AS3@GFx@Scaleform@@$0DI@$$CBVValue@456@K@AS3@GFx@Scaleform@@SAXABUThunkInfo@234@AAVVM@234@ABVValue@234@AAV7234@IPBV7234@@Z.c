void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,56,Scaleform::GFx::AS3::Value const,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,unsigned long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, unsigned int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextField,56,Scaleform::GFx::AS3::Value const,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACD84 + v6.VInt),
      args.r,
      args.a0);
}
