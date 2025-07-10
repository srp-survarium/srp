int __thiscall Scaleform::GFx::AS3::Instances::fl::XML::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Instances::fl::XML *other)
{
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v4; // ebx

  if ( this == other )
    return 1;
  v4 = other->GetKind(other);
  if ( this->GetKind(this) == v4 )
    return other->Text.pNode != this->Text.pNode ? 2 : 0;
  else
    return 2;
}
