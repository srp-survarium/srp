void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::GetDynamicProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value::Assign(value, this->List.Data.Data[ind.Index].pObject);
}
