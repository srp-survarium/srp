void __thiscall Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider::WriteNextPixel(
        Scaleform::GFx::AS3::AS3ByteArray_DIPixelProvider *this,
        unsigned int pixel)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *PixelArray; // esi
  const Scaleform::GFx::AS3::Value *Undefined; // eax

  PixelArray = this->PixelArray;
  Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeUnsignedInt(PixelArray, Undefined, pixel);
}
