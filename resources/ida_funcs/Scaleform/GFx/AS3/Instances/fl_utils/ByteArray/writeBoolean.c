void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeBoolean(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  unsigned int v4; // eax
  unsigned int Position; // eax

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
  this->Position = Position + 1;
  this->Data.Data.Data[Position] = value;
}
