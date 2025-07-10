void __userpurge stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __pos,
        const vostok::math::float3 *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  vostok::math::float3 *v7; // ebx
  unsigned int size; // ebp
  int *p_pos; // eax
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3 *v14; // ebx
  unsigned int v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+Ch] [ebp-4h] BYREF

  v7 = (vostok::math::float3 *)__pos;
  size = stlp_std::priv::_Impl_vector<vostok::render::effect_manager::effect_holder_struct,vostok::render::std_allocator<vostok::render::effect_manager::effect_holder_struct>>::_M_compute_next_size(
           this,
           v15);
  v16 = size;
  __pos = 1;
  p_pos = &__pos;
  if ( size )
    p_pos = (int *)&v16;
  v10 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             12 * *p_pos);
  v11 = (char *)v7 - (char *)*a2;
  if ( v11 )
  {
    memmove(v10, *a2, v11);
    v13 = (vostok::math::float3 *)(v11 + v12);
  }
  else
  {
    v13 = (vostok::math::float3 *)v10;
  }
  *v13 = *__x;
  v14 = v13 + 1;
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  *a2 = v10;
  a2[1] = (unsigned __int8 *)v14;
  a2[3] = &v10[12 * size];
}
