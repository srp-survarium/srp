void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeShort(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned __int16 value)
{
  unsigned int v4; // eax

  if ( (*((_DWORD *)this + 8) & 0x18) != 8 )
    value = (value << 8) | HIBYTE(value);
  v4 = this->Position + 2;
  if ( v4 < this->Data.Data.Size )
  {
    if ( v4 >= this->Length )
      this->Length = v4;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, this->Position + 2);
  }
  *(_WORD *)&this->Data.Data.Data[this->Position] = value;
  this->Position += 2;
}
