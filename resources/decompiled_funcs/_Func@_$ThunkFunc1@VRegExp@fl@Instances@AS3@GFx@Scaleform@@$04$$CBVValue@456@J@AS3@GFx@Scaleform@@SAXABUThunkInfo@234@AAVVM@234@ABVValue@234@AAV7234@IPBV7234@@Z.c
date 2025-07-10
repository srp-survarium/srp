void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,5,Scaleform::GFx::AS3::Value const,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,long> args; // [esp+8h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  args.r = result;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::RegExp *, const Scaleform::GFx::AS3::Value *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::RegExp,5,Scaleform::GFx::AS3::Value const,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::RegExp *)(dword_AAD504 + v6.VInt),
      args.r,
      args.a0);
}
