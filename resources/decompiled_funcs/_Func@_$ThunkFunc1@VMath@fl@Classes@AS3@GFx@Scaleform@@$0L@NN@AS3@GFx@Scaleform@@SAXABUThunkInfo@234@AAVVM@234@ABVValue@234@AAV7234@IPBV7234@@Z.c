void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,11,double,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  double def_ags; // [esp+10h] [ebp-20h]
  long double def_agsa; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::UnboxArgV1<double,double> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  def_ags = Scaleform::GFx::NumberUtil::NaN();
  args.Result = result;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  args.a0 = def_ags;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl::Math *, long double *, long double))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Math,11,double,double>::Method)(
      (Scaleform::GFx::AS3::Classes::fl::Math *)(v6.VInt + dword_AAD054),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
    {
      def_agsa = args.r;
      args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 4;
      args.Result->value.VNumber = def_agsa;
    }
  }
}
