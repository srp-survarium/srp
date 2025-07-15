void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeUnsignedInt(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  unsigned int v4; // edi
  unsigned int v5; // eax

  if ( (*((_DWORD *)this + 8) & 0x18) == 8 )
    v4 = value;
  else
    v4 = (((value << 16) | value & 0xFF00) << 8) | ((((unsigned __int64)value >> 16) | value & 0xFF0000) >> 8);
  v5 = this->Position + 4;
  if ( v5 < this->Data.Data.Size )
  {
    if ( v5 >= this->Length )
      this->Length = v5;
    *(_DWORD *)&this->Data.Data.Data[this->Position] = v4;
    this->Position += 4;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, this->Position + 4);
    *(_DWORD *)&this->Data.Data.Data[this->Position] = v4;
    this->Position += 4;
  }
}
