unsigned int __fastcall vostok::memory::doug_lea_allocator::usable_size(
        vostok::memory::doug_lea_allocator *this,
        char *pointer)
{
  int v3; // eax
  int v4; // ecx

  if ( this->m_use_guards )
    return this->usable_size_impl(this, pointer);
  if ( !pointer )
    return 0;
  v3 = *((_DWORD *)pointer - 1);
  if ( (v3 & 2) == 0 )
    return 0;
  if ( (v3 & 1) != 0 || (v4 = 8, (*(pointer - 8) & 1) == 0) )
    v4 = 4;
  return (v3 & 0xFFFFFFF8) - v4;
}
