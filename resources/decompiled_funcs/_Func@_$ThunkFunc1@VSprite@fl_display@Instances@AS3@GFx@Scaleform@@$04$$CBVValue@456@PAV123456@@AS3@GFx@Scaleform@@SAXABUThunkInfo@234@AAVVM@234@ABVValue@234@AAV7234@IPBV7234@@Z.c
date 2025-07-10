void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::Sprite *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::Sprite *VInt; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VInt = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::fl_display::SpriteTI, &to, argv);
    VInt = (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)to.value.VS._1.VInt;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Sprite *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_display::Sprite *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_display::Sprite,5,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_display::Sprite *>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(dword_AAE7AC + v6.VInt),
      result,
      VInt);
}
