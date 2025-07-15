void __thiscall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, Scaleform::MsgFormat *f, int v)
{
  char v3; // al
  char v4; // dl
  char v5; // dl

  this->pParentFmt = f;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::Formatter::`vftable';
  this->IsConverted = 0;
  v3 = *((_BYTE *)&this->Scaleform::NumericBase + 4);
  *(_DWORD *)&this->Scaleform::NumericBase = *(_DWORD *)&this->Scaleform::NumericBase & 0xFFFFFC00 | 0x21;
  v4 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  this->ValueStr = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) = v3 & 0x80 | 0x20;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = v4 & 0xF0 | 1;
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  v5 = *((_BYTE *)this + 32);
  *((_DWORD *)this + 7) = *((_DWORD *)this + 7) & 0xFFFFFFE0 | 0xA;
  *((_BYTE *)this + 32) = v5 & 0xFC | 1;
  LODWORD(this->Value) = v;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::LongFormatter::`vftable'{for `Scaleform::Formatter'};
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::DoubleFormatter::`vftable'{for `Scaleform::String::InitStruct'};
  HIDWORD(this->Value) = v >> 31;
}


void __thiscall Scaleform::LongFormatter::LongFormatter(
        Scaleform::LongFormatter *this,
        Scaleform::MsgFormat *f,
        unsigned int v)
{
  char v4; // cl
  int v5; // ecx

  this->pParentFmt = f;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::Formatter::`vftable';
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase = *(_DWORD *)&this->Scaleform::NumericBase & 0xFFFFFC00 | 0x21;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) = *((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x80 | 0x20;
  v4 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  this->ValueStr = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = v4 & 0xF0 | 1;
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  v5 = *((_DWORD *)this + 7);
  *((_BYTE *)this + 32) &= 0xFCu;
  *((_DWORD *)this + 7) = v5 & 0xFFFFFFE0 | 0xA;
  LODWORD(this->Value) = v;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::LongFormatter::`vftable'{for `Scaleform::Formatter'};
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::DoubleFormatter::`vftable'{for `Scaleform::String::InitStruct'};
  HIDWORD(this->Value) = 0;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}


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


void __thiscall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, unsigned int v)
{
  char v3; // cl
  int v4; // ecx

  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::Formatter::`vftable';
  this->pParentFmt = 0;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase = *(_DWORD *)&this->Scaleform::NumericBase & 0xFFFFFC00 | 0x21;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) = *((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x80 | 0x20;
  v3 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  this->ValueStr = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = v3 & 0xF0 | 1;
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  v4 = *((_DWORD *)this + 7);
  *((_BYTE *)this + 32) &= 0xFCu;
  *((_DWORD *)this + 7) = v4 & 0xFFFFFFE0 | 0xA;
  LODWORD(this->Value) = v;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::LongFormatter::`vftable'{for `Scaleform::Formatter'};
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::DoubleFormatter::`vftable'{for `Scaleform::String::InitStruct'};
  HIDWORD(this->Value) = 0;
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}


void __thiscall Scaleform::LongFormatter::LongFormatter(Scaleform::LongFormatter *this, __int64 v)
{
  char v3; // cl
  int v4; // ecx

  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::Formatter::`vftable';
  this->pParentFmt = 0;
  this->IsConverted = 0;
  *(_DWORD *)&this->Scaleform::NumericBase = *(_DWORD *)&this->Scaleform::NumericBase & 0xFFFFFC00 | 0x21;
  *((_BYTE *)&this->Scaleform::NumericBase + 4) = *((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x80 | 0x20;
  v3 = *((_BYTE *)&this->Scaleform::NumericBase + 6) & 0xF1;
  *((_BYTE *)&this->Scaleform::NumericBase + 5) = 0;
  this->ValueStr = 0;
  *((_BYTE *)&this->Scaleform::NumericBase + 6) = v3 | 1;
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  v4 = *((_DWORD *)this + 7);
  *((_BYTE *)this + 32) |= 3u;
  *((_DWORD *)this + 7) = v4 & 0xFFFFFFE0 | 0xA;
  this->Value = v;
  this->Scaleform::Formatter::Scaleform::FmtResource::__vftable = (Scaleform::LongFormatter_vtbl *)&Scaleform::LongFormatter::`vftable'{for `Scaleform::Formatter'};
  this->Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::DoubleFormatter::`vftable'{for `Scaleform::String::InitStruct'};
  this->ValueStr = &this->Buff[28];
  this->Buff[28] = 0;
}


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
