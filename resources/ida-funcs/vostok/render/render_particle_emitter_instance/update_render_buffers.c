void __thiscall vostok::render::render_particle_emitter_instance::update_render_buffers(
        vostok::render::render_particle_emitter_instance *this,
        vostok::particle::enum_particle_data_type datatype,
        bool use_subuv,
        unsigned int in_num_max_particles,
        unsigned int beamtrail_parameters_num_sheets)
{
  vostok::render::res_geometry *m_object; // eax
  bool v7; // zf
  vostok::render::res_geometry *v8; // eax
  vostok::render::res_geometry *v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  volatile int m_initialized; // edx
  vostok::uninitialized_reference<vostok::render::vertex_buffer> *v13; // ecx
  volatile __int32 *p_m_initialized; // ebx
  vostok::uninitialized_reference<vostok::render::index_buffer> *v15; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_subuv_particle_sprite_geometry; // ecx
  vostok::uninitialized_reference<vostok::render::index_buffer> *v18; // ecx
  vostok::render::res_geometry *v19; // eax
  vostok::render::res_geometry *v20; // eax
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_particle_beamtrail_geometry; // ecx
  vostok::render::res_geometry *v22; // eax
  unsigned int v23; // eax
  vostok::uninitialized_reference<vostok::render::vertex_buffer> *v24; // ecx
  unsigned int v25; // edx
  volatile int v26; // eax
  vostok::uninitialized_reference<vostok::render::index_buffer> *v27; // ecx
  vostok::render::res_geometry *v28; // eax
  vostok::render::res_geometry *v29; // eax
  unsigned int m_max_particles; // [esp-8h] [ebp-20h]
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_particle_sprite_geometry; // [esp+10h] [ebp-8h]

  m_object = this->m_particle_sprite_geometry.m_object;
  p_m_particle_sprite_geometry = &this->m_particle_sprite_geometry;
  this->m_particle_sprite_geometry.m_object = 0;
  if ( m_object )
  {
    v7 = m_object->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  v8 = this->m_subuv_particle_sprite_geometry.m_object;
  this->m_subuv_particle_sprite_geometry.m_object = 0;
  if ( v8 )
  {
    v7 = v8->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v8);
  }
  v9 = this->m_particle_beamtrail_geometry.m_object;
  this->m_particle_beamtrail_geometry.m_object = 0;
  if ( v9 )
  {
    v7 = v9->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v9);
  }
  m_max_particles = this->m_max_particles;
  this->m_num_vertices = 0;
  this->m_num_indices = 0;
  v10 = vostok::math::max(m_max_particles, in_num_max_particles);
  v11 = v10 < 0x7D0 ? v10 - 2000 + 2000 : 2000;
  this->m_max_particles = v11;
  switch ( datatype )
  {
    case particle_data_type_billboard:
      m_initialized = this->m_vertices.m_initialized;
      v13 = (vostok::uninitialized_reference<vostok::render::vertex_buffer> *)(352 * v11);
      p_m_initialized = &this->m_vertices.m_initialized;
      this->m_num_vertices = 352 * v11;
      this->m_num_indices = 528 * v11;
      if ( use_subuv )
      {
        this->m_vertex_type = particle_vertex_type_billboard_subuv;
        if ( m_initialized )
          vostok::uninitialized_reference<vostok::render::vertex_buffer>::destroy(
            v13,
            (int)this->m_vertices.m_static_memory);
        if ( this != (vostok::render::render_particle_emitter_instance *)-1024 )
          vostok::render::vertex_buffer::vertex_buffer(
            (vostok::render::vertex_buffer *)&this->m_vertices,
            this->m_num_vertices);
        _InterlockedExchange(p_m_initialized, 1);
        v15 = (vostok::uninitialized_reference<vostok::render::index_buffer> *)this->m_indices.m_initialized;
        if ( v15 )
          vostok::uninitialized_reference<vostok::render::index_buffer>::destroy(
            v15,
            (int)this->m_indices.m_static_memory);
        if ( this != (vostok::render::render_particle_emitter_instance *)-1064 )
          vostok::render::index_buffer::index_buffer(
            (vostok::render::index_buffer *)&this->m_indices,
            this->m_num_indices);
        _InterlockedExchange(&this->m_indices.m_initialized, 1);
        geometry = vostok::render::resource_manager::create_geometry(
                     (stlp_std::forward_iterator_tag *)v_subuv_particle_sprite_fvf,
                     (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                     9u,
                     0x58u,
                     this->m_vertices.m_variable->m_buffer.m_object,
                     this->m_indices.m_variable->m_buffer.m_object);
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
          (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)geometry,
          (const vostok::render::res_geometry **)&this->m_subuv_particle_sprite_geometry.m_object);
        p_m_subuv_particle_sprite_geometry = p_m_particle_sprite_geometry;
      }
      else
      {
        this->m_vertex_type = particle_vertex_type_billboard;
        if ( m_initialized )
          vostok::uninitialized_reference<vostok::render::vertex_buffer>::destroy(
            v13,
            (int)this->m_vertices.m_static_memory);
        if ( this != (vostok::render::render_particle_emitter_instance *)-1024 )
          vostok::render::vertex_buffer::vertex_buffer(
            (vostok::render::vertex_buffer *)&this->m_vertices,
            this->m_num_vertices);
        _InterlockedExchange(p_m_initialized, 1);
        v18 = (vostok::uninitialized_reference<vostok::render::index_buffer> *)this->m_indices.m_initialized;
        if ( v18 )
          vostok::uninitialized_reference<vostok::render::index_buffer>::destroy(
            v18,
            (int)this->m_indices.m_static_memory);
        if ( this != (vostok::render::render_particle_emitter_instance *)-1064 )
          vostok::render::index_buffer::index_buffer(
            (vostok::render::index_buffer *)&this->m_indices,
            this->m_num_indices);
        _InterlockedExchange(&this->m_indices.m_initialized, 1);
        v19 = vostok::render::resource_manager::create_geometry(
                (stlp_std::forward_iterator_tag *)v_particle_sprite_fvf,
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                7u,
                0x40u,
                this->m_vertices.m_variable->m_buffer.m_object,
                this->m_indices.m_variable->m_buffer.m_object);
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
          (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v19,
          (const vostok::render::res_geometry **)&p_m_particle_sprite_geometry->m_object);
        p_m_subuv_particle_sprite_geometry = &this->m_subuv_particle_sprite_geometry;
      }
      v20 = p_m_subuv_particle_sprite_geometry->m_object;
      p_m_subuv_particle_sprite_geometry->m_object = 0;
      if ( v20 )
      {
        v7 = v20->m_reference_count-- == 1;
        if ( v7 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v20);
      }
      p_m_particle_beamtrail_geometry = &this->m_particle_beamtrail_geometry;
      goto LABEL_34;
    case particle_data_type_trail:
    case particle_data_type_beam:
      this->m_vertex_type = (datatype != particle_data_type_trail) + 2;
      v23 = vostok::math::max(beamtrail_parameters_num_sheets, 1u);
      v24 = (vostok::uninitialized_reference<vostok::render::vertex_buffer> *)(v23 < 0x2710 ? v23 - 10000 + 10000 : 10000);
      v25 = (_DWORD)v24 * this->m_max_particles;
      this->m_num_indices = 528 * v25;
      v26 = this->m_vertices.m_initialized;
      this->m_num_vertices = 176 * v25;
      if ( v26 )
        vostok::uninitialized_reference<vostok::render::vertex_buffer>::destroy(
          v24,
          (int)this->m_vertices.m_static_memory);
      if ( this != (vostok::render::render_particle_emitter_instance *)-1024 )
        vostok::render::vertex_buffer::vertex_buffer(
          (vostok::render::vertex_buffer *)&this->m_vertices,
          this->m_num_vertices);
      v27 = (vostok::uninitialized_reference<vostok::render::index_buffer> *)_InterlockedExchange(
                                                                               &this->m_vertices.m_initialized,
                                                                               1);
      if ( this->m_indices.m_initialized )
        vostok::uninitialized_reference<vostok::render::index_buffer>::destroy(
          v27,
          (int)this->m_indices.m_static_memory);
      if ( this != (vostok::render::render_particle_emitter_instance *)-1064 )
        vostok::render::index_buffer::index_buffer(
          (vostok::render::index_buffer *)&this->m_indices,
          this->m_num_indices);
      _InterlockedExchange(&this->m_indices.m_initialized, 1);
      v28 = vostok::render::resource_manager::create_geometry(
              (stlp_std::forward_iterator_tag *)v_particle_beamtrail_fvf,
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              3u,
              0x24u,
              this->m_vertices.m_variable->m_buffer.m_object,
              this->m_indices.m_variable->m_buffer.m_object);
      vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v28,
        (const vostok::render::res_geometry **)&this->m_particle_beamtrail_geometry.m_object);
      v29 = p_m_particle_sprite_geometry->m_object;
      p_m_particle_sprite_geometry->m_object = 0;
      if ( v29 )
      {
        v7 = v29->m_reference_count-- == 1;
        if ( v7 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v29);
      }
      p_m_particle_beamtrail_geometry = &this->m_subuv_particle_sprite_geometry;
LABEL_34:
      v22 = p_m_particle_beamtrail_geometry->m_object;
      p_m_particle_beamtrail_geometry->m_object = 0;
      if ( v22 )
      {
        v7 = v22->m_reference_count-- == 1;
        if ( v7 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v22);
      }
      break;
    case particle_data_type_decal:
      this->m_vertex_type = particle_vertex_type_decal;
      break;
    default:
      this->m_vertex_type = particle_vertex_type_unknown;
      break;
  }
}
