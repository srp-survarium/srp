void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readUTF(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::ASString *result)
{
  unsigned int Position; // eax
  unsigned int v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // [esp+4h] [ebp-4h]

  Position = this->Position;
  v4 = Position + 2;
  if ( Position + 2 > this->Data.Data.Size )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
LABEL_5:
    v5 = v6;
    goto LABEL_6;
  }
  v5 = *(_WORD *)&this->Data.Data.Data[Position];
  this->Position = v4;
  if ( (*((_DWORD *)this + 8) & 0x18) != 8 )
  {
    v6 = __ROL2__(v5, 8);
    goto LABEL_5;
  }
LABEL_6:
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ReadUTFBytes(
    this,
    (Scaleform::GFx::AS3::CheckResult *)&result,
    result,
    v5);
}
