void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Write(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned __int8 *src,
        unsigned int buff_size)
{
  unsigned int v4; // eax

  v4 = buff_size + this->Position;
  if ( v4 < this->Data.Data.Size )
  {
    if ( v4 >= this->Length )
      this->Length = v4;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, buff_size + this->Position);
  }
  memcpy(&this->Data.Data.Data[this->Position], src, buff_size);
  this->Position += buff_size;
}
