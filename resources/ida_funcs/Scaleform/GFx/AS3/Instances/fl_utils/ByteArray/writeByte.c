void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeByte(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned __int8 value)
{
  unsigned int v4; // eax
  unsigned int Position; // eax
  unsigned __int8 *Data; // edx

  v4 = this->Position + 1;
  if ( v4 < this->Data.Data.Size )
  {
    if ( v4 >= this->Length )
      this->Length = v4;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, this->Position + 1);
  }
  Position = this->Position;
  Data = this->Data.Data.Data;
  this->Position = Position + 1;
  Data[Position] = value;
}
