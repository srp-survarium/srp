void __thiscall survarium::options_tab::~options_tab(survarium::options_tab *this, survarium::options_tab *thisa)
{
  unsigned __int8 i; // bl
  int f; // ebp
  void ***v4; // edi
  _BYTE *v5; // esi
  void **v6; // eax
  void (__thiscall ***v7)(_DWORD, int); // eax
  void *v8; // eax
  void *v9; // esi
  vostok::sound::sound_world *v10; // ecx
  void *m_start_time_high; // esi
  survarium::options_item_base **v12; // eax

  for ( i = 0; i < thisa->m_options_count; ++i )
  {
    f = (int)survarium::g_allocator.f_.f_;
    v4 = (void ***)&thisa->m_options[i];
    if ( *v4 )
    {
      v5 = __RTCastToVoid(*v4);
      v6 = *v4;
      *v6 = &survarium::flash_function_handler::`vftable';
      v7 = (void (__thiscall ***)(_DWORD, int))v6[1];
      if ( v7 )
        (**v7)(v7, 1);
      if ( v5 )
      {
        v8 = v5;
        v9 = *(void **)(f + 20);
        *(_BYTE *)(f + 42) = 0;
        vostok_mspace_free(v9, v8);
      }
      *v4 = 0;
    }
  }
  v10 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  m_start_time_high = (void *)HIDWORD(v10->m_timer.m_start_time);
  v12 = thisa->m_options - 2;
  BYTE2(v10->m_xaudio_callback_orders.m_pop_thread_id) = 0;
  vostok_mspace_free(m_start_time_high, v12);
}
