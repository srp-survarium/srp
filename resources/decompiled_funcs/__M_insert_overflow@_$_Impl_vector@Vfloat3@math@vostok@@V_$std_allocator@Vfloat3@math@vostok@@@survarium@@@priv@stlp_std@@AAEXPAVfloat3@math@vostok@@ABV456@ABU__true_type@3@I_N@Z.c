void __userpurge stlp_std::priv::_Impl_vector<vostok::math::float3,survarium::std_allocator<vostok::math::float3>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::math::float3,survarium::std_allocator<vostok::math::float3> > *this@<edi>,
        vostok::math::float3 *__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *a3@<ecx>,
        const vostok::math::float3 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int size; // ebp
  unsigned __int8 *v9; // ebx
  unsigned int v10; // esi
  int v11; // eax
  vostok::math::float3 *v12; // eax
  vostok::math::float3 *M_start; // eax
  void *v14; // esi
  unsigned int v15; // [esp+0h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,survarium::std_allocator<vostok::math::float3> > *v16; // [esp+0h] [ebp-Ch]
  vostok::math::float3 *__xa; // [esp+10h] [ebp+4h]

  size = stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct>>::_M_compute_next_size(
           a3,
           v15);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,survarium::std_allocator<vostok::math::float3>>::allocate(
                            v16,
                            size);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (vostok::math::float3 *)(v10 + v11);
  }
  else
  {
    v12 = (vostok::math::float3 *)v9;
  }
  *v12 = *__x;
  __xa = v12 + 1;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    v14 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v14, M_start);
  }
  this->_M_start = (vostok::math::float3 *)v9;
  this->_M_finish = __xa;
  this->_M_end_of_storage._M_data = (vostok::math::float3 *)&v9[12 * size];
}
