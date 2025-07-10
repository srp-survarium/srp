void __userpurge stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>(
        stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *this@<ecx>,
        unsigned __int8 **a2@<edi>,
        const stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *__x)
{
  signed int v3; // esi
  unsigned __int8 *v4; // eax
  vostok::math::float4x4 *M_finish; // esi
  unsigned __int8 *M_start; // ebx
  unsigned int v7; // esi
  int v8; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex> > *v9; // [esp+0h] [ebp-8h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v3 >>= 6;
  a2[2] = 0;
  v4 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::allocate(
                            v3,
                            v9);
  *a2 = v4;
  a2[1] = v4;
  a2[2] = &v4[64 * v3];
  M_finish = __x->_M_finish;
  M_start = (unsigned __int8 *)__x->_M_start;
  if ( M_finish != __x->_M_start )
  {
    v7 = (char *)M_finish - (char *)M_start;
    memcpy(v4, M_start, v7);
    v4 = (unsigned __int8 *)(v7 + v8);
  }
  a2[1] = v4;
}
