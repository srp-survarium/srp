void __userpurge vostok::render::static_model_instance_cook::translate_query(
        vostok::render::static_model_instance_cook *this@<ecx>,
        vostok::sound::world *a2@<ebp>,
        char *a3@<edi>,
        int a4@<esi>,
        vostok::resources::query_result_for_cook *parent)
{
  char *m_requery_path; // eax
  vostok::variant<32> *m_user_data; // ecx
  vostok::configs::binary_config_value *config; // esi
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v9; // ecx
  unsigned int config_high; // esi
  void *v11; // esp
  char **v12; // edi
  void *v13; // esp
  char **v14; // eax
  int v15; // ecx
  vostok::variant<32> *v16; // ecx
  vostok::configs::binary_config_value *v17; // esi
  const vostok::configs::binary_config_value *v18; // eax
  vostok::resources::unmanaged_resource *v19; // eax
  vostok::resources::unmanaged_intrusive_base *v20; // ecx
  void (__cdecl *v21)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  char *m_begin; // [esp-14h] [ebp-1CCh] BYREF
  int v23; // [esp-10h] [ebp-1C8h]
  vostok::fs_new::path_string_impl v24; // [esp-Ch] [ebp-1C4h] BYREF
  vostok::variant<32> v25; // [esp+10Ch] [ebp-ACh] BYREF
  vostok::variant<32> v26; // [esp+13Ch] [ebp-7Ch] BYREF
  boost::function4<void,unsigned int,float,float,char const *> v27; // [esp+16Ch] [ebp-4Ch] BYREF
  vostok::sound::world *v28; // [esp+18Ch] [ebp-2Ch]
  unsigned int v29; // [esp+190h] [ebp-28h]
  char **p_m_begin; // [esp+194h] [ebp-24h]
  const vostok::variant<32> **v31; // [esp+198h] [ebp-20h]
  vostok::render::static_model_instance_user_data v32; // [esp+19Ch] [ebp-1Ch] BYREF
  vostok::render::static_model_instance_user_data model_user_data; // [esp+1A8h] [ebp-10h]
  vostok::resources::unmanaged_resource *retaddr; // [esp+1B8h] [ebp+0h]

  model_user_data.sound_world = a2;
  model_user_data.sound_scene.m_object = retaddr;
  v23 = a4;
  v28 = (vostok::sound::world *)this;
  v24.m_string.m_begin = v24.m_string.m_buffer;
  m_requery_path = parent->m_requery_path;
  m_begin = a3;
  v24.m_string.m_end = v24.m_string.m_buffer;
  v24.m_string.m_max_end = &v24.m_separator;
  v24.m_string.m_buffer[0] = 0;
  v24.m_separator = 47;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  vostok::fs_new::path_string_impl::assignf(&v24, "%s.model/render", m_requery_path);
  m_user_data = parent->m_user_data;
  HIBYTE(model_user_data.config) = 1;
  if ( m_user_data )
  {
    v32.sound_scene.m_object = 0;
    vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(m_user_data, &v32);
    config = (vostok::configs::binary_config_value *)v32.config;
    if ( vostok::configs::binary_config_value::value_exists(
           (vostok::configs::binary_config_value *)v32.config,
           "sound_environment")
      && strlen((const char *)vostok::configs::binary_config_value::operator[](config, "sound_environment")->data.pointer) )
    {
      HIBYTE(model_user_data.config) = 2;
    }
    m_object = v32.sound_scene.m_object;
    if ( v32.sound_scene.m_object )
    {
      v9 = &v32.sound_scene.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v32.sound_scene.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v9, m_object);
    }
  }
  config_high = HIBYTE(model_user_data.config);
  v29 = HIBYTE(model_user_data.config);
  v11 = alloca(8 * HIBYTE(model_user_data.config));
  v12 = &m_begin;
  m_begin = v24.m_string.m_begin;
  p_m_begin = &m_begin;
  v23 = 24;
  v13 = alloca(4 * HIBYTE(model_user_data.config));
  v14 = &m_begin;
  v31 = (const vostok::variant<32> **)&m_begin;
  if ( HIBYTE(model_user_data.config) )
  {
    v15 = HIBYTE(model_user_data.config);
    do
    {
      if ( v14 )
        *v14 = 0;
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  v16 = parent->m_user_data;
  v25.m_helper = 0;
  v25.m_type_id = 0;
  v26.m_helper = 0;
  v26.m_type_id = 0;
  if ( v16 )
  {
    v32.sound_scene.m_object = 0;
    vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(v16, &v32);
    v17 = (vostok::configs::binary_config_value *)v32.config;
    if ( vostok::configs::binary_config_value::value_exists(
           (vostok::configs::binary_config_value *)v32.config,
           "sectors") )
    {
      v18 = vostok::configs::binary_config_value::operator[](v17, "sectors");
      vostok::variant<32>::set<vostok::configs::binary_config_value>(&v25, v18);
      v12 = p_m_begin;
      v17 = (vostok::configs::binary_config_value *)v32.config;
      *v31 = &v25;
    }
    if ( vostok::configs::binary_config_value::value_exists(v17, "sound_environment")
      && strlen((const char *)vostok::configs::binary_config_value::operator[](v17, "sound_environment")->data.pointer) )
    {
      v12[2] = (char *)vostok::configs::binary_config_value::operator[](v17, "sound_environment")->data.pointer;
      v12[3] = (char *)55;
      vostok::variant<32>::set<vostok::render::static_model_instance_user_data>(&v26, &v32);
      v31[1] = &v26;
    }
    v19 = v32.sound_scene.m_object;
    if ( v32.sound_scene.m_object )
    {
      v20 = &v32.sound_scene.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v32.sound_scene.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v20, v19);
    }
    config_high = v29;
  }
  v32.sound_world = v28;
  v32.config = (const vostok::configs::binary_config_value *)vostok::render::static_model_instance_cook::on_subresources_loaded;
  v32.sound_scene.m_object = (vostok::resources::unmanaged_resource *)parent;
  if ( survarium::generate_shaders_world::is_loading() )
  {
    v27.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v27.functor.obj_ptr = *(_QWORD *)&v32.config;
    v27.functor.vostok_pointer_size_alignment[2] = v32.sound_scene.m_object;
    v27.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::static_model_instance_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::render::static_model_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  vostok::resources::query_resources(
    (const vostok::resources::request *)v12,
    config_high,
    &v27,
    (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
    v31,
    parent,
    assert_on_fail_true);
  if ( v27.vtable )
  {
    if ( ((int)v27.vtable & 1) == 0 )
    {
      v21 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v27.vtable & 0xFFFFFFFE);
      if ( v21 )
        v21(&v27.functor, &v27.functor, 2);
    }
  }
  if ( v26.m_helper )
  {
    v26.m_helper->destroy(v26.m_helper, v26.m_storage);
    v26.m_helper = 0;
  }
  if ( v25.m_helper )
    v25.m_helper->destroy(v25.m_helper, v25.m_storage);
}
