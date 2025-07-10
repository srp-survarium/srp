void __thiscall _STLP_atomic_freelist::push(_STLP_atomic_freelist *this, _STLP_atomic_freelist::item *__item)
{
  signed __int64 M_align; // rax
  signed __int64 v3; // rtt

  M_align = this->_M._M_align;
  do
  {
    __item->_M_next = (_STLP_atomic_freelist::item *)M_align;
    v3 = M_align;
    M_align = _InterlockedCompareExchange64(
                &this->_M._M_align,
                __SPAIR64__(HIDWORD(M_align) + 1, (unsigned int)__item),
                M_align);
  }
  while ( v3 != M_align );
}
