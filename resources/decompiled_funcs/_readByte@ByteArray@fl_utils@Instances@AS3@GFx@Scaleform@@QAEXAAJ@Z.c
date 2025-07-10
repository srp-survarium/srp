void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readByte(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        int *result)
{
  unsigned int Position; // eax

  Position = this->Position;
  if ( Position < this->Data.Data.Size )
  {
    this->Position = Position + 1;
    *result = (char)this->Data.Data.Data[Position];
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
  }
}
