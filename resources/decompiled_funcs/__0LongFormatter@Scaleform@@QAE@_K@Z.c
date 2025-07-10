void __thiscall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, __int64 v)
{
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::Formatter::`vftable';
  this->pParentFmt = 0;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase = *(_DWORD *)&this->Scaleform::NumericBase & 0xFFFFFC00 | 0x21;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) = *((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x80 | 0x20;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF0 | 1;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  this->ValueStr = 0;
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  *((_DWORD *)this + 7) = *((_DWORD *)this + 7) & 0xFFFFFFE0 | 0xA;
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFC | 2;
  this->Value = v;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::LongFormatter::`vftable'{for `Scaleform::Formatter'};
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::DoubleFormatter::`vftable'{for `Scaleform::String::InitStruct'};
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}
