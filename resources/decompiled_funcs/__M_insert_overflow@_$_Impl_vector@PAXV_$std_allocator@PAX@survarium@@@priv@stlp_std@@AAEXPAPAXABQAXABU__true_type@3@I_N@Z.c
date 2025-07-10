void __userpurge stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this@<ecx>,
        unsigned __int8 **a2@<edi>,
        void **__pos,
        void *const *__x,
        const stlp_std::__true_type *__formal,
        bool __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // edx
  char *v10; // esi
  int v11; // eax
  unsigned __int8 *v12; // eax
  const stlp_std::__true_type *i; // ecx
  unsigned __int8 *v14; // ebx
  unsigned int v15; // esi
  int v16; // eax
  unsigned __int8 *v17; // eax
  void *v18; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v19; // [esp+0h] [ebp-Ch]
  unsigned int __xa; // [esp+14h] [ebp+8h]
  void **__new_start; // [esp+18h] [ebp+Ch]

  __xa = stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int> > *)this,
           a2,
           (unsigned int)__formal);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<enum survarium::game_action_id *,enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::allocate(
                            v19,
                            __xa);
  v10 = (char *)((char *)__pos - (char *)*a2);
  __new_start = (void **)v9;
  if ( __pos == (void **)*a2 )
  {
    v12 = v9;
  }
  else
  {
    memmove(v9, *a2, (unsigned int)v10);
    v9 = (unsigned __int8 *)__new_start;
    v12 = (unsigned __int8 *)&v10[v11];
  }
  for ( i = __formal; i; v12 += 4 )
  {
    *(void **)v12 = *__x;
    --i;
  }
  v14 = v12;
  if ( !__fill_len )
  {
    v15 = a2[1] - (unsigned __int8 *)__pos;
    if ( v15 )
    {
      memmove(v12, (unsigned __int8 *)__pos, v15);
      v9 = (unsigned __int8 *)__new_start;
      v14 = (unsigned __int8 *)(v15 + v16);
    }
  }
  v17 = *a2;
  if ( *a2 )
  {
    v18 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v18, v17);
    v9 = (unsigned __int8 *)__new_start;
  }
  a2[1] = v14;
  *a2 = v9;
  a2[2] = &v9[4 * __xa];
}
