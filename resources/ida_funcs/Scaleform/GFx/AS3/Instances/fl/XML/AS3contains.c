void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3contains(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        bool *result,
        const Scaleform::GFx::AS3::Value *value)
{
  *result = 0;
  if ( (value->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLObject(value->value.VS._1.VObj) )
    *result = this->EqualsInternal(this, (const Scaleform::GFx::AS3::Instances::fl::XML *)value->value.VS._1.VInt) == true3;
}
