int __thiscall Scaleform::GFx::AS3::Instances::fl::XMLComment::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XMLComment *this,
        Scaleform::GFx::AS3::Instances::fl::XMLComment *other)
{
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v4; // ebx

  if ( this == other )
    return 1;
  v4 = other->GetKind(other);
  if ( this->GetKind(this) == v4 )
    return (this->Text.pNode != other->Text.pNode) + 1;
  else
    return 2;
}
