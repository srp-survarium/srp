void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,8,Scaleform::GFx::AS3::Value const,long,long,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v6; // zf
  Scaleform::GFx::AS3::DefArgs3<long,long,bool> def_ags; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const ,long,long,bool> args; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *_this; // [esp+3Ch] [ebp+Ch]

  _this = (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)obj->pNext;
  memset(&def_ags, 0, 9);
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  args.a2 = 0;
  v6 = !vm->HandleException;
  if ( !vm->HandleException )
  {
    if ( argc > 2 )
      args.a2 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 2);
    v6 = !vm->HandleException;
  }
  if ( v6 )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, const Scaleform::GFx::AS3::Value *, int, int, bool))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,8,Scaleform::GFx::AS3::Value const,long,long,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)((char *)_this + dword_AACF1C),
      args.r,
      args.a0,
      args.a1,
      args.a2);
}
