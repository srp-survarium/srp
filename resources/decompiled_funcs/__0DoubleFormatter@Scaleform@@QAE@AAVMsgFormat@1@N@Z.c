void __thiscall Scaleform::DoubleFormatter::DoubleFormatter(
        Scaleform::DoubleFormatter *this,
        Scaleform::MsgFormat *f,
        long double v)
{
  char v4; // cl

  this->pParentFmt = f;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::DoubleFormatter_vtbl *)&Scaleform::Formatter::`vftable';
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase = *(_DWORD *)&this->Scaleform::NumericBase & 0xFFFFFC00 | 0x21;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) = *((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x80 | 0x20;
  v4 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = v4 & 0xF0 | 1;
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  this->Type = FmtDecimal;
  this->Len = 0;
  this->Value = v;
  this->Buff[347] = 0;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::DoubleFormatter_vtbl *)&Scaleform::DoubleFormatter::`vftable'{for `Scaleform::Formatter'};
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::DoubleFormatter::`vftable'{for `Scaleform::String::InitStruct'};
  this->ValueStr = &this->Buff[347];
  *(_DWORD *)&this->Scaleform::NumericBase = *(_DWORD *)&this->Scaleform::NumericBase & 0xFFFFFFE0 | 6;
}
