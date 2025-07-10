void __usercall vostok::resources::query_result::do_create_resource_end_part(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  char v2; // bl
  int v4; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  int v6; // ecx
  const char *v7; // edi
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  vostok::resources::query_result *v9; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v10; // ecx
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  const char *v12; // eax
  vostok::resources::query_result *v13; // edi
  bool resource_if_no_file; // al
  void (__cdecl *v15)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  int v16; // esi
  vostok::fixed_string<512> *v17; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v18; // [esp+Ch] [ebp-47Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v19; // [esp+10h] [ebp-478h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v20; // [esp+30h] [ebp-458h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+50h] [ebp-438h] BYREF
  _BYTE v22[524]; // [esp+70h] [ebp-418h] BYREF
  vostok::fixed_string<512> v23; // [esp+27Ch] [ebp-20Ch] BYREF

  v2 = 0;
  v18.m_object = 0;
  if ( *(_DWORD *)(a2 + 260) == 4 )
  {
    v18.m_object = *(vostok::resources::managed_resource **)(a2 + 632);
    *(_DWORD *)(a2 + 632) = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v18);
  }
  v4 = *(_DWORD *)(a2 + 260);
  if ( v4 != 1 )
  {
    if ( v4 == 4 )
    {
      *(_DWORD *)(a2 + 256) = 0;
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
      {
        v6 = *(_DWORD *)(a2 + 632);
        if ( v6
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          v7 = *(const char **)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v6 + 4))(v6, v22);
        }
        else
        {
          v7 = *(const char **)(a2 + 252);
          if ( !v7 )
            v7 = *(const char **)(a2 + 248);
        }
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
        v2 = 1;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\resources_query_result_cook.cpp",
          0x127u,
          "void __thiscall vostok::resources::query_result::do_create_resource_end_part(void)",
          "resources:",
          info,
          "requerying resource '%s' [quid %d]",
          v7,
          *(_DWORD *)(a2 + 32));
      }
      if ( (v2 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v5,
          (int *)&log_callback);
    }
    else
    {
      v9 = *(vostok::resources::query_result **)(a2 + 688);
      if ( ((unsigned __int16)v9 & 0x8000) != 0 )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
        {
          v11 = vostok::core::g_log_callback;
          v19.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &v19.functor,
              &v19.functor,
              destroy_functor_tag);
          if ( v11 )
          {
            v19.functor.obj_ptr = v11;
            v19.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                + 1);
          }
          else
          {
            v19.vtable = 0;
          }
          v12 = *(const char **)(a2 + 252);
          v2 = 2;
          if ( !v12 )
            v12 = *(const char **)(a2 + 248);
          vostok::logging::append(
            &v19,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\resources_query_result_cook.cpp",
            0x12Fu,
            "void __thiscall vostok::resources::query_result::do_create_resource_end_part(void)",
            "resources:",
            info,
            "no resource was cooked by cook, request path was: '%s' [quid %d]",
            v12,
            *(_DWORD *)(a2 + 32));
        }
        if ( (v2 & 2) != 0 )
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            v10,
            (int *)&v19);
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "resources:", info) )
        {
          if ( !*(_DWORD *)(a2 + 216)
            || (v13 = *(vostok::resources::query_result **)(a2 + 216),
                !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
          {
            v13 = *(vostok::resources::query_result **)(a2 + 220);
          }
          resource_if_no_file = vostok::resources::query_result::need_create_resource_if_no_file(v9, (_DWORD *)a2);
          v18.m_object = (vostok::resources::managed_resource *)"generated";
          if ( !resource_if_no_file )
            v18.m_object = (vostok::resources::managed_resource *)"cooked";
          v15 = vostok::core::g_log_callback;
          v20.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &v20.functor,
              &v20.functor,
              destroy_functor_tag);
          if ( v15 )
          {
            v20.functor.obj_ptr = v15;
            v20.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                + 1);
          }
          else
          {
            v20.vtable = 0;
          }
          v16 = *(_DWORD *)(a2 + 32);
          v2 = 4;
          v17 = vostok::resources::log_string(v13, &v23);
          vostok::logging::append(
            &v20,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\resources_query_result_cook.cpp",
            0x138u,
            "void __thiscall vostok::resources::query_result::do_create_resource_end_part(void)",
            "resources:",
            info,
            "%s %s [quid %d]",
            (const char *)v18.m_object,
            v17->m_begin,
            v16);
        }
        if ( (v2 & 4) != 0 )
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v9,
            (int *)&v20);
      }
    }
  }
}
