void *__cdecl stlp_std::__node_alloc::allocate(unsigned int *__n)
{
  if ( *__n <= 0x80 )
    return stlp_std::__node_alloc::_M_allocate(__n);
  else
    return operator new(*__n);
}
