void __thiscall Scaleform::StrFormatter::StrFormatter(
        Scaleform::StrFormatter *this,
        Scaleform::MsgFormat *f,
        const Scaleform::String *v)
{
  this->pParentFmt = f;
  this->IsConverted = 0;
  this->__vftable = (Scaleform::StrFormatter_vtbl *)&Scaleform::StrFormatter::`vftable';
  this->Value.pStr = (const char *)((v->HeapTypeBits & 0xFFFFFFFC) + 8);
  this->Value.Size = *(_DWORD *)(v->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF;
}


void __thiscall Scaleform::StrFormatter::StrFormatter(
        Scaleform::StrFormatter *this,
        Scaleform::MsgFormat *f,
        const Scaleform::StringDataPtr *v)
{
  this->pParentFmt = f;
  this->IsConverted = 0;
  this->__vftable = (Scaleform::StrFormatter_vtbl *)&Scaleform::StrFormatter::`vftable';
  this->Value = *v;
}


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


void __thiscall Scaleform::StrFormatter::StrFormatter(Scaleform::StrFormatter *this, const char *v)
{
  this->pParentFmt = 0;
  this->IsConverted = 0;
  this->__vftable = (Scaleform::StrFormatter_vtbl *)&Scaleform::StrFormatter::`vftable';
  this->Value.pStr = v;
  if ( v )
    this->Value.Size = strlen(v);
  else
    this->Value.Size = 0;
}
