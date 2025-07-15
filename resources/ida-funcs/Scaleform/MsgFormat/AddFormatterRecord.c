void __thiscall Scaleform::MsgFormat::AddFormatterRecord(
        Scaleform::MsgFormat *this,
        Scaleform::Formatter *f,
        bool allocated)
{
  unsigned int Size; // eax
  char *v5; // eax
  unsigned int v6; // [esp+Ch] [ebp-10h]
  Scaleform::MsgFormat::fmt_record val; // [esp+10h] [ebp-Ch] BYREF

  Size = this->Data.Size;
  LOBYTE(v6) = allocated;
  val.RecType = eFmtType;
  val.RecValue = (Scaleform::MsgFormat::fmt_value)__PAIR64__(v6, (unsigned int)f);
  if ( Size >= 0x10 )
  {
    Scaleform::ArrayData<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->Data.DynamicArray.Data,
      &val);
  }
  else
  {
    v5 = &this->Data.StaticArray[12 * Size];
    *(_DWORD *)v5 = 2;
    *((_DWORD *)v5 + 1) = f;
    *((_DWORD *)v5 + 2) = v6;
  }
  ++this->Data.Size;
}
