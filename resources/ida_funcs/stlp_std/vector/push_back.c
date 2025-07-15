void __usercall stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::push_back(
        stlp_std::vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  bool v4; // [esp+0h] [ebp-4h]

  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 == *(_DWORD *)(a2 + 8) )
  {
    stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::_M_insert_overflow(
      &this->_M_impl,
      (vostok::resources::request *)v3,
      (const vostok::resources::request *)this,
      (const stlp_std::__true_type *)1,
      1u,
      v4);
  }
  else
  {
    *(_DWORD *)v3 = this->_M_impl._M_start;
    *(_DWORD *)(v3 + 4) = this->_M_impl._M_finish;
    *(_DWORD *)(a2 + 4) += 8;
  }
}


void __userpurge stlp_std::vector<vostok::render::streaming_ready_texture,vostok::render::std_allocator<vostok::render::streaming_ready_texture>>::push_back(
        const stlp_std::__false_type *__x@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::streaming_ready_texture,vostok::render::std_allocator<vostok::render::streaming_ready_texture> > *a2@<ecx>,
        stlp_std::vector<vostok::render::streaming_ready_texture,vostok::render::std_allocator<vostok::render::streaming_ready_texture> > *this)
{
  vostok::render::streaming_ready_texture *M_finish; // esi
  unsigned int v4; // [esp+0h] [ebp-10h]
  bool v5; // [esp+4h] [ebp-Ch]

  M_finish = this->_M_impl._M_finish;
  if ( M_finish == this->_M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::render::streaming_ready_texture,vostok::render::std_allocator<vostok::render::streaming_ready_texture>>::_M_insert_overflow_aux(
      a2,
      (vostok::render::streaming_ready_texture *)this,
      M_finish,
      __x,
      v4,
      v5);
  }
  else
  {
    if ( M_finish )
      vostok::render::streaming_ready_texture::streaming_ready_texture(
        M_finish,
        (const vostok::render::streaming_ready_texture *)__x);
    ++this->_M_impl._M_finish;
  }
}
