void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, value);
}


void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned int value)
{
  const Scaleform::GFx::AS3::Value *Undefined; // eax

  Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(this, Undefined, value);
}
