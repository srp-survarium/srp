void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *VObj; // edi
  Scaleform::GFx::AS3::Classes::fl::Boolean *ClassBoolean; // eax

  if ( (_this->Flags & 0x1F) - 12 <= 3
    && (VObj = _this->value.VS._1.VObj,
        ClassBoolean = Scaleform::GFx::AS3::VM::GetClassBoolean(vm),
        VObj == Scaleform::GFx::AS3::Class::GetPrototype(ClassBoolean)) )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[5]);
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::AS3toString(ti, vm, _this, result);
  }
}
