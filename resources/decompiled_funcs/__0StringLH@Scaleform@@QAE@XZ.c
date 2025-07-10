void __thiscall Scaleform::StringLH::StringLH(Scaleform::StringLH *this)
{
  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
  this->HeapTypeBits = (unsigned int)&Scaleform::String::NullData.Size + 1;
}
