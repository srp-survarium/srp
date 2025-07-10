void __thiscall Scaleform::StrFormatter::StrFormatter(
        Scaleform::StrFormatter *this,
        Scaleform::MsgFormat *f,
        const char *v)
{
  this->pParentFmt = f;
  this->IsConverted = 0;
  this->__vftable = (Scaleform::StrFormatter_vtbl *)&Scaleform::StrFormatter::`vftable';
  this->Value.pStr = v;
  if ( v )
    this->Value.Size = strlen(v);
  else
    this->Value.Size = 0;
}
