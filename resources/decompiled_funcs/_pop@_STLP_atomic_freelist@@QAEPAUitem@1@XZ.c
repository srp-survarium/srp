signed __int64 __thiscall _STLP_atomic_freelist::pop(_STLP_atomic_freelist *this)
{
  signed __int64 result; // rax
  signed __int64 v2; // rtt

  result = this->_M._M_align;
  do
  {
    if ( !(_DWORD)result )
      break;
    v2 = result;
    result = _InterlockedCompareExchange64(
               &this->_M._M_align,
               __SPAIR64__(HIDWORD(result) + 1, *(_DWORD *)result),
               result);
  }
  while ( v2 != result );
  return result;
}
