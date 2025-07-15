survarium::account_list_item *__usercall stlp_std::priv::__copy<survarium::account_list_item *,survarium::account_list_item *,int>@<eax>(
        survarium::account_list_item *__last@<eax>,
        survarium::account_list_item *__first,
        survarium::account_list_item *__result)
{
  survarium::account_list_item *v3; // ecx
  int v4; // ebp
  survarium::account_list_item *v5; // edi
  vostok::fixed_string<32> *p_account_name; // ebx
  char **p_m_end; // esi
  char *v8; // eax
  unsigned int v9; // edi

  v3 = __first;
  v4 = __last - __first;
  if ( v4 <= 0 )
    return __result;
  v5 = __result;
  p_account_name = &__first->account_name;
  p_m_end = &__result->account_name.m_end;
  do
  {
    v5->account_id = v3->account_id;
    if ( p_m_end - 1 != (char **)p_account_name )
    {
      v8 = *(p_m_end - 1);
      *p_m_end = v8;
      *v8 = 0;
      v9 = p_account_name->m_end - p_account_name->m_begin;
      memcpy((unsigned __int8 *)*p_m_end, (unsigned __int8 *)p_account_name->m_begin, v9);
      v3 = __first;
      *p_m_end += v9;
      v5 = __result;
      **p_m_end = 0;
    }
    *((_BYTE *)p_m_end + 40) = p_account_name[1].m_begin;
    ++v3;
    ++v5;
    --v4;
    p_account_name = (vostok::fixed_string<32> *)((char *)p_account_name + 52);
    p_m_end += 13;
    __first = v3;
    __result = v5;
  }
  while ( v4 > 0 );
  return v5;
}


vostok::render::light_data *__usercall stlp_std::priv::__copy<vostok::render::light_data *,vostok::render::light_data *,int>@<eax>(
        vostok::render::light_data *__last@<edx>,
        vostok::render::light_data *__first,
        vostok::render::light_data *__result)
{
  vostok::render::light_data *v3; // ebx
  int v5; // edx
  vostok::render::light *m_object; // ecx
  vostok::render::light *v7; // eax
  vostok::render::light *v8; // edi
  vostok::render::grass_render_model *v10; // esi
  int __n; // [esp+1Ch] [ebp+8h]

  v3 = __first;
  v5 = __last - __first;
  for ( __n = v5; v5 > 0; __n = v5 )
  {
    m_object = v3->light.m_object;
    v7 = 0;
    if ( v3->light.m_object )
    {
      v7 = v3->light.m_object;
      ++m_object->m_reference_count;
    }
    v8 = __result->light.m_object;
    __result->light.m_object = v7;
    if ( v8 )
    {
      if ( v8->m_reference_count-- == 1 )
      {
        v10 = vostok::render::g_allocator.m_object;
        vostok::render::light::~light(m_object);
        BYTE2(v10->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v10->m_reconstruction_info_actuality_tick), v8);
        v5 = __n;
      }
    }
    --v5;
    __result->id = v3->id;
    ++v3;
    ++__result;
  }
  return __result;
}


vostok::render::lpv_render_surface *__usercall stlp_std::priv::__copy<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,int>@<eax>(
        vostok::render::lpv_render_surface *__last@<eax>,
        vostok::render::lpv_render_surface *__result@<ecx>,
        vostok::render::lpv_render_surface *__first)
{
  vostok::render::lpv_render_surface *v3; // edi
  int i; // ebx
  vostok::render::render_model_instance_impl *m_object; // ecx
  vostok::render::render_model_instance_impl *v7; // eax
  vostok::render::render_model_instance_impl *v8; // edx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    __result->surface = v3->surface;
    m_object = v3->model.m_object;
    v7 = 0;
    if ( m_object )
    {
      v7 = v3->model.m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    v8 = __result->model.m_object;
    __result->model.m_object = v7;
    if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
    --i;
    ++v3;
  }
  return __result;
}


vostok::render::material_effects_entry *__usercall stlp_std::priv::__copy<vostok::render::material_effects_entry *,vostok::render::material_effects_entry *,int>@<eax>(
        vostok::render::material_effects_entry *__first@<ecx>,
        vostok::render::material_effects_entry *__last@<eax>,
        vostok::render::material_effects_entry *__result)
{
  vostok::render::material_effects_entry *v4; // edi
  int i; // esi

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    __result->m_material_effects_instance_ptr = v4->m_material_effects_instance_ptr;
    vostok::fs_new::virtual_path_string::operator=(&__result->m_material_name, &v4->m_material_name);
    --i;
    ++v4;
  }
  return __result;
}


vostok::render::requested_streamable_texture *__usercall stlp_std::priv::__copy<vostok::render::requested_streamable_texture *,vostok::render::requested_streamable_texture *,int>@<eax>(
        vostok::render::requested_streamable_texture *__last@<eax>,
        vostok::render::requested_streamable_texture *__first,
        vostok::render::requested_streamable_texture *__result)
{
  vostok::render::requested_streamable_texture *v3; // ebx
  vostok::render::requested_streamable_texture *v4; // edi
  int i; // ebp
  vostok::render::res_texture *m_object; // ecx
  vostok::render::res_texture *v7; // eax
  const vostok::render::res_texture *v8; // esi
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  vostok::render::resource_manager *v12; // [esp+0h] [ebp-14h]
  stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *__pos; // [esp+10h] [ebp-4h]

  v3 = __result;
  v4 = __first;
  for ( i = __last - __first; i > 0; __first = v4 )
  {
    vostok::fixed_string<260>::operator=(&v3->path, &v4->path);
    m_object = v4->texture.m_object;
    v7 = 0;
    if ( m_object )
    {
      v7 = v4->texture.m_object;
      ++m_object->m_reference_count;
    }
    v8 = v3->texture.m_object;
    v3->texture.m_object = v7;
    if ( v8 )
    {
      if ( v8->m_reference_count-- == 1 && v8->m_is_registered )
      {
        __result = (vostok::render::requested_streamable_texture *)v8->m_name.m_string.m_begin;
        __pos = (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
        v10 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&__result,
                (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
        if ( v10 != (stlp_std::priv::_Rb_tree_node_base *)__pos )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            __pos,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v10);
          vostok::render::resource_manager::release_impl(v12, v8);
          v4 = __first;
        }
      }
    }
    v3->num_mips = v4->num_mips;
    ++v4;
    --i;
    ++v3;
  }
  return v3;
}


vostok::render::streamable_texture_info *__usercall stlp_std::priv::__copy<vostok::render::streamable_texture_info *,vostok::render::streamable_texture_info *,int>@<eax>(
        vostok::render::streamable_texture_info *__last@<eax>,
        vostok::render::streamable_texture_info *__first,
        vostok::render::streamable_texture_info *__result)
{
  vostok::render::streamable_texture_info *v4; // edi
  stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *m_object; // ecx
  int i; // ebp
  vostok::render::res_texture *v7; // eax
  vostok::render::res_texture *v8; // esi
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  vostok::render::resource_manager *v12; // [esp+0h] [ebp-14h]
  stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *__pos; // [esp+10h] [ebp-4h]

  v4 = __first;
  m_object = (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)((char *)__last - (char *)__first);
  for ( i = __last - __first; i > 0; __first = v4 )
  {
    stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::operator=(
      m_object,
      &__result->instances._M_impl);
    vostok::fixed_string<260>::operator=(&__result->path, &v4->path);
    m_object = (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)v4->texture.m_object;
    v7 = 0;
    if ( m_object )
    {
      v7 = v4->texture.m_object;
      ++m_object->_M_finish;
    }
    v8 = __result->texture.m_object;
    __result->texture.m_object = v7;
    if ( v8 )
    {
      if ( v8->m_reference_count-- == 1 && v8->m_is_registered )
      {
        __pos = (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7];
        v10 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v8->m_name.m_string.m_begin,
                (const char *const *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7]);
        m_object = (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)__pos;
        if ( v10 != (stlp_std::priv::_Rb_tree_node_base *)__pos )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            __pos,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v10);
          vostok::render::resource_manager::release_impl(v12, v8);
          v4 = __first;
        }
      }
    }
    ++v4;
    --i;
    ++__result;
  }
  return __result;
}


vostok::render::streaming_ready_texture *__usercall stlp_std::priv::__copy<vostok::render::streaming_ready_texture *,vostok::render::streaming_ready_texture *,int>@<eax>(
        vostok::render::streaming_ready_texture *__last@<eax>,
        vostok::render::streaming_ready_texture *__result@<ecx>,
        vostok::render::streaming_ready_texture *__first)
{
  const vostok::render::streaming_ready_texture *v3; // ebx
  vostok::render::streaming_ready_texture *v5; // ecx
  int i; // esi

  v3 = __first;
  v5 = (vostok::render::streaming_ready_texture *)((char *)__last - (char *)__first);
  for ( i = __last - __first; i > 0; ++__result )
  {
    vostok::render::streaming_ready_texture::operator=(v5, v3);
    --i;
    ++v3;
  }
  return __result;
}


vostok::render::shader_constant_binding *__usercall stlp_std::priv::__copy<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding *,int>@<eax>(
        vostok::render::shader_constant_binding *__last@<eax>,
        vostok::render::shader_constant_binding *__result@<ecx>,
        vostok::render::shader_constant_binding *__first)
{
  vostok::render::shader_constant_binding *v3; // edi
  int i; // ebx
  vostok::strings::shared::profile *m_object; // eax
  vostok::strings::shared::profile *v7; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    m_object = __result->m_name.m_pointer.m_object;
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    __result->m_source.m_pointer = v3->m_source.m_pointer;
    __result->m_source.m_size = v3->m_source.m_size;
    __result->m_name.m_pointer.m_object = 0;
    v7 = v3->m_name.m_pointer.m_object;
    if ( v7 )
    {
      __result->m_name.m_pointer.m_object = v7;
      _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
    }
    __result->m_type = v3->m_type;
    __result->m_class_id = v3->m_class_id;
    --i;
    ++v3;
  }
  return __result;
}


vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__copy<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string *,int>@<eax>(
        vostok::fs_new::virtual_path_string *__first@<ecx>,
        vostok::fs_new::virtual_path_string *__last@<eax>,
        vostok::fs_new::virtual_path_string *__result)
{
  vostok::fs_new::virtual_path_string *v4; // edi
  int i; // esi

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    vostok::fs_new::virtual_path_string::operator=(__result, v4);
    --i;
    ++v4;
  }
  return __result;
}


vostok::fixed_string<32> *__usercall stlp_std::priv::__copy<vostok::fixed_string<32> *,vostok::fixed_string<32> *,int>@<eax>(
        vostok::fixed_string<32> *__last@<eax>,
        vostok::fixed_string<32> *__result@<ecx>,
        vostok::fixed_string<32> *__first)
{
  vostok::fixed_string<32> *v3; // ebx
  int i; // ebp
  char *m_begin; // eax
  unsigned int v7; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result != v3 )
    {
      m_begin = __result->m_begin;
      __result->m_end = __result->m_begin;
      *m_begin = 0;
      v7 = v3->m_end - v3->m_begin;
      memcpy((unsigned __int8 *)__result->m_end, (unsigned __int8 *)v3->m_begin, v7);
      __result->m_end += v7;
      *__result->m_end = 0;
    }
    --i;
    ++v3;
  }
  return __result;
}
