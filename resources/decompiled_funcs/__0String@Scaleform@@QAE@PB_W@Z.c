void __thiscall Scaleform::String::String(Scaleform::String *this, const wchar_t *data)
{
  this->HeapTypeBits = (unsigned int)&Scaleform::String::NullData;
  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
  if ( data )
    Scaleform::String::operator=(this, data);
}
