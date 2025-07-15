void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::uint::valueOfProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *VObj; // edi
  Scaleform::GFx::AS3::Classes::fl::uint *ClassUInt; // eax

  if ( (_this->Flags & 0x1F) - 12 <= 3
    && (VObj = _this->value.VS._1.VObj,
        ClassUInt = Scaleform::GFx::AS3::VM::GetClassUInt(vm),
        VObj == Scaleform::GFx::AS3::Class::GetPrototype(ClassUInt)) )
  {
    Scaleform::GFx::AS3::Value::SetUInt32(result, 0);
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3valueOf(ti, vm, _this, result);
  }
}
