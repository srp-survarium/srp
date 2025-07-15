void __usercall stlp_std::priv::__fill<survarium::account_list_item *,survarium::account_list_item,int>(
        survarium::account_list_item *__last@<eax>,
        survarium::account_list_item *__first,
        const survarium::account_list_item *__val)
{
  survarium::account_list_item *v3; // ecx
  int v4; // ebx
  const survarium::account_list_item *v5; // edi
  char **p_m_end; // esi
  char *v7; // eax
  unsigned int v8; // edi

  v3 = __first;
  v4 = __last - __first;
  if ( v4 > 0 )
  {
    v5 = __val;
    p_m_end = &__first->account_name.m_end;
    do
    {
      v3->account_id = v5->account_id;
      if ( p_m_end - 1 != (char **)&__val->account_name )
      {
        v7 = *(p_m_end - 1);
        *p_m_end = v7;
        *v7 = 0;
        v8 = __val->account_name.m_end - __val->account_name.m_begin;
        memcpy((unsigned __int8 *)*p_m_end, (unsigned __int8 *)__val->account_name.m_begin, v8);
        v3 = __first;
        *p_m_end += v8;
        v5 = __val;
        **p_m_end = 0;
      }
      *((_BYTE *)p_m_end + 40) = v5->online;
      ++v3;
      --v4;
      p_m_end += 13;
      __first = v3;
    }
    while ( v4 > 0 );
  }
}


void __usercall stlp_std::priv::__fill<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,int>(
        vostok::render::batched_vertex_source *__first@<ecx>,
        vostok::render::batched_vertex_source *__last@<eax>,
        const vostok::render::batched_vertex_source *__val@<esi>)
{
  int i; // eax

  for ( i = __last - __first; i > 0; ++__first )
  {
    *__first = *__val;
    --i;
  }
}


void __usercall stlp_std::priv::__fill<D3D11_INPUT_ELEMENT_DESC *,D3D11_INPUT_ELEMENT_DESC,int>(
        D3D11_INPUT_ELEMENT_DESC *__first@<ecx>,
        D3D11_INPUT_ELEMENT_DESC *__last@<eax>,
        const D3D11_INPUT_ELEMENT_DESC *__val@<esi>)
{
  int i; // eax

  for ( i = __last - __first; i > 0; ++__first )
  {
    *__first = *__val;
    --i;
  }
}


void __usercall stlp_std::priv::__fill<vostok::render::frond_vertex *,vostok::render::frond_vertex,int>(
        vostok::render::frond_vertex *__last@<eax>,
        vostok::render::frond_vertex *__first,
        const vostok::render::frond_vertex *__x)
{
  vostok::render::frond_vertex *v3; // ebx
  int i; // eax
  vostok::render::frond_vertex *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __x, sizeof(vostok::render::frond_vertex));
  }
}


void __usercall stlp_std::priv::__fill<vostok::render::leafcard_vertex *,vostok::render::leafcard_vertex,int>(
        vostok::render::leafcard_vertex *__last@<eax>,
        vostok::render::leafcard_vertex *__first,
        const vostok::render::leafcard_vertex *__x)
{
  vostok::render::leafcard_vertex *v3; // ebx
  int i; // eax
  vostok::render::leafcard_vertex *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __x, sizeof(vostok::render::leafcard_vertex));
  }
}


void __usercall stlp_std::priv::__fill<vostok::render::light_data *,vostok::render::light_data,int>(
        vostok::render::light_data *__last@<eax>,
        vostok::render::light_data *__first,
        const vostok::render::light_data *__val)
{
  vostok::render::light_data *v3; // ebp
  int i; // ebx
  vostok::render::light *m_object; // ecx
  vostok::render::light *v6; // eax
  vostok::render::light *v7; // edi
  vostok::render::grass_render_model *v9; // esi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    m_object = __val->light.m_object;
    v6 = 0;
    if ( __val->light.m_object )
    {
      v6 = __val->light.m_object;
      ++m_object->m_reference_count;
    }
    v7 = v3->light.m_object;
    v3->light.m_object = v6;
    if ( v7 )
    {
      if ( v7->m_reference_count-- == 1 )
      {
        v9 = vostok::render::g_allocator.m_object;
        vostok::render::light::~light(m_object);
        BYTE2(v9->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v9->m_reconstruction_info_actuality_tick), v7);
      }
    }
    v3->id = __val->id;
    --i;
  }
}


void __usercall stlp_std::priv::__fill<vostok::render::signature_layout_pair *,vostok::render::signature_layout_pair,int>(
        vostok::render::signature_layout_pair *__first@<ecx>,
        vostok::render::signature_layout_pair *__last@<eax>,
        const vostok::render::signature_layout_pair *__val)
{
  vostok::render::signature_layout_pair *v3; // esi
  int i; // edi
  vostok::render::res_input_layout *m_object; // eax
  const vostok::render::res_input_layout *v6; // ecx
  bool v7; // zf
  const vostok::render::res_signature *v8; // ecx
  const vostok::render::res_signature *v9; // eax
  const vostok::render::res_signature *v10; // ecx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    m_object = 0;
    if ( __val->input_layout.m_object )
    {
      m_object = __val->input_layout.m_object;
      ++__val->input_layout.m_object->m_reference_count;
    }
    v6 = v3->input_layout.m_object;
    v3->input_layout.m_object = m_object;
    if ( v6 )
    {
      v7 = v6->m_reference_count-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v6);
    }
    v8 = __val->signature.m_object;
    v9 = 0;
    if ( v8 )
    {
      v9 = __val->signature.m_object;
      ++v8->m_reference_count;
    }
    v10 = v3->signature.m_object;
    v3->signature.m_object = v9;
    if ( v10 )
    {
      v7 = v10->m_reference_count-- == 1;
      if ( v7 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v10);
    }
    --i;
  }
}


void __usercall stlp_std::priv::__fill<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,int>(
        stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__last@<eax>,
        stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__first,
        const stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__val)
{
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *v3; // ebx
  int i; // eax
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __val, sizeof(stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>));
  }
}


void __usercall stlp_std::priv::__fill<stlp_std::pair<unsigned int,vostok::math::float4x4> *,stlp_std::pair<unsigned int,vostok::math::float4x4>,int>(
        stlp_std::pair<unsigned int,vostok::math::float4x4> *__last@<eax>,
        stlp_std::pair<unsigned int,vostok::math::float4x4> *__first,
        const stlp_std::pair<unsigned int,vostok::math::float4x4> *__val)
{
  stlp_std::pair<unsigned int,vostok::math::float4x4> *v3; // ebx
  int i; // eax
  stlp_std::pair<unsigned int,vostok::math::float4x4> *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __val, sizeof(stlp_std::pair<unsigned int,vostok::math::float4x4>));
  }
}


void __usercall stlp_std::priv::__fill<vostok::fixed_string<32> *,vostok::fixed_string<32>,int>(
        vostok::fixed_string<32> *__first@<ecx>,
        vostok::fixed_string<32> *__last@<eax>,
        const vostok::fixed_string<32> *__val)
{
  vostok::fixed_string<32> *v3; // esi
  int i; // ebx
  char *m_begin; // eax
  unsigned int v6; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    if ( v3 != __val )
    {
      m_begin = v3->m_begin;
      v3->m_end = v3->m_begin;
      *m_begin = 0;
      v6 = __val->m_end - __val->m_begin;
      memcpy((unsigned __int8 *)v3->m_end, (unsigned __int8 *)__val->m_begin, v6);
      v3->m_end += v6;
      *v3->m_end = 0;
    }
    --i;
  }
}
