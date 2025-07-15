// attributes: thunk
char *__thiscall stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  return stlp_std::allocator<char>::_M_allocate(this, __n, __allocated_n);
}


unsigned __int16 *__usercall stlp_std::priv::_STLP_alloc_proxy<unsigned short *,unsigned short,vostok::render::std_allocator<unsigned short>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<unsigned short *,unsigned short,vostok::render::std_allocator<unsigned short> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  m_object = vostok::render::g_allocator.m_object;
  v7 = 2 * v5;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v7 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v7 )
    return (unsigned __int16 *)vostok_mspace_malloc((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v7);
  else
    return 0;
}


unsigned int *__thiscall stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::ai::std_allocator<unsigned int>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (unsigned int *)vostok::memory::doug_lea_allocator::realloc_impl(vostok::ai::g_allocator, 0, 4 * *v3);
}


float *__thiscall stlp_std::priv::_STLP_alloc_proxy<float *,float,vostok::vectora_allocator<float>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<float *,float,vostok::vectora_allocator<float> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  int *v4; // [esp+0h] [ebp-18h]
  _DWORD v5[2]; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  char v7; // [esp+17h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  v5[0] = __n;
  v6 = 1;
  if ( __n )
    v4 = v5;
  else
    v4 = &v6;
  v5[1] = v4;
  return (float *)vostok::memory::base_allocator::realloc_impl(this->m_allocator, 0, 4 * *v4);
}


void **__thiscall stlp_std::priv::_STLP_alloc_proxy<void * *,void *,stlp_std::allocator<void *>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,stlp_std::allocator<void *> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  void *v3; // eax
  unsigned int v6; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  if ( __n > 0x3FFFFFFF )
  {
    puts("out of memory\n");
    exit(1);
  }
  if ( !__n )
    return 0;
  v6 = 4 * __n;
  v3 = stlp_std::__node_alloc::allocate(&v6);
  *__allocated_n = v6 >> 2;
  return (void **)v3;
}


void **__usercall stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::input::std_allocator<void *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::input::std_allocator<void *> > *this)
{
  bool v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  v6 = vostok::input::g_allocator;
  v7 = 4 * v5;
  if ( !vostok::input::g_allocator->m_out_of_memory || !v7 )
    v2 = 0;
  vostok::input::g_allocator->m_out_of_memory = v2;
  if ( v7 )
    return (void **)vostok_mspace_malloc(v6->m_arena, v7);
  else
    return 0;
}


void **__usercall stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::resources::std_allocator<void *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::resources::std_allocator<void *> > *this)
{
  bool v2; // cf
  unsigned int *v3; // eax
  void **result; // eax
  int v5; // [esp+0h] [ebp-8h] BYREF
  unsigned int v6; // [esp+4h] [ebp-4h] BYREF

  v6 = __n;
  v2 = __n == 0;
  v5 = 1;
  v3 = (unsigned int *)&v5;
  if ( !v2 )
    v3 = &v6;
  result = (void **)(4 * *v3);
  if ( vostok::memory::g_resources_helper_allocator.m_out_of_memory )
  {
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 1;
    if ( result )
      return (void **)vostok_mspace_malloc(vostok::memory::g_resources_helper_allocator.m_arena, (unsigned int)result);
  }
  vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
  if ( result )
    return (void **)vostok_mspace_malloc(vostok::memory::g_resources_helper_allocator.m_arena, (unsigned int)result);
  return result;
}


const void **__userpurge stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *>>::allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int *__allocated_n@<ecx>,
        stlp_std::priv::_STLP_alloc_proxy<void const * *,void const *,vostok::vectora_allocator<void const *> > *this)
{
  bool v3; // cf
  unsigned int *v4; // eax
  int v6; // [esp+0h] [ebp-8h] BYREF
  unsigned int v7; // [esp+4h] [ebp-4h] BYREF

  *__allocated_n = __n;
  v7 = __n;
  v3 = __n == 0;
  v6 = 1;
  v4 = (unsigned int *)&v6;
  if ( !v3 )
    v4 = &v7;
  return (const void **)((int (__stdcall *)(_DWORD, unsigned int))this->m_allocator->call_realloc)(0, 4 * *v4);
}


D3D11_INPUT_ELEMENT_DESC *__usercall stlp_std::priv::_STLP_alloc_proxy<D3D11_INPUT_ELEMENT_DESC *,D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<D3D11_INPUT_ELEMENT_DESC *,D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // esi
  int v8; // [esp+0h] [ebp-8h] BYREF
  unsigned int v9; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v9 = __n;
  v3 = __n == 0;
  v8 = 1;
  v4 = (unsigned int *)&v8;
  if ( !v3 )
    v4 = &v9;
  v5 = 28 * *v4;
  m_object = vostok::render::g_allocator.m_object;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v5 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v5 )
    return (D3D11_INPUT_ELEMENT_DESC *)vostok_mspace_malloc(
                                         (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                         v5);
  else
    return 0;
}


vostok::render::frond_vertex *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::frond_vertex *,vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::frond_vertex *,vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // esi
  int v8; // [esp+0h] [ebp-8h] BYREF
  unsigned int v9; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v9 = __n;
  v3 = __n == 0;
  v8 = 1;
  v4 = (unsigned int *)&v8;
  if ( !v3 )
    v4 = &v9;
  v5 = 56 * *v4;
  m_object = vostok::render::g_allocator.m_object;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v5 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v5 )
    return (vostok::render::frond_vertex *)vostok_mspace_malloc(
                                             (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                             v5);
  else
    return 0;
}


survarium::game_material_manager_cook::query_ext_data *__thiscall stlp_std::priv::_STLP_alloc_proxy<survarium::hit_receiver_info *,survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<survarium::game_material_manager_cook::query_ext_data *,survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (survarium::game_material_manager_cook::query_ext_data *)vostok::memory::doug_lea_allocator::realloc_impl(
                                                                    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                                                    0,
                                                                    12 * *v3);
}


vostok::logging::initiator_filter *__thiscall stlp_std::priv::_STLP_alloc_proxy<vostok::logging::initiator_filter *,vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<vostok::logging::initiator_filter *,vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v8; // [esp+13h] [ebp-1h]

  v8 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (vostok::logging::initiator_filter *)vostok::memory::base_allocator::realloc_impl(
                                                this->m_allocator,
                                                0,
                                                60 * *v3);
}


vostok::render::leafcard_vertex *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::leafcard_vertex *,vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::leafcard_vertex *,vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // esi
  int v8; // [esp+0h] [ebp-8h] BYREF
  unsigned int v9; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v9 = __n;
  v3 = __n == 0;
  v8 = 1;
  v4 = (unsigned int *)&v8;
  if ( !v3 )
    v4 = &v9;
  v5 = 60 * *v4;
  m_object = vostok::render::g_allocator.m_object;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v5 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v5 )
    return (vostok::render::leafcard_vertex *)vostok_mspace_malloc(
                                                (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                                v5);
  else
    return 0;
}


vostok::render::leafmesh_vertex *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  m_object = vostok::render::g_allocator.m_object;
  v7 = v5 << 6;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v7 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v7 )
    return (vostok::render::leafmesh_vertex *)vostok_mspace_malloc(
                                                (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                                v7);
  else
    return 0;
}


survarium::relocate_item_descr *__usercall stlp_std::priv::_STLP_alloc_proxy<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<survarium::relocate_item_descr *,survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  int v5; // ecx
  int f; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = 3 * *v4;
  f = (int)survarium::g_allocator.f_.f_;
  v7 = 8 * v5;
  if ( !*(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) || !v7 )
    v2 = 0;
  *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = v2;
  if ( v7 )
    return (survarium::relocate_item_descr *)vostok_mspace_malloc(*(void **)(f + 20), v7);
  else
    return 0;
}


vostok::render::shadow_vertex *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::shadow_vertex *,vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  m_object = vostok::render::g_allocator.m_object;
  v7 = 32 * v5;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v7 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v7 )
    return (vostok::render::shadow_vertex *)vostok_mspace_malloc(
                                              (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                              v7);
  else
    return 0;
}


vostok::sound::sound_voice_params *__thiscall stlp_std::priv::_STLP_alloc_proxy<vostok::sound::sound_voice_params *,vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<vostok::sound::sound_voice_params *,vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  int *v4; // [esp+0h] [ebp-18h]
  _DWORD v5[2]; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  char v7; // [esp+17h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  v5[0] = __n;
  v6 = 1;
  if ( __n )
    v4 = v5;
  else
    v4 = &v6;
  v5[1] = v4;
  return (vostok::sound::sound_voice_params *)vostok::memory::base_allocator::realloc_impl(
                                                this->m_allocator,
                                                0,
                                                12 * *v4);
}


vostok::render::trample_desc *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // esi
  int v8; // [esp+0h] [ebp-8h] BYREF
  unsigned int v9; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v9 = __n;
  v3 = __n == 0;
  v8 = 1;
  v4 = (unsigned int *)&v8;
  if ( !v3 )
    v4 = &v9;
  v5 = 20 * *v4;
  m_object = vostok::render::g_allocator.m_object;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v5 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v5 )
    return (vostok::render::trample_desc *)vostok_mspace_malloc(
                                             (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                             v5);
  else
    return 0;
}


vostok::render::vertex_colored *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  m_object = vostok::render::g_allocator.m_object;
  v7 = 16 * v5;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v7 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v7 )
    return (vostok::render::vertex_colored *)vostok_mspace_malloc(
                                               (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                               v7);
  else
    return 0;
}


vostok::math::float3 *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,survarium::std_allocator<vostok::math::float3>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::math::float3 *,vostok::math::float3,survarium::std_allocator<vostok::math::float3> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  int v5; // ecx
  int f; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = 3 * *v4;
  f = (int)survarium::g_allocator.f_.f_;
  v7 = 4 * v5;
  if ( !*(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) || !v7 )
    v2 = 0;
  *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = v2;
  if ( v7 )
    return (vostok::math::float3 *)vostok_mspace_malloc(*(void **)(f + 20), v7);
  else
    return 0;
}


stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::math::frustum *,vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // esi
  int v8; // [esp+0h] [ebp-8h] BYREF
  unsigned int v9; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v9 = __n;
  v3 = __n == 0;
  v8 = 1;
  v4 = (unsigned int *)&v8;
  if ( !v3 )
    v4 = &v9;
  v5 = 120 * *v4;
  m_object = vostok::render::g_allocator.m_object;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v5 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v5 )
    return (stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *)vostok_mspace_malloc(
                                                                                   (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                                                                   v5);
  else
    return 0;
}


vostok::ai::planning::operator_pair *__thiscall stlp_std::priv::_STLP_alloc_proxy<vostok::ai::planning::operator_pair *,vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<vostok::ai::planning::operator_pair *,vostok::ai::planning::operator_pair,vostok::ai::std_allocator<vostok::ai::planning::operator_pair> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (vostok::ai::planning::operator_pair *)vostok::memory::doug_lea_allocator::realloc_impl(
                                                  vostok::ai::g_allocator,
                                                  0,
                                                  8 * *v3);
}


vostok::render::streaming_texture_instance *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // esi
  int v8; // [esp+0h] [ebp-8h] BYREF
  unsigned int v9; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v9 = __n;
  v3 = __n == 0;
  v8 = 1;
  v4 = (unsigned int *)&v8;
  if ( !v3 )
    v4 = &v9;
  v5 = 24 * *v4;
  m_object = vostok::render::g_allocator.m_object;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v5 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v5 )
    return (vostok::render::streaming_texture_instance *)vostok_mspace_malloc(
                                                           (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                                           v5);
  else
    return 0;
}


vostok::fixed_string<16> *__thiscall stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_string<16> *,vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16>>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_string<16> *,vostok::fixed_string<16>,survarium::std_allocator<vostok::fixed_string<16> > > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (vostok::fixed_string<16> *)vostok::memory::doug_lea_allocator::realloc_impl(
                                       (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                       0,
                                       28 * *v3);
}


vostok::fixed_string<260> *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_string<260> *,vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260>>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_string<260> *,vostok::fixed_string<260>,vostok::render::std_allocator<vostok::fixed_string<260> > > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  m_object = vostok::render::g_allocator.m_object;
  v7 = 272 * v5;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v7 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v7 )
    return (vostok::fixed_string<260> *)vostok_mspace_malloc(
                                          (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                          v7);
  else
    return 0;
}


vostok::fixed_string<32> *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_string<32> *,vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_string<32> *,vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32> > > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  m_object = vostok::render::g_allocator.m_object;
  v7 = 44 * v5;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v7 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v7 )
    return (vostok::fixed_string<32> *)vostok_mspace_malloc(
                                         (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                         v7);
  else
    return 0;
}


vostok::fixed_vector<unsigned int,32> *__thiscall stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_vector<unsigned int,32> *,vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<vostok::fixed_vector<unsigned int,32> *,vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  int *v4; // [esp+0h] [ebp-18h]
  _DWORD v5[2]; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  char v7; // [esp+17h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  v5[0] = __n;
  v6 = 1;
  if ( __n )
    v4 = v5;
  else
    v4 = &v6;
  v5[1] = v4;
  return (vostok::fixed_vector<unsigned int,32> *)vostok::memory::base_allocator::realloc_impl(
                                                    this->m_allocator,
                                                    0,
                                                    136 * *v4);
}


vostok::variant<32> *__thiscall stlp_std::priv::_STLP_alloc_proxy<vostok::variant<32> *,vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<vostok::variant<32> *,vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (vostok::variant<32> *)vostok::memory::doug_lea_allocator::realloc_impl(
                                  (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                  0,
                                  48 * *v3);
}


vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *__usercall stlp_std::priv::_STLP_alloc_proxy<enum survarium::game_action_id *,enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  int f; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  f = (int)survarium::g_allocator.f_.f_;
  v7 = 4 * v5;
  if ( !*(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) || !v7 )
    v2 = 0;
  *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = v2;
  if ( v7 )
    return (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)vostok_mspace_malloc(*(void **)(f + 20), v7);
  else
    return 0;
}


unsigned __int64 *__thiscall stlp_std::priv::_STLP_alloc_proxy<unsigned __int64 *,unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<unsigned __int64 *,unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  int *v4; // [esp+0h] [ebp-18h]
  _DWORD v5[2]; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  char v7; // [esp+17h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  v5[0] = __n;
  v6 = 1;
  if ( __n )
    v4 = v5;
  else
    v4 = &v6;
  v5[1] = v4;
  return (unsigned __int64 *)vostok::memory::base_allocator::realloc_impl(this->m_allocator, 0, 8 * *v4);
}
