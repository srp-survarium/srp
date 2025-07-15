char *__cdecl stlp_std::priv::__ucopy<char *,char *,int>(const char *__first, const char *__last, char *__result)
{
  int __n; // [esp+4h] [ebp-8h]

  for ( __n = __last - __first; __n > 0; --__n )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *__result++ = *__first++;
  }
  return __result;
}


survarium::account_list_item *__usercall stlp_std::priv::__ucopy<survarium::account_list_item *,survarium::account_list_item *,int>@<eax>(
        survarium::account_list_item *__last@<eax>,
        survarium::account_list_item *__result@<ecx>,
        survarium::account_list_item *__first)
{
  survarium::account_list_item *v3; // edi
  int v4; // ebx
  unsigned __int8 *m_buffer; // esi
  unsigned __int8 *m_begin; // [esp-Ch] [ebp-1Ch]
  unsigned int v8; // [esp-8h] [ebp-18h]
  unsigned int v9; // [esp+Ch] [ebp-4h]
  survarium::account_list_item *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->account_name.m_buffer;
    do
    {
      if ( __result )
      {
        __result->account_id = v3->account_id;
        v8 = v3->account_name.m_end - v3->account_name.m_begin;
        m_begin = (unsigned __int8 *)v3->account_name.m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 32;
        v9 = v8;
        memcpy(m_buffer, m_begin, v8);
        *((_DWORD *)m_buffer - 2) += v9;
        __result = __cur;
        **((_BYTE **)m_buffer - 2) = 0;
        m_buffer[32] = v3->online;
      }
      ++__result;
      --v4;
      ++v3;
      m_buffer += 52;
      __cur = __result;
    }
    while ( v4 > 0 );
  }
  return __result;
}


vostok::render::batched_vertex_source *__usercall stlp_std::priv::__ucopy<vostok::render::batched_vertex_source *,vostok::render::batched_vertex_source *,int>@<eax>(
        vostok::render::batched_vertex_source *__last@<eax>,
        vostok::render::batched_vertex_source *__result@<ecx>,
        vostok::render::batched_vertex_source *__first)
{
  vostok::render::batched_vertex_source *v3; // esi
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      *__result = *v3;
    --i;
    ++v3;
  }
  return __result;
}


vostok::render::geometry_batch *__usercall stlp_std::priv::__ucopy<vostok::render::geometry_batch *,vostok::render::geometry_batch *,int>@<eax>(
        vostok::render::geometry_batch *__last@<eax>,
        vostok::render::geometry_batch *__result@<ecx>,
        vostok::render::geometry_batch *__first)
{
  vostok::render::geometry_batch *v3; // ebx
  int i; // esi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      vostok::render::geometry_batch::geometry_batch(v3, (int)__result);
    --i;
    ++v3;
  }
  return __result;
}


vostok::render::light_data *__fastcall stlp_std::priv::__ucopy<vostok::render::light_data *,vostok::render::light_data *,int>(
        vostok::render::light_data *__last,
        vostok::render::light_data *__first,
        vostok::render::light_data *__result)
{
  vostok::render::light_data *result; // eax
  int i; // esi
  vostok::render::light *m_object; // ecx

  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    if ( result )
    {
      result->light.m_object = 0;
      m_object = __first->light.m_object;
      if ( __first->light.m_object )
      {
        result->light.m_object = m_object;
        ++m_object->m_reference_count;
      }
      result->id = __first->id;
    }
    --i;
    ++__first;
  }
  return result;
}


survarium::game_world::bullet_tracer *__fastcall stlp_std::priv::__ucopy<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,int>(
        survarium::game_world::bullet_tracer *__last,
        survarium::game_world::bullet_tracer *__first,
        survarium::game_world::bullet_tracer *__result)
{
  survarium::game_world::bullet_tracer *result; // eax
  int i; // esi
  vostok::render::tracer_model_instance *m_object; // ecx

  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    if ( result )
    {
      result->bullet = __first->bullet;
      result->tracer.m_object = 0;
      m_object = __first->tracer.m_object;
      if ( m_object )
      {
        result->tracer.m_object = m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
    }
    --i;
    ++__first;
  }
  return result;
}


vostok::render::material_effects_entry *__usercall stlp_std::priv::__ucopy<vostok::render::material_effects_entry *,vostok::render::material_effects_entry *,int>@<eax>(
        vostok::render::material_effects_entry *__last@<eax>,
        vostok::render::material_effects_entry *__result@<ecx>,
        vostok::render::material_effects_entry *__first)
{
  vostok::render::material_effects_entry *v3; // edi
  int v4; // eax
  unsigned __int8 *m_buffer; // esi
  unsigned int v6; // ebp
  unsigned __int8 *m_begin; // [esp-Ch] [ebp-1Ch]
  int __n; // [esp+Ch] [ebp-4h]
  vostok::render::material_effects_entry *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  __cur = __result;
  __n = v4;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->m_material_name.m_string.m_buffer;
    do
    {
      if ( __result )
      {
        __result->m_material_effects_instance_ptr = v3->m_material_effects_instance_ptr;
        v6 = v3->m_material_name.m_string.m_end - v3->m_material_name.m_string.m_begin;
        m_begin = (unsigned __int8 *)v3->m_material_name.m_string.m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        memcpy(m_buffer, m_begin, v6);
        __result = __cur;
        *((_DWORD *)m_buffer - 2) += v6;
        **((_BYTE **)m_buffer - 2) = 0;
        v4 = __n;
        m_buffer[260] = 47;
      }
      --v4;
      ++__result;
      ++v3;
      m_buffer += 280;
      __cur = __result;
      __n = v4;
    }
    while ( v4 > 0 );
  }
  return __result;
}


survarium::scheduler::record *__usercall stlp_std::priv::__ucopy<survarium::scheduler::record *,survarium::scheduler::record *,int>@<eax>(
        survarium::scheduler::record *__first@<ecx>,
        survarium::scheduler::record *__last@<eax>,
        survarium::scheduler::record *__result)
{
  survarium::scheduler::record *v4; // edi
  int i; // ebp
  boost::detail::function::vtable_base *vtable; // eax

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
    {
      __result->m_id = v4->m_id;
      __result->m_callback.vtable = 0;
      vtable = v4->m_callback.vtable;
      if ( vtable )
      {
        __result->m_callback.vtable = vtable;
        if ( ((unsigned __int8)vtable & 1) != 0 )
        {
          *(_QWORD *)&__result->m_callback.functor.obj_ptr = *(_QWORD *)&v4->m_callback.functor.obj_ptr;
          *((_QWORD *)&__result->m_callback.functor.data + 1) = *((_QWORD *)&v4->m_callback.functor.data + 1);
          *((_QWORD *)&__result->m_callback.functor.data + 2) = *((_QWORD *)&v4->m_callback.functor.data + 2);
        }
        else
        {
          (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
            &v4->m_callback.functor,
            &__result->m_callback.functor,
            0);
        }
      }
      *(_QWORD *)&__result->survarium::scheduler::scheduler_record = v4->survarium::scheduler::scheduler_record;
      __result->m_last_update_time = v4->m_last_update_time;
    }
    --i;
    ++v4;
  }
  return __result;
}


vostok::render::requested_streamable_texture *__usercall stlp_std::priv::__ucopy<vostok::render::requested_streamable_texture *,vostok::render::requested_streamable_texture *,int>@<eax>(
        vostok::render::requested_streamable_texture *__first@<ecx>,
        vostok::render::requested_streamable_texture *__last@<eax>,
        vostok::render::requested_streamable_texture *__result)
{
  const vostok::render::requested_streamable_texture *v4; // edi
  int i; // ebx

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      vostok::render::requested_streamable_texture::requested_streamable_texture(__result, v4);
    --i;
    ++v4;
  }
  return __result;
}


vostok::render::shadow_vertex *__usercall stlp_std::priv::__ucopy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex *,int>@<eax>(
        vostok::render::shadow_vertex *__last@<ecx>,
        vostok::render::shadow_vertex *__result@<eax>,
        vostok::render::shadow_vertex *__first)
{
  vostok::render::shadow_vertex *v3; // esi
  int v4; // edi
  vostok::math::float3 *p_object_position; // edx
  vostok::math::float3 *v6; // ecx

  v3 = __first;
  v4 = __last - __first;
  if ( v4 > 0 )
  {
    p_object_position = &__result->object_position;
    v6 = &__first->object_position;
    do
    {
      if ( __result )
      {
        *(_QWORD *)&__result->position.x = *(_QWORD *)&v3->position.x;
        __result->position.z = v3->position.z;
        *(_QWORD *)&p_object_position->x = *(_QWORD *)&v6->x;
        p_object_position->z = v6->z;
        p_object_position[1].x = v6[1].x;
        p_object_position[1].y = v6[1].y;
      }
      --v4;
      ++v3;
      v6 = (vostok::math::float3 *)((char *)v6 + 32);
      ++__result;
      p_object_position = (vostok::math::float3 *)((char *)p_object_position + 32);
    }
    while ( v4 > 0 );
  }
  return __result;
}


vostok::render::signature_layout_pair *__fastcall stlp_std::priv::__ucopy<vostok::render::signature_layout_pair *,vostok::render::signature_layout_pair *,int>(
        vostok::render::signature_layout_pair *__last,
        vostok::render::signature_layout_pair *__first,
        vostok::render::signature_layout_pair *__result)
{
  vostok::render::signature_layout_pair *result; // eax
  int i; // esi
  vostok::render::res_input_layout *m_object; // ecx
  const vostok::render::res_signature *v6; // ecx

  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    if ( result )
    {
      result->input_layout.m_object = 0;
      m_object = __first->input_layout.m_object;
      if ( __first->input_layout.m_object )
      {
        result->input_layout.m_object = m_object;
        ++m_object->m_reference_count;
      }
      result->signature.m_object = 0;
      v6 = __first->signature.m_object;
      if ( v6 )
      {
        result->signature.m_object = v6;
        ++v6->m_reference_count;
      }
    }
    --i;
    ++__first;
  }
  return result;
}


vostok::render::streamable_texture_info *__usercall stlp_std::priv::__ucopy<vostok::render::streamable_texture_info *,vostok::render::streamable_texture_info *,int>@<eax>(
        vostok::render::streamable_texture_info *__last@<eax>,
        vostok::render::streamable_texture_info *__result@<ecx>,
        vostok::render::streamable_texture_info *__first)
{
  const vostok::render::streamable_texture_info *v3; // ebx
  int i; // esi

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      vostok::render::streamable_texture_info::streamable_texture_info(__result, v3);
    --i;
    ++v3;
  }
  return __result;
}


vostok::render::streaming_ready_texture *__usercall stlp_std::priv::__ucopy<vostok::render::streaming_ready_texture *,vostok::render::streaming_ready_texture *,int>@<eax>(
        vostok::render::streaming_ready_texture *__first@<ecx>,
        vostok::render::streaming_ready_texture *__last@<eax>,
        vostok::render::streaming_ready_texture *__result)
{
  const vostok::render::streaming_ready_texture *v4; // edi
  int i; // ebx

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      vostok::render::streaming_ready_texture::streaming_ready_texture(__result, v4);
    --i;
    ++v4;
  }
  return __result;
}


vostok::render::texture_named_instance *__usercall stlp_std::priv::__ucopy<vostok::render::texture_named_instance *,vostok::render::texture_named_instance *,int>@<eax>(
        vostok::render::texture_named_instance *__last@<eax>,
        vostok::render::texture_named_instance *__result@<ecx>,
        vostok::render::texture_named_instance *__first)
{
  vostok::render::texture_named_instance *v3; // edi
  int v4; // ebx
  unsigned __int8 *m_buffer; // esi
  unsigned int v6; // ebp
  unsigned __int8 *m_begin; // [esp-Ch] [ebp-18h]
  vostok::render::texture_named_instance *__cur; // [esp+10h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->path.m_buffer;
    do
    {
      if ( __result )
      {
        __result->texture = v3->texture;
        v6 = v3->path.m_end - v3->path.m_begin;
        m_begin = (unsigned __int8 *)v3->path.m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        memcpy(m_buffer, m_begin, v6);
        __result = __cur;
        *((_DWORD *)m_buffer - 2) += v6;
        **((_BYTE **)m_buffer - 2) = 0;
      }
      ++__result;
      --v4;
      ++v3;
      m_buffer += 276;
      __cur = __result;
    }
    while ( v4 > 0 );
  }
  return __result;
}


vostok::render::effect_compiler::texture_query_desc *__usercall stlp_std::priv::__ucopy<vostok::render::effect_compiler::texture_query_desc *,vostok::render::effect_compiler::texture_query_desc *,int>@<eax>(
        vostok::render::effect_compiler::texture_query_desc *__last@<eax>,
        vostok::render::effect_compiler::texture_query_desc *__result@<ecx>,
        vostok::render::effect_compiler::texture_query_desc *__first)
{
  vostok::render::effect_compiler::texture_query_desc *v3; // edi
  int v4; // ebx
  vostok::render::effect_compiler::texture_query_desc *v5; // ebp
  char *m_buffer; // esi
  unsigned __int8 *m_begin; // ecx
  unsigned int v9; // [esp-4h] [ebp-18h]
  unsigned int v10; // [esp+10h] [ebp-4h]
  vostok::render::effect_compiler::texture_query_desc *__cur; // [esp+18h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  v5 = __result;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = __result->m_query_physicaly_path.m_buffer;
    do
    {
      if ( v5 )
      {
        m_begin = (unsigned __int8 *)v3->m_query_physicaly_path.m_begin;
        v9 = v3->m_query_physicaly_path.m_end - v3->m_query_physicaly_path.m_begin;
        v5->m_query_physicaly_path.m_begin = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        v10 = v9;
        memcpy((unsigned __int8 *)m_buffer, m_begin, v9);
        *((_DWORD *)m_buffer - 2) += v10;
        **((_BYTE **)m_buffer - 2) = 0;
        *((_DWORD *)m_buffer + 65) = v3->m_mip_level_cut;
        v5 = __cur;
        *((_DWORD *)m_buffer + 66) = v3->m_num_last_mips_used;
      }
      ++v5;
      --v4;
      ++v3;
      m_buffer += 280;
      __cur = v5;
    }
    while ( v4 > 0 );
  }
  return v5;
}


vostok::ui::typed_handlers *__usercall stlp_std::priv::__ucopy<vostok::ui::typed_handlers *,vostok::ui::typed_handlers *,int>@<eax>(
        vostok::ui::typed_handlers *__last@<eax>,
        vostok::ui::typed_handlers *__result@<ecx>,
        vostok::ui::typed_handlers *__first)
{
  vostok::ui::typed_handlers *v3; // edi
  int v4; // ebp
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> **p_M_finish; // ebx
  stlp_std::priv::_STLP_alloc_proxy<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > > *p_M_end_of_storage; // esi
  vostok::memory::base_allocator *v7; // eax
  int v8; // edi
  int *v9; // eax
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v10; // eax
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *v11; // eax
  vostok::ui::typed_handlers *__cur; // [esp+8h] [ebp-Ch]
  int v14; // [esp+Ch] [ebp-8h] BYREF
  int v15; // [esp+10h] [ebp-4h] BYREF

  v3 = __first;
  v4 = __last - __first;
  __cur = __result;
  if ( v4 > 0 )
  {
    p_M_finish = &__first->list._M_impl._M_finish;
    p_M_end_of_storage = &__result->list._M_impl._M_end_of_storage;
    do
    {
      if ( __result )
      {
        __result->type = v3->type;
        v7 = (vostok::memory::base_allocator *)p_M_finish[1];
        v8 = *p_M_finish - *(p_M_finish - 1);
        p_M_end_of_storage[-1].m_allocator = 0;
        p_M_end_of_storage[-1]._M_data = 0;
        p_M_end_of_storage->m_allocator = v7;
        p_M_end_of_storage->_M_data = 0;
        v15 = v8;
        v14 = 1;
        v9 = &v14;
        if ( v8 )
          v9 = &v15;
        v10 = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)((int (__stdcall *)(_DWORD, int))p_M_end_of_storage->m_allocator->call_realloc)(
                                                                                          0,
                                                                                          8 * *v9);
        p_M_end_of_storage[-1].m_allocator = (vostok::memory::base_allocator *)v10;
        p_M_end_of_storage[-1]._M_data = v10;
        p_M_end_of_storage->_M_data = &v10[v8];
        v11 = stlp_std::priv::__ucopy<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)> *,int>(
                *p_M_finish,
                *(p_M_finish - 1),
                v10);
        __result = __cur;
        v3 = __first;
        p_M_end_of_storage[-1]._M_data = v11;
      }
      ++v3;
      ++__result;
      --v4;
      p_M_finish += 5;
      p_M_end_of_storage = (stlp_std::priv::_STLP_alloc_proxy<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *,fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,vostok::vectora_allocator<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> > > *)((char *)p_M_end_of_storage + 20);
      __first = v3;
      __cur = __result;
    }
    while ( v4 > 0 );
  }
  return __result;
}


vostok::render::ui::vertex *__usercall stlp_std::priv::__ucopy<vostok::render::ui::vertex *,vostok::render::ui::vertex *,int>@<eax>(
        const vostok::render::ui::vertex *__last@<eax>,
        vostok::render::ui::vertex *__result@<ecx>,
        vostok::render::ui::vertex *__first)
{
  vostok::render::ui::vertex *v3; // esi
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      *__result = *v3;
    --i;
    ++v3;
  }
  return __result;
}


vostok::render::culling::aab_rect *__fastcall stlp_std::priv::__ucopy<vostok::render::culling::aab_rect *,vostok::render::culling::aab_rect *,int>(
        vostok::render::culling::aab_rect *__first,
        vostok::render::culling::aab_rect *__last,
        vostok::render::culling::aab_rect *__result)
{
  vostok::render::culling::aab_rect *result; // eax
  int i; // edx

  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    if ( result )
      *result = *__first;
    --i;
    ++__first;
  }
  return result;
}


vostok::render::shader_constant_binding *__usercall stlp_std::priv::__ucopy<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding *,int>@<eax>(
        vostok::render::shader_constant_binding *__last@<eax>,
        vostok::render::shader_constant_binding *__result@<ecx>,
        vostok::render::shader_constant_binding *__first)
{
  vostok::render::shader_constant_binding *v3; // esi
  int i; // eax
  vostok::strings::shared::profile *m_object; // edx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
    {
      __result->m_source.m_pointer = v3->m_source.m_pointer;
      __result->m_source.m_size = v3->m_source.m_size;
      __result->m_name.m_pointer.m_object = 0;
      m_object = v3->m_name.m_pointer.m_object;
      if ( m_object )
      {
        __result->m_name.m_pointer.m_object = m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      __result->m_type = v3->m_type;
      __result->m_class_id = v3->m_class_id;
    }
    --i;
    ++v3;
  }
  return __result;
}


vostok::fixed_string<260> *__usercall stlp_std::priv::__ucopy<vostok::fixed_string<260> *,vostok::fixed_string<260> *,int>@<eax>(
        vostok::fixed_string<260> *__last@<eax>,
        vostok::fixed_string<260> *__result@<ecx>,
        vostok::fixed_string<260> *__first)
{
  vostok::fixed_string<260> *v3; // ebx
  int v4; // edi
  vostok::fixed_string<260> *v5; // ebp
  unsigned __int8 *m_buffer; // esi
  unsigned __int8 *m_begin; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ebp
  vostok::fixed_string<260> *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  v5 = __result;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->m_buffer;
    do
    {
      if ( v5 )
      {
        m_begin = (unsigned __int8 *)v3->m_begin;
        v8 = v3->m_end - v3->m_begin;
        v5->m_begin = (char *)m_buffer;
        v9 = v8;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        memcpy(m_buffer, m_begin, v8);
        *((_DWORD *)m_buffer - 2) += v9;
        v5 = __cur;
        **((_BYTE **)m_buffer - 2) = 0;
      }
      ++v5;
      --v4;
      ++v3;
      m_buffer += 272;
      __cur = v5;
    }
    while ( v4 > 0 );
  }
  return v5;
}


vostok::fixed_string<32> *__usercall stlp_std::priv::__ucopy<vostok::fixed_string<32> *,vostok::fixed_string<32> *,int>@<eax>(
        vostok::fixed_string<32> *__last@<eax>,
        vostok::fixed_string<32> *__result@<ecx>,
        vostok::fixed_string<32> *__first)
{
  vostok::fixed_string<32> *v3; // ebx
  int v4; // edi
  vostok::fixed_string<32> *v5; // ebp
  unsigned __int8 *m_buffer; // esi
  unsigned __int8 *m_begin; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ebp
  vostok::fixed_string<32> *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  v5 = __result;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->m_buffer;
    do
    {
      if ( v5 )
      {
        m_begin = (unsigned __int8 *)v3->m_begin;
        v8 = v3->m_end - v3->m_begin;
        v5->m_begin = (char *)m_buffer;
        v9 = v8;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 32;
        memcpy(m_buffer, m_begin, v8);
        *((_DWORD *)m_buffer - 2) += v9;
        v5 = __cur;
        **((_BYTE **)m_buffer - 2) = 0;
      }
      ++v5;
      --v4;
      ++v3;
      m_buffer += 44;
      __cur = v5;
    }
    while ( v4 > 0 );
  }
  return v5;
}


vostok::fixed_vector<unsigned int,32> *__cdecl stlp_std::priv::__ucopy<vostok::fixed_vector<unsigned int,32> *,vostok::fixed_vector<unsigned int,32> *,int>(
        vostok::fixed_vector<unsigned int,32> *__first,
        vostok::fixed_vector<unsigned int,32> *__last,
        vostok::fixed_vector<unsigned int,32> *__result)
{
  stlp_std::__false_type v4; // [esp+26h] [ebp-Ah] BYREF
  char v5; // [esp+27h] [ebp-9h]
  int __n; // [esp+28h] [ebp-8h]
  vostok::fixed_vector<unsigned int,32> *__cur; // [esp+2Ch] [ebp-4h]

  __cur = __result;
  for ( __n = __last - __first; __n > 0; --__n )
  {
    v5 = 0;
    v4 = 0;
    stlp_std::_Param_Construct_aux<vostok::fixed_vector<unsigned int,32>,vostok::fixed_vector<unsigned int,32>>(
      __cur++,
      __first++,
      &v4);
  }
  return __cur;
}


boost::shared_ptr<boost::asio::detail::win_mutex> *__cdecl stlp_std::priv::__ucopy<boost::shared_ptr<boost::asio::detail::win_mutex> *,boost::shared_ptr<boost::asio::detail::win_mutex> *,int>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *__first,
        boost::shared_ptr<boost::asio::detail::win_mutex> *__last,
        boost::shared_ptr<boost::asio::detail::win_mutex> *__result)
{
  stlp_std::__false_type v4; // [esp+Eh] [ebp-Ah] BYREF
  char v5; // [esp+Fh] [ebp-9h]
  int __n; // [esp+10h] [ebp-8h]
  boost::shared_ptr<boost::asio::detail::win_mutex> *__cur; // [esp+14h] [ebp-4h]

  __cur = __result;
  for ( __n = __last - __first; __n > 0; --__n )
  {
    v5 = 0;
    v4 = 0;
    stlp_std::_Copy_Construct_aux<boost::shared_ptr<boost::asio::detail::win_mutex>>(__cur++, __first++, &v4);
  }
  return __cur;
}


vostok::render::shader_constant *__usercall stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>@<eax>(
        const vostok::render::shader_constant *__last@<eax>,
        vostok::render::shader_constant *__result@<ecx>,
        vostok::render::shader_constant *__first)
{
  vostok::render::shader_constant *v3; // esi
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    if ( __result )
      *__result = *v3;
    --i;
    ++v3;
  }
  return __result;
}


vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__ucopy<vostok::fs_new::virtual_path_string const *,vostok::fs_new::virtual_path_string *,int>@<eax>(
        vostok::fs_new::virtual_path_string *__last@<eax>,
        vostok::fs_new::virtual_path_string *__result@<ecx>,
        vostok::fs_new::virtual_path_string *__first)
{
  vostok::fs_new::virtual_path_string *v3; // ebp
  int v4; // eax
  vostok::fs_new::virtual_path_string *v5; // edi
  unsigned __int8 *m_buffer; // esi
  unsigned __int8 *m_begin; // ecx
  unsigned int v8; // ebx
  int __n; // [esp+Ch] [ebp-4h]
  vostok::fs_new::virtual_path_string *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  v5 = __result;
  __cur = __result;
  __n = v4;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->m_string.m_buffer;
    do
    {
      if ( v5 )
      {
        m_begin = (unsigned __int8 *)v3->m_string.m_begin;
        v8 = v3->m_string.m_end - v3->m_string.m_begin;
        v5->m_string.m_begin = (char *)m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        memcpy(m_buffer, m_begin, v8);
        *((_DWORD *)m_buffer - 2) += v8;
        **((_BYTE **)m_buffer - 2) = 0;
        v4 = __n;
        m_buffer[260] = 47;
        v5 = __cur;
      }
      --v4;
      ++v5;
      ++v3;
      m_buffer += 276;
      __cur = v5;
      __n = v4;
    }
    while ( v4 > 0 );
  }
  return v5;
}


wchar_t *__cdecl stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(
        wchar_t *__first,
        const wchar_t *__last,
        wchar_t *__result)
{
  wchar_t *v3; // edx
  wchar_t *result; // eax
  int i; // ecx

  v3 = __first;
  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    *result = *v3;
    --i;
    ++v3;
  }
  return result;
}
