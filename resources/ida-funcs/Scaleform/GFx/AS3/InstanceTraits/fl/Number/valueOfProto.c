void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::Number::valueOfProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *VObj; // edi
  Scaleform::GFx::AS3::Classes::fl::Number *ClassNumber; // eax

  if ( (_this->Flags & 0x1F) - 12 <= 3
    && (VObj = _this->value.VS._1.VObj,
        ClassNumber = Scaleform::GFx::AS3::VM::GetClassNumber(vm),
        VObj == Scaleform::GFx::AS3::Class::GetPrototype(ClassNumber)) )
  {
    Scaleform::GFx::AS3::Value::SetNumber(result, 0.0);
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3valueOf(ti, vm, _this, result);
  }
}
