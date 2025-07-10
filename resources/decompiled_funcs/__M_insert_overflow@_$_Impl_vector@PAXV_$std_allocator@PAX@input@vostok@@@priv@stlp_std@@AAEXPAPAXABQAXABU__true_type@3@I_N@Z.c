void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *this@<ecx>,
        unsigned __int8 **a2@<edi>,
        void **__pos,
        void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v7; // ebx
  char *v8; // esi
  int v9; // eax
  void **v10; // eax
  unsigned __int8 *v11; // ebp
  unsigned int v12; // esi
  int v13; // eax
  unsigned __int8 *v14; // eax
  void *m_arena; // esi
  stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::input::std_allocator<void *> > *v16; // [esp+0h] [ebp-10h]
  unsigned int size; // [esp+Ch] [ebp-4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)this,
           a2);
  v7 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::input::std_allocator<void *>>::allocate(
                            v16,
                            size);
  v8 = (char *)((char *)__pos - (char *)*a2);
  if ( __pos == (void **)*a2 )
  {
    v10 = (void **)v7;
  }
  else
  {
    memmove(v7, *a2, (char *)__pos - (char *)*a2);
    v10 = (void **)&v8[v9];
  }
  *v10 = *__x;
  v11 = (unsigned __int8 *)(v10 + 1);
  v12 = a2[1] - (unsigned __int8 *)__pos;
  if ( v12 )
  {
    memmove(v11, (unsigned __int8 *)__pos, v12);
    v11 = (unsigned __int8 *)(v12 + v13);
  }
  v14 = *a2;
  if ( *a2 )
  {
    m_arena = vostok::input::g_allocator->m_arena;
    vostok::input::g_allocator->m_out_of_memory = 0;
    vostok_mspace_free(m_arena, v14);
  }
  a2[1] = v11;
  *a2 = v7;
  a2[2] = &v7[4 * size];
}
