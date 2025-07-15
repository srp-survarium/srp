void __usercall vostok::buffer_vector<int>::construct(int *p@<eax>, int *value@<ecx>)
{
  if ( p )
    *p = *value;
}


void __cdecl vostok::buffer_vector<vostok::variant<32> const *>::construct(
        const vostok::variant<32> **p,
        const vostok::variant<32> *const *value)
{
  if ( p )
    *p = *value;
}


void __cdecl vostok::buffer_vector<void const *>::construct(const void **p, const void **value)
{
  const void **v2; // [esp+4h] [ebp-4h]

  v2 = (const void **)operator new(4u, p);
  if ( v2 )
    *v2 = *value;
}


void __cdecl vostok::buffer_vector<vostok::apc::callback>::construct(
        vostok::apc::callback *begin,
        vostok::apc::callback **end)
{
  vostok::apc::callback *v2; // ebx
  vostok::apc::callback *v3; // edi
  vostok::apc::callback *i; // esi

  v2 = begin;
  if ( begin != *end )
  {
    v3 = begin + 1;
    do
    {
      for ( i = v2; i != v3; ++i )
      {
        if ( i )
        {
          i->m_callback.vtable = 0;
          i->m_pending = 0;
          i->m_break_parameters = break_process_loop;
          i->m_thread_id = GetCurrentThreadId();
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 != *end );
  }
}


void __usercall vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::construct(
        vostok::render::grass_layer_desc::model_desc *begin@<edx>,
        vostok::render::grass_layer_desc::model_desc *const *end@<esi>)
{
  vostok::render::grass_layer_desc::model_desc *v2; // ecx
  char *m_buffer; // eax

  if ( begin != *end )
  {
    v2 = begin + 1;
    do
    {
      if ( begin != v2 )
      {
        m_buffer = v2[-1].name.m_buffer;
        do
        {
          if ( m_buffer != (char *)12 )
          {
            *((_DWORD *)m_buffer - 3) = m_buffer;
            *((_DWORD *)m_buffer - 2) = m_buffer;
            *((_DWORD *)m_buffer - 1) = m_buffer + 260;
            *m_buffer = 0;
            *m_buffer = 0;
          }
          m_buffer += 280;
        }
        while ( m_buffer - 12 != (char *)v2 );
      }
      ++begin;
      ++v2;
    }
    while ( begin != *end );
  }
}


void __cdecl vostok::buffer_vector<vostok::ai::planning::plan_item>::construct(
        vostok::ai::planning::plan_item *p,
        const vostok::ai::planning::plan_item *value)
{
  vostok::ai::planning::plan_item *v2; // [esp+2Ch] [ebp-4h]

  v2 = (vostok::ai::planning::plan_item *)operator new(0x1Cu, p);
  if ( v2 )
    vostok::ai::planning::plan_item::plan_item(v2, value);
}


void __cdecl vostok::buffer_vector<vostok::resources::request>::construct(
        vostok::resources::request *p,
        const vostok::resources::request *value)
{
  if ( p )
    *p = *value;
}


void __cdecl vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::construct(
        vostok::ai::statistics_item<46,16> *p,
        const vostok::ai::statistics_item<46,16> *value)
{
  vostok::ai::statistics_item<46,16> *v2; // [esp+58h] [ebp-4h]

  v2 = (vostok::ai::statistics_item<46,16> *)operator new(0x3F4u, p);
  if ( v2 )
    vostok::ai::statistics_item<46,16>::statistics_item<46,16>(v2, value);
}


void __cdecl vostok::buffer_vector<vostok::animation::mixing::animation_interval>::construct(
        vostok::animation::mixing::animation_interval *p,
        const vostok::animation::mixing::animation_interval *value)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v2; // [esp+8h] [ebp-4h]

  v2 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)operator new(0xCu, (void *)p);
  if ( v2 )
  {
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      v2,
      &value->m_animation);
    v2[1].m_object = (vostok::resources::managed_resource *)LODWORD(value->m_start_time);
    v2[2].m_object = (vostok::resources::managed_resource *)LODWORD(value->m_length);
  }
}


void __cdecl vostok::buffer_vector<vostok::resources::creation_request>::construct(
        vostok::resources::creation_request *p,
        const vostok::resources::creation_request *value)
{
  vostok::resources::creation_request *v2; // [esp+4h] [ebp-4h]

  v2 = (vostok::resources::creation_request *)operator new(0x10u, (void *)p);
  if ( v2 )
    *v2 = *value;
}


void __cdecl vostok::buffer_vector<vostok::ai::planning::object_instance>::construct(
        vostok::ai::planning::object_instance *p,
        const vostok::ai::planning::object_instance *value)
{
  char *v2; // [esp+20h] [ebp-4h]

  v2 = (char *)operator new(0x114u, p);
  if ( v2 )
  {
    *(_DWORD *)v2 = value->m_type;
    *((_DWORD *)v2 + 1) = value->m_instance;
    vostok::fixed_string<256>::fixed_string<256>((vostok::fixed_string<256> *)(v2 + 8), &value->m_caption);
  }
}


void __cdecl vostok::buffer_vector<vostok::tasks::thread_tls>::construct(
        vostok::tasks::thread_tls *begin,
        vostok::tasks::thread_tls **end)
{
  vostok::tasks::thread_tls *v2; // ecx
  vostok::tasks::thread_tls *v3; // ebx
  vostok::tasks::thread_tls *v4; // edi
  int i; // esi

  v3 = begin;
  if ( begin != *end )
  {
    v4 = begin + 1;
    do
    {
      for ( i = (int)v3; (vostok::tasks::thread_tls *)i != v4; i += 360 )
      {
        if ( i )
          vostok::tasks::thread_tls::thread_tls(v2, i);
      }
      ++v3;
      ++v4;
    }
    while ( v3 != *end );
  }
}


void __cdecl vostok::buffer_vector<vostok::variant<32>>::construct(
        vostok::variant<32> *p,
        const vostok::variant<32> *value)
{
  if ( p )
  {
    p->m_helper = 0;
    p->m_type_id = value->m_type_id;
    vostok::variant<32>::operator=(p, value);
  }
}


void __usercall vostok::buffer_vector<vostok::render::vector<vostok::render::culling::aab_rect>>::construct(
        vostok::render::vector<vostok::math::frustum> *begin@<edx>,
        vostok::render::vector<vostok::math::frustum> *const *end@<edi>)
{
  vostok::render::vector<vostok::math::frustum> *v2; // ecx
  vostok::render::vector<vostok::math::frustum> *i; // eax

  if ( begin != *end )
  {
    v2 = begin + 1;
    do
    {
      for ( i = begin; i != v2; ++i )
      {
        if ( i )
        {
          i->_M_impl._M_start = 0;
          i->_M_impl._M_finish = 0;
          i->_M_impl._M_end_of_storage._M_data = 0;
        }
      }
      ++begin;
      ++v2;
    }
    while ( begin != *end );
  }
}
