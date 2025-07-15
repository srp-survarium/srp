void __thiscall survarium::options_resolution_selector::fill_resolutions(
        survarium::options_resolution_selector *this,
        survarium::options_resolution_selector *monitor_number,
        unsigned __int8 monitor_numbera)
{
  const char **m_values; // eax
  vostok::fixed_string<32> *v4; // ecx
  char *m_buffer; // eax
  vostok::sound::sound_world *v6; // ecx
  void *m_start_time_high; // esi
  const char **v8; // eax
  unsigned __int8 v9; // bl
  vostok::math::int2 *v10; // esi
  int x; // edx
  unsigned int v12; // edi
  vostok::memory::doug_lea_allocator *v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // edx
  _DWORD *i; // ecx
  survarium::options_resolution_selector *v18; // ecx
  unsigned int v19; // esi
  const char **v20; // ebx
  survarium::flash_value *v21; // eax
  int j; // ecx
  int m_current_value; // esi
  survarium::options_tab *m_parent_tab; // ecx
  char *v25; // esi
  int k; // ebx
  int v27; // edx
  vostok::buffer_string *v28; // [esp-10h] [ebp-B8h]
  int v29; // [esp+Ch] [ebp-9Ch]
  vostok::fixed_string<32> *m_cached_resolutions; // [esp+Ch] [ebp-9Ch]
  unsigned int old_resolution_index; // [esp+10h] [ebp-98h]
  vostok::fixed_string<32> old_resolution; // [esp+14h] [ebp-94h] BYREF
  survarium::flash_value new_resolution_data[4]; // [esp+40h] [ebp-68h] BYREF
  char v34; // [esp+A0h] [ebp-8h] BYREF

  m_values = monitor_number->m_values;
  old_resolution.m_buffer[0] = 0;
  old_resolution_index = -1;
  if ( m_values )
  {
    v4 = (vostok::fixed_string<32> *)m_values[monitor_number->m_current_value];
    if ( old_resolution.m_buffer != (char *)v4 )
    {
      m_buffer = old_resolution.m_buffer;
      old_resolution.m_end = old_resolution.m_buffer;
      old_resolution.m_buffer[0] = 0;
      if ( v4 )
      {
        for ( ; LOBYTE(v4->m_begin); ++old_resolution.m_end )
        {
          if ( m_buffer >= (char *)new_resolution_data )
            break;
          *m_buffer = (char)v4->m_begin;
          m_buffer = old_resolution.m_end + 1;
          v4 = (vostok::fixed_string<32> *)((char *)v4 + 1);
        }
        *m_buffer = 0;
      }
    }
    v6 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
    m_start_time_high = (void *)HIDWORD(v6->m_timer.m_start_time);
    v8 = monitor_number->m_values - 2;
    BYTE2(v6->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(m_start_time_high, v8);
  }
  v9 = 0;
  v10 = vostok::render::g_monitor_resolutions[monitor_numbera];
  v29 = 512;
  do
  {
    x = v10->x;
    if ( v10->y >= 720 && x >= 1280 )
    {
      v28 = &monitor_number->m_cached_resolutions[v9++];
      vostok::buffer_string::assignf(v28, "%dx%d", x, v10->y);
    }
    ++v10;
    --v29;
  }
  while ( v29 );
  v12 = v9;
  v13 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, 4 * v9 + 8);
  *v14 = v9;
  v15 = v14 + 2;
  *(v15 - 1) = 4;
  v16 = &v15[v9];
  for ( i = v15; i != v16; ++i )
  {
    if ( i )
      *i = 0;
  }
  v18 = monitor_number;
  v19 = 0;
  monitor_number->m_values = (const char **)v15;
  monitor_number->m_values_count = v9;
  if ( v9 )
  {
    v20 = (const char **)v15;
    m_cached_resolutions = monitor_number->m_cached_resolutions;
    while ( 1 )
    {
      v20[v19] = m_cached_resolutions->m_begin;
      v20 = v18->m_values;
      if ( !strcmp(old_resolution.m_buffer, v20[v19]) )
        old_resolution_index = v19;
      ++m_cached_resolutions;
      if ( ++v19 >= v12 )
        break;
      v18 = monitor_number;
    }
  }
  if ( strcmp(old_resolution.m_buffer, (const char *)&buf) )
  {
    if ( old_resolution_index == -1 )
    {
      monitor_number->m_current_value = monitor_number->m_values_count - 1;
      v21 = new_resolution_data;
      for ( j = 3; j >= 0; --j )
      {
        if ( v21 )
        {
          *(_DWORD *)v21->body = 0;
          *(_DWORD *)&v21->body[4] = 0;
        }
        ++v21;
      }
      if ( (new_resolution_data[0].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[0].body + 8))(
          *(_DWORD *)new_resolution_data[0].body,
          new_resolution_data,
          *(_DWORD *)&new_resolution_data[0].body[8]);
        *(_DWORD *)new_resolution_data[0].body = 0;
      }
      *(_DWORD *)&new_resolution_data[0].body[4] = 4;
      *(_DWORD *)&new_resolution_data[0].body[8] = 2;
      if ( (new_resolution_data[1].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[1].body + 8))(
          *(_DWORD *)new_resolution_data[1].body,
          &new_resolution_data[1],
          *(_DWORD *)&new_resolution_data[1].body[8]);
        *(_DWORD *)new_resolution_data[1].body = 0;
      }
      m_current_value = monitor_number->m_current_value;
      *(_DWORD *)&new_resolution_data[1].body[4] = 4;
      *(_DWORD *)&new_resolution_data[1].body[8] = 1;
      if ( (new_resolution_data[2].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[2].body + 8))(
          *(_DWORD *)new_resolution_data[2].body,
          &new_resolution_data[2],
          *(_DWORD *)&new_resolution_data[2].body[8]);
        *(_DWORD *)new_resolution_data[2].body = 0;
      }
      *(_DWORD *)&new_resolution_data[2].body[4] = 4;
      *(_DWORD *)&new_resolution_data[2].body[8] = m_current_value;
      if ( (new_resolution_data[3].body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)new_resolution_data[3].body + 8))(
          *(_DWORD *)new_resolution_data[3].body,
          &new_resolution_data[3],
          *(_DWORD *)&new_resolution_data[3].body[8]);
        *(_DWORD *)new_resolution_data[3].body = 0;
      }
      m_parent_tab = monitor_number->m_parent_tab;
      *(_DWORD *)&new_resolution_data[3].body[4] = 4;
      *(_DWORD *)&new_resolution_data[3].body[8] = 0;
      Scaleform::GFx::Movie::Invoke(
        m_parent_tab->m_movie->m_object->movie->m_movie,
        "root.set_value",
        0,
        (const Scaleform::GFx::Value *)new_resolution_data,
        4u);
      v25 = &v34;
      for ( k = 3; k >= 0; --k )
      {
        v27 = *((_DWORD *)v25 - 5);
        v25 -= 24;
        if ( (v27 & 0x40) != 0 )
        {
          (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v25 + 8))(v25, *((_DWORD *)v25 + 2));
          *(_DWORD *)v25 = 0;
        }
        *((_DWORD *)v25 + 1) = 0;
      }
    }
    else
    {
      monitor_number->m_current_value = old_resolution_index;
    }
  }
}
