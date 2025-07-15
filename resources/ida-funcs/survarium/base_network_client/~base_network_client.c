void __thiscall survarium::base_network_client::~base_network_client(survarium::base_network_client *this)
{
  vostok::resources::unmanaged_resource *v2; // ebx
  int f; // edi
  char *v4; // esi
  char *v5; // eax
  malloc_state *v6; // esi
  char *m_linear_speed_graph; // edi
  int v8; // esi
  char *m_angular_speed_graph; // edi
  int v10; // esi
  survarium::player *m_object; // eax
  survarium::player *v12; // ebp

  v2 = 0;
  f = (int)survarium::g_allocator.f_.f_;
  if ( this->m_input_handler )
  {
    v4 = __RTCastToVoid((void **)&this->m_input_handler->__vftable);
    ((void (__thiscall *)(survarium::player_input_handler *, _DWORD))this->m_input_handler->~survarium::player_input_handler)(
      this->m_input_handler,
      0);
    if ( v4 )
    {
      v5 = v4;
      v6 = *(malloc_state **)(f + 20);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(v6, v5);
    }
    this->m_input_handler = 0;
  }
  m_linear_speed_graph = (char *)this->m_linear_speed_graph;
  v8 = (int)survarium::g_allocator.f_.f_;
  if ( m_linear_speed_graph )
  {
    survarium::stats_graph::~stats_graph((survarium::stats_graph *)this, (int)m_linear_speed_graph);
    *(_BYTE *)(v8 + 42) = 0;
    vostok_mspace_free(*(malloc_state **)(v8 + 20), m_linear_speed_graph);
    this->m_linear_speed_graph = 0;
  }
  m_angular_speed_graph = (char *)this->m_angular_speed_graph;
  v10 = (int)survarium::g_allocator.f_.f_;
  if ( m_angular_speed_graph )
  {
    survarium::stats_graph::~stats_graph((survarium::stats_graph *)this, (int)m_angular_speed_graph);
    *(_BYTE *)(v10 + 42) = 0;
    vostok_mspace_free(*(malloc_state **)(v10 + 20), m_angular_speed_graph);
    this->m_angular_speed_graph = 0;
  }
  m_object = this->m_current_player.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
  {
    v12 = this->m_current_player.m_object;
    if ( v12 )
      v2 = &v12->vostok::resources::unmanaged_resource;
    vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v2);
  }
}
