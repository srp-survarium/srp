void __userpurge vostok::buffer_vector<vostok::render::shader_constant_host *>::insert(
        vostok::buffer_vector<vostok::render::shader_constant_host *> *this@<ecx>,
        int a2@<esi>,
        vostok::render::shader_constant_host **const *where,
        _DWORD *count,
        vostok::render::shader_constant_host *const *value)
{
  vostok::render::shader_constant_host **v5; // eax
  _DWORD *v6; // edx
  vostok::render::shader_constant_host **v7; // ecx
  vostok::render::shader_constant_host **v8; // edi
  _DWORD *i; // eax
  const char *v10; // [esp+0h] [ebp-10h]
  bool v11; // [esp+Fh] [ebp-1h] BYREF

  if ( (unsigned int)(*(_DWORD *)(a2 + 4) + 4) > *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::shader_constant_host *>::insert'::`15'::debug_macro_helper_ignore_always )
  {
    v11 = 0;
    vostok::debug::on_error(
      &v11,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::render::shader_constant_host *>::insert",
      (const char *)0xE6,
      "buffer overflow",
      v10);
    if ( vostok::debug::is_debugger_present() || v11 )
      __debugbreak();
  }
  v5 = *(vostok::render::shader_constant_host ***)(a2 + 4);
  v6 = *where;
  v7 = v5 - 1;
  v8 = *where - 1;
  while ( v7 != v8 )
  {
    if ( v5 )
      *v5 = *v7;
    --v7;
    --v5;
  }
  *(_DWORD *)(a2 + 4) += 4;
  for ( i = v6; i != v6 + 1; ++i )
  {
    if ( i )
      *i = *count;
  }
}


void __userpurge vostok::buffer_vector<vostok::render::data_indexer>::insert(
        vostok::buffer_vector<vostok::render::data_indexer> *this@<ecx>,
        int a2@<eax>,
        vostok::render::data_indexer *const *where,
        _DWORD *count,
        const vostok::render::data_indexer *value)
{
  unsigned int **v6; // eax
  _DWORD *v7; // edx
  vostok::render::data_indexer *v8; // ecx
  vostok::render::data_indexer *v9; // edi
  _DWORD *v10; // eax
  const char *v11; // [esp+0h] [ebp-10h]
  bool v12; // [esp+Fh] [ebp-1h] BYREF

  if ( (unsigned int)(*(_DWORD *)(a2 + 4) + 8) > *(_DWORD *)(a2 + 8)
    && !`vostok::buffer_vector<vostok::render::data_indexer>::insert'::`15'::debug_macro_helper_ignore_always )
  {
    v12 = 0;
    vostok::debug::on_error(
      &v12,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::data_indexer>::insert",
      (const char *)0xE6,
      "buffer overflow",
      v11);
    if ( vostok::debug::is_debugger_present() || v12 )
      __debugbreak();
  }
  v6 = *(unsigned int ***)(a2 + 4);
  v7 = *where;
  v8 = (vostok::render::data_indexer *)(v6 - 2);
  v9 = *where - 1;
  while ( v8 != v9 )
  {
    if ( v6 )
    {
      *v6 = v8->data_ptr;
      v6[1] = (unsigned int *)v8->class_id;
    }
    --v8;
    v6 -= 2;
  }
  *(_DWORD *)(a2 + 4) += 8;
  v10 = v7;
  do
  {
    if ( v10 )
    {
      *v10 = *count;
      v10[1] = count[1];
    }
    v10 += 2;
  }
  while ( v10 != v7 + 2 );
}


void __thiscall vostok::buffer_vector<vostok::render::light_data>::insert(
        vostok::buffer_vector<vostok::render::light_data> *this,
        vostok::render::light_data *const *where,
        vostok::render::light ***count,
        const vostok::render::light_data *value)
{
  vostok::render::light_data *const *v4; // esi
  char **v5; // eax
  vostok::render::light *v6; // ecx
  char **v7; // ebx
  char *v8; // edx
  char *v9; // edx
  char *v11; // edi
  vostok::memory::doug_lea_allocator *v12; // ecx
  vostok::render::light **v13; // eax
  vostok::render::light **v14; // esi
  vostok::render::light *m_object; // ecx
  const char *v16; // [esp+0h] [ebp-1Ch]
  const char *v17; // [esp+4h] [ebp-18h]
  unsigned int v18; // [esp+8h] [ebp-14h]
  vostok::render::light *v19; // [esp+Ch] [ebp-10h]
  vostok::memory::doug_lea_allocator *v20; // [esp+10h] [ebp-Ch]
  char **v21; // [esp+14h] [ebp-8h]
  bool v22; // [esp+1Bh] [ebp-1h] BYREF

  v4 = where;
  if ( (unsigned int)(*((_DWORD *)where + 1) + 8) > *((_DWORD *)where + 2)
    && !BYTE2(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[3]) )
  {
    v22 = 0;
    vostok::debug::on_error(
      &v22,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::light_data>::insert",
      (const char *)0xE6,
      "buffer overflow",
      v16);
    if ( vostok::debug::is_debugger_present() || v22 )
      __debugbreak();
  }
  v5 = (char **)*((_DWORD *)where + 1);
  v6 = (vostok::render::light *)(*count - 2);
  v7 = v5 - 2;
  v19 = v6;
  while ( 1 )
  {
    v21 = v5;
    if ( v7 == (char **)v6 )
      break;
    if ( v5 )
    {
      *v5 = 0;
      v8 = *v7;
      if ( *v7 )
      {
        *v5 = v8;
        ++*(_DWORD *)v8;
      }
      v5[1] = v7[1];
    }
    v9 = *v7;
    if ( *v7 )
    {
      if ( (*(_DWORD *)v9)-- == 1 )
      {
        v11 = *v7;
        v20 = vostok::render::g_allocator;
        if ( *v7 )
        {
          vostok::render::light::remove_collision(v6, (int)v11);
          `vector destructor iterator'(
            v11 + 724,
            4u,
            6,
            (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
          `vector destructor iterator'(
            v11 + 700,
            4u,
            6,
            (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
          vostok::memory::doug_lea_allocator::free_impl(v12, (int)v20, v11, v16, v17, v18);
          v5 = v21;
          v4 = where;
          v6 = v19;
        }
      }
    }
    v7 -= 2;
    v5 -= 2;
  }
  v13 = *count;
  *((_DWORD *)v4 + 1) += 8;
  v14 = v13 + 2;
  while ( v13 != v14 )
  {
    if ( v13 )
    {
      *v13 = 0;
      m_object = value->light.m_object;
      if ( value->light.m_object )
      {
        *v13 = m_object;
        ++m_object->m_reference_count;
      }
      v13[1] = (vostok::render::light *)value->id;
    }
    v13 += 2;
  }
}


void __thiscall vostok::buffer_vector<vostok::memory::platform::region>::insert(
        vostok::buffer_vector<vostok::memory::platform::region> *this,
        vostok::memory::platform::region *const *where,
        _DWORD *count,
        const vostok::memory::platform::region *value)
{
  vostok::memory::platform::region *const *v4; // ebx
  _DWORD *v5; // ecx
  _DWORD *v6; // edx
  int v7; // eax
  _DWORD **v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  const vostok::memory::platform::region *v11; // esi
  const char *v12; // [esp+0h] [ebp-Ch]

  v4 = where;
  if ( (unsigned int)(*((_DWORD *)where + 1) + 16) > *((_DWORD *)where + 2)
    && !`vostok::buffer_vector<vostok::memory::platform::region>::insert'::`15'::debug_macro_helper_ignore_always )
  {
    HIBYTE(where) = 0;
    vostok::debug::on_error(
      (bool *)&where + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::memory::platform::region>::insert",
      (const char *)0xE6,
      "buffer overflow",
      v12);
    if ( vostok::debug::is_debugger_present() || HIBYTE(where) )
      __debugbreak();
  }
  v5 = (_DWORD *)*((_DWORD *)v4 + 1);
  v6 = v5 - 4;
  v7 = *count - 16;
  while ( v6 != (_DWORD *)v7 )
  {
    if ( v5 )
    {
      *v5 = *v6;
      v5[1] = v6[1];
      v5[2] = v6[2];
      v5[3] = v6[3];
    }
    v6 -= 4;
    v5 -= 4;
  }
  v8 = (_DWORD **)count;
  *((_DWORD *)v4 + 1) += 16;
  v9 = *v8;
  v10 = v9 + 4;
  while ( v9 != v10 )
  {
    if ( v9 )
    {
      v11 = value;
      *v9 = value->size;
      v11 = (const vostok::memory::platform::region *)((char *)v11 + 4);
      v9[1] = v11->size;
      v11 = (const vostok::memory::platform::region *)((char *)v11 + 4);
      v9[2] = v11->size;
      v9[3] = HIDWORD(v11->size);
    }
    v9 += 4;
  }
}


void __thiscall vostok::buffer_vector<vostok::render::signature_layout_pair>::insert(
        vostok::buffer_vector<vostok::render::signature_layout_pair> *this,
        vostok::render::signature_layout_pair *const *where,
        int *count,
        const vostok::render::signature_layout_pair *value)
{
  vostok::render::signature_layout_pair *const *v4; // ebx
  int v5; // edi
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int v9; // esi
  const vostok::render::signature_layout_pair *v10; // edi
  vostok::render::res_input_layout *m_object; // eax
  const vostok::render::res_signature *v12; // edi
  const char *v13; // [esp+0h] [ebp-Ch]

  v4 = where;
  if ( (unsigned int)(*((_DWORD *)where + 1) + 8) > *((_DWORD *)where + 2)
    && !`vostok::buffer_vector<vostok::render::signature_layout_pair>::insert'::`15'::debug_macro_helper_ignore_always )
  {
    HIBYTE(where) = 0;
    vostok::debug::on_error(
      (bool *)&where + 3,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::signature_layout_pair>::insert",
      (const char *)0xE6,
      "buffer overflow",
      v13);
    if ( vostok::debug::is_debugger_present() || HIBYTE(where) )
      __debugbreak();
  }
  v5 = *((_DWORD *)v4 + 1);
  v6 = v5 - 8;
  where = (vostok::render::signature_layout_pair *const *)(*count - 8);
  if ( (vostok::render::signature_layout_pair *const *)(v5 - 8) != where )
  {
    do
    {
      if ( v5 )
      {
        *(_DWORD *)v5 = 0;
        if ( *(_DWORD *)v6 )
        {
          vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v5);
          v7 = *(_DWORD **)v6;
          *(_DWORD *)v5 = *(_DWORD *)v6;
          if ( v7 )
            ++*v7;
        }
        *(_DWORD *)(v5 + 4) = 0;
        if ( *(_DWORD *)(v6 + 4) )
        {
          vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *)(v5 + 4));
          v8 = *(_DWORD **)(v6 + 4);
          *(_DWORD *)(v5 + 4) = v8;
          if ( v8 )
            ++*v8;
        }
      }
      vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *)(v6 + 4));
      vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v6);
      v6 -= 8;
      v5 -= 8;
    }
    while ( (vostok::render::signature_layout_pair *const *)v6 != where );
  }
  v9 = *count;
  *((_DWORD *)v4 + 1) += 8;
  count = (int *)(v9 + 8);
  do
  {
    if ( v9 )
    {
      v10 = value;
      *(_DWORD *)v9 = 0;
      if ( v10->input_layout.m_object )
      {
        vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v9);
        m_object = v10->input_layout.m_object;
        *(_DWORD *)v9 = v10->input_layout.m_object;
        if ( m_object )
          ++m_object->m_reference_count;
      }
      *(_DWORD *)(v9 + 4) = 0;
      if ( v10->signature.m_object )
      {
        vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *)(v9 + 4));
        v12 = v10->signature.m_object;
        *(_DWORD *)(v9 + 4) = v12;
        if ( v12 )
          ++v12->m_reference_count;
      }
    }
    v9 += 8;
  }
  while ( (int *)v9 != count );
}


void __userpurge vostok::buffer_vector<vostok::memory::platform::region>::insert<vostok::memory::platform::region *>(
        vostok::memory::platform::region *const *end@<eax>,
        vostok::buffer_vector<vostok::memory::platform::region> *this,
        vostok::memory::platform::region **where,
        vostok::memory::platform::region *begin)
{
  vostok::buffer_vector<vostok::memory::platform::region> *v4; // esi
  int v5; // ebx
  vostok::memory::platform::region *m_end; // eax
  vostok::memory::platform::region *v7; // edx
  vostok::memory::platform::region *v8; // ecx
  vostok::memory::platform::region *v9; // eax
  vostok::memory::platform::region *v10; // eax
  vostok::memory::platform::region *v11; // ebx
  const char *v12; // [esp+0h] [ebp-14h]
  bool do_debug_break; // [esp+13h] [ebp-1h] BYREF

  v4 = this;
  v5 = *end - begin;
  if ( &this->m_end[v5] > this->m_max_end
    && !`vostok::buffer_vector<vostok::memory::platform::region>::insert<vostok::memory::platform::region *>'::`15'::debug_macro_helper_ignore_always )
  {
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::memory::platform::region>::insert",
      (const char *)0xCD,
      "buffer overflow",
      v12);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  m_end = this->m_end;
  v7 = &m_end[v5 - 1];
  v8 = m_end - 1;
  v9 = *where - 1;
  while ( v8 != v9 )
  {
    if ( v7 )
    {
      LODWORD(v7->size) = v8->size;
      HIDWORD(v7->size) = HIDWORD(v8->size);
      v7->address = v8->address;
      v7->data = v8->data;
      v4 = this;
    }
    --v8;
    --v7;
  }
  v4->m_end = (vostok::memory::platform::region *)((char *)v4->m_end + v5 * 16);
  v10 = *where;
  v11 = &(*where)[v5];
  while ( v10 != v11 )
  {
    if ( v10 )
      *v10 = *begin;
    ++v10;
    ++begin;
  }
}


void __userpurge vostok::buffer_vector<vostok::render::vertex_colored>::insert<vostok::render::vertex_colored const *>(
        const vostok::render::vertex_colored *const *end@<eax>,
        vostok::buffer_vector<vostok::render::vertex_colored> *this,
        vostok::render::vertex_colored **where,
        const vostok::render::vertex_colored *begin)
{
  vostok::buffer_vector<vostok::render::vertex_colored> *v4; // esi
  int v5; // ebx
  vostok::render::vertex_colored *m_end; // eax
  _DWORD *p_x; // edx
  vostok::render::vertex_colored *v8; // ecx
  vostok::render::vertex_colored *v9; // eax
  vostok::render::vertex_colored *v10; // eax
  vostok::render::vertex_colored *v11; // ebx
  const char *v12; // [esp+0h] [ebp-10h]
  bool v13; // [esp+Fh] [ebp-1h] BYREF

  v4 = this;
  v5 = *end - begin;
  if ( &this->m_end[v5] > this->m_max_end
    && !`vostok::buffer_vector<vostok::render::vertex_colored>::insert<vostok::render::vertex_colored const *>'::`15'::debug_macro_helper_ignore_always )
  {
    v13 = 0;
    vostok::debug::on_error(
      &v13,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<struct vostok::render::vertex_colored>::insert",
      (const char *)0xCD,
      "buffer overflow",
      v12);
    if ( vostok::debug::is_debugger_present() || v13 )
      __debugbreak();
  }
  m_end = this->m_end;
  p_x = (_DWORD *)&m_end[v5 - 1].position.x;
  v8 = m_end - 1;
  v9 = *where - 1;
  while ( v8 != v9 )
  {
    if ( p_x )
    {
      *p_x = LODWORD(v8->position.x);
      p_x[1] = LODWORD(v8->position.y);
      p_x[2] = LODWORD(v8->position.z);
      p_x[3] = v8->color.m_value;
      v4 = this;
    }
    --v8;
    p_x -= 4;
  }
  v4->m_end = (vostok::render::vertex_colored *)((char *)v4->m_end + v5 * 16);
  v10 = *where;
  v11 = &(*where)[v5];
  while ( v10 != v11 )
  {
    if ( v10 )
      *v10 = *begin;
    ++v10;
    ++begin;
  }
}


void __userpurge vostok::buffer_vector<vostok::math::float3>::insert<vostok::math::float3 const *>(
        const vostok::math::float3 *const *end@<eax>,
        vostok::buffer_vector<vostok::math::float3> *this,
        vostok::math::float3 **where,
        const vostok::math::float3 *begin)
{
  vostok::buffer_vector<vostok::math::float3> *v4; // esi
  int v5; // ebx
  vostok::math::float3 *m_end; // eax
  _DWORD *p_x; // edx
  vostok::math::float3 *v8; // ecx
  vostok::math::float3 *v9; // eax
  vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // ebx
  const char *v12; // [esp+0h] [ebp-14h]
  bool v13; // [esp+13h] [ebp-1h] BYREF

  v4 = this;
  v5 = *end - begin;
  if ( &this->m_end[v5] > this->m_max_end
    && !`vostok::buffer_vector<vostok::math::float3>::insert<vostok::math::float3 const *>'::`15'::debug_macro_helper_ignore_always )
  {
    v13 = 0;
    vostok::debug::on_error(
      &v13,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
      "vostok::buffer_vector<class vostok::math::float3>::insert",
      (const char *)0xCD,
      "buffer overflow",
      v12);
    if ( vostok::debug::is_debugger_present() || v13 )
      __debugbreak();
  }
  m_end = this->m_end;
  p_x = (_DWORD *)&m_end[v5 - 1].x;
  v8 = m_end - 1;
  v9 = *where - 1;
  while ( v8 != v9 )
  {
    if ( p_x )
    {
      *p_x = LODWORD(v8->x);
      p_x[1] = LODWORD(v8->y);
      p_x[2] = LODWORD(v8->z);
      v4 = this;
    }
    --v8;
    p_x -= 3;
  }
  v4->m_end = (vostok::math::float3 *)((char *)v4->m_end + v5 * 12);
  v10 = *where;
  v11 = &(*where)[v5];
  while ( v10 != v11 )
  {
    if ( v10 )
      *v10 = *begin;
    ++v10;
    ++begin;
  }
}
