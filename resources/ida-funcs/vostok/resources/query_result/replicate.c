void __userpurge vostok::resources::query_result::replicate(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_raw_managed_resource@<edi>,
        vostok::resources::query_result *thisa)
{
  vostok::resources::class_id_enum m_class_id; // edx
  vostok::resources::cook_base *cook; // eax
  vostok::resources::resources_manager *v5; // ecx
  vostok::resources::managed_resource *m_object; // eax
  vostok::resources::managed_resource *managed_resource; // eax
  vostok::resources::managed_resource *v8; // esi
  vostok::resources::resources_manager *v9; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v10; // ecx
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  char v12; // bl
  const char **v13; // eax
  vostok::vfs::vfs_iterator v14; // [esp-34h] [ebp-294h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v15; // [esp-24h] [ebp-284h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> v16; // [esp-20h] [ebp-280h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+10h] [ebp-250h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> replication_resource; // [esp+14h] [ebp-24Ch] BYREF
  int v19; // [esp+18h] [ebp-248h]
  vostok::resources::pinned_ptr_const<unsigned char> src_data; // [esp+1Ch] [ebp-244h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-238h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> dest_data; // [esp+48h] [ebp-218h] BYREF
  vostok::fixed_string<512> v23; // [esp+54h] [ebp-20Ch] BYREF

  m_class_id = thisa->m_class_id;
  v19 = 0;
  cook = vostok::resources::resources_manager::find_cook((int)this, m_class_id);
  if ( !cook || (cook->m_flags.m_flags & 8) != 0 )
  {
    object.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &object,
      &thisa->m_raw_managed_resource);
    m_object = object.m_object;
    object.m_object = 0;
    replication_resource.m_object = m_object;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
LABEL_7:
    v16.vtable = 0;
    v15.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v15,
      &replication_resource);
    vostok::vfs::vfs_iterator::vfs_iterator(&v14, &thisa->m_fat_it);
    vostok::resources::resources_manager::replicate_resource(
      v9,
      v14,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v15.m_object,
      v16);
    goto $LN279_2;
  }
  p_m_raw_managed_resource = &thisa->m_raw_managed_resource;
  managed_resource = vostok::resources::resources_manager::allocate_managed_resource(
                       v5,
                       thisa->m_raw_managed_resource.m_object->m_memory_usage_self.size,
                       raw_data_class);
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    managed_resource);
  v8 = object.m_object;
  object.m_object = 0;
  replication_resource.m_object = v8;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    &thisa->m_raw_managed_resource);
  v16.functor.vostok_pointer_size_alignment[5] = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v16.functor.data
  + 5,
    &object);
  vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
    &src_data,
    *(vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(&v16.functor.data + 20));
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  if ( v8
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    object.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &object,
      &replication_resource);
    v16.functor.vostok_pointer_size_alignment[5] = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v16.functor.data
    + 5,
      &object);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &dest_data,
      *(vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(&v16.functor.data + 20));
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
    memcpy((unsigned __int8 *)dest_data.m_data, (unsigned __int8 *)src_data.m_data, src_data.m_size);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&dest_data);
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&src_data);
    goto LABEL_7;
  }
$LN279_2:
  if ( vostok::core::g_log_filter_tree
    && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
  {
    v12 = v19;
  }
  else
  {
    v11 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v11 )
    {
      log_callback.functor.obj_ptr = v11;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v12 = 1;
    v13 = (const char **)p_m_raw_managed_resource->m_object->log_string(p_m_raw_managed_resource->m_object, &v23);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\resources_query_result_replication.cpp",
      0x3Eu,
      "void __thiscall vostok::resources::query_result::replicate(void)",
      "resources:",
      info,
      "synchronously replicated due to low memory %s",
      *v13);
  }
  if ( (v12 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v10,
      (int *)&log_callback);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&src_data);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&replication_resource);
}
