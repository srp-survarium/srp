void __usercall vostok::render::scene::select_model(
        vostok::render::scene *this@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > > *a2@<eax>)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > > *v3; // ebx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  const stlp_std::__false_type *v5; // [esp+0h] [ebp-Ch]

  M_finish = a2[67]._M_finish;
  v3 = a2 + 67;
  v4 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
         a2[67]._M_start,
         M_finish,
         (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this);
  if ( v4 != M_finish )
    stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::_M_erase(
      v3,
      v4,
      v5);
}
