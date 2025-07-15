void __thiscall vostok::render::grass_world::grass_layer_resources_ready_from_cook(
        vostok::render::grass_world *this,
        vostok::resources::queries_result *data,
        vostok::render::grass_layer_desc *desc,
        vostok::render::grass_layer_data *layer_data,
        bool do_populate)
{
  unsigned int v5; // eax
  vostok::render::grass_layer_desc *v6; // ebx
  vostok::render::grass_world *v7; // ecx
  vostok::render::grass_render_model *m_object; // ecx
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model *v10; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v11; // [esp-4h] [ebp-44h] BYREF
  vostok::memory::chunk_reader::chunk_type *v12; // [esp+0h] [ebp-40h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+Ch] [ebp-34h] BYREF
  vostok::render::grass_world *v14; // [esp+10h] [ebp-30h]
  vostok::resources::pinned_ptr_const<unsigned char> pdata; // [esp+14h] [ebp-2Ch] BYREF
  vostok::memory::chunk_reader chunk; // [esp+20h] [ebp-20h] BYREF

  v14 = this;
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    &layer_data->layer_data_raw_file);
  v11.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v11,
    &object);
  vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
    &pdata,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v11.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  chunk.m_reader.m_size = pdata.m_size;
  chunk.m_reader.m_data = pdata.m_data;
  chunk.m_reader.m_pointer = pdata.m_data;
  memset(&chunk.m_chunks, 0, 16);
  if ( vostok::memory::chunk_reader::chunk_exists(&chunk, (unsigned int)v12) )
  {
    v5 = vostok::memory::chunk_reader::chunk_size(
           (vostok::memory::chunk_reader *)0x58,
           (const unsigned int)&object,
           v12);
    v6 = desc;
    layer_data->instances_positions = (vostok::math::float3 *)chunk.m_reader.m_pointer;
    layer_data->instances_count = v5 / 0xC;
    if ( desc->use_face_normal )
    {
      vostok::memory::chunk_reader::chunk_size((vostok::memory::chunk_reader *)0x59, (const unsigned int)&object, v12);
      layer_data->instances_normals = (vostok::math::float3 *)chunk.m_reader.m_pointer;
    }
    vostok::render::grass_world::grass_layer_resources_ready(v14, data, desc, layer_data, do_populate);
  }
  else
  {
    v6 = desc;
    v7 = v14;
    LOBYTE(v11.m_object) = do_populate;
    layer_data->instances_positions = 0;
    layer_data->instances_count = 0;
    vostok::render::grass_world::grass_layer_resources_ready(v7, data, desc, layer_data, (bool)v11.m_object);
  }
  m_object = vostok::render::g_allocator.m_object;
  if ( v6 )
  {
    v6->models_list.m_end = v6->models_list.m_begin;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
  }
  v10 = vostok::render::g_allocator.m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&layer_data->layer_data_raw_file);
  BYTE2(v10->m_children_resources.m_lock) = 0;
  vostok_mspace_free((void *)HIDWORD(v10->m_reconstruction_info_actuality_tick), layer_data);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pdata);
}
