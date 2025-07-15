void __thiscall Scaleform::GFx::AS3::Instances::fl::QName::GetNextPropertyValue(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax

  if ( ind.Index == 1 )
  {
    pObject = this->Ns.pObject;
    if ( pObject )
      Scaleform::GFx::AS3::Value::Assign(value, &pObject->Uri);
    else
      Scaleform::GFx::AS3::Value::SetNull(value);
  }
  else if ( ind.Index == 2 )
  {
    Scaleform::GFx::AS3::Value::Assign(value, &this->LocalName);
  }
}
