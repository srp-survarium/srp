void __usercall vostok::render::scene::dump_scene_statistics(vostok::render::scene *this@<ecx>, int a2@<eax>)
{
  unsigned int *v3; // edi
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *M_finish; // ebp
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *v5; // esi
  char *m_buffer; // eax
  const char *v7; // ecx
  char *m_end; // ebp
  char *v9; // eax
  _BYTE *v10; // ecx
  int v11; // ebp
  void (__cdecl *v12)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebp
  int v13; // eax
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  const char *v16; // [esp-4h] [ebp-170h]
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v17; // [esp+0h] [ebp-16Ch]
  int __comp; // [esp+10h] [ebp-15Ch]
  int v19; // [esp+14h] [ebp-158h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-154h] BYREF
  vostok::render::vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > dump_instances; // [esp+3Ch] [ebp-130h]
  vostok::fixed_string<128> model_name; // [esp+48h] [ebp-124h] BYREF
  char v23; // [esp+D4h] [ebp-98h] BYREF
  unsigned __int8 *src; // [esp+DCh] [ebp-90h]
  _BYTE *v25; // [esp+E0h] [ebp-8Ch]
  char *v26; // [esp+E4h] [ebp-88h]
  _BYTE v27[128]; // [esp+E8h] [ebp-84h] BYREF
  char v28; // [esp+168h] [ebp-4h] BYREF

  v19 = 0;
  v3 = stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
         (*(_DWORD *)(a2 + 936) - *(_DWORD *)(a2 + 932)) >> 2,
         v17);
  M_finish = (vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *)stlp_std::priv::__ucopy<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> const *,vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *,int>(*(vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> **)(a2 + 936), (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)v3, *(vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> **)(a2 + 932));
  dump_instances._M_impl._M_finish = M_finish;
  ___sort_PAV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok__Usort_predicate__1__dump_scene_statistics_scene_render_3_QBEXXZ__stlp_std__YAXPAV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_vostok__0Usort_predicate__1__dump_scene_statistics_scene_render_3_QBEXXZ__Z(
    (vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3,
    M_finish,
    0);
  v5 = (vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v3;
  if ( v3 != (unsigned int *)M_finish )
  {
    __comp = 1;
    do
    {
      m_buffer = model_name.m_buffer;
      model_name.m_begin = model_name.m_buffer;
      model_name.m_end = model_name.m_buffer;
      model_name.m_max_end = &v23;
      model_name.m_buffer[0] = 0;
      v7 = "<unknown>";
      do
      {
        if ( m_buffer >= model_name.m_max_end )
          break;
        *m_buffer = *v7;
        m_buffer = model_name.m_end + 1;
        ++v7;
        ++model_name.m_end;
      }
      while ( *v7 );
      *m_buffer = 0;
      if ( (unsigned int)(model_name.m_end - model_name.m_begin) > 0x11 )
      {
        src = v27;
        m_end = model_name.m_end;
        v26 = &v28;
        v9 = model_name.m_begin + 17;
        v10 = v27;
        v25 = v27;
        for ( v27[0] = 0; v9 != m_end; ++v25 )
        {
          *v10 = *v9++;
          v10 = v25 + 1;
        }
        *v10 = 0;
        model_name.m_end = model_name.m_begin;
        *model_name.m_begin = 0;
        v11 = v25 - src;
        memcpy((unsigned __int8 *)model_name.m_end, src, v25 - src);
        model_name.m_end += v11;
        *model_name.m_end = 0;
      }
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", info) )
      {
        v12 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v12 )
        {
          log_callback.functor.obj_ptr = v12;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v19 |= 1u;
        v13 = ((int (__thiscall *)(vostok::render::render_model_instance_impl *, char *))v5->m_object->get_surfaces_count)(
                v5->m_object,
                model_name.m_begin);
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\scene.cpp",
          0x4E2u,
          "void __thiscall vostok::render::scene::dump_scene_statistics(void) const",
          "render_pc_dx11:",
          info,
          "%d: surfaces: %d, model: %s",
          __comp,
          v13,
          v16);
      }
      if ( (v19 & 1) != 0 )
      {
        v19 &= ~1u;
        if ( log_callback.vtable )
        {
          if ( ((int)log_callback.vtable & 1) == 0 )
          {
            v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
            if ( v14 )
              v14(&log_callback.functor, &log_callback.functor, 2);
          }
        }
      }
      M_finish = dump_instances._M_impl._M_finish;
      ++__comp;
      ++v5;
    }
    while ( v5 != dump_instances._M_impl._M_finish );
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>>(
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)M_finish,
    (stlp_std::reverse_iterator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *>)v3);
  if ( v3 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
  }
}
