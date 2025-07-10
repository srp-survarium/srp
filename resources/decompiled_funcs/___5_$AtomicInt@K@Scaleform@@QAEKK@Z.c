LONG __thiscall Scaleform::AtomicInt<unsigned long>::operator|=(
        Scaleform::AtomicInt<unsigned long> *this,
        unsigned int arg)
{
  volatile unsigned int Value; // edi
  LONG v4; // esi

  do
  {
    Value = this->Value;
    v4 = arg | this->Value;
  }
  while ( InterlockedCompareExchange((volatile LONG *)this, v4, this->Value) != Value );
  return v4;
}
