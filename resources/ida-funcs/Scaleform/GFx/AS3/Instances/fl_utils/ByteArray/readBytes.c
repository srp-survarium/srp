void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readBytes(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        unsigned int offset,
        unsigned int length)
{
  unsigned int v6; // edi
  unsigned int Position; // eax

  v6 = length;
  if ( length )
  {
    if ( length > this->Data.Data.Size - this->Position )
    {
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
      return;
    }
  }
  else
  {
    v6 = this->Data.Data.Size - this->Position;
  }
  if ( v6 + offset >= bytes->Data.Data.Size )
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(bytes, v6 + offset);
  Position = this->Position;
  if ( Position + v6 <= this->Data.Data.Size )
  {
    memcpy((int)&bytes->Data.Data.Data[offset], (const __m128i *)&this->Data.Data.Data[Position], v6);
    this->Position += v6;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
  }
}
