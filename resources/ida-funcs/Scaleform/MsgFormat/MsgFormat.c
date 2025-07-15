void __thiscall Scaleform::MsgFormat::MsgFormat(Scaleform::MsgFormat *this, const Scaleform::MsgFormat::Sink *r)
{
  char *v2; // edx

  this->FirstArgNum = 0;
  this->StrSize = 0;
  this->pLocaleProvider = 0;
  this->NonPosParamNum = 0;
  this->__vftable = (Scaleform::MsgFormat_vtbl *)&Scaleform::MsgFormat::`vftable';
  this->EscapeChar = 37;
  this->UnboundFmtrInd = -1;
  this->Result = *r;
  this->Data.Size = 0;
  this->Data.DynamicArray.Data.Data = 0;
  this->Data.DynamicArray.Data.Size = 0;
  this->Data.DynamicArray.Data.Policy.Capacity = 0;
  this->MemPool.pHeap = 0;
  v2 = (char *)((((unsigned int)&this->MemPool.pHeap + 3) & 0xFFFFFFFC) + 4);
  this->MemPool.BuffSize = (char *)&this->MemPool - v2 + 516;
  this->MemPool.BuffPtr = v2;
}
