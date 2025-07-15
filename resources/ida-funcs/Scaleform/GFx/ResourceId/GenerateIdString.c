int __thiscall Scaleform::GFx::ResourceId::GenerateIdString(
        Scaleform::GFx::ResourceId *this,
        char *pbuffer,
        unsigned int bufferSize,
        char suffixLetter)
{
  char *v4; // eax
  char *v5; // esi
  void (__thiscall *Convert)(struct Scaleform::LongFormatter *); // eax
  int Size; // esi
  Scaleform::LongFormatter v9; // [esp+4h] [ebp-50h] BYREF

  if ( suffixLetter )
  {
    v5 = pbuffer;
    *pbuffer = suffixLetter;
  }
  else
  {
    v4 = (char *)(this->Id & 0xFFF0000);
    if ( v4 == (_BYTE *)&loc_4FFFF + 1 )
    {
      v5 = pbuffer;
      *pbuffer = 71;
    }
    else if ( v4 == (char *)&loc_60000 || v4 == (_BYTE *)&locret_8FFFF + 1 )
    {
      v5 = pbuffer;
      *pbuffer = 70;
    }
    else
    {
      v5 = pbuffer;
      *pbuffer = 73;
    }
  }
  Scaleform::LongFormatter::LongFormatter(&v9, LOWORD(this->Id));
  Convert = v9.Convert;
  *((_BYTE *)&v9.Scaleform::NumericBase + 6) |= 1u;
  *((_DWORD *)&v9 + 7) = *((_DWORD *)&v9 + 7) & 0xFFFFFFE0 | 0x10;
  Convert(&v9);
  Scaleform::DoubleFormatter::InitString(
    (Scaleform::DoubleFormatter *)&v9.Scaleform::String::InitStruct,
    v5 + 1,
    bufferSize);
  Size = Scaleform::LongFormatter::GetSize(&v9);
  v9.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  Scaleform::Formatter::~Formatter(&v9);
  return Size;
}
