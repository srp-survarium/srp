void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Write(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned __int16 v)
{
  unsigned int v3; // eax

  if ( (*((_DWORD *)this + 8) & 0x18) != 8 )
    v = __ROL2__(v, 8);
  v3 = this->Position + 2;
  if ( v3 < this->Data.Data.Size )
  {
    if ( v3 >= this->Length )
      this->Length = v3;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, this->Position + 2);
  }
  *(_WORD *)&this->Data.Data.Data[this->Position] = v;
  this->Position += 2;
}


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
