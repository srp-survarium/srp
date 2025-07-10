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
