void __cdecl stlp_std::priv::__ufill<char *,char,int>(char *__first, char *__last, const char *__x)
{
  int __n; // [esp+4h] [ebp-8h]
  char *__cur; // [esp+8h] [ebp-4h]

  __cur = __first;
  for ( __n = __last - __first; __n > 0; --__n )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *__cur++ = *__x;
  }
}


void __usercall stlp_std::priv::__ufill<survarium::account_list_item *,survarium::account_list_item,int>(
        survarium::account_list_item *__first@<ecx>,
        survarium::account_list_item *__last@<eax>,
        const survarium::account_list_item *__x@<edi>)
{
  int v3; // eax
  unsigned __int8 *m_buffer; // esi
  unsigned int v5; // ebp
  unsigned __int8 *m_begin; // [esp-10h] [ebp-18h]
  int __n; // [esp+4h] [ebp-4h]

  v3 = __last - __first;
  __n = v3;
  if ( v3 > 0 )
  {
    m_buffer = (unsigned __int8 *)__first->account_name.m_buffer;
    do
    {
      if ( m_buffer != (unsigned __int8 *)16 )
      {
        *((_DWORD *)m_buffer - 4) = __x->account_id;
        v5 = __x->account_name.m_end - __x->account_name.m_begin;
        m_begin = (unsigned __int8 *)__x->account_name.m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 32;
        memcpy(m_buffer, m_begin, v5);
        *((_DWORD *)m_buffer - 2) += v5;
        **((_BYTE **)m_buffer - 2) = 0;
        m_buffer[32] = __x->online;
        v3 = __n;
      }
      --v3;
      m_buffer += 52;
      __n = v3;
    }
    while ( v3 > 0 );
  }
}


void __usercall stlp_std::priv::__ufill<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source,int>(
        vostok::render::batched_vertex_source *__first@<edi>,
        vostok::render::batched_vertex_source *__last@<eax>,
        const vostok::render::batched_vertex_source *__x@<esi>)
{
  int v3; // eax
  vostok::math::color *p_normal; // ecx

  v3 = __last - __first;
  if ( v3 > 0 )
  {
    p_normal = &__first->normal;
    do
    {
      if ( p_normal != (vostok::math::color *)12 )
        *(vostok::render::batched_vertex_source *)&p_normal[-3].r = *__x;
      --v3;
      p_normal += 9;
    }
    while ( v3 > 0 );
  }
}


void __usercall stlp_std::priv::__ufill<vostok::render::light_data *,vostok::render::light_data,int>(
        vostok::render::light_data *__first@<ecx>,
        vostok::render::light_data *__last@<eax>,
        const vostok::render::light_data *__x@<esi>)
{
  int i; // edx
  vostok::render::light *m_object; // eax

  for ( i = __last - __first; i > 0; ++__first )
  {
    if ( __first )
    {
      __first->light.m_object = 0;
      m_object = __x->light.m_object;
      if ( __x->light.m_object )
      {
        __first->light.m_object = m_object;
        ++m_object->m_reference_count;
      }
      __first->id = __x->id;
    }
    --i;
  }
}


void __usercall stlp_std::priv::__ufill<vostok::render::signature_layout_pair *,vostok::render::signature_layout_pair,int>(
        vostok::render::signature_layout_pair *__first@<eax>,
        vostok::render::signature_layout_pair *__last@<ecx>,
        const vostok::render::signature_layout_pair *__x@<edi>)
{
  int i; // edx
  vostok::render::res_input_layout *m_object; // ecx
  const vostok::render::res_signature *v5; // ecx

  for ( i = __last - __first; i > 0; ++__first )
  {
    if ( __first )
    {
      __first->input_layout.m_object = 0;
      m_object = __x->input_layout.m_object;
      if ( __x->input_layout.m_object )
      {
        __first->input_layout.m_object = m_object;
        ++m_object->m_reference_count;
      }
      __first->signature.m_object = 0;
      v5 = __x->signature.m_object;
      if ( v5 )
      {
        __first->signature.m_object = v5;
        ++v5->m_reference_count;
      }
    }
    --i;
  }
}


void __usercall stlp_std::priv::__ufill<vostok::render::ui::vertex *,vostok::render::ui::vertex,int>(
        vostok::render::ui::vertex *__first@<edi>,
        vostok::render::ui::vertex *__last@<eax>,
        const vostok::render::ui::vertex *__x@<esi>)
{
  int v3; // eax
  unsigned int *p_m_color; // ecx

  v3 = __last - __first;
  if ( v3 > 0 )
  {
    p_m_color = &__first->m_color;
    do
    {
      if ( p_m_color != (unsigned int *)16 )
        *(vostok::render::ui::vertex *)(p_m_color - 4) = *__x;
      --v3;
      p_m_color += 7;
    }
    while ( v3 > 0 );
  }
}


void __usercall stlp_std::priv::__ufill<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,int>(
        stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__first@<ecx>,
        stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__last@<eax>,
        const stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__x)
{
  int v3; // ebx
  vostok::math::float3 *p_fog_color; // eax

  v3 = __last - __first;
  if ( v3 > 0 )
  {
    p_fog_color = &__first->second.fog_color;
    do
    {
      if ( p_fog_color != (vostok::math::float3 *)68 )
      {
        LODWORD(p_fog_color[-6].y) = __x->first;
        qmemcpy(&p_fog_color[-6].elements[2], &__x->second, 0x48u);
        p_fog_color->z = __x->second.fog_color.z;
        *(vostok::math::float2 *)&p_fog_color[1].x = __x->second.direction;
        p_fog_color[1].z = __x->second.height_falloff_offset;
        p_fog_color[2].x = __x->second.density;
        p_fog_color[2].y = __x->second.speed;
        p_fog_color[2].z = __x->second.noise_scale;
        p_fog_color[3].x = __x->second.wave_length;
        p_fog_color[3].y = __x->second.near_density;
        p_fog_color[3].z = __x->second.transparency_multiplier;
        p_fog_color[4].x = __x->second.density_offset;
      }
      --v3;
      p_fog_color += 10;
    }
    while ( v3 > 0 );
  }
}


void __usercall stlp_std::priv::__ufill<stlp_std::pair<unsigned int,vostok::math::float4x4> *,stlp_std::pair<unsigned int,vostok::math::float4x4>,int>(
        stlp_std::pair<unsigned int,vostok::math::float4x4> *__last@<eax>,
        stlp_std::pair<unsigned int,vostok::math::float4x4> *__first,
        const stlp_std::pair<unsigned int,vostok::math::float4x4> *__x)
{
  stlp_std::pair<unsigned int,vostok::math::float4x4> *v3; // ebx
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    if ( v3 )
    {
      v3->first = __x->first;
      qmemcpy((void *)&v3->second, &__x->second, sizeof(v3->second));
    }
    --i;
  }
}


void __usercall stlp_std::priv::__ufill<vostok::fixed_string<32> *,vostok::fixed_string<32>,int>(
        vostok::fixed_string<32> *__first@<ecx>,
        vostok::fixed_string<32> *__last@<eax>,
        const vostok::fixed_string<32> *__x)
{
  int v3; // edi
  unsigned __int8 *m_buffer; // esi
  unsigned int v5; // ebx
  unsigned __int8 *m_begin; // [esp-Ch] [ebp-18h]

  v3 = __last - __first;
  if ( v3 > 0 )
  {
    m_buffer = (unsigned __int8 *)__first->m_buffer;
    do
    {
      if ( m_buffer != (unsigned __int8 *)12 )
      {
        v5 = __x->m_end - __x->m_begin;
        m_begin = (unsigned __int8 *)__x->m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 32;
        memcpy(m_buffer, m_begin, v5);
        *((_DWORD *)m_buffer - 2) += v5;
        **((_BYTE **)m_buffer - 2) = 0;
      }
      --v3;
      m_buffer += 44;
    }
    while ( v3 > 0 );
  }
}


void __cdecl stlp_std::priv::__ufill<wchar_t *,wchar_t,int>(wchar_t *__first, wchar_t *__last, wchar_t *__x)
{
  wchar_t *v3; // ecx
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    *v3 = *__x;
    --i;
  }
}
