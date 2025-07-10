void __thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::multilineGet(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        bool *result)
{
  *result = (this->OptionFlags & 2) != 0;
}
