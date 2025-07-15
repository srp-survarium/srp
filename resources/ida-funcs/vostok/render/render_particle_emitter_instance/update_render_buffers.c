void __thiscall vostok::render::render_particle_emitter_instance::update_render_buffers(
        vostok::render::render_particle_emitter_instance *this,
        int datatype,
        bool use_subuv,
        unsigned int in_num_max_particles,
        unsigned int beamtrail_parameters_num_sheets)
{
  vostok::render::hw_buffer_pool *v6; // esi
  unsigned __int64 v7; // kr00_8
  unsigned int v8; // eax
  unsigned int v9; // esi
  int v10; // ecx
  unsigned int v11; // esi
  int v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  volatile int m_initialized; // eax
  vostok::render::vertex_buffer *p_m_vertices; // esi
  vostok::render::res_geometry *geometry; // eax
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_subuv_particle_sprite_geometry; // esi
  unsigned int v19; // ecx
  volatile __int32 *p_m_initialized; // ebx
  volatile int v21; // eax
  vostok::render::res_geometry *v22; // eax
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v23; // esi
  vostok::render::res_geometry *v24; // eax
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_particle_sprite_geometry; // [esp+14h] [ebp-4h]

  p_m_particle_sprite_geometry = &this->m_particle_sprite_geometry;
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_particle_sprite_geometry,
    0);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_subuv_particle_sprite_geometry,
    0);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_particle_beamtrail_geometry,
    0);
  v6 = 0;
  v7 = this->m_max_particles - (unsigned __int64)in_num_max_particles;
  v8 = this->m_max_particles - (v7 & HIDWORD(v7));
  this->m_num_vertices = 0;
  this->m_num_indices = 0;
  this->m_max_particles = v8;
  if ( datatype )
  {
    if ( datatype <= 1 )
    {
LABEL_18:
      this->m_vertex_type = particle_vertex_type_unknown;
      return;
    }
    if ( datatype > 3 )
    {
      if ( datatype == 4 )
      {
        this->m_vertex_type = particle_vertex_type_decal;
        return;
      }
      goto LABEL_18;
    }
    this->m_vertex_type = (datatype != 2) + 2;
    v9 = beamtrail_parameters_num_sheets
       - (beamtrail_parameters_num_sheets == 0 ? beamtrail_parameters_num_sheets - 1 : 0);
    v10 = -(v9 < 0x2710);
    v11 = v9 - 10000;
    v12 = (v11 & v10) + 10000;
    if ( this->m_beamtrail_parameters->continuous_uv )
    {
      v13 = v12 * v8;
      v14 = 168 * v13;
    }
    else
    {
      v13 = v12 * (v8 - 1);
      v14 = 336 * v13;
    }
    this->m_num_indices = 504 * v13;
    m_initialized = this->m_vertices.m_initialized;
    this->m_num_vertices = v14;
    if ( m_initialized )
    {
      vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        &this->m_vertices.m_variable->m_buffer,
        (vostok::render::hw_buffer_pool *)v11);
      this->m_vertices.m_initialized = 0;
    }
    p_m_vertices = (vostok::render::vertex_buffer *)&this->m_vertices;
    if ( this != (vostok::render::render_particle_emitter_instance *)-264 )
      vostok::render::vertex_buffer::vertex_buffer(p_m_vertices, this->m_num_vertices);
    _InterlockedExchange(&this->m_vertices.m_initialized, 1);
    if ( this->m_indices.m_initialized )
    {
      vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        &this->m_indices.m_variable->m_buffer,
        (vostok::render::hw_buffer_pool *)p_m_vertices);
      this->m_indices.m_initialized = 0;
    }
    if ( this != (vostok::render::render_particle_emitter_instance *)-304 )
      vostok::render::index_buffer::index_buffer((vostok::render::index_buffer *)&this->m_indices, this->m_num_indices);
    _InterlockedExchange(&this->m_indices.m_initialized, 1);
    geometry = vostok::render::resource_manager::create_geometry(
                 (vostok::render::resource_manager *)this->m_vertices.m_variable->m_buffer.m_object,
                 (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                 v_particle_beamtrail_fvf,
                 4u,
                 (vostok::render::untyped_buffer *)0x30,
                 this->m_vertices.m_variable->m_buffer.m_object,
                 (int)this->m_indices.m_variable->m_buffer.m_object);
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      &this->m_particle_beamtrail_geometry,
      geometry);
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      p_m_particle_sprite_geometry,
      0);
    p_m_subuv_particle_sprite_geometry = &this->m_subuv_particle_sprite_geometry;
  }
  else
  {
    v19 = 336 * v8;
    p_m_initialized = &this->m_vertices.m_initialized;
    this->m_num_indices = 504 * v8;
    v21 = this->m_vertices.m_initialized;
    this->m_num_vertices = v19;
    if ( use_subuv )
    {
      this->m_vertex_type = particle_vertex_type_billboard_subuv;
      if ( v21 )
      {
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &this->m_vertices.m_variable->m_buffer,
          0);
        this->m_vertices.m_initialized = 0;
      }
      if ( this != (vostok::render::render_particle_emitter_instance *)-264 )
      {
        v6 = (vostok::render::hw_buffer_pool *)&this->m_vertices;
        vostok::render::vertex_buffer::vertex_buffer(
          (vostok::render::vertex_buffer *)&this->m_vertices,
          this->m_num_vertices);
      }
      _InterlockedExchange(p_m_initialized, 1);
      if ( this->m_indices.m_initialized )
      {
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &this->m_indices.m_variable->m_buffer,
          v6);
        this->m_indices.m_initialized = 0;
      }
      if ( this != (vostok::render::render_particle_emitter_instance *)-304 )
        vostok::render::index_buffer::index_buffer(
          (vostok::render::index_buffer *)&this->m_indices,
          this->m_num_indices);
      _InterlockedExchange(&this->m_indices.m_initialized, 1);
      v22 = vostok::render::resource_manager::create_geometry(
              (vostok::render::resource_manager *)this->m_vertices.m_variable->m_buffer.m_object,
              (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v_subuv_particle_sprite_fvf,
              8u,
              (vostok::render::untyped_buffer *)0x54,
              this->m_vertices.m_variable->m_buffer.m_object,
              (int)this->m_indices.m_variable->m_buffer.m_object);
      vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        &this->m_subuv_particle_sprite_geometry,
        v22);
      v23 = p_m_particle_sprite_geometry;
    }
    else
    {
      this->m_vertex_type = particle_vertex_type_billboard;
      if ( v21 )
      {
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &this->m_vertices.m_variable->m_buffer,
          0);
        this->m_vertices.m_initialized = 0;
      }
      if ( this != (vostok::render::render_particle_emitter_instance *)-264 )
      {
        v6 = (vostok::render::hw_buffer_pool *)&this->m_vertices;
        vostok::render::vertex_buffer::vertex_buffer(
          (vostok::render::vertex_buffer *)&this->m_vertices,
          this->m_num_vertices);
      }
      _InterlockedExchange(p_m_initialized, 1);
      if ( this->m_indices.m_initialized )
      {
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &this->m_indices.m_variable->m_buffer,
          v6);
        this->m_indices.m_initialized = 0;
      }
      if ( this != (vostok::render::render_particle_emitter_instance *)-304 )
        vostok::render::index_buffer::index_buffer(
          (vostok::render::index_buffer *)&this->m_indices,
          this->m_num_indices);
      _InterlockedExchange(&this->m_indices.m_initialized, 1);
      v24 = vostok::render::resource_manager::create_geometry(
              (vostok::render::resource_manager *)this->m_vertices.m_variable->m_buffer.m_object,
              (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v_particle_sprite_fvf,
              6u,
              (vostok::render::untyped_buffer *)0x3C,
              this->m_vertices.m_variable->m_buffer.m_object,
              (int)this->m_indices.m_variable->m_buffer.m_object);
      vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
        p_m_particle_sprite_geometry,
        v24);
      v23 = &this->m_subuv_particle_sprite_geometry;
    }
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v23,
      0);
    p_m_subuv_particle_sprite_geometry = &this->m_particle_beamtrail_geometry;
  }
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    p_m_subuv_particle_sprite_geometry,
    0);
}
