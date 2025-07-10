void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_text::Font,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Class *>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::AS3::Class *VClass; // esi
  Scaleform::GFx::AS3::Value to; // [esp+Ch] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  VClass = 0;
  if ( argc )
  {
    to.Flags = 0;
    to.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Impl::CoerceInternal(vm, &Scaleform::GFx::AS3::ClassClassTI, &to, argv);
    VClass = to.value.VS._1.VClass;
    if ( (to.Flags & 0x1F) > 9 )
    {
      if ( (to.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&to);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&to);
    }
  }
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_text::Font *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Class *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_text::Font,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Class *>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_text::Font *)(dword_AACD5C + v6.VInt),
      result,
      VClass);
}
