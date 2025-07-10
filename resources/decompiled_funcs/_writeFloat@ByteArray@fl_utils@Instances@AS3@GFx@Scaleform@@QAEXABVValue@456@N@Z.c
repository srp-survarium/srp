void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeFloat(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  float v4; // edi
  unsigned int v5; // eax
  float v; // [esp+8h] [ebp+8h]

  v = value;
  if ( (*((_DWORD *)this + 8) & 0x18) == 8 )
    v4 = v;
  else
    LODWORD(v4) = (((LODWORD(v) << 16) | LOWORD(v) & 0xFF00) << 8)
                | ((((unsigned __int64)LODWORD(v) >> 16)
                  | (unsigned int)&vostok::memory::s_CRT_arena[5508664] & LODWORD(v)) >> 8);
  v5 = this->Position + 4;
  if ( v5 < this->Data.Data.Size )
  {
    if ( v5 >= this->Length )
      this->Length = v5;
    *(float *)&this->Data.Data.Data[this->Position] = v4;
    this->Position += 4;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, this->Position + 4);
    *(float *)&this->Data.Data.Data[this->Position] = v4;
    this->Position += 4;
  }
}
