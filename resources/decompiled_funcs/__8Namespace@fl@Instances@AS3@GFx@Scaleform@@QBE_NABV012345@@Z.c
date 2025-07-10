BOOL __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::operator==(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *other)
{
  return this->Uri.pNode == other->Uri.pNode && ((*((_BYTE *)this + 20) ^ *((_BYTE *)other + 20)) & 0xF) == 0;
}
