void __thiscall vostok::render::user_render_surface_editable::load_from_chunk_data(
        vostok::render::user_render_surface_editable *this,
        vostok::memory::chunk_reader *chunk)
{
  vostok::memory::reader *v3; // ecx
  char *v4; // eax
  vostok::fixed_string<256> *v5; // ecx
  vostok::memory::chunk_reader *v6; // ecx
  const unsigned __int8 *m_pointer; // esi
  unsigned int v8; // edi
  vostok::render::untyped_buffer *v9; // eax
  vostok::memory::chunk_reader *v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // edi
  vostok::render::untyped_buffer *v13; // eax
  vostok::render::resource_manager *v14; // ecx
  vostok::render::res_declaration *declaration; // eax
  vostok::render::resource_manager *v16; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::memory::doug_lea_allocator *v18; // esi
  survarium::pure_game_effect_emitter_base *v19; // ecx
  vostok::render::material_effects_instance_cook_data *v20; // eax
  vostok::memory::doug_lea_allocator *v21; // esi
  char *v22; // eax
  vostok::memory::doug_lea_allocator *v23; // ecx
  char *v24; // esi
  bool ListenerStatus; // al
  vostok::fixed_string<260> *v26; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v27; // ecx
  vostok::variant<32> *v28; // ecx
  const vostok::render::untyped_buffer *v29; // esi
  bool v30; // zf
  vostok::render::untyped_buffer *v31; // esi
  vostok::render::resource_manager *v32; // [esp-24h] [ebp-2C0h]
  const unsigned __int8 *v33; // [esp-1Ch] [ebp-2B8h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v34; // [esp-14h] [ebp-2B0h] BYREF
  int v35; // [esp-10h] [ebp-2ACh]
  vostok::render::hw_buffer_pool *v36; // [esp-Ch] [ebp-2A8h]
  const char *v37; // [esp-8h] [ebp-2A4h]
  unsigned int v38; // [esp-4h] [ebp-2A0h]
  unsigned int v39; // [esp+4h] [ebp-298h]
  vostok::render::material_effects_instance_cook_data *v40; // [esp+8h] [ebp-294h] BYREF
  vostok::render::untyped_buffer *ib; // [esp+Ch] [ebp-290h]
  vostok::memory::reader v42[2]; // [esp+10h] [ebp-28Ch] BYREF
  unsigned int vertex_stride; // [esp+28h] [ebp-274h] BYREF
  _BYTE v44[32]; // [esp+2Ch] [ebp-270h] BYREF
  vostok::variant<32> v45; // [esp+4Ch] [ebp-250h] BYREF
  vostok::buffer_string _Src[22]; // [esp+7Ch] [ebp-220h] BYREF
  vostok::buffer_string v47[22]; // [esp+18Ch] [ebp-110h] BYREF

  *(float *)&v42[0].m_pointer = FLOAT_N10_0;
  *(float *)&v42[0].m_size = FLOAT_N10_0;
  this->m_aabbox.min.x = FLOAT_N10_0;
  *(_QWORD *)&this->m_aabbox.min.elements[1] = *(_QWORD *)&v42[0].m_pointer;
  *(float *)&v42[0].m_data = FLOAT_10_0;
  *(float *)&v42[0].m_pointer = FLOAT_10_0;
  *(float *)&v42[0].m_size = FLOAT_10_0;
  this->m_aabbox.max.x = FLOAT_10_0;
  *(_QWORD *)&this->m_aabbox.max.elements[1] = *(_QWORD *)&v42[0].m_pointer;
  v35 = 2;
  this->m_vertex_input_type = user_vertex_input_type;
  vostok::memory::chunk_reader::open_reader(
    (vostok::memory::chunk_reader *)this,
    chunk,
    &v42[0].m_data,
    (vostok::memory::chunk_reader::chunk_type *)v35,
    (unsigned int)v36);
  v4 = (char *)vostok::memory::reader::r_string(v3, v42);
  vostok::fixed_string<256>::fixed_string<256>(v5, _Src, v4);
  v42[0] = *vostok::memory::chunk_reader::open_reader(
              v6,
              chunk,
              (const unsigned __int8 **)v44,
              (vostok::memory::chunk_reader::chunk_type *)3,
              (unsigned int)v36);
  m_pointer = v42[0].m_pointer;
  v42[0].m_pointer += 4;
  v8 = *(_DWORD *)m_pointer;
  LOBYTE(v35) = 0;
  LOBYTE(v34.m_object) = 1;
  this->m_render_geometry.vertex_count = v8;
  vostok::render::resource_manager::create_buffer(
    20 * v8,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0x14,
    (vostok::render::enum_buffer_type)v42[0].m_pointer,
    0,
    (bool)v34.m_object,
    v35);
  ib = 0;
  if ( v9 )
  {
    ++v9->m_reference_count;
    ib = v9;
  }
  v42[0] = *vostok::memory::chunk_reader::open_reader(
              v10,
              chunk,
              (const unsigned __int8 **)v44,
              (vostok::memory::chunk_reader::chunk_type *)4,
              (unsigned int)v36);
  v35 = 3;
  v39 = *(_DWORD *)v42[0].m_pointer;
  v11 = v39 / 3;
  v42[0].m_pointer += 4;
  LOBYTE(v35) = 0;
  LOBYTE(v34.m_object) = 0;
  v33 = v42[0].m_pointer;
  v12 = 2 * v39;
  v32 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  this->m_render_geometry.index_count = v39;
  this->m_render_geometry.primitive_count = v11;
  vostok::render::resource_manager::create_buffer(
    v12,
    v32,
    (void *)2,
    (vostok::render::enum_buffer_type)v33,
    1,
    (bool)v34.m_object,
    v35);
  v39 = 0;
  if ( v13 )
  {
    ++v13->m_reference_count;
    v39 = (unsigned int)v13;
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  v14,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  layout_editable,
                  2u);
  vertex_stride = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    vertex_stride = (unsigned int)declaration;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               v16,
               (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
               (vostok::render::res_declaration *)vertex_stride,
               (vostok::render::untyped_buffer *)0x14,
               ib,
               (vostok::render::untyped_buffer *)v39);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_render_geometry.geom,
    geometry);
  v18 = vostok::render::g_allocator;
  this->m_vb = ib;
  v40 = (vostok::render::material_effects_instance_cook_data *)vostok::memory::new_helper<vostok::render::material_effects_instance_cook_data>::call<vostok::memory::doug_lea_allocator>(
                                                                 v18,
                                                                 (const char *const)v36,
                                                                 v37,
                                                                 v38);
  if ( v40 )
  {
    v35 = 0;
    v34.m_object = v19;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v34,
      0);
    vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
      this->m_vertex_input_type,
      v40,
      v34,
      v35,
      (vostok::render::enum_cull_mode)v36);
    v40 = v20;
  }
  else
  {
    v40 = 0;
  }
  v45.m_helper = 0;
  v45.m_type_id = 0;
  vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
    (vostok::variant<32> *)v19,
    &v45,
    &v40);
  v21 = vostok::render::g_allocator;
  v22 = type_info::raw_name(&char `RTTI Type Descriptor');
  v24 = vostok::memory::doug_lea_allocator::malloc_impl(v23, (int)v21, 0x100u, v22, (const char *const)v36, v37, v38);
  memset((int)v24, 0, 0x100u);
  strcpy_s(v24, 0x100u, _Src[0].m_begin);
  *(_DWORD *)&v44[4] = 0;
  *(_DWORD *)v44 = vostok::render::user_render_surface::material_ready;
  *(_DWORD *)&v44[8] = this;
  *(_DWORD *)&v44[12] = v40;
  *(_DWORD *)&v44[16] = v24;
  v35 = (int)v42;
  qmemcpy(v42, v44, sizeof(v42));
  ListenerStatus = Scaleform::Render::RenderEvent::GetListenerStatus(0);
  v26 = (vostok::fixed_string<260> *)v35;
  if ( ListenerStatus )
  {
    *(_DWORD *)v44 = 0;
  }
  else
  {
    qmemcpy(&v44[8], v42, 0x18u);
    v26 = 0;
    *(_DWORD *)v44 = (char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::user_render_surface,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *,char *>,boost::_bi::list4<boost::_bi::value<vostok::render::user_render_surface_editable *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *>,boost::_bi::value<char *>>>>'::`2'::stored_vtable
                   + 1;
  }
  vostok::fixed_string<260>::fixed_string<260>(v26, v47, _Src[0].m_begin);
  vostok::resources::query_resource(
    v47[0].m_begin,
    (vostok::variant<32> *)0xF,
    vostok::render::g_allocator,
    &v45,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v27,
    (int *)v44);
  vostok::variant<32>::destroy_previous_variable_if_needed(v28, (int)&v45);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&vertex_stride);
  v29 = (const vostok::render::untyped_buffer *)v39;
  if ( v39 )
  {
    v30 = (*(_DWORD *)v39)-- == 1;
    if ( v30 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v29, v36);
  }
  v31 = ib;
  if ( ib )
  {
    v30 = ib->m_reference_count-- == 1;
    if ( v30 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v31, v36);
  }
}
