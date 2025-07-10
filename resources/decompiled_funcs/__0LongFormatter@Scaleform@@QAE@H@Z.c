void __thiscall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, int v)
{
  char v2; // dl
  char v3; // al
  unsigned int v4; // edx

  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::Formatter::`vftable';
  this->pParentFmt = 0;
  this->IsConverted = 0;
  v2 = *((_BYTE *)&this->Scaleform::NumericBase + 4);
  *(_DWORD *)&this->Scaleform::NumericBase = *(_DWORD *)&this->Scaleform::NumericBase & 0xFFFFFC00 | 0x21;
  v3 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  this->ValueStr = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = v3 & 0xF0 | 1;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) = v2 & 0x80 | 0x20;
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  v4 = *((_DWORD *)this + 7) & 0xFFFFFFEA;
  *((_BYTE *)this + 32) = *((_BYTE *)this + 32) & 0xFC | 1;
  *((_DWORD *)this + 7) = v4 | 0xA;
  LODWORD(this->Value) = v;
  this->Buff[28] = 0;
  this->ValueStr = &this->Buff[28];
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::LongFormatter::`vftable'{for `Scaleform::Formatter'};
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::DoubleFormatter::`vftable'{for `Scaleform::String::InitStruct'};
  HIDWORD(this->Value) = v >> 31;
}
