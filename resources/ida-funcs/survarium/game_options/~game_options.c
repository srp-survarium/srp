void __thiscall survarium::game_options::~game_options(survarium::game_options *this, survarium::game_options *thisa)
{
  int f; // ebp
  survarium::options_tab **m_options; // edi
  survarium::options_tab *v5; // esi
  char *v6; // eax
  malloc_state *v7; // esi
  char *M_start; // eax
  malloc_state *v9; // esi
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_movie_resource *v11; // eax
  survarium::flash_external_handler_impl *impl; // ecx
  int thisb; // [esp+14h] [ebp+4h]

  f = (int)survarium::g_allocator.f_.f_;
  thisa->vostok::input::handler::__vftable = (survarium::game_options_vtbl *)&survarium::game_options::`vftable'{for `vostok::input::handler'};
  thisa->survarium::flash_external_handler::__vftable = (survarium::flash_external_handler_vtbl *)&survarium::game_options::`vftable'{for `survarium::flash_external_handler'};
  m_options = thisa->m_options;
  thisb = 4;
  do
  {
    v5 = *m_options;
    if ( *m_options )
    {
      survarium::options_tab::~options_tab((survarium::options_tab *)this, *m_options);
      v6 = (char *)v5;
      v7 = *(malloc_state **)(f + 20);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(v7, v6);
      f = (int)survarium::g_allocator.f_.f_;
      *m_options = 0;
    }
    ++m_options;
    --thisb;
  }
  while ( thisb );
  M_start = (char *)thisa->m_conflicted_action_ids._M_impl._M_start;
  if ( M_start )
  {
    v9 = *(malloc_state **)(f + 20);
    *(_BYTE *)(f + 42) = 0;
    vostok_mspace_free(v9, M_start);
  }
  m_object = thisa->m_cursor_ui.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_cursor_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_cursor_ui.m_object);
  v11 = thisa->m_options_ui.m_object;
  if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_options_ui.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_options_ui.m_object);
  impl = thisa->impl;
  thisa->survarium::flash_external_handler::__vftable = (survarium::flash_external_handler_vtbl *)&survarium::flash_external_handler::`vftable';
  if ( impl )
    ((void (__thiscall *)(survarium::flash_external_handler_impl *, int))impl->~survarium::flash_external_handler_impl)(
      impl,
      1);
}
