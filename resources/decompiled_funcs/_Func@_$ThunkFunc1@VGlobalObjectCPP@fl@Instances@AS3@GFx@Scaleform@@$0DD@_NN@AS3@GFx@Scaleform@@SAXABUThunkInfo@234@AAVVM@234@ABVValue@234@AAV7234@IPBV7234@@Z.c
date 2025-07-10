void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,51,bool,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v8; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  args.a0 = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, bool *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,51,bool,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(v6.VInt + dword_AAD414),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      r = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
      v8.VS._1.VBool = r;
      args.Result->value = v8;
    }
  }
}
