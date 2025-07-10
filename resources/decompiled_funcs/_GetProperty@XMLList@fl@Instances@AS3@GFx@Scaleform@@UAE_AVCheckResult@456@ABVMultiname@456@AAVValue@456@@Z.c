Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Object *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::SoundObject *v4; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v7; // ebx
  unsigned int ind; // [esp+8h] [ebp-4h] BYREF

  v4 = (Scaleform::GFx::AS3::SoundObject *)prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         (const Scaleform::GFx::AS3::Multiname *)prop_name,
         &ind)->Result )
  {
    if ( ind >= this->List.Data.Size )
    {
      v6 = result;
      result->Result = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(value, this->List.Data.Data[ind].pObject);
      v6 = result;
      result->Result = 1;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
      this,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&prop_name,
      v4);
    v7 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)prop_name;
    Scaleform::GFx::AS3::Value::Pick(value, prop_name);
    Scaleform::GFx::AS3::Instances::fl::XMLList::GetProperty(
      this,
      result,
      (const Scaleform::GFx::AS3::Multiname *)v4,
      v7);
    return result;
  }
  return v6;
}
