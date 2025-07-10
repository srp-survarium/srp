void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,16,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // esi
  long double r; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV0<double> args; // [esp+Ch] [ebp-10h] BYREF

  v4 = obj->value.VS._1;
  args.r = Scaleform::GFx::NumberUtil::NaN();
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, long double *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,16,double>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v4.VInt + dword_AADC5C),
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 4;
    result->value.VNumber = r;
  }
}
