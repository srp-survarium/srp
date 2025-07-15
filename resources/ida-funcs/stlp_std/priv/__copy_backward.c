survarium::account_list_item *__cdecl stlp_std::priv::__copy_backward<survarium::account_list_item *,survarium::account_list_item *,int>(
        survarium::account_list_item *__first,
        survarium::account_list_item *__last,
        survarium::account_list_item *__result)
{
  survarium::account_list_item *v3; // edi
  survarium::account_list_item *result; // eax
  int v5; // ebp
  vostok::fixed_string<32> *p_account_name; // ebx
  char **p_m_end; // esi
  unsigned int account_id; // ecx
  char *v9; // eax
  unsigned int v10; // edi
  survarium::account_list_item *__lasta; // [esp+10h] [ebp+8h]
  survarium::account_list_item *__resulta; // [esp+14h] [ebp+Ch]

  v3 = __last;
  result = __result;
  v5 = __last - __first;
  if ( v5 > 0 )
  {
    p_account_name = &__last->account_name;
    p_m_end = &__result->account_name.m_end;
    do
    {
      account_id = v3[-1].account_id;
      --v3;
      p_m_end -= 13;
      --result;
      p_account_name = (vostok::fixed_string<32> *)((char *)p_account_name - 52);
      __lasta = v3;
      __resulta = result;
      result->account_id = account_id;
      if ( p_m_end - 1 != (char **)p_account_name )
      {
        v9 = *(p_m_end - 1);
        *p_m_end = v9;
        *v9 = 0;
        v10 = p_account_name->m_end - p_account_name->m_begin;
        memcpy((unsigned __int8 *)*p_m_end, (unsigned __int8 *)p_account_name->m_begin, v10);
        *p_m_end += v10;
        v3 = __lasta;
        **p_m_end = 0;
        result = __resulta;
      }
      --v5;
      *((_BYTE *)p_m_end + 40) = p_account_name[1].m_begin;
    }
    while ( v5 > 0 );
  }
  return result;
}


vostok::render::light_data *__cdecl stlp_std::priv::__copy_backward<vostok::render::light_data *,vostok::render::light_data *,int>(
        vostok::render::light_data *__first,
        vostok::render::light_data *__last,
        vostok::render::light_data *__result)
{
  vostok::render::light_data *v3; // edx
  int i; // ebx
  vostok::render::light *m_object; // ecx
  vostok::render::light *v7; // eax
  vostok::render::light *v8; // edi
  vostok::render::grass_render_model *v10; // esi
  vostok::render::light_data *__lasta; // [esp+18h] [ebp+8h]

  v3 = __last;
  for ( i = __last - __first; i > 0; __result->id = v3->id )
  {
    m_object = v3[-1].light.m_object;
    --v3;
    --__result;
    v7 = 0;
    __lasta = v3;
    if ( m_object )
    {
      v7 = m_object;
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
        v3 = __lasta;
      }
    }
    --i;
  }
  return __result;
}


vostok::render::signature_layout_pair *__usercall stlp_std::priv::__copy_backward<vostok::render::signature_layout_pair *,vostok::render::signature_layout_pair *,int>@<eax>(
        vostok::render::signature_layout_pair *__last@<ecx>,
        vostok::render::signature_layout_pair *__result@<eax>,
        vostok::render::signature_layout_pair *__first)
{
  vostok::render::signature_layout_pair *v3; // edi
  vostok::render::signature_layout_pair *v4; // esi
  int v5; // ebx
  vostok::render::res_input_layout *m_object; // ecx
  vostok::render::res_input_layout *v7; // eax
  const vostok::render::res_input_layout *v8; // ecx
  bool v9; // zf
  const vostok::render::res_signature *v10; // ecx
  const vostok::render::res_signature *v11; // eax
  const vostok::render::res_signature *v12; // ecx

  v3 = __last;
  v4 = __result;
  v5 = __last - __first;
  if ( v5 > 0 )
  {
    do
    {
      m_object = v3[-1].input_layout.m_object;
      --v3;
      --v4;
      v7 = 0;
      if ( m_object )
      {
        v7 = m_object;
        ++m_object->m_reference_count;
      }
      v8 = v4->input_layout.m_object;
      v4->input_layout.m_object = v7;
      if ( v8 )
      {
        v9 = v8->m_reference_count-- == 1;
        if ( v9 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v8);
      }
      v10 = v3->signature.m_object;
      v11 = 0;
      if ( v10 )
      {
        v11 = v3->signature.m_object;
        ++v10->m_reference_count;
      }
      v12 = v4->signature.m_object;
      v4->signature.m_object = v11;
      if ( v12 )
      {
        v9 = v12->m_reference_count-- == 1;
        if ( v9 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v12);
      }
      --v5;
    }
    while ( v5 > 0 );
    return v4;
  }
  return __result;
}


vostok::render::streaming_ready_texture *__usercall stlp_std::priv::__copy_backward<vostok::render::streaming_ready_texture *,vostok::render::streaming_ready_texture *,int>@<eax>(
        vostok::render::streaming_ready_texture *__result@<eax>,
        vostok::render::streaming_ready_texture *__first,
        vostok::render::streaming_ready_texture *__last)
{
  const vostok::render::streaming_ready_texture *v3; // ebx
  vostok::render::streaming_ready_texture *v4; // ecx
  int i; // esi

  v3 = __last;
  v4 = (vostok::render::streaming_ready_texture *)((char *)__last - (char *)__first);
  for ( i = __last - __first; i > 0; --i )
    vostok::render::streaming_ready_texture::operator=(v4, (int)--__result, --v3);
  return __result;
}


vostok::render::shader_constant *__usercall stlp_std::priv::__copy_backward<vostok::render::shader_constant *,vostok::render::shader_constant *,int>@<eax>(
        vostok::render::shader_constant *__last@<ecx>,
        vostok::render::shader_constant *__result@<eax>,
        vostok::render::shader_constant *__first)
{
  int i; // eax

  for ( i = __last - __first; i > 0; --i )
  {
    --__last;
    if ( --__result )
      *__result = *__last;
  }
  return __result;
}


vostok::fixed_string<32> *__usercall stlp_std::priv::__copy_backward<vostok::fixed_string<32> *,vostok::fixed_string<32> *,int>@<eax>(
        vostok::fixed_string<32> *__result@<eax>,
        vostok::fixed_string<32> *__first,
        vostok::fixed_string<32> *__last)
{
  vostok::fixed_string<32> *v3; // ebx
  int i; // ebp
  char *m_begin; // eax
  unsigned int v7; // edi

  v3 = __last;
  for ( i = __last - __first; i > 0; --i )
  {
    if ( --__result != --v3 )
    {
      m_begin = __result->m_begin;
      __result->m_end = __result->m_begin;
      *m_begin = 0;
      v7 = v3->m_end - v3->m_begin;
      memcpy((unsigned __int8 *)__result->m_end, (unsigned __int8 *)v3->m_begin, v7);
      __result->m_end += v7;
      *__result->m_end = 0;
    }
  }
  return __result;
}
