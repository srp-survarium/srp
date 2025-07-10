void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,0,unsigned long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v4; // ecx
  unsigned int r; // ecx
  Scaleform::GFx::AS3::UnboxArgV0<unsigned long> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAEFA4 + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, unsigned int *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,0,unsigned long>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 3;
    result->value.VS._1.VInt = r;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result;
  }
}
