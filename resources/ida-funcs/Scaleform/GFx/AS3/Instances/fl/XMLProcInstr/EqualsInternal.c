int __thiscall Scaleform::GFx::AS3::Instances::fl::XMLProcInstr::EqualsInternal(
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *this,
        Scaleform::GFx::AS3::Instances::fl::XMLProcInstr *other)
{
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v4; // ebx

  if ( this == other )
    return 1;
  v4 = other->GetKind(other);
  if ( this->GetKind(this) == v4 && this->Text.pNode == other->Text.pNode )
    return (this->Data.pNode != other->Data.pNode) + 1;
  else
    return 2;
}
