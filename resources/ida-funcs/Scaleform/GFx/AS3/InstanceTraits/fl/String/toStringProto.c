void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *VObj; // edi
  Scaleform::GFx::AS3::Classes::fl::String *ClassString; // eax

  if ( (_this->Flags & 0x1F) - 12 <= 3
    && (VObj = _this->value.VS._1.VObj,
        ClassString = Scaleform::GFx::AS3::VM::GetClassString(vm),
        VObj == Scaleform::GFx::AS3::Class::GetPrototype(ClassString)) )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)vm->StringManagerRef);
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3toString(ti, vm, _this, result);
  }
}
