void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,7,Scaleform::GFx::AS3::Value const,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  bool args_8; // [esp+Ch] [ebp-4h]

  v6 = obj->value.VS._1;
  args_8 = 0;
  if ( argc )
    args_8 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *, const Scaleform::GFx::AS3::Value *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TouchEvent,7,Scaleform::GFx::AS3::Value const,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_events::TouchEvent *)(v6.VInt + dword_AADC94),
      result,
      args_8);
}
