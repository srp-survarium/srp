void __userpurge stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int> > *this@<ecx>,
        unsigned int **a2@<edi>,
        unsigned int *__pos,
        const unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // edx
  char *v11; // esi
  int v12; // eax
  const stlp_std::__true_type *i; // ecx
  unsigned int v14; // esi
  unsigned __int8 *v15; // ebx
  int v16; // eax
  unsigned __int8 *v17; // eax
  void *v18; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v19; // [esp+0h] [ebp-Ch]
  unsigned int __xa; // [esp+14h] [ebp+8h]
  unsigned int *__new_start; // [esp+18h] [ebp+Ch]

  __xa = stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_compute_next_size(
           this,
           a2,
           (unsigned int)__formal);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<enum survarium::game_action_id *,enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::allocate(
                            __xa,
                            v19);
  v10 = (unsigned __int8 *)__pos;
  v11 = (char *)((char *)__pos - (char *)*a2);
  __new_start = (unsigned int *)v9;
  if ( __pos != *a2 )
  {
    memmove(v9, (unsigned __int8 *)*a2, (unsigned int)v11);
    v10 = (unsigned __int8 *)__pos;
    v9 = (unsigned __int8 *)&v11[v12];
  }
  for ( i = __formal; i; v9 += 4 )
  {
    *(_DWORD *)v9 = *__x;
    --i;
  }
  v14 = (char *)a2[1] - (char *)v10;
  v15 = v9;
  if ( v14 )
  {
    memmove(v9, v10, v14);
    v15 = (unsigned __int8 *)(v14 + v16);
  }
  v17 = (unsigned __int8 *)*a2;
  if ( *a2 )
  {
    v18 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v18, v17);
  }
  a2[1] = (unsigned int *)v15;
  *a2 = __new_start;
  a2[2] = &__new_start[__xa];
}
