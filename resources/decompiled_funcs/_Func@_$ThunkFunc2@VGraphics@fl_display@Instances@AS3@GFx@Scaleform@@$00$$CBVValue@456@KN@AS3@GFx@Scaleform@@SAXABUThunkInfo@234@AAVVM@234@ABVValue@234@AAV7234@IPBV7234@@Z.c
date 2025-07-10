void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::Graphics,1,Scaleform::GFx::AS3::Value const,unsigned long,double>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::DefArgs2<unsigned long,double> def_ags; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,unsigned long,double> args; // [esp+20h] [ebp-18h] BYREF

  def_ags._1 = 1.0;
  v6 = obj->value.VS._1;
  def_ags._0 = 0;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,unsigned long,double>::UnboxArgV2<Scaleform::GFx::AS3::Value const,unsigned long,double>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_display::Graphics *, const Scaleform::GFx::AS3::Value *, unsigned int, long double))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_display::Graphics,1,Scaleform::GFx::AS3::Value const,unsigned long,double>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)(v6.VInt + dword_AAE13C),
      args.r,
      args.a0,
      args.a1);
}
