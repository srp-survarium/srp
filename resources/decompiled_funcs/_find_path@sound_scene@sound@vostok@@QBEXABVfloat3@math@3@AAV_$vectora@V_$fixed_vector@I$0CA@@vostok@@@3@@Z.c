void __thiscall vostok::sound::sound_scene::find_path(
        vostok::sound::sound_scene *this,
        const vostok::math::float3 *destination_point,
        vostok::vectora<vostok::fixed_vector<unsigned int,32> > *result_paths)
{
  vostok::math::float3 result; // [esp+A0h] [ebp-5Ch] BYREF
  float max_distance; // [esp+ACh] [ebp-50h] BYREF
  char v6; // [esp+B3h] [ebp-49h]
  vostok::sound::vector<vostok::sound::search::vertex_id_type> path; // [esp+B4h] [ebp-48h] BYREF
  vostok::sound::search::search_service s; // [esp+C0h] [ebp-3Ch] BYREF

  memset(&path, 0, sizeof(path));
  vostok::sound::search::search_service::search_service(
    &s,
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object);
  v6 = 0;
  max_distance = 200.0;
  vostok::math::half3_pod::operator vostok::math::float3(&this->m_list_position.m_data.m_val, &result);
  vostok::sound::search::search_service::search(
    &s,
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
    &this->m_graph,
    &path,
    destination_point,
    &result,
    &max_distance,
    result_paths);
  vostok::sound::search::search_service::~search_service(&s);
  stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::~_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>(&path._M_impl);
}
