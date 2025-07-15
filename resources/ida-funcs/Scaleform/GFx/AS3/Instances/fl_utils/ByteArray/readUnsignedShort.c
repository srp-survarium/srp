void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readUnsignedShort(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned int *result)
{
  unsigned int Position; // eax
  unsigned int v3; // edx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // [esp+0h] [ebp-4h]

  v5 = (unsigned __int16)this;
  Position = this->Position;
  v3 = Position + 2;
  if ( Position + 2 <= this->Data.Data.Size )
  {
    v4 = *(_WORD *)&this->Data.Data.Data[Position];
    this->Position = v3;
    if ( (*((_DWORD *)this + 8) & 0x18) != 8 )
      v4 = __ROL2__(v4, 8);
    *result = v4;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
    *result = v5;
  }
}
