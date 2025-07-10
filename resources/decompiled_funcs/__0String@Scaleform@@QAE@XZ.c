void __thiscall Scaleform::String::String(Scaleform::String *this)
{
  this->HeapTypeBits = (unsigned int)&Scaleform::String::NullData;
  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
}
