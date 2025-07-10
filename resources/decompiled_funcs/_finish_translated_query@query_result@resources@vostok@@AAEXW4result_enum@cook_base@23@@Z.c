void __usercall vostok::resources::query_result::finish_translated_query(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::cook_base::result_enum result@<eax>)
{
  char v3; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  vostok::resources::resources_manager *m_variable; // ebx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v7; // ecx
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  vostok::fixed_string<512> *v9; // eax
  int *p_log_callback; // esi
  vostok::resources::query_result *m_object; // ebp
  void (__cdecl *v12)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  unsigned int m_uid; // esi
  vostok::fixed_string<512> *v14; // eax
  bool *v15; // [esp+0h] [ebp-47Ch]
  bool is_new_resource; // [esp+16h] [ebp-466h] BYREF
  bool is_requery_result; // [esp+17h] [ebp-465h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-464h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v19; // [esp+38h] [ebp-444h] BYREF
  int v20; // [esp+5Ch] [ebp-420h]
  _BYTE v21[524]; // [esp+60h] [ebp-41Ch] BYREF
  vostok::fixed_string<512> v22; // [esp+26Ch] [ebp-210h] BYREF

  v3 = 0;
  v20 = 0;
  is_requery_result = result == result_requery;
  is_new_resource = 0;
  vostok::resources::query_result::set_deleter_object_if_needed(
    (vostok::resources::query_result *)&is_new_resource,
    (int)this);
  if ( this->m_save_generated_data )
  {
    vostok::threading::interlocked_and(&this->m_flags, 0xFFDFFFFF);
    m_variable = vostok::resources::g_resources_manager.m_variable;
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v7,
      (char *)&loc_2044D + (unsigned int)vostok::resources::g_resources_manager.m_variable + 3,
      this,
      v15);
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)m_variable));
    return;
  }
  if ( (this->m_flags & 0x8000) != 0 )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
    {
      v8 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v8 )
      {
        log_callback.functor.obj_ptr = v8;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v3 = 1;
      v9 = this->log_string(this, v21);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_query_result_cook.cpp",
        0x1D1u,
        "void __thiscall vostok::resources::query_result::finish_translated_query(enum vostok::resources::cook_base::result_enum)",
        "resources:",
        info,
        "no resource was cooked by cook: %s",
        v9->m_begin);
    }
    if ( (v3 & 1) == 0 )
      goto LABEL_32;
    p_log_callback = (int *)&log_callback;
  }
  else
  {
    if ( is_requery_result || result != result_success || !is_new_resource || this->m_class_id == unknown_data_class )
      goto LABEL_32;
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
    {
      if ( !this->m_managed_resource.m_object
        || (m_object = (vostok::resources::query_result *)this->m_managed_resource.m_object,
            !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
      {
        m_object = (vostok::resources::query_result *)this->m_unmanaged_resource.m_object;
      }
      v12 = vostok::core::g_log_callback;
      v19.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &v19.functor,
          &v19.functor,
          destroy_functor_tag);
      if ( v12 )
      {
        v19.functor.obj_ptr = v12;
        v19.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                            + 1);
      }
      else
      {
        v19.vtable = 0;
      }
      m_uid = this->m_uid;
      v3 = 2;
      v14 = vostok::resources::log_string(m_object, &v22);
      vostok::logging::append(
        &v19,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\resources_query_result_cook.cpp",
        0x1DCu,
        "void __thiscall vostok::resources::query_result::finish_translated_query(enum vostok::resources::cook_base::result_enum)",
        "resources:",
        info,
        "cooked %s [quid %d] (cook id: %d)",
        v14->m_begin,
        m_uid,
        this->m_class_id);
    }
    if ( (v3 & 2) == 0 )
      goto LABEL_32;
    p_log_callback = (int *)&v19;
  }
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v5,
    p_log_callback);
LABEL_32:
  vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this((vostok::resources::query_result *)v5);
}
