void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readDouble(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        long double *result)
{
  unsigned int Position; // edx

  Position = this->Position;
  if ( Position + 8 <= this->Data.Data.Size )
  {
    *result = *(long double *)&this->Data.Data.Data[Position];
    this->Position += 8;
    if ( (*((_DWORD *)this + 8) & 0x18) != 8 )
      *(_QWORD *)result = Scaleform::Alg::ByteUtil::SwapOrder(COERCE_UNSIGNED_INT64(*result));
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
  }
}
