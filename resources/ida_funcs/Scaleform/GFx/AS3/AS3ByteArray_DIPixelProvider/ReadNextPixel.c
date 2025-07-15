unsigned int __thiscall Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::ReadNextPixel(
        Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider *this)
{
  unsigned int result; // [esp+0h] [ebp-4h] BYREF

  result = (unsigned int)this;
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readInt(this->PixelArray, &result);
  return result;
}
