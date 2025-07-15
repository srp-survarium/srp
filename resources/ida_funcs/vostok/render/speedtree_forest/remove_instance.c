void __thiscall vostok::render::speedtree_forest::remove_instance(
        vostok::render::speedtree_forest *this,
        vostok::render::speedtree_forest *st_instance_ptr,
        vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> st_instance_ptra)
{
  const struct SpeedTree::CCore *v4; // ebx
  vostok::render::speedtree_tree_base *m_object; // eax
  vostok::render::speedtree_instance_vtbl *v6; // eax
  float v7; // ecx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  float v9; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v10; // eax
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  char v12; // bl
  void (__cdecl *v13)(unsigned int *, unsigned int *, int); // eax
  const stlp_std::__false_type *v14; // [esp+0h] [ebp-6Ch]
  vostok::render *v15; // [esp+0h] [ebp-6Ch]
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *found; // [esp+14h] [ebp-58h]
  SpeedTree::CArray<SpeedTree::CInstance,1> instances_of_tree; // [esp+20h] [ebp-4Ch] BYREF
  SpeedTree::CInstance speedtree_instance; // [esp+44h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *thisa; // [esp+70h] [ebp+4h]

  v4 = 0;
  thisa = &st_instance_ptra.m_object->m_speedtree_tree_ptr;
  m_object = st_instance_ptra.m_object->m_speedtree_tree_ptr.m_object;
  if ( m_object )
    v4 = (const struct SpeedTree::CCore *)&m_object[1];
  v6 = st_instance_ptra.m_object[1].__vftable;
  *(_QWORD *)&speedtree_instance.m_vPos.x = *(_QWORD *)&v6->~vostok::resources::resource_base;
  *(_QWORD *)&speedtree_instance.m_vPos.z = *(_QWORD *)&v6->link_child_resource;
  *(_QWORD *)&speedtree_instance.m_vGeometricCenter.x = *(_QWORD *)&v6->decrease_quality;
  v7 = *(float *)&st_instance_ptr->m_forest;
  *(_QWORD *)&speedtree_instance.m_vGeometricCenter.z = *(_QWORD *)&v6->is_increasing_quality;
  *(_DWORD *)speedtree_instance.m_anRotationVector = v6[1].log_string;
  SpeedTree::CForest::DeleteInstances((SpeedTree::CForest *)LODWORD(v7), v4, &speedtree_instance, 1, 1);
  M_finish = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)st_instance_ptr->m_tree_instances._M_impl._M_finish;
  found = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
            (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)st_instance_ptr->m_tree_instances._M_impl._M_start,
            M_finish,
            (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&st_instance_ptra);
  if ( found == M_finish )
  {
    if ( vostok::core::g_log_filter_tree
      && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", error) )
    {
      v12 = 0;
    }
    else
    {
      v11 = vostok::core::g_log_callback;
      instances_of_tree.__vftable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          (const boost::detail::function::function_buffer *)&instances_of_tree.m_uiSize,
          (boost::detail::function::function_buffer *)&instances_of_tree.m_uiSize,
          destroy_functor_tag);
      if ( v11 )
      {
        instances_of_tree.m_uiSize = (unsigned int)v11;
        instances_of_tree.__vftable = (SpeedTree::CArray<SpeedTree::CInstance,1>_vtbl *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                                       + 1);
      }
      else
      {
        instances_of_tree.__vftable = 0;
      }
      v12 = 1;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&instances_of_tree,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\speedtree_forest.cpp",
        0x1DEu,
        "void __thiscall vostok::render::speedtree_forest::remove_instance(class vostok::resources::resource_ptr<class vo"
        "stok::render::speedtree_instance,class vostok::resources::unmanaged_intrusive_base>)",
        "render_pc_dx11:",
        error,
        "Cant find speedtree instance.");
    }
    if ( (v12 & 1) != 0 )
    {
      if ( instances_of_tree.__vftable )
      {
        if ( ((int)instances_of_tree.__vftable & 1) == 0 )
        {
          v13 = *(void (__cdecl **)(unsigned int *, unsigned int *, int))((int)instances_of_tree.__vftable & 0xFFFFFFFE);
          if ( v13 )
            v13(&instances_of_tree.m_uiSize, &instances_of_tree.m_uiSize, 2);
        }
      }
    }
    SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&speedtree_instance);
    if ( st_instance_ptra.m_object )
      goto LABEL_24;
  }
  else
  {
    instances_of_tree.__vftable = (SpeedTree::CArray<SpeedTree::CInstance,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CInstance,1>::`vftable';
    memset(&instances_of_tree.m_pData, 0, 13);
    SpeedTree::CForest::GetInstances(v4, &instances_of_tree);
    if ( !instances_of_tree.m_uiSize )
    {
      SpeedTree::CForest::UnregisterTree(st_instance_ptr->m_forest, v4);
      v9 = *(float *)&st_instance_ptr->m_trees._M_impl._M_finish;
      v10 = stlp_std::priv::__find<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>(
              (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)st_instance_ptr->m_trees._M_impl._M_start,
              (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)LODWORD(v9),
              (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)thisa);
      if ( v10 != (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)LODWORD(v9) )
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::_M_erase(
          (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > > *)&st_instance_ptr->m_trees,
          v10,
          v14);
    }
    stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::_M_erase(
      (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > > *)&st_instance_ptr->m_tree_instances,
      found,
      v14);
    SpeedTree::CArray<SpeedTree::CInstance,1>::~CArray<SpeedTree::CInstance,1>(&instances_of_tree);
    vostok::render::print_speedtree_errors(v15);
    SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&speedtree_instance);
    if ( st_instance_ptra.m_object )
    {
LABEL_24:
      if ( !_InterlockedExchangeAdd(&st_instance_ptra.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &st_instance_ptra.m_object->vostok::resources::unmanaged_intrusive_base,
          st_instance_ptra.m_object);
    }
  }
}
