void __userpurge stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __pos,
        const unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int *v7; // ebx
  unsigned int size; // ebp
  int *p_pos; // eax
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // ebx
  unsigned int v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+Ch] [ebp-4h] BYREF

  v7 = (unsigned int *)__pos;
  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)this,
           v15);
  v16 = size;
  __pos = 1;
  p_pos = &__pos;
  if ( size )
    p_pos = (int *)&v16;
  v10 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             4 * *p_pos);
  v11 = (char *)v7 - (char *)*a2;
  if ( v11 )
  {
    memmove(v10, *a2, v11);
    v13 = (unsigned __int8 *)(v11 + v12);
  }
  else
  {
    v13 = v10;
  }
  *(_DWORD *)v13 = *__x;
  v14 = v13 + 4;
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  *a2 = v10;
  a2[1] = v14;
  a2[3] = &v10[4 * size];
}
