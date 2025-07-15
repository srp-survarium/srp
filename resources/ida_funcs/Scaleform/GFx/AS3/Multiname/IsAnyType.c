char __thiscall Scaleform::GFx::AS3::Multiname::IsAnyType(Scaleform::GFx::AS3::Multiname *this)
{
  char v1; // dl
  Scaleform::GFx::ASStringNode *VStr; // ecx
  char v3; // bl

  v1 = 0;
  if ( (this->Name.Flags & 0x1F) == 0 || (this->Name.Flags & 0x1F) - 12 <= 3 && !this->Name.value.VS._1.VInt )
  {
    VStr = 0;
    goto LABEL_9;
  }
  if ( (this->Name.Flags & 0x1F) != 0xA )
  {
    VStr = 0;
    v3 = 0;
    goto LABEL_10;
  }
  VStr = this->Name.value.VS._1.VStr;
  v1 = 1;
  ++VStr->RefCount;
  if ( !VStr->Size )
  {
LABEL_9:
    v3 = 1;
    goto LABEL_10;
  }
  v3 = 0;
LABEL_10:
  if ( (v1 & 1) != 0 && VStr->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  return v3;
}
