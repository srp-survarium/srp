void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,17,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v4; // ecx
  int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)(dword_AAF184 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *, int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int,17,long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}
