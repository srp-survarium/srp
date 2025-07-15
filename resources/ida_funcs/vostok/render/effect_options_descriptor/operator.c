vostok::render::effect_options_descriptor *__usercall vostok::render::effect_options_descriptor::operator=<int>@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        vostok::render::effect_options_descriptor *result@<eax>)
{
  result->data = 0;
  result->data = (unsigned __int8 *)1;
  result->count = 4;
  if ( (`vostok::render::static_type::get_type_id<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<int>'::`2'::`local static guard' |= 1u;
    `vostok::render::static_type::get_type_id<int>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
  }
  result->type = `vostok::render::static_type::get_type_id<int>'::`2'::current_id;
  if ( result != (vostok::render::effect_options_descriptor *)-4 )
    result->destroyer = &stru_965008.m_surface;
  return result;
}


vostok::render::effect_options_descriptor *__usercall vostok::render::effect_options_descriptor::operator=<char const *>@<eax>(
        vostok::render::effect_options_descriptor *this@<esi>,
        char *value@<edx>)
{
  const char *v2; // eax
  unsigned __int8 *data; // ecx

  v2 = &value[strlen(value) + 1];
  data = this->data;
  LOWORD(v2) = (_WORD)v2 - (_WORD)value;
  this->count = (unsigned __int16)v2;
  memcpy(data, (unsigned __int8 *)value, (unsigned __int16)v2);
  if ( this->type == 3 )
    this->bytes += this->count;
  if ( (`vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' & 1) != 0 )
  {
    this->type = (unsigned __int16)`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id;
  }
  else
  {
    `vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' |= 1u;
    LOWORD(`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
    this->type = vostok::render::static_type::type_id_counter;
  }
  return this;
}


vostok::render::effect_options_descriptor *__usercall vostok::render::effect_options_descriptor::operator=<enum D3D11_CULL_MODE>@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        vostok::render::effect_options_descriptor *result@<eax>)
{
  result->data = 0;
  result->data = (unsigned __int8 *)this;
  result->count = 4;
  if ( (`vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' |= 1u;
    `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
  }
  result->type = `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id;
  if ( result != (vostok::render::effect_options_descriptor *)-4 )
    result->destroyer = &vostok::render::destroy_data_helper<enum D3D11_CULL_MODE const>::`vftable';
  return result;
}


vostok::render::effect_options_descriptor *__usercall vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        vostok::render::effect_options_descriptor *result@<eax>)
{
  result->data = 0;
  result->data = (unsigned __int8 *)this;
  result->count = 4;
  if ( (`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard' |= 1u;
    LOWORD(`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
  }
  result->type = (unsigned __int16)`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id;
  if ( result != (vostok::render::effect_options_descriptor *)-4 )
    result->destroyer = &vostok::render::destroy_data_helper<enum vostok::render::enum_vertex_input_type const>::`vftable';
  return result;
}


vostok::render::effect_options_descriptor *__userpurge vostok::render::effect_options_descriptor::operator[]@<eax>(
        vostok::render::effect_options_descriptor *this@<ecx>,
        int a2@<edi>,
        const char *key)
{
  const char *v4; // edx
  int v5; // ebp
  vostok::render::effect_options_descriptor *v6; // esi
  int v7; // ecx
  unsigned int v8; // kr04_4
  unsigned int i; // [esp+10h] [ebp+4h]

  v4 = 0;
  v5 = 0;
  if ( *(_WORD *)(a2 + 16) == 3
    && (v6 = *(vostok::render::effect_options_descriptor **)(a2 + 8), i = 0, *(_WORD *)(a2 + 18)) )
  {
    while ( v6->id == v4 || key == v4 || strcmp(v6->id, key) )
    {
      v5 += vostok::render::effect_options_descriptor::get_num_used_bytes(v6);
      v6 = (vostok::render::effect_options_descriptor *)((char *)v6
                                                       + vostok::render::effect_options_descriptor::get_num_used_bytes(v6));
      if ( ++i >= *(unsigned __int16 *)(a2 + 18) )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v6 = (vostok::render::effect_options_descriptor *)(v5 + *(_DWORD *)(a2 + 8));
    if ( v6 )
    {
      v6->id = v4;
      v6->destroyer = v4;
      v6->data = (unsigned __int8 *)v4;
      v6->bytes = (unsigned int)v4;
      v6->type = 0;
      v6->count = 0;
      v6->memory_size = 0;
    }
    else
    {
      v6 = 0;
    }
    strcpy((char *)(*(_DWORD *)(a2 + 8) + v5 + 24), key);
    v7 = *(_DWORD *)(a2 + 8) + v5 + 24;
    ++*(_WORD *)(a2 + 18);
    v6->id = (const char *)v7;
    v6->type = 3;
    v8 = strlen(key);
    v6->bytes = v8 + 25;
    v6->data = (unsigned __int8 *)(*(_DWORD *)(a2 + 8) + v5 + v8 + 25);
    v6->count = 0;
    v6->destroyer = 0;
  }
  return v6;
}
