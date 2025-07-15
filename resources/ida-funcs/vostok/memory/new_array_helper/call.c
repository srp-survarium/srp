unsigned int *__usercall vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<esi>)
{
  _DWORD *v2; // eax
  unsigned int *result; // eax
  unsigned int *v4; // edx
  unsigned int *i; // ecx

  v2 = allocator->call_malloc(allocator, 4 * count + 8);
  *v2 = count;
  result = v2 + 2;
  *(result - 1) = 4;
  v4 = &result[count];
  for ( i = result; i != v4; ++i )
  {
    if ( i )
      *i = 0;
  }
  return result;
}


vostok::ui::progress_bar **__cdecl vostok::memory::new_array_helper<vostok::ui::progress_bar *>::call<vostok::memory::base_allocator>(
        vostok::memory::base_allocator *allocator,
        unsigned int count)
{
  unsigned int *v2; // eax
  unsigned int *i; // [esp+8h] [ebp-Ch]

  v2 = (unsigned int *)vostok::memory::base_allocator::malloc_impl(allocator, 4 * count + 8);
  *v2 = count;
  v2[1] = 4;
  for ( i = v2 + 2; i != &v2[count + 2]; ++i )
  {
    if ( i )
      *i = 0;
  }
  return (vostok::ui::progress_bar **)(v2 + 2);
}


Opcode::AABBCollisionNode *__usercall vostok::memory::new_array_helper<Opcode::AABBCollisionNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  Opcode::AABBCollisionNode *result; // eax
  Opcode::AABBCollisionNode *i; // ecx

  v2 = (char *)allocator->call_malloc(allocator, 28 * count + 8);
  *(_DWORD *)v2 = count;
  result = (Opcode::AABBCollisionNode *)(v2 + 8);
  result[-1].mData = 28;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      i->mData = 0;
  }
  return result;
}


Opcode::AABBNoLeafNode *__usercall vostok::memory::new_array_helper<Opcode::AABBNoLeafNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  Opcode::AABBNoLeafNode *result; // eax
  Opcode::AABBNoLeafNode *i; // ecx

  v2 = (char *)allocator->call_malloc(allocator, 32 * count + 8);
  *(_DWORD *)v2 = count;
  result = (Opcode::AABBNoLeafNode *)(v2 + 8);
  result[-1].mNegData = 32;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
    {
      i->mPosData = 0;
      i->mNegData = 0;
    }
  }
  return result;
}


Opcode::AABBQuantizedNode *__usercall vostok::memory::new_array_helper<Opcode::AABBQuantizedNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  Opcode::AABBQuantizedNode *result; // eax
  Opcode::AABBQuantizedNode *i; // ecx

  v2 = (char *)allocator->call_malloc(allocator, 16 * count + 8);
  *(_DWORD *)v2 = count;
  result = (Opcode::AABBQuantizedNode *)(v2 + 8);
  result[-1].mData = 16;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      i->mData = 0;
  }
  return result;
}


Opcode::AABBQuantizedNoLeafNode *__usercall vostok::memory::new_array_helper<Opcode::AABBQuantizedNoLeafNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  Opcode::AABBQuantizedNoLeafNode *result; // eax
  Opcode::AABBQuantizedNoLeafNode *i; // ecx

  v2 = (char *)allocator->call_malloc(allocator, 20 * count + 8);
  *(_DWORD *)v2 = count;
  result = (Opcode::AABBQuantizedNoLeafNode *)(v2 + 8);
  result[-1].mNegData = 20;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
    {
      i->mPosData = 0;
      i->mNegData = 0;
    }
  }
  return result;
}


Opcode::AABBTreeNode *__usercall vostok::memory::new_array_helper<Opcode::AABBTreeNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        unsigned int count@<eax>)
{
  unsigned int v3; // esi
  char *v4; // eax
  Opcode::AABBTreeNode *result; // eax
  unsigned int **p_mNodePrimitives; // ecx

  v3 = count;
  v4 = (char *)allocator->call_malloc(allocator, 36 * count + 8);
  *(_DWORD *)v4 = count;
  v4 += 4;
  *(_DWORD *)v4 = 36;
  result = (Opcode::AABBTreeNode *)(v4 + 4);
  if ( result != &result[v3] )
  {
    p_mNodePrimitives = &result->mNodePrimitives;
    do
    {
      if ( p_mNodePrimitives != (unsigned int **)28 )
      {
        *(p_mNodePrimitives - 1) = 0;
        *p_mNodePrimitives = 0;
        p_mNodePrimitives[1] = 0;
      }
      p_mNodePrimitives += 9;
    }
    while ( p_mNodePrimitives - 7 != (unsigned int **)&result[v3] );
  }
  return result;
}


char *__cdecl vostok::memory::new_array_helper<char>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator,
        unsigned int count)
{
  char *v2; // eax
  char *b; // [esp+Ch] [ebp-4h]

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, count + 8);
  *(_DWORD *)v2 = count;
  *((_DWORD *)v2 + 1) = 1;
  b = v2 + 8;
  vostok::memory::detail::call_constructor<char>(v2 + 8, &v2[count + 8]);
  return b;
}


unsigned __int8 *__usercall vostok::memory::new_array_helper<unsigned char>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<esi>)
{
  char *v2; // eax
  unsigned __int8 *result; // eax
  unsigned __int8 *i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, count + 8);
  *(_DWORD *)v2 = count;
  result = (unsigned __int8 *)(v2 + 8);
  *((_DWORD *)result - 1) = 1;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      *i = 0;
  }
  return result;
}


unsigned int *__cdecl vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator,
        unsigned int count)
{
  unsigned int *v2; // eax
  unsigned int *b; // [esp+Ch] [ebp-4h]

  v2 = (unsigned int *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 4 * count + 8);
  *v2 = count;
  v2[1] = 4;
  b = v2 + 2;
  vostok::memory::detail::call_constructor<unsigned int>(v2 + 2, &v2[count + 2]);
  return b;
}


float *__usercall vostok::memory::new_array_helper<float>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<esi>)
{
  char *v2; // eax
  float *result; // eax
  float *v4; // edx
  float *i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 4 * count + 8);
  *(_DWORD *)v2 = count;
  result = (float *)(v2 + 8);
  *((_DWORD *)result - 1) = 4;
  v4 = &result[count];
  for ( i = result; i != v4; ++i )
  {
    if ( i )
      *i = 0.0;
  }
  return result;
}


vostok::render::grass_layer_desc **__usercall vostok::memory::new_array_helper<survarium::options_item_base *>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<esi>)
{
  char *v2; // eax
  vostok::render::grass_layer_desc **result; // eax
  vostok::render::grass_layer_desc **v4; // edx
  vostok::render::grass_layer_desc **i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 4 * count + 8);
  *(_DWORD *)v2 = count;
  result = (vostok::render::grass_layer_desc **)(v2 + 8);
  *(result - 1) = (vostok::render::grass_layer_desc *)4;
  v4 = &result[count];
  for ( i = result; i != v4; ++i )
  {
    if ( i )
      *i = 0;
  }
  return result;
}


vostok::render::lod_entry *__usercall vostok::memory::new_array_helper<vostok::render::lod_entry>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        unsigned int count@<eax>)
{
  vostok::render::lod_entry *v3; // eax
  vostok::render::lod_entry *result; // eax
  vostok::render::lod_entry *v5; // edx
  vostok::render::lod_entry *i; // ecx

  v3 = (vostok::render::lod_entry *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 8 * count + 8);
  v3->start_index = count;
  result = v3 + 1;
  result[-1].num_indices = 8;
  v5 = &result[count];
  for ( i = result; i != v5; ++i )
  {
    if ( i )
    {
      i->start_index = 0;
      i->num_indices = 0;
    }
  }
  return result;
}


vostok::render::render_surface_instance *__usercall vostok::memory::new_array_helper<vostok::render::render_surface_instance>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        unsigned int count@<eax>)
{
  unsigned int v3; // esi
  char *v4; // eax
  vostok::render::render_surface_instance *result; // eax
  const vostok::math::float4x4 *v6; // xmm0_4
  float *p_m_dynamic_screen_factor; // ecx

  v3 = count;
  v4 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 28 * count + 8);
  *(_DWORD *)v4 = count;
  v4 += 4;
  *(_DWORD *)v4 = 28;
  result = (vostok::render::render_surface_instance *)(v4 + 4);
  if ( result != &result[v3] )
  {
    v6 = clear_value;
    p_m_dynamic_screen_factor = &result->m_dynamic_screen_factor;
    do
    {
      if ( p_m_dynamic_screen_factor != (float *)16 )
      {
        *(p_m_dynamic_screen_factor - 1) = NAN;
        *(_DWORD *)p_m_dynamic_screen_factor = v6;
        *((_BYTE *)p_m_dynamic_screen_factor + 8) = 0;
        *((_BYTE *)p_m_dynamic_screen_factor + 9) = 0;
      }
      p_m_dynamic_screen_factor += 7;
    }
    while ( p_m_dynamic_screen_factor - 4 != (float *)&result[v3] );
  }
  return result;
}


survarium::render_visual *__usercall vostok::memory::new_array_helper<survarium::render_visual>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  survarium::render_visual *result; // eax
  survarium::render_visual *i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 68 * count + 8);
  *(_DWORD *)v2 = count;
  result = (survarium::render_visual *)(v2 + 8);
  result[-1].model.m_object = (vostok::render::static_model_instance *)68;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      i->model.m_object = 0;
  }
  return result;
}


survarium::static_collision *__usercall vostok::memory::new_array_helper<survarium::static_collision>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  survarium::static_collision *result; // eax
  survarium::static_collision *i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 76 * count + 8);
  *(_DWORD *)v2 = count;
  result = (survarium::static_collision *)(v2 + 8);
  result[-1].physics_rigid_body_ = (vostok::physics::bt_static_rigid_body *)76;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      i->shape_.m_object = 0;
  }
  return result;
}


vostok::math::float2 *__thiscall vostok::memory::new_array_helper<vostok::math::float2>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator)
{
  char *v1; // eax
  vostok::math::float2 *result; // eax
  vostok::math::float2 *v3; // ecx
  float v4; // xmm0_4

  v1 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 0x328u);
  *(_DWORD *)v1 = 100;
  result = (vostok::math::float2 *)(v1 + 8);
  LODWORD(result[-1].y) = 8;
  v3 = result;
  v4 = SNaN;
  do
  {
    if ( v3 )
    {
      v3->x = v4;
      v3->y = v4;
    }
    ++v3;
  }
  while ( v3 != &result[100] );
  return result;
}


vostok::fixed_string<64> *__usercall vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  vostok::fixed_string<64> *result; // eax
  char *m_buffer; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 76 * count + 8);
  *(_DWORD *)v2 = count;
  v2 += 4;
  *(_DWORD *)v2 = 76;
  result = (vostok::fixed_string<64> *)(v2 + 4);
  if ( result != &result[count] )
  {
    m_buffer = result->m_buffer;
    do
    {
      if ( m_buffer != (char *)12 )
      {
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 64;
        *m_buffer = 0;
        *m_buffer = 0;
      }
      m_buffer += 76;
    }
    while ( m_buffer - 12 != (char *)&result[count] );
  }
  return result;
}
