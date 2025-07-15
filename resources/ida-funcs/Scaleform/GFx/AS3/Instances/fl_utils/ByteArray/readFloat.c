void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readFloat(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        long double *result)
{
  unsigned int Position; // eax
  unsigned int v3; // edx
  float v4; // eax
  float v; // [esp+0h] [ebp-8h]

  Position = this->Position;
  v3 = Position + 4;
  if ( Position + 4 <= this->Data.Data.Size )
  {
    v4 = *(float *)&this->Data.Data.Data[Position];
    this->Position = v3;
    v = v4;
    if ( (*((_DWORD *)this + 8) & 0x18) != 8 )
      LODWORD(v) = (((LODWORD(v4) << 16) | LOWORD(v4) & 0xFF00) << 8)
                 | ((HIWORD(LODWORD(v4)) | LODWORD(v4) & 0xFF0000u) >> 8);
    *result = v;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
  }
}
