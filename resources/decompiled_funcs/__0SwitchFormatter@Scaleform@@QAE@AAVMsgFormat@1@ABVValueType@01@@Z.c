void __thiscall Scaleform::SwitchFormatter::SwitchFormatter(
        Scaleform::SwitchFormatter *this,
        Scaleform::MsgFormat *f,
        const Scaleform::SwitchFormatter::ValueType *v)
{
  this->pParentFmt = f;
  this->IsConverted = 0;
  this->__vftable = (Scaleform::SwitchFormatter_vtbl *)&Scaleform::SwitchFormatter::`vftable';
  this->Value = v->Value;
  this->StringSet.mHash.pTable = 0;
  this->StrValue.pStr = 0;
  this->StrValue.Size = 0;
  this->DefaultStrValue.pStr = 0;
  this->DefaultStrValue.Size = 0;
}
