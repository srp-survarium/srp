void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropertyValue(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index == 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(value, &this->Uri);
  }
  else if ( ind.Index == 2 )
  {
    Scaleform::GFx::AS3::Value::Assign(value, &this->Prefix);
  }
}
