void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,22,long,long,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // esi
  Scaleform::GFx::AS3::Value *v7; // eax
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::DefArgs2<long,long> def_ags; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<long,long,long> args; // [esp+10h] [ebp-14h] BYREF

  v6 = obj->value.VS._1;
  def_ags._0 = 0;
  def_ags._1 = 0x7FFFFFFF;
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,long,long>::UnboxArgV2<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,long,long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, int *, int, int))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,22,long,long,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAF0AC + v6.VInt),
      &args.r,
      args.a0,
      args.a1);
  if ( !args.Vm->HandleException )
  {
    v7 = args.Result;
    Flags = args.Result->Flags;
    args.Result->value.VS._1.VInt = args.r;
    v7->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)def_ags._1;
    v7->Flags = Flags & 0xFFFFFFE0 | 2;
  }
}
