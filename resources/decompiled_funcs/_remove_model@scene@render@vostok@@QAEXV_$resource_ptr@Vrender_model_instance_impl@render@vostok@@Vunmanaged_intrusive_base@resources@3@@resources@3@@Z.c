void __thiscall vostok::render::scene::remove_model(
        vostok::render::scene *this,
        vostok::render::scene *v,
        vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> va)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v3; // edi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  const stlp_std::__false_type *v6; // [esp+0h] [ebp-14h]
  const stlp_std::__false_type *v7; // [esp+0h] [ebp-14h]

  v3 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v->m_render_model_instances._M_impl._M_start,
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v->m_render_model_instances._M_impl._M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&va);
  v->m_models_tree->erase(v->m_models_tree, &va.m_object->m_collision_object);
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::_M_erase(
    (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > > *)&v->m_render_model_instances,
    v3,
    v6);
  M_finish = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v->m_selected_models._M_impl._M_finish;
  v5 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v->m_selected_models._M_impl._M_start,
         M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&va);
  if ( v5 != M_finish )
    stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::_M_erase(
      (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > > *)&v->m_selected_models,
      v5,
      v7);
  if ( va.m_object )
  {
    if ( !_InterlockedExchangeAdd(&va.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &va.m_object->vostok::resources::unmanaged_intrusive_base,
        va.m_object);
  }
}
