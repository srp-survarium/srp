void __cdecl Scaleform::GFx::AS3::Impl::CoerceInternal(
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::TypeInfo *ti,
        Scaleform::GFx::AS3::Value *to,
        const Scaleform::GFx::AS3::Value *from)
{
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v5; // eax

  if ( vm->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    AppDomain = vm->CallStack.Pages[(vm->CallStack.Size - 1) >> 6][(vm->CallStack.Size - 1) & 0x3F].pFile->AppDomain;
  else
    AppDomain = vm->CurrentDomain;
  v5 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, ti, AppDomain);
  if ( !v5 || !v5->Coerce(v5, from, to) )
    Scaleform::GFx::AS3::Value::Assign(to, from);
}
