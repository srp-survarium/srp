void __thiscall vostok::render::res_buffer_list::res_buffer_list(
        vostok::render::res_buffer_list *this,
        const vostok::fixed_vector<vostok::render::buffer_slot,128> *slots,
        _DWORD *a3)
{
  vostok::render::buffer_slot **p_m_end; // ebx
  _DWORD *v4; // esi
  const vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  vostok::render::shader_buffer *m_object; // ecx
  unsigned int v7; // [esp+10h] [ebp-8h]
  unsigned int v8; // [esp+14h] [ebp-4h]
  int v9; // [esp+24h] [ebp+Ch]

  slots->m_begin = 0;
  p_m_end = &slots->m_end;
  slots->m_end = (vostok::render::buffer_slot *)&slots->m_buffer[0].m_store[4];
  slots->m_max_end = (vostok::render::buffer_slot *)&slots->m_buffer[0].m_store[4];
  v4 = a3;
  *(_DWORD *)slots->m_buffer[0].m_store = &slots->m_buffer[1].m_store[48];
  v7 = (v4[1] - *v4) / 84;
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
    (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)v7,
    (int *)&slots->m_end);
  v8 = 0;
  if ( v7 )
  {
    do
      vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&(*p_m_end)->name.m_begin
      + v8++,
        0);
    while ( v8 < v7 );
    v4 = a3;
  }
  if ( v7 )
  {
    v9 = 0;
    do
    {
      v5 = (const vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v9 + *v4);
      m_object = v5[19].m_object;
      if ( m_object != (vostok::render::shader_buffer *)-1 )
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
          v5 + 20,
          (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&(*p_m_end)->name.m_begin
        + (_DWORD)m_object);
      v9 += 84;
      --v7;
    }
    while ( v7 );
  }
}
