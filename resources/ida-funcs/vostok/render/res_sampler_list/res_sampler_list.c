void __thiscall vostok::render::res_sampler_list::res_sampler_list(
        vostok::render::res_sampler_list *this,
        vostok::render::res_sampler_list *slots,
        const vostok::fixed_vector<vostok::render::sampler_slot,16> *slotsa)
{
  const vostok::fixed_vector<vostok::render::sampler_slot,16> *v3; // edi
  int v4; // ecx
  int v5; // ebp
  unsigned int v6; // ebx
  vostok::render::sampler_slot *v7; // esi
  vostok::render::sampler_slot *v8; // eax
  char *m_begin; // ecx
  unsigned int v10; // edi
  int v11; // [esp+8h] [ebp-3Ch]
  int v12; // [esp+Ch] [ebp-38h]
  int v13; // [esp+10h] [ebp-34h]
  void *__x; // [esp+14h] [ebp-30h] BYREF
  vostok::fixed_string<32> v15; // [esp+18h] [ebp-2Ch] BYREF
  _UNKNOWN *retaddr; // [esp+44h] [ebp+0h] BYREF

  v3 = (const vostok::fixed_vector<vostok::render::sampler_slot,16> *)slots;
  slots->m_reference_count = 0;
  slots->m_samplers._M_impl._M_start = 0;
  slots->m_samplers._M_impl._M_finish = 0;
  slots->m_samplers._M_impl._M_end_of_storage._M_data = 0;
  slots->m_names._M_impl._M_start = 0;
  slots->m_names._M_impl._M_finish = 0;
  slots->m_names._M_impl._M_end_of_storage._M_data = 0;
  slots->m_is_registered = 0;
  v4 = (char *)slotsa->m_end - (char *)slotsa->m_begin;
  if ( v4 / 84 )
  {
    v12 = 0;
    v5 = 0;
    v11 = 0;
    v6 = 1;
    v13 = v4 / 84;
    do
    {
      if ( slotsa->m_begin[v5].slot_id != -1 )
      {
        __x = 0;
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::resize(
          (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&v3->m_end,
          v6,
          &__x);
        v15.m_begin = v15.m_buffer;
        v15.m_end = v15.m_buffer;
        v15.m_max_end = (char *)&retaddr;
        v15.m_buffer[0] = 0;
        stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::resize(
          v6,
          (stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32> > > *)&v3->m_buffer[0].m_store[8],
          &v15);
        *(char **)((char *)&v3->m_end->name.vostok::buffer_vector<vostok::render::sampler_slot>::m_begin + v11) = (char *)slotsa->m_begin[v5].state;
        v7 = (vostok::render::sampler_slot *)(v12 + *(_DWORD *)&v3->m_buffer[0].m_store[8]);
        v8 = &slotsa->m_begin[v5];
        if ( v7 != v8 )
        {
          m_begin = v7->name.m_begin;
          v7->name.m_end = v7->name.m_begin;
          *m_begin = 0;
          v10 = v8->name.m_end - v8->name.m_begin;
          memcpy((unsigned __int8 *)v7->name.m_end, (unsigned __int8 *)v8->name.m_begin, v10);
          v7->name.m_end += v10;
          v3 = (const vostok::fixed_vector<vostok::render::sampler_slot,16> *)slots;
          *v7->name.m_end = 0;
        }
      }
      v11 += 4;
      v12 += 44;
      ++v6;
      ++v5;
      --v13;
    }
    while ( v13 );
  }
}
