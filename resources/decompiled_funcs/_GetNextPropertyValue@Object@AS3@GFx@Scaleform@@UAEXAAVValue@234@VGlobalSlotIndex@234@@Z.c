void __thiscall Scaleform::GFx::AS3::Object::GetNextPropertyValue(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Object *, unsigned int, Scaleform::GFx::AS3::Value *))this->GetDynamicProperty)(
      this,
      ind.Index - 1,
      value);
}
