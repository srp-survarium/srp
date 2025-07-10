void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::int_::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Object *VObj; // edi
  Scaleform::GFx::AS3::Classes::fl::int_ *ClassSInt; // eax

  if ( (_this->Flags & 0x1F) - 12 <= 3
    && (VObj = _this->value.VS._1.VObj,
        ClassSInt = Scaleform::GFx::AS3::VM::GetClassSInt(vm),
        VObj == Scaleform::GFx::AS3::Class::GetPrototype(ClassSInt)) )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[15]);
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::int_::AS3toString(ti, vm, _this, result, argc, argv);
  }
}
