void __cdecl Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,24,Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v6; // zf
  Scaleform::GFx::AS3::DefArgs5<long,unsigned long,unsigned long,unsigned long,bool> def_ags; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::UnboxArgV5<Scaleform::GFx::AS3::Value const ,long,unsigned long,unsigned long,unsigned long,bool> args; // [esp+24h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *_this; // [esp+4Ch] [ebp+Ch]

  _this = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)obj->pNext;
  def_ags._0 = 0;
  def_ags._1 = 0;
  def_ags._2 = 255;
  def_ags._3 = 7;
  def_ags._4 = 0;
  Scaleform::GFx::AS3::UnboxArgV4<Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long>::UnboxArgV4<Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  args.a4 = 0;
  v6 = !vm->HandleException;
  if ( !vm->HandleException )
  {
    if ( argc > 4 )
      args.a4 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 4);
    v6 = !vm->HandleException;
  }
  if ( v6 )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::BitmapData *, const Scaleform::GFx::AS3::Value *, int, unsigned int, unsigned int, unsigned int, bool))Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_display::BitmapData,24,Scaleform::GFx::AS3::Value const,long,unsigned long,unsigned long,unsigned long,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)((char *)_this + dword_AAE934),
      args.r,
      args.a0,
      args.a1,
      args.a2,
      args.a3,
      args.a4);
}
