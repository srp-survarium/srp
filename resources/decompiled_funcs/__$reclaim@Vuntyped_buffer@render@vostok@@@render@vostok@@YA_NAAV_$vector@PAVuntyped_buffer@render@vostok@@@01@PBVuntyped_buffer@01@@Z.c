char __usercall vostok::render::reclaim<vostok::render::untyped_buffer>@<al>(
        vostok::render::vector<vostok::render::res_state *> *vec@<esi>,
        const vostok::render::res_state *ptr@<edx>)
{
  void **M_start; // eax
  void **M_finish; // ecx

  M_start = vec->_M_impl._M_start;
  M_finish = vec->_M_impl._M_finish;
  if ( vec->_M_impl._M_start == M_finish )
    return 0;
  while ( *M_start != ptr )
  {
    if ( ++M_start == M_finish )
      return 0;
  }
  if ( M_start + 1 != M_finish )
    stlp_std::priv::__copy_ptrs<void * *,void * *>(M_start + 1, M_finish, M_start);
  --vec->_M_impl._M_finish;
  return 1;
}
