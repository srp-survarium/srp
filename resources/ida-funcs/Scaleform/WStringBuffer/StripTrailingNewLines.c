void __thiscall Scaleform::WStringBuffer::StripTrailingNewLines(Scaleform::WStringBuffer *this)
{
  signed int Length; // eax
  int i; // esi
  wchar_t v3; // dx
  wchar_t *v4; // eax

  Length = this->Length;
  if ( Length > 0 && !this->pText[Length - 1] )
    --Length;
  for ( i = Length - 1; i >= 0; *v4 = 0 )
  {
    v3 = this->pText[i];
    v4 = &this->pText[i];
    if ( v3 != 10 && v3 != 13 )
      break;
    --this->Length;
    --i;
  }
}
