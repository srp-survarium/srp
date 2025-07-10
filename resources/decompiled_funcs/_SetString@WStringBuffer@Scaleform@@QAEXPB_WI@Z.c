void __thiscall Scaleform::WStringBuffer::SetString(Scaleform::WStringBuffer *this, wchar_t *pstr, unsigned int length)
{
  unsigned int v3; // esi

  v3 = length;
  if ( length == -1 )
    v3 = Scaleform::SFwcslen(pstr);
  if ( Scaleform::WStringBuffer::Resize(this, v3) )
  {
    if ( v3 )
      memcpy((unsigned __int8 *)this->pText, (unsigned __int8 *)pstr, 2 * v3 + 2);
  }
}
