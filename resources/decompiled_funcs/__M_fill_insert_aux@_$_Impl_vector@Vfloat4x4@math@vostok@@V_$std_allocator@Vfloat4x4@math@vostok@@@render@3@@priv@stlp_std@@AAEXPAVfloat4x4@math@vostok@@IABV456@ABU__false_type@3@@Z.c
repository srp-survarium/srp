void __thiscall stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *this,
        vostok::math::float4x4 *__pos,
        unsigned int __n,
        const vostok::math::float4x4 *__x,
        const stlp_std::__false_type *__formal)
{
  const vostok::render::leafmesh_vertex *v5; // edx
  vostok::math::float4x4 *M_finish; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  vostok::math::float4x4 *v10; // eax
  const vostok::render::leafmesh_vertex *v11; // [esp-4h] [ebp-58h]
  vostok::math::float4x4 __x_copy; // [esp+10h] [ebp-44h] BYREF

  v5 = (const vostok::render::leafmesh_vertex *)__x;
  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v8 = M_finish - __pos;
    if ( v8 <= __n )
    {
      v10 = stlp_std::priv::__uninitialized_fill_n<vostok::math::float4x4 *,unsigned int,vostok::math::float4x4>(
              M_finish,
              __n - v8,
              __x);
      this->_M_finish = v10;
      if ( M_finish != __pos )
        memcpy((unsigned __int8 *)v10, (unsigned __int8 *)__pos, (char *)M_finish - (char *)__pos);
      v11 = (const vostok::render::leafmesh_vertex *)__x;
      this->_M_finish += v8;
      stlp_std::fill<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex>(
        (vostok::render::leafmesh_vertex *)__pos,
        (vostok::render::leafmesh_vertex *)M_finish,
        v11);
    }
    else
    {
      v9 = __n << 6;
      if ( M_finish != &M_finish[-__n] )
      {
        memcpy((unsigned __int8 *)M_finish, (unsigned __int8 *)M_finish - v9, v9);
        v5 = (const vostok::render::leafmesh_vertex *)__x;
        v9 = __n << 6;
      }
      this->_M_finish = (vostok::math::float4x4 *)((char *)this->_M_finish + v9);
      if ( (char *)&M_finish[-__n] - (char *)__pos > 0 )
      {
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&M_finish[-__n] - (char *)__pos);
        v5 = (const vostok::render::leafmesh_vertex *)__x;
        v9 = __n << 6;
      }
      stlp_std::fill<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex>(
        (vostok::render::leafmesh_vertex *)__pos,
        (vostok::render::leafmesh_vertex *)((char *)__pos + v9),
        v5);
    }
  }
  else
  {
    qmemcpy((void *)&__x_copy, __x, sizeof(__x_copy));
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}
