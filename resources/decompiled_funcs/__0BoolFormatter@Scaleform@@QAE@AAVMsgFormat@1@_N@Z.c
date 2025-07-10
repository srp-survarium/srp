void __thiscall Scaleform::BoolFormatter::BoolFormatter(
        Scaleform::BoolFormatter *this,
        Scaleform::MsgFormat *f,
        bool v)
{
  char v3; // dl

  v3 = *((_BYTE *)this + 12);
  this->pParentFmt = f;
  this->IsConverted = 0;
  this->__vftable = (Scaleform::BoolFormatter_vtbl *)&Scaleform::BoolFormatter::`vftable';
  *((_BYTE *)this + 12) = v | v3 & 0xFC;
  this->result.pStr = 0;
  this->result.Size = 0;
}
