void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeDouble(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned __int64 value)
{
  unsigned __int64 v4; // kr00_8
  unsigned int v5; // eax

  if ( (*((_DWORD *)this + 8) & 0x18) == 8 )
    v4 = value;
  else
    v4 = Scaleform::Alg::ByteUtil::SwapOrder(value);
  v5 = this->Position + 8;
  if ( v5 < this->Data.Data.Size )
  {
    if ( v5 >= this->Length )
      this->Length = v5;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, this->Position + 8);
  }
  *(_QWORD *)&this->Data.Data.Data[this->Position] = v4;
  this->Position += 8;
}
