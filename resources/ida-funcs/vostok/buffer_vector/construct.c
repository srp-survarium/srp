void __usercall vostok::buffer_vector<vostok::apc::callback>::construct(
        vostok::apc::callback *begin@<eax>,
        vostok::apc::callback **end)
{
  vostok::apc::callback *v2; // edi
  vostok::apc::callback *v3; // ebx
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


void __cdecl vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::construct(
        survarium::particle_game_effect_presenter::effect_data *begin,
        survarium::particle_game_effect_presenter::effect_data **end)
{
  survarium::particle_game_effect_presenter::effect_data *v2; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v3; // ebx
  survarium::particle_game_effect_presenter::effect_data *v4; // [esp+Ch] [ebp-4h]

  v2 = begin;
  if ( begin != *end )
  {
    v4 = begin + 1;
    do
    {
      v3 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v2;
      if ( v2 != v4 )
      {
        do
        {
          if ( v3 )
          {
            v3->m_object = 0;
            vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
              v3 + 1,
              0);
            v2 = begin;
            v3[3].m_object = 0;
          }
          v3 += 4;
        }
        while ( v3 != (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)v4 );
      }
      ++v4;
      begin = ++v2;
    }
    while ( v2 != *end );
  }
}


void __cdecl vostok::buffer_vector<vostok::render::effect_manager::effect_holder_struct>::construct(
        vostok::render::effect_manager::effect_holder_struct *p,
        const vostok::render::effect_manager::effect_holder_struct *value)
{
  if ( p )
  {
    p->descriptor = value->descriptor;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&p->config,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value->config);
    p->parameters = value->parameters;
    p->effect = value->effect;
    p->stage_index = value->stage_index;
  }
}


void __cdecl vostok::buffer_vector<vostok::render::grass_template>::construct(
        vostok::render::grass_template *p,
        const vostok::render::grass_template *value)
{
  if ( p )
  {
    p->m_instances.m_size = 0;
    p->m_instances.m_first = 0;
    p->m_instances.m_last = 0;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&p->m_render_model,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value->m_render_model);
    p->m_sizes = value->m_sizes;
    p->m_index = value->m_index;
  }
}


void __usercall vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::construct(
        vostok::render::grass_layer_desc::model_desc *begin@<edx>,
        vostok::render::grass_layer_desc::model_desc *const *end@<edi>)
{
  vostok::render::grass_layer_desc::model_desc *v2; // esi
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


void __cdecl vostok::buffer_vector<vostok::render::requested_streamable_texture>::construct(
        vostok::render::requested_streamable_texture *p,
        const vostok::render::requested_streamable_texture *value)
{
  if ( p )
  {
    vostok::fixed_string<260>::fixed_string<260>(&p->path, &value->path);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &p->texture,
      &value->texture);
    p->num_mips = value->num_mips;
  }
}


void __usercall vostok::buffer_vector<vostok::render::effect_compiler::texture_query_desc>::construct(
        vostok::render::effect_compiler::texture_query_desc *p@<edi>,
        const vostok::render::effect_compiler::texture_query_desc *value)
{
  if ( p )
  {
    vostok::fixed_string<260>::fixed_string<260>(&p->m_query_physicaly_path, &value->m_query_physicaly_path);
    vostok::fixed_string<260>::fixed_string<260>(&p->m_query_short_path, &value->m_query_short_path);
    p->m_mip_level_cut = value->m_mip_level_cut;
    p->m_num_last_mips_used = value->m_num_last_mips_used;
  }
}


void __usercall vostok::buffer_vector<vostok::render::ui::vertex>::construct(
        vostok::render::ui::vertex *p@<eax>,
        const vostok::render::ui::vertex *value@<ecx>)
{
  if ( p )
    *p = *value;
}


void __usercall vostok::buffer_vector<vostok::collision::bone_collision_data>::construct(
        vostok::collision::bone_collision_data *p@<edi>,
        const vostok::collision::bone_collision_data *value)
{
  if ( p )
  {
    vostok::fixed_string<64>::fixed_string<64>(&p->bone_name, &value->bone_name);
    vostok::fixed_string<16>::fixed_string<16>(&p->body_part_name, &value->body_part_name);
    p->skeleton_bone_index = value->skeleton_bone_index;
  }
}


void __usercall vostok::buffer_vector<vostok::render::buffer_slot>::construct(
        vostok::render::buffer_slot *begin@<ecx>,
        vostok::render::buffer_slot *const *end@<esi>)
{
  vostok::render::buffer_slot *v2; // edx
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
            *((_DWORD *)m_buffer - 1) = m_buffer + 64;
            *m_buffer = 0;
            *((_DWORD *)m_buffer + 16) = -1;
            *m_buffer = 0;
            *((_DWORD *)m_buffer + 17) = 0;
          }
          m_buffer += 84;
        }
        while ( m_buffer - 12 != (char *)v2 );
      }
      ++begin;
      ++v2;
    }
    while ( begin != *end );
  }
}


void __usercall vostok::buffer_vector<vostok::render::sampler_slot>::construct(
        vostok::render::sampler_slot *begin@<ecx>,
        vostok::render::sampler_slot *const *end@<esi>)
{
  vostok::render::sampler_slot *v2; // edx
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
            *((_DWORD *)m_buffer - 1) = m_buffer + 64;
            *m_buffer = 0;
            *((_DWORD *)m_buffer + 16) = -1;
            *((_DWORD *)m_buffer + 17) = 0;
            *m_buffer = 0;
          }
          m_buffer += 84;
        }
        while ( m_buffer - 12 != (char *)v2 );
      }
      ++begin;
      ++v2;
    }
    while ( begin != *end );
  }
}


void __usercall vostok::buffer_vector<vostok::render::texture_slot>::construct(
        vostok::render::texture_slot *begin@<ecx>,
        vostok::render::texture_slot *const *end@<esi>)
{
  vostok::render::texture_slot *v2; // edx
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
            *((_DWORD *)m_buffer - 1) = m_buffer + 64;
            *m_buffer = 0;
            *((_DWORD *)m_buffer + 16) = -1;
            *m_buffer = 0;
            *((_DWORD *)m_buffer + 17) = 0;
          }
          m_buffer += 84;
        }
        while ( m_buffer - 12 != (char *)v2 );
      }
      ++begin;
      ++v2;
    }
    while ( begin != *end );
  }
}


void __cdecl vostok::buffer_vector<vostok::tasks::thread_tls>::construct(
        vostok::tasks::thread_tls *begin,
        vostok::tasks::thread_tls **end)
{
  vostok::tasks::thread_tls *v2; // ecx
  vostok::tasks::thread_tls *v3; // ebx
  int i; // edi
  vostok::tasks::thread_tls *v5; // [esp+Ch] [ebp+8h]

  v3 = begin;
  if ( begin != *end )
  {
    v5 = begin + 1;
    do
    {
      for ( i = (int)v3; (vostok::tasks::thread_tls *)i != v5; i += 360 )
      {
        if ( i )
          vostok::tasks::thread_tls::thread_tls(v2, i);
      }
      ++v5;
      ++v3;
    }
    while ( v3 != *end );
  }
}


void __usercall vostok::buffer_vector<vostok::fixed_vector<vostok::math::frustum,1024>>::construct(
        vostok::fixed_vector<vostok::math::frustum,1024> *begin@<edx>,
        vostok::fixed_vector<vostok::math::frustum,1024> *const *end@<edi>)
{
  vostok::fixed_vector<vostok::math::frustum,1024> *v2; // esi
  vostok::fixed_vector<vostok::math::frustum,1024>::allign_helper *m_buffer; // eax

  if ( begin != *end )
  {
    v2 = (vostok::fixed_vector<vostok::math::frustum,1024> *)((char *)begin + (_DWORD)&loc_1E00A + 2);
    do
    {
      if ( begin != v2 )
      {
        m_buffer = v2[-1].m_buffer;
        do
        {
          if ( m_buffer != (vostok::fixed_vector<vostok::math::frustum,1024>::allign_helper *)12 )
          {
            *(_DWORD *)&m_buffer[-1].m_store[108] = m_buffer;
            *(_DWORD *)&m_buffer[-1].m_store[112] = m_buffer;
            *(_DWORD *)&m_buffer[-1].m_store[116] = (char *)&loc_1E000 + (_DWORD)m_buffer;
          }
          m_buffer = (vostok::fixed_vector<vostok::math::frustum,1024>::allign_helper *)((char *)m_buffer
                                                                                       + (_DWORD)&loc_1E00A
                                                                                       + 2);
        }
        while ( &m_buffer[-1].m_store[108] != (char *)v2 );
      }
      begin = (vostok::fixed_vector<vostok::math::frustum,1024> *)((char *)begin + (_DWORD)&loc_1E00A + 2);
      v2 = (vostok::fixed_vector<vostok::math::frustum,1024> *)((char *)v2 + (_DWORD)&loc_1E00A + 2);
    }
    while ( begin != *end );
  }
}
