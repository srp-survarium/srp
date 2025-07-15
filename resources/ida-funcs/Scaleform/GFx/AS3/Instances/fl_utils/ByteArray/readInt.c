void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readInt(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned int *result)
{
  unsigned int Position; // eax

  Position = this->Position;
  if ( Position + 4 <= this->Data.Data.Size )
  {
    *result = *(_DWORD *)&this->Data.Data.Data[Position];
    this->Position += 4;
    if ( (*((_DWORD *)this + 8) & 0x18) != 8 )
      *result = (((*result << 16) | *result & 0xFF00) << 8) | ((HIWORD(*result) | *result & 0xFF0000) >> 8);
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
  }
}
