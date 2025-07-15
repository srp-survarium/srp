void __usercall vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::clear(
        vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *this@<ecx>,
        survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **a2@<edi>)
{
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *i; // esi

  for ( i = *a2; i != a2[1]; i += 3 )
    survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(i);
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::render::geometry_batch>::clear(
        vostok::buffer_vector<vostok::render::geometry_batch> *this@<ecx>,
        int *a2@<edi>)
{
  int i; // esi

  for ( i = *a2; i != a2[1]; i += 36 )
  {
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(i + 28));
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(i + 24));
  }
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::render::requested_streamable_texture>::clear(
        vostok::buffer_vector<vostok::render::requested_streamable_texture> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // esi

  for ( i = *a2; i != a2[1]; i += 70 )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i + 68);
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::render::streamable_texture_info>::clear(
        vostok::buffer_vector<vostok::render::streamable_texture_info> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // esi

  for ( i = *a2; i != a2[1]; i += 82 )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i + 69);
  a2[1] = *a2;
}


void __userpurge vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
        vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *this@<ecx>,
        unsigned int a2@<ebx>,
        const char *a3@<edi>,
        const char *a4@<esi>,
        vostok::render::light *a5)
{
  vostok::render::light *v5; // ecx
  char **m_reference_count; // ebx
  char *v7; // eax
  char *v9; // edi
  vostok::memory::doug_lea_allocator *v10; // esi
  vostok::memory::doug_lea_allocator *v11; // ecx
  const char *v12; // [esp-10h] [ebp-10h]
  const char *v13; // [esp-Ch] [ebp-Ch]
  unsigned int v14; // [esp-8h] [ebp-8h]

  v5 = a5;
  v14 = a2;
  m_reference_count = (char **)a5->m_reference_count;
  v13 = a4;
  v12 = a3;
  while ( m_reference_count != (char **)LODWORD(v5->m_view_to_light[0].i.x) )
  {
    v7 = *m_reference_count;
    if ( *m_reference_count )
    {
      if ( (*(_DWORD *)v7)-- == 1 )
      {
        v9 = *m_reference_count;
        v10 = vostok::render::g_allocator;
        if ( *m_reference_count )
        {
          vostok::render::light::remove_collision(v5, (int)v9);
          `vector destructor iterator'(
            v9 + 724,
            4u,
            6,
            (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
          `vector destructor iterator'(
            v9 + 700,
            4u,
            6,
            (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
          vostok::memory::doug_lea_allocator::free_impl(v11, (int)v10, v9, v12, v13, v14);
          v5 = a5;
        }
      }
    }
    ++m_reference_count;
  }
  LODWORD(v5->m_view_to_light[0].i.x) = v5->m_reference_count;
}


void __usercall vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
        vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // esi

  for ( i = *a2; i != a2[1]; ++i )
    vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i);
  a2[1] = *a2;
}
