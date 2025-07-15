unsigned int __thiscall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::GetLength(
        Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this)
{
  unsigned int result; // [esp+0h] [ebp-4h] BYREF

  result = (unsigned int)this;
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthGet(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)this->PixelVector,
    &result);
  return result;
}
