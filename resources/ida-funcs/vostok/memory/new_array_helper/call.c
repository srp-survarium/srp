unsigned int *__usercall vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<eax>,
        const unsigned int count@<esi>)
{
  char *v3; // eax
  _DWORD *v4; // eax
  unsigned int *result; // eax
  unsigned int *v6; // ecx
  unsigned int *i; // edi

  v3 = type_info::raw_name(&unsigned int `RTTI Type Descriptor');
  v4 = allocator->call_malloc(allocator, 4 * count + 8, v3, "Opcode::AABBTree::Build", ".\\OPC_AABBTree.cpp", 437);
  *v4++ = count;
  *v4 = 4;
  result = v4 + 1;
  v6 = &result[count];
  for ( i = result; i != v6; ++i )
  {
    if ( i )
      *i = 0;
  }
  return result;
}


survarium::dictionary_item *__usercall vostok::memory::new_array_helper<survarium::dictionary_item>::call<vostok::memory::base_allocator>@<eax>(
        const unsigned int count@<eax>,
        vostok::memory::base_allocator *allocator)
{
  char *v3; // eax
  char *v4; // eax
  survarium::dictionary_item *result; // eax
  survarium::dictionary_item *v6; // esi
  char *m_buffer; // ecx

  v3 = type_info::raw_name(&survarium::dictionary_item `RTTI Type Descriptor');
  v4 = (char *)allocator->call_malloc(
                 allocator,
                 380 * count + 8,
                 v3,
                 "survarium::items_dictionary_cook::on_configs_loaded",
                 ".\\items_dictionary_cook.cpp",
                 93);
  *(_DWORD *)v4 = count;
  v4 += 4;
  *(_DWORD *)v4 = 380;
  result = (survarium::dictionary_item *)(v4 + 4);
  v6 = &result[count];
  if ( result != v6 )
  {
    m_buffer = result->item_cfg_name.m_buffer;
    do
    {
      if ( m_buffer != (char *)20 )
      {
        *((_DWORD *)m_buffer - 4) = 0;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        *m_buffer = 0;
      }
      m_buffer += 380;
    }
    while ( m_buffer - 20 != (char *)v6 );
  }
  return result;
}


Opcode::AABBCollisionNode *__usercall vostok::memory::new_array_helper<Opcode::AABBCollisionNode>::call<vostok::memory::base_allocator>@<eax>(
        unsigned int count@<eax>,
        vostok::memory::base_allocator *allocator,
        const char *function,
        const char *const file)
{
  char *v5; // eax
  unsigned int v6; // esi
  char *v7; // eax
  Opcode::AABBCollisionNode *result; // eax
  Opcode::AABBCollisionNode *v9; // ecx
  Opcode::AABBCollisionNode *v10; // edi

  v5 = type_info::raw_name(&Opcode::AABBCollisionNode `RTTI Type Descriptor');
  v6 = count;
  v7 = (char *)allocator->call_malloc(allocator, 28 * count + 8, v5, function, ".\\OPC_OptimizedTree.cpp", file);
  *(_DWORD *)v7 = count;
  v7 += 4;
  *(_DWORD *)v7 = 28;
  result = (Opcode::AABBCollisionNode *)(v7 + 4);
  v9 = &result[count];
  v10 = result;
  if ( result != &result[v6] )
  {
    do
    {
      if ( v10 )
        v10->mData = 0;
      ++v10;
    }
    while ( v10 != v9 );
  }
  return result;
}


Opcode::AABBNoLeafNode *__usercall vostok::memory::new_array_helper<Opcode::AABBNoLeafNode>::call<vostok::memory::base_allocator>@<eax>(
        unsigned int count@<eax>,
        vostok::memory::base_allocator *allocator,
        const char *function,
        const char *const file)
{
  char *v5; // eax
  unsigned int v6; // esi
  char *v7; // eax
  Opcode::AABBNoLeafNode *result; // eax
  Opcode::AABBNoLeafNode *v9; // ecx
  Opcode::AABBNoLeafNode *v10; // edi

  v5 = type_info::raw_name(&Opcode::AABBNoLeafNode `RTTI Type Descriptor');
  v6 = count;
  v7 = (char *)allocator->call_malloc(allocator, 32 * count + 8, v5, function, ".\\OPC_OptimizedTree.cpp", file);
  *(_DWORD *)v7 = count;
  v7 += 4;
  *(_DWORD *)v7 = 32;
  result = (Opcode::AABBNoLeafNode *)(v7 + 4);
  v9 = &result[count];
  v10 = result;
  if ( result != &result[v6] )
  {
    do
    {
      if ( v10 )
      {
        v10->mPosData = 0;
        v10->mNegData = 0;
      }
      ++v10;
    }
    while ( v10 != v9 );
  }
  return result;
}


Opcode::AABBQuantizedNode *__usercall vostok::memory::new_array_helper<Opcode::AABBQuantizedNode>::call<vostok::memory::base_allocator>@<eax>(
        unsigned int count@<eax>,
        vostok::memory::base_allocator *allocator)
{
  char *v3; // eax
  unsigned int v4; // esi
  char *v5; // eax
  Opcode::AABBQuantizedNode *result; // eax
  Opcode::AABBQuantizedNode *v7; // ecx
  Opcode::AABBQuantizedNode *v8; // edi

  v3 = type_info::raw_name(&Opcode::AABBQuantizedNode `RTTI Type Descriptor');
  v4 = count;
  v5 = (char *)allocator->call_malloc(
                 allocator,
                 16 * count + 8,
                 v3,
                 "Opcode::AABBQuantizedTree::Build",
                 ".\\OPC_OptimizedTree.cpp",
                 606);
  *(_DWORD *)v5 = count;
  v5 += 4;
  *(_DWORD *)v5 = 16;
  result = (Opcode::AABBQuantizedNode *)(v5 + 4);
  v7 = &result[count];
  v8 = result;
  if ( result != &result[v4] )
  {
    do
    {
      if ( v8 )
        v8->mData = 0;
      ++v8;
    }
    while ( v8 != v7 );
  }
  return result;
}


Opcode::AABBTreeNode *__usercall vostok::memory::new_array_helper<Opcode::AABBTreeNode>::call<vostok::memory::base_allocator>@<eax>(
        const unsigned int count@<eax>,
        vostok::memory::base_allocator *allocator,
        const char *function,
        const char *const file)
{
  char *v5; // eax
  char *v6; // eax
  Opcode::AABBTreeNode *result; // eax
  unsigned int **p_mNodePrimitives; // ecx

  v5 = type_info::raw_name(&Opcode::AABBTreeNode `RTTI Type Descriptor');
  v6 = (char *)allocator->call_malloc(allocator, 36 * count + 8, v5, function, ".\\OPC_AABBTree.cpp", file);
  *(_DWORD *)v6 = count;
  v6 += 4;
  *(_DWORD *)v6 = 36;
  result = (Opcode::AABBTreeNode *)(v6 + 4);
  if ( result != &result[count] )
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
    while ( p_mNodePrimitives - 7 != (unsigned int **)&result[count] );
  }
  return result;
}


vostok::resources::request *__cdecl vostok::memory::new_array_helper<vostok::resources::request>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator,
        const unsigned int count)
{
  char *v2; // eax
  vostok::memory::doug_lea_allocator *v3; // ecx
  char *v4; // eax
  char *v5; // esi
  vostok::render::stage_screen_space_reflections *v6; // ecx
  const char *v8; // [esp+0h] [ebp-Ch]
  const char *v9; // [esp+4h] [ebp-8h]
  unsigned int v10; // [esp+8h] [ebp-4h]

  v2 = type_info::raw_name(&vostok::resources::request `RTTI Type Descriptor');
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(v3, (int)allocator, 8 * count + 8, v2, v8, v9, v10);
  *(_DWORD *)v4 = count;
  v4 += 4;
  v5 = v4 + 4;
  *(_DWORD *)v4 = 8;
  vostok::memory::process_allocator::finalize_impl(v6);
  return (vostok::resources::request *)v5;
}
