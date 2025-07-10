void __thiscall vostok::sound::sound_scene::calculate_in_graph_position(
        vostok::sound::sound_scene *this,
        const vostok::math::float3 *proxy_position)
{
  vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> v3; // [esp+97h] [ebp-75h] BYREF
  vostok::resources::unmanaged_resource *m_object; // [esp+98h] [ebp-74h]
  vostok::resources::unmanaged_resource *v5; // [esp+9Ch] [ebp-70h]
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > __a; // [esp+A0h] [ebp-6Ch] BYREF
  vostok::math::float3 result; // [esp+A4h] [ebp-68h] BYREF
  float max_distance; // [esp+B0h] [ebp-5Ch] BYREF
  vostok::sound::vector<vostok::sound::search::vertex_id_type> path; // [esp+B4h] [ebp-58h] BYREF
  vostok::vectora<vostok::fixed_vector<unsigned int,32> > paths; // [esp+C0h] [ebp-4Ch] BYREF
  vostok::sound::search::search_service s; // [esp+D0h] [ebp-3Ch] BYREF

  m_object = vostok::sound::g_allocator.m_object;
  v5 = vostok::sound::g_allocator.m_object;
  __a.m_allocator = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
    &paths._M_impl,
    &__a);
  path._M_impl._M_start = 0;
  path._M_impl._M_finish = 0;
  boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>(
    &path._M_impl._M_end_of_storage,
    &v3,
    0);
  vostok::sound::search::search_service::search_service(
    &s,
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object);
  max_distance = 200.0;
  vostok::math::half3_pod::operator vostok::math::float3(&this->m_list_position.m_data.m_val, &result);
  vostok::sound::search::search_service::search(
    &s,
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
    &this->m_graph,
    &path,
    proxy_position,
    &result,
    &max_distance,
    &paths);
  vostok::sound::search::search_service::~search_service(&s);
  stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::~_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>(&path._M_impl);
  stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::~_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(&paths._M_impl);
}
