void __thiscall vostok::input::input_world::remove_handler(
        vostok::input::input_world *this,
        vostok::input::handler *handler)
{
  unsigned __int8 *M_start; // eax
  unsigned __int8 *M_finish; // edi
  int i; // ecx

  M_start = (unsigned __int8 *)this->m_handlers._M_impl._M_start;
  M_finish = (unsigned __int8 *)this->m_handlers._M_impl._M_finish;
  for ( i = (M_finish - M_start) >> 4; i > 0; --i )
  {
    if ( *(vostok::input::handler **)M_start == handler )
      goto LABEL_17;
    M_start += 4;
    if ( *(vostok::input::handler **)M_start == handler )
      goto LABEL_17;
    M_start += 4;
    if ( *(vostok::input::handler **)M_start == handler )
      goto LABEL_17;
    M_start += 4;
    if ( *(vostok::input::handler **)M_start == handler )
      goto LABEL_17;
    M_start += 4;
  }
  switch ( (M_finish - M_start) >> 2 )
  {
    case 1:
      goto LABEL_15;
    case 2:
LABEL_13:
      if ( *(vostok::input::handler **)M_start == handler )
        goto LABEL_17;
      M_start += 4;
LABEL_15:
      if ( *(vostok::input::handler **)M_start == handler )
        goto LABEL_17;
      break;
    case 3:
      if ( *(vostok::input::handler **)M_start == handler )
        goto LABEL_17;
      M_start += 4;
      goto LABEL_13;
  }
  M_start = M_finish;
LABEL_17:
  if ( M_start + 4 != M_finish )
    stlp_std::priv::__copy_trivial(M_start + 4, M_finish, M_start);
  --this->m_handlers._M_impl._M_finish;
}
