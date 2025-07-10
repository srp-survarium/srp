void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,30,Scaleform::GFx::AS3::Value const,long,long,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v6; // ebp
  Scaleform::GFx::AS3::Value *v7; // edi
  bool v8; // zf
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *_this; // [esp+10h] [ebp-24h]
  Scaleform::GFx::AS3::DefArgs3<long,long,unsigned long> def_ags; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const ,long,long,unsigned long> args; // [esp+20h] [ebp-14h] BYREF

  v6 = argc;
  v7 = argv;
  _this = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)obj->value.VS._1.VInt;
  memset(&def_ags, 0, sizeof(def_ags));
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  args.a2 = 0;
  v8 = !vm->HandleException;
  if ( !vm->HandleException )
  {
    if ( v6 > 2 )
      Scaleform::GFx::AS3::Value::Convert2UInt32(v7 + 2, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a2);
    v8 = !vm->HandleException;
  }
  if ( v8 )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, const Scaleform::GFx::AS3::Value *, int, int, unsigned int))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,30,Scaleform::GFx::AS3::Value const,long,long,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)((char *)_this + dword_AAE4D4),
      args.r,
      args.a0,
      args.a1,
      args.a2);
}
