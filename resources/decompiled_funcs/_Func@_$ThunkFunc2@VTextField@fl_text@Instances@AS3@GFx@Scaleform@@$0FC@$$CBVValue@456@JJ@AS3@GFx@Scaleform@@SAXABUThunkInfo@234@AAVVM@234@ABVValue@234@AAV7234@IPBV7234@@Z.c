void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_text::TextField,82,Scaleform::GFx::AS3::Value const,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::DefArgs2<long,long> def_ags; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,long,long> args; // [esp+10h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  def_ags._0 = 0;
  def_ags._1 = 0;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,long,long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, int, int))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_text::TextField,82,Scaleform::GFx::AS3::Value const,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACFAC + v6.VInt),
      args.r,
      args.a0,
      args.a1);
}
