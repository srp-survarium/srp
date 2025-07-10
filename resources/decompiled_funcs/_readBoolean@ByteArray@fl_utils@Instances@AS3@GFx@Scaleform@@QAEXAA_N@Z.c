void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readBoolean(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        bool *result)
{
  unsigned int Position; // eax

  Position = this->Position;
  if ( Position < this->Data.Data.Size )
  {
    this->Position = Position + 1;
    *result = this->Data.Data.Data[Position] != 0;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
  }
}
