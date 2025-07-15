void __thiscall Scaleform::DoubleFormatter::InitString(
        Scaleform::DoubleFormatter *this,
        char *pbuffer,
        unsigned int size)
{
  if ( this[-1].Buff[344] )
    memcpy((unsigned __int8 *)pbuffer, (unsigned __int8 *)this->Scaleform::String::InitStruct::__vftable, size);
}
