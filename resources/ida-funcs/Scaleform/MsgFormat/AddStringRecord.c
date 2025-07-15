void __thiscall Scaleform::MsgFormat::AddStringRecord(Scaleform::MsgFormat *this, const Scaleform::StringDataPtr *str)
{
  const char *pStr; // ecx
  unsigned int Size; // eax
  char *v5; // eax
  unsigned int v6; // [esp+Ch] [ebp-10h]
  Scaleform::MsgFormat::fmt_record val; // [esp+10h] [ebp-Ch] BYREF

  pStr = str->pStr;
  LOBYTE(v6) = str->Size;
  Size = this->Data.Size;
  val.RecType = eStrType;
  val.RecValue = (Scaleform::MsgFormat::fmt_value)__PAIR64__(v6, (unsigned int)pStr);
  if ( Size >= 0x10 )
  {
    Scaleform::ArrayData<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->Data.DynamicArray.Data,
      &val);
  }
  else
  {
    v5 = &this->Data.StaticArray[12 * Size];
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 1) = pStr;
    *((_DWORD *)v5 + 2) = v6;
  }
  ++this->Data.Size;
}
