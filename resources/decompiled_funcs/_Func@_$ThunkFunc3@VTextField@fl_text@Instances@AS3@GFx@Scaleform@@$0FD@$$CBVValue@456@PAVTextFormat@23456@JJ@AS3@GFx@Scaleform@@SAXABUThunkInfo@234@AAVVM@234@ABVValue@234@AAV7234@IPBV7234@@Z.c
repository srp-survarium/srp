void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextField,83,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextFormat *,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v6; // ebx
  Scaleform::GFx::AS3::Value::V1U v7; // ebp
  Scaleform::GFx::AS3::Value *v8; // edi
  bool v9; // zf
  Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_text::TextFormat *,long,long> def_ags; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::AS3::Instances::fl_text::TextFormat *,long,long> args; // [esp+1Ch] [ebp-14h] BYREF

  v6 = argc;
  v7 = obj->value.VS._1;
  v8 = argv;
  def_ags._0 = 0;
  def_ags._1 = -1;
  def_ags._2 = -1;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextFormat *,long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextFormat *,long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  v9 = !vm->HandleException;
  args.a2 = -1;
  if ( v9 )
  {
    if ( v6 > 2 )
      Scaleform::GFx::AS3::Value::Convert2Int32(v8 + 2, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a2);
    if ( !vm->HandleException )
      ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextField *, const Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Instances::fl_text::TextFormat *, int, int))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextField,83,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_text::TextFormat *,long,long>::Method)(
        (Scaleform::GFx::AS3::Instances::fl_text::TextField *)(dword_AACDEC + v7.VInt),
        args.r,
        args.a0,
        args.a1,
        args.a2);
  }
}
