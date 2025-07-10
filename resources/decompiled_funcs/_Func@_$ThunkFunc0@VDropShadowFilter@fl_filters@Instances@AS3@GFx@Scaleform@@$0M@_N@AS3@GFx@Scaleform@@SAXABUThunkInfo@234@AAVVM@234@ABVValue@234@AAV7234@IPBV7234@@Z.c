void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,12,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *v4; // ecx
  bool r; // cl
  long double v6; // [esp+0h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV0<bool> args; // [esp+8h] [ebp-Ch] BYREF

  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *)(dword_AADECC + obj->value.VS._1.VInt);
  args.r = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *, bool *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter,12,bool>::Method)(
    v4,
    &args.r);
  if ( !vm->HandleException )
  {
    r = args.r;
    result->Flags = result->Flags & 0xFFFFFFE0 | 1;
    LOBYTE(v6) = r;
    result->value.VNumber = v6;
  }
}
