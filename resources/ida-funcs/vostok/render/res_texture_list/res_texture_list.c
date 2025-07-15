void __thiscall vostok::render::res_texture_list::res_texture_list(
        vostok::render::res_texture_list *this,
        const vostok::fixed_vector<vostok::render::texture_slot,128> *slots,
        _DWORD *a3)
{
  vostok::render::texture_slot **p_m_end; // ebx
  unsigned int i; // edi
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  vostok::render::res_texture *m_object; // ecx
  unsigned int v7; // [esp+Ch] [ebp-4h]
  int v8; // [esp+18h] [ebp+8h]

  slots->m_begin = 0;
  p_m_end = &slots->m_end;
  slots->m_end = (vostok::render::texture_slot *)&slots->m_buffer[0].m_store[4];
  slots->m_max_end = (vostok::render::texture_slot *)&slots->m_buffer[0].m_store[4];
  *(_DWORD *)slots->m_buffer[0].m_store = &slots->m_buffer[3].m_store[8];
  slots->m_buffer[3].m_store[8] = 0;
  v7 = (a3[1] - *a3) / 84;
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
    (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)v7,
    (int *)&slots->m_end);
  for ( i = 0; i < v7; ++i )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)(&(*p_m_end)->name.m_begin + i));
  if ( v7 )
  {
    v8 = 0;
    do
    {
      v5 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v8 + *a3);
      m_object = v5[19].m_object;
      if ( m_object != (vostok::render::res_texture *)-1 )
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
          v5 + 20,
          (vostok::render::res_texture *)(&(*p_m_end)->name.m_begin + (_DWORD)m_object));
      v8 += 84;
      --v7;
    }
    while ( v7 );
  }
}
