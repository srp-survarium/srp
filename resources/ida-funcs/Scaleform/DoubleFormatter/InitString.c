void __thiscall Scaleform::DoubleFormatter::InitString(
        Scaleform::DoubleFormatter *this,
        char *pbuffer,
        unsigned int size)
{
  if ( this[-1].Buff[344] )
    memcpy((int)pbuffer, (const __m128i *)this->Scaleform::String::InitStruct::__vftable, size);
}
