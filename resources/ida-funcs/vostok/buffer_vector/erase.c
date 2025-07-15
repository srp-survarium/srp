void __usercall vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
        vostok::buffer_vector<vostok::render::ambient_light *> *this@<ecx>,
        vostok::render::ambient_light ***begin@<edi>,
        vostok::render::ambient_light ***end@<eax>)
{
  vostok::render::ambient_light **v3; // edx
  vostok::render::ambient_light **v5; // eax

  v3 = *begin;
  v5 = *end;
  if ( *begin != v5 )
  {
    for ( ; v5 != this->m_end; ++v3 )
    {
      if ( v3 )
        *v3 = *v5;
      ++v5;
    }
    this->m_end = &this->m_begin[this->m_end - this->m_begin - (*end - *begin)];
  }
}


void __usercall vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::erase(
        vostok::buffer_vector<enum survarium::game_action_id> *this@<edx>,
        survarium::game_action_id **where@<eax>)
{
  int v2; // edi
  survarium::game_action_id *v3; // ecx
  survarium::game_action_id *v4; // esi
  survarium::game_action_id *v5; // eax

  v2 = (int)*where;
  v3 = *where + 1;
  if ( *where != v3 )
  {
    v4 = *where;
    if ( v3 != this->m_end )
    {
      v5 = *where + 1;
      do
      {
        if ( v4 )
          *v4 = *v5;
        ++v5;
        ++v4;
      }
      while ( v5 != this->m_end );
    }
    this->m_end = &this->m_begin[this->m_end - this->m_begin - (((int)v3 - v2) >> 2)];
  }
}


void __thiscall vostok::buffer_vector<survarium::animations_registry::animations_tuple>::erase(
        vostok::buffer_vector<survarium::animations_registry::animations_tuple> *this,
        survarium::animations_registry::animations_tuple *const *begin,
        survarium::animations_registry::animations_tuple **end,
        survarium::animations_registry::animations_tuple **a4)
{
  int v5; // esi
  survarium::animations_registry::animations_tuple **v6; // edi
  survarium::animations_registry::animations_tuple *v7; // ecx
  int v8; // esi
  survarium::animations_registry::animations_tuple *v9; // [esp+14h] [ebp+8h]

  v5 = (int)*a4;
  if ( *end != *a4 )
  {
    v9 = *end;
    v6 = (survarium::animations_registry::animations_tuple **)(begin + 1);
    while ( (survarium::animations_registry::animations_tuple *)v5 != *v6 )
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v9->third_view);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v9->first_view);
      if ( v9 )
        survarium::animations_registry::animations_tuple::animations_tuple(v7, v9, v5);
      ++v9;
      v5 += 12;
    }
    v8 = *v6 - *begin - (*a4 - *end);
    vostok::buffer_vector<survarium::animations_registry::animations_tuple>::destroy(&(*begin)[v8], v6);
    *v6 = &(*begin)[v8];
  }
}


void __userpurge vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::erase(
        vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *this@<ecx>,
        _DWORD *a2@<edi>,
        survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **begin,
        const survarium::hud_game_effect_presenter::effect_data **end)
{
  const survarium::hud_game_effect_presenter::effect_data *v5; // esi
  int v6; // esi
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *i; // ebx
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *v8; // [esp+14h] [ebp+Ch]

  v5 = *end;
  if ( *begin != (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)*end )
  {
    v8 = *begin;
    while ( v5 != (const survarium::hud_game_effect_presenter::effect_data *)a2[1] )
    {
      survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(v8);
      if ( v8 )
        survarium::hud_game_effect_presenter::effect_data::effect_data(
          (survarium::hud_game_effect_presenter::effect_data *)v8,
          v5);
      v8 += 3;
      ++v5;
    }
    v6 = 12 * ((a2[1] - *a2) / 12 - ((char *)*end - (char *)*begin) / 12);
    for ( i = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)(v6 + *a2);
          i != (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)a2[1];
          i += 3 )
    {
      survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(i);
    }
    a2[1] = v6 + *a2;
  }
}


void __thiscall vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::erase(
        vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> *this,
        survarium::particle_game_effect_presenter::effect_data *const *begin,
        survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **end,
        survarium::particle_game_effect_presenter::effect_data **a4)
{
  char *v5; // esi
  survarium::particle_game_effect_presenter::effect_data **v6; // edi
  survarium::particle_game_effect_presenter::effect_data *v7; // ecx
  int v8; // esi
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *v9; // [esp+14h] [ebp+8h]

  v5 = (char *)*a4;
  if ( *end != (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)*a4 )
  {
    v9 = *end;
    v6 = (survarium::particle_game_effect_presenter::effect_data **)(begin + 1);
    while ( v5 != (char *)*v6 )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v9[1]);
      survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(v9);
      if ( v9 )
        survarium::particle_game_effect_presenter::effect_data::effect_data(
          v7,
          (const survarium::particle_game_effect_presenter::effect_data *)v9,
          (int)v5);
      v9 += 4;
      v5 += 16;
    }
    v8 = *v6 - *begin - (((char *)*a4 - (char *)*end) >> 4);
    vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(&(*begin)[v8], v6);
    *v6 = &(*begin)[v8];
  }
}


void __thiscall vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::erase(
        vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> *this,
        survarium::sound_game_effect_presenter::effect_data *const *begin,
        survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **end,
        survarium::sound_game_effect_presenter::effect_data **a4)
{
  survarium::sound_game_effect_presenter::effect_data *v5; // esi
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **v6; // edi
  int v7; // esi
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *v8; // [esp+10h] [ebp+8h]

  v5 = *a4;
  if ( *end != (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)*a4 )
  {
    v8 = *end;
    v6 = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)(begin + 1);
    while ( v5 != (survarium::sound_game_effect_presenter::effect_data *)*v6 )
    {
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&v8[2]);
      survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(v8);
      if ( v8 )
        survarium::sound_game_effect_presenter::effect_data::effect_data(
          v5,
          (const survarium::sound_game_effect_presenter::effect_data *)v8);
      v8 += 3;
      ++v5;
    }
    v7 = ((char *)*v6 - (char *)*begin) / 12 - ((char *)*a4 - (char *)*end) / 12;
    vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
      (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&(*begin)[v7],
      v6);
    *v6 = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&(*begin)[v7];
  }
}


void __userpurge vostok::buffer_vector<vostok::render::effect_manager::effect_holder_struct>::erase(
        vostok::buffer_vector<vostok::render::effect_manager::effect_holder_struct> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::render::effect_manager::effect_holder_struct **where)
{
  vostok::render::effect_manager::effect_holder_struct *v3; // edi
  vostok::render::effect_manager::effect_holder_struct *v4; // ebx
  int v5; // ebx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // edi
  vostok::render::effect_manager::effect_holder_struct *value; // [esp+4h] [ebp-4h]

  v3 = *where + 1;
  if ( *where != v3 )
  {
    v4 = *where;
    value = *where + 1;
    if ( v3 != (vostok::render::effect_manager::effect_holder_struct *)a2[1] )
    {
      do
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v4->config);
        vostok::buffer_vector<vostok::render::effect_manager::effect_holder_struct>::construct(v4++, value++);
      }
      while ( value != (vostok::render::effect_manager::effect_holder_struct *)a2[1] );
    }
    v5 = 32 * (((a2[1] - *a2) >> 5) - (v3 - *where));
    for ( i = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(v5 + *a2);
          i != (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2[1];
          i += 8 )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i + 1);
    }
    a2[1] = v5 + *a2;
  }
}


void __userpurge vostok::buffer_vector<vostok::render::hw_buffer_pool_range>::erase(
        vostok::render::hw_buffer_pool_range **where@<eax>,
        vostok::buffer_vector<vostok::render::hw_buffer_pool_range> *this)
{
  vostok::render::hw_buffer_pool_range *v2; // ecx
  vostok::render::hw_buffer_pool_range *v3; // edx
  vostok::render::hw_buffer_pool_range *v4; // eax

  v2 = *where + 1;
  if ( *where != v2 )
  {
    v3 = *where;
    if ( v2 != this->m_end )
    {
      v4 = *where + 1;
      do
      {
        if ( v3 )
        {
          v3->owner = v4->owner;
          v3->begin_offset = v4->begin_offset;
          v3->end_offset = v4->end_offset;
        }
        ++v4;
        ++v3;
      }
      while ( v4 != this->m_end );
    }
    this->m_end = &this->m_begin[this->m_end - this->m_begin - 1];
  }
}


void __thiscall vostok::buffer_vector<vostok::render::light_data>::erase(
        vostok::buffer_vector<vostok::render::light_data> *this,
        vostok::render::light_data *const *begin,
        vostok::render::light_data *const *end,
        vostok::render::light_data **a4)
{
  int v4; // eax
  vostok::render::light_data *v5; // ebx
  vostok::render::light_data *const *v6; // edi
  vostok::render::light_data **v7; // esi
  const vostok::render::light *v8; // ecx
  vostok::render::light *m_object; // ecx
  int v11; // ebx
  int v12; // [esp+10h] [ebp-4h]

  v4 = (int)*end;
  v5 = *a4;
  if ( *end != *a4 )
  {
    v6 = begin;
    v7 = (vostok::render::light_data **)(begin + 1);
    while ( 1 )
    {
      v12 = v4;
      if ( v5 == *v7 )
        break;
      v8 = *(const vostok::render::light **)v4;
      if ( *(_DWORD *)v4 )
      {
        if ( v8->m_reference_count-- == 1 )
        {
          vostok::render::resource_intrusive_base::destroy<vostok::render::light>(*(const vostok::render::light *const *)v4);
          v6 = begin;
          v4 = v12;
        }
      }
      *(_DWORD *)v4 = 0;
      m_object = v5->light.m_object;
      if ( v5->light.m_object )
      {
        *(_DWORD *)v4 = m_object;
        ++m_object->m_reference_count;
      }
      *(_DWORD *)(v4 + 4) = v5->id;
      v4 += 8;
      ++v5;
    }
    v11 = *v7 - *v6 - (*a4 - *end);
    vostok::buffer_vector<vostok::render::light_data>::destroy(&(*v6)[v11], v7);
    *v7 = &(*v6)[v11];
  }
}


void __thiscall vostok::buffer_vector<vostok::render::potential_request>::erase(
        vostok::buffer_vector<vostok::render::potential_request> *this,
        vostok::render::potential_request *const *begin,
        vostok::render::potential_request **end,
        vostok::render::potential_request **a4)
{
  char *v4; // eax
  char *v5; // edx

  v4 = (char *)*a4;
  if ( *end != *a4 )
  {
    v5 = (char *)*end;
    while ( v4 != *((char **)begin + 1) )
    {
      if ( v5 )
        qmemcpy(v5, v4, 0x70u);
      v5 += 112;
      v4 += 112;
    }
    *((_DWORD *)begin + 1) = &(*begin)[(signed int)(*((_DWORD *)begin + 1) - (unsigned int)*begin) / 112 - (*a4 - *end)];
  }
}


void __thiscall vostok::buffer_vector<vostok::collision::ray_triangle_result>::erase(
        vostok::buffer_vector<vostok::collision::ray_triangle_result> *this,
        vostok::collision::ray_triangle_result *const *begin,
        vostok::collision::ray_triangle_result **end,
        vostok::collision::ray_triangle_result **a4)
{
  _DWORD *v4; // ecx
  _DWORD *v5; // eax

  v4 = *end;
  v5 = *a4;
  if ( *end != *a4 )
  {
    while ( v5 != *((_DWORD **)begin + 1) )
    {
      if ( v4 )
      {
        *v4 = *v5;
        v4[1] = v5[1];
        v4[2] = v5[2];
      }
      v4 += 3;
      v5 += 3;
    }
    *((_DWORD *)begin + 1) = &(*begin)[(signed int)(*((_DWORD *)begin + 1) - (unsigned int)*begin) / 12 - (*a4 - *end)];
  }
}


void __thiscall vostok::buffer_vector<vostok::memory::platform::region>::erase(
        vostok::buffer_vector<vostok::memory::platform::region> *this,
        vostok::memory::platform::region **where)
{
  vostok::memory::platform::region *v3; // edx
  vostok::memory::platform::region *i; // eax
  vostok::memory::platform::region *v5; // [esp+Ch] [ebp+8h]

  v3 = *where + 1;
  if ( *where != v3 )
  {
    v5 = *where;
    for ( i = v3; i != this->m_end; ++i )
    {
      if ( v5 )
      {
        LODWORD(v5->size) = i->size;
        HIDWORD(v5->size) = HIDWORD(i->size);
        v5->address = i->address;
        v5->data = i->data;
      }
      ++v5;
    }
    this->m_end = &this->m_begin[this->m_end - this->m_begin - (v3 - *where)];
  }
}


void __userpurge vostok::buffer_vector<vostok::render::requested_streamable_texture>::erase(
        vostok::buffer_vector<vostok::render::requested_streamable_texture> *this@<ecx>,
        _DWORD *a2@<edi>,
        vostok::render::requested_streamable_texture **begin,
        const vostok::render::requested_streamable_texture **end)
{
  const vostok::render::requested_streamable_texture *v4; // esi
  int v5; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  vostok::render::requested_streamable_texture *p; // [esp+Ch] [ebp-4h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // [esp+1Ch] [ebp+Ch]

  v4 = *end;
  if ( *begin != *end )
  {
    p = *begin;
    while ( v4 != (const vostok::render::requested_streamable_texture *)a2[1] )
    {
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&p->texture);
      vostok::buffer_vector<vostok::render::requested_streamable_texture>::construct(p++, v4++);
    }
    v5 = 280 * ((a2[1] - *a2) / 280 - (*end - *begin));
    v6 = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v5 + *a2);
    v8 = v6;
    if ( v6 != (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2[1] )
    {
      while ( 1 )
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(v6 + 68);
        v8 += 70;
        if ( v8 == (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2[1] )
          break;
        v6 = v8;
      }
    }
    a2[1] = v5 + *a2;
  }
}


void __usercall vostok::buffer_vector<survarium::player_shootmarks_storage::sm>::erase(
        vostok::buffer_vector<survarium::player_shootmarks_storage::sm> *this@<ecx>,
        survarium::player_shootmarks_storage::sm **where@<edi>)
{
  survarium::player_shootmarks_storage::sm *v2; // eax
  survarium::player_shootmarks_storage::sm *v3; // edx
  survarium::player_shootmarks_storage::sm *v4; // esi

  v2 = *where;
  v3 = *where + 1;
  if ( *where != v3 )
  {
    v4 = *where + 1;
    if ( v3 != this->m_end )
    {
      do
      {
        if ( v2 )
        {
          v2->bullet_id = v4->bullet_id;
          *(_DWORD *)&v2->bullet_change_trajectory_count = *(_DWORD *)&v4->bullet_change_trajectory_count;
        }
        ++v4;
        ++v2;
      }
      while ( v4 != this->m_end );
    }
    this->m_end = &this->m_begin[this->m_end - this->m_begin - (v3 - *where)];
  }
}


void __userpurge vostok::buffer_vector<vostok::render::streamable_texture_info>::erase(
        vostok::buffer_vector<vostok::render::streamable_texture_info> *this@<ecx>,
        _DWORD *a2@<edi>,
        vostok::render::streamable_texture_info **begin,
        vostok::render::streamable_texture_info **end)
{
  int v4; // esi
  vostok::render::streamable_texture_info *v5; // ecx
  int v6; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v7; // eax
  vostok::render::streamable_texture_info *__that; // [esp+Ch] [ebp-4h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // [esp+1Ch] [ebp+Ch]

  v4 = (int)*end;
  if ( *begin != *end )
  {
    __that = *begin;
    while ( v4 != a2[1] )
    {
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&__that->texture);
      if ( __that )
        vostok::render::streamable_texture_info::streamable_texture_info(v5, __that, v4);
      ++__that;
      v4 += 328;
    }
    v6 = 328 * ((a2[1] - *a2) / 328 - (*end - *begin));
    v7 = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v6 + *a2);
    v9 = v7;
    if ( v7 != (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2[1] )
    {
      while ( 1 )
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(v7 + 69);
        v9 += 82;
        if ( v9 == (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2[1] )
          break;
        v7 = v9;
      }
    }
    a2[1] = v6 + *a2;
  }
}


void __thiscall vostok::buffer_vector<vostok::render::streaming_ready_texture>::erase(
        vostok::buffer_vector<vostok::render::streaming_ready_texture> *this,
        vostok::render::streaming_ready_texture *const *begin,
        vostok::fixed_string<260> **end,
        vostok::render::streaming_ready_texture **a4)
{
  char *v4; // edi
  vostok::render::streaming_ready_texture **v5; // ebx
  vostok::fixed_string<260> *v6; // esi
  int v7; // esi
  vostok::fixed_string<260> *v8; // [esp+10h] [ebp-Ch]
  char *v9; // [esp+14h] [ebp-8h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *p_m_end; // [esp+18h] [ebp-4h]

  v4 = (char *)*a4;
  if ( *end != (vostok::fixed_string<260> *)*a4 )
  {
    v5 = (vostok::render::streaming_ready_texture **)(begin + 1);
    v6 = *end;
    v8 = *end;
    v9 = (char *)*a4;
    if ( v4 != *((char **)begin + 1) )
    {
      p_m_end = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v6[1].m_end;
      do
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(p_m_end);
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&p_m_end[-1]);
        if ( v6 )
        {
          vostok::fixed_string<260>::fixed_string<260>(v6, (const vostok::fixed_string<260> *)v4);
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&p_m_end[-1],
            (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v4
          + 68);
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
            p_m_end,
            (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v9
          + 69);
          p_m_end[1].m_object = *(vostok::resources::managed_resource **)(v9 + 280);
          p_m_end[2].m_object = *(vostok::resources::managed_resource **)(v9 + 284);
          v4 = v9;
        }
        p_m_end += 72;
        v4 += 288;
        v6 = (vostok::fixed_string<260> *)((char *)v8 + 288);
        v8 = (vostok::fixed_string<260> *)((char *)v8 + 288);
        v9 = v4;
      }
      while ( v4 != (char *)*v5 );
    }
    v7 = *v5 - *begin - ((char *)*a4 - (char *)*end) / 288;
    vostok::buffer_vector<vostok::render::streaming_ready_texture>::destroy(&(*begin)[v7], v5);
    *v5 = &(*begin)[v7];
  }
}


void __usercall vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>>::erase(
        vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *this@<edx>,
        stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> **where@<eax>)
{
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *v2; // edi
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *v3; // ecx
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *v4; // esi
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *v5; // eax

  v2 = *where;
  v3 = *where + 1;
  if ( *where != v3 )
  {
    v4 = *where;
    if ( v3 != this->m_end )
    {
      v5 = *where + 1;
      do
      {
        if ( v4 )
        {
          v4->first = v5->first;
          v4->second = v5->second;
        }
        ++v5;
        ++v4;
      }
      while ( v5 != this->m_end );
    }
    this->m_end = &this->m_begin[this->m_end - this->m_begin - (v3 - v2)];
  }
}


void __userpurge vostok::buffer_vector<vostok::fs_new::virtual_path_string>::erase(
        vostok::buffer_vector<vostok::fs_new::virtual_path_string> *this@<ecx>,
        _DWORD *a2@<edi>,
        vostok::fs_new::virtual_path_string **where)
{
  vostok::fs_new::virtual_path_string *v3; // esi
  vostok::fs_new::virtual_path_string *v4; // [esp+4h] [ebp-Ch]
  vostok::fs_new::virtual_path_string *v5; // [esp+8h] [ebp-8h]
  vostok::fs_new::virtual_path_string *v6; // [esp+Ch] [ebp-4h]

  v3 = *where + 1;
  v4 = v3;
  if ( *where != v3 )
  {
    v6 = *where;
    v5 = *where + 1;
    if ( v3 != (vostok::fs_new::virtual_path_string *)a2[1] )
    {
      do
      {
        if ( v6 )
        {
          vostok::fixed_string<260>::fixed_string<260>(&v6->m_string, &v5->m_string);
          v3 = v4;
          v6->m_separator = 47;
        }
        ++v5;
        ++v6;
      }
      while ( v5 != (vostok::fs_new::virtual_path_string *)a2[1] );
    }
    a2[1] = *a2 + 276 * ((a2[1] - *a2) / 276 - (v3 - *where));
  }
}


void __userpurge vostok::buffer_vector<vostok::fixed_string<260>>::erase(
        vostok::buffer_vector<vostok::fixed_string<260> > *this@<ecx>,
        _DWORD *a2@<edi>,
        vostok::fixed_string<260> **where)
{
  vostok::fixed_string<260> *v3; // eax
  vostok::fixed_string<260> *v4; // esi
  vostok::fixed_string<260> *v5; // [esp+0h] [ebp-8h]
  const vostok::fixed_string<260> *v6; // [esp+4h] [ebp-4h]

  v3 = *where + 1;
  v5 = v3;
  if ( *where != v3 )
  {
    v4 = *where;
    v6 = *where + 1;
    if ( v3 != (vostok::fixed_string<260> *)a2[1] )
    {
      do
      {
        if ( v4 )
        {
          vostok::fixed_string<260>::fixed_string<260>(v4, v6);
          v3 = v5;
        }
        ++v6;
        ++v4;
      }
      while ( v6 != (const vostok::fixed_string<260> *)a2[1] );
    }
    a2[1] = *a2 + 272 * ((a2[1] - *a2) / 272 - (v3 - *where));
  }
}
