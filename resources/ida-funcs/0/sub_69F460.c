void sub_69F460()
{
  if ( p != &dword_8E4C1C && p )
  {
    if ( (unsigned int)(dword_8E4C1C - (_DWORD)p) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate((_STLP_atomic_freelist::item *)p, dword_8E4C1C - (_DWORD)p);
    else
      operator delete(p);
  }
}
