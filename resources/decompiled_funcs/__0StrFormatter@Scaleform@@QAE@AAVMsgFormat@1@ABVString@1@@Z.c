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
