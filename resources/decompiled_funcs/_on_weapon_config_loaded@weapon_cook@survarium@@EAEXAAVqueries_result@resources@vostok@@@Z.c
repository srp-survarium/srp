void __thiscall survarium::weapon_cook::on_weapon_config_loaded(
        survarium::weapon_cook *this,
        vostok::configs::binary_config *data)
{
  vostok::configs::binary_config *v2; // esi
  vostok::configs::binary_config_value *m_root; // ebx
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  const void *pointer; // eax
  vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // eax
  const void *v9; // eax
  int v10; // esi
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // eax
  unsigned int *v13; // eax
  survarium::items_dictionary *m_object; // ecx
  unsigned int v15; // esi
  void *v16; // esp
  int *v17; // edi
  vostok::configs::binary_config_value *v18; // eax
  const void *v19; // eax
  char *v20; // edi
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // esi
  int v23; // eax
  int v24; // edx
  vostok::configs::binary_config_value *v25; // eax
  const vostok::configs::binary_config_value *v26; // ebx
  int v27; // ecx
  int v28; // edx
  vostok::configs::binary_config_value *v29; // eax
  const vostok::configs::binary_config_value *v30; // esi
  int v31; // ecx
  int v32; // edx
  unsigned int v33; // ecx
  int v34; // eax
  int v35; // esi
  vostok::memory::doug_lea_allocator *v36; // eax
  vostok::configs::binary_config *v37; // ebx
  _DWORD *v38; // eax
  _DWORD *v39; // eax
  _DWORD *v40; // edx
  _DWORD *i; // ecx
  char v42; // dl
  vostok::memory::doug_lea_allocator *v43; // eax
  vostok::configs::binary_config *v44; // ebx
  _DWORD *v45; // eax
  _DWORD *v46; // eax
  _DWORD *v47; // edx
  _DWORD *j; // ecx
  bool v49; // zf
  unsigned __int8 v50; // dl
  vostok::configs::binary_config_value *v51; // ebx
  vostok::configs::binary_config_value *v52; // eax
  const void *v53; // eax
  vostok::configs::binary_config_value *v54; // eax
  const void *v55; // eax
  unsigned int v56; // edx
  void (__cdecl *v57)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v58; // eax
  vostok::resources::unmanaged_intrusive_base *v59; // ecx
  _BYTE v60[24]; // [esp-18h] [ebp-8Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v61; // [esp-4h] [ebp-78h]
  vostok::sound::sound_world *f; // [esp-4h] [ebp-78h]
  vostok::configs::binary_config *v63; // [esp-4h] [ebp-78h]
  int v64[2]; // [esp+0h] [ebp-74h] BYREF
  int v65; // [esp+8h] [ebp-6Ch] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+Ch] [ebp-68h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v67[3]; // [esp+2Ch] [ebp-48h] BYREF
  vostok::resources::unmanaged_resource *resource; // [esp+38h] [ebp-3Ch]
  boost::function1<void,vostok::resources::queries_result &> *v69; // [esp+3Ch] [ebp-38h]
  const vostok::resources::request *requests; // [esp+48h] [ebp-2Ch]
  vostok::resources::query_result_for_cook *parent; // [esp+4Ch] [ebp-28h]
  unsigned int first_view_death_animations_count; // [esp+54h] [ebp-20h]
  survarium::weapon_cook *a1; // [esp+58h] [ebp-1Ch]
  vostok::configs::binary_config *v74; // [esp+5Ch] [ebp-18h]
  vostok::configs::binary_config *v75; // [esp+60h] [ebp-14h]
  const vostok::configs::binary_config_value *first_view_animations; // [esp+64h] [ebp-10h]
  const vostok::configs::binary_config_value *config; // [esp+68h] [ebp-Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+6Ch] [ebp-8h] BYREF
  unsigned __int8 fire_pfx_count; // [esp+73h] [ebp-1h]

  a1 = this;
  parent = (vostok::resources::query_result_for_cook *)data->m_uid;
  v61 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(&data[1].m_reconstruction_size + 1);
  data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v61);
  v2 = data;
  config_ptr.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &config_ptr,
    data);
  if ( v2 && !_InterlockedExchangeAdd(&v2->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v2->vostok::resources::unmanaged_intrusive_base, v2);
  m_root = config_ptr.m_object->m_root;
  config = m_root;
  v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "particles");
  if ( vostok::configs::binary_config_value::value_exists(v4, "bullet_shells_count") )
  {
    v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "particles");
    pointer = vostok::configs::binary_config_value::operator[](v5, "bullet_shells_count")->data.pointer;
    requests = 0;
    HIBYTE(data) = (_BYTE)pointer;
  }
  else
  {
    HIBYTE(data) = 10;
  }
  v7 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "particles");
  if ( vostok::configs::binary_config_value::value_exists(v7, "shoot_pfx_count") )
  {
    v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "particles");
    v9 = vostok::configs::binary_config_value::operator[](v8, "shoot_pfx_count")->data.pointer;
    requests = 0;
    fire_pfx_count = (unsigned __int8)v9;
  }
  else
  {
    fire_pfx_count = 3;
  }
  v75 = (vostok::configs::binary_config *)HIBYTE(data);
  v74 = (vostok::configs::binary_config *)fire_pfx_count;
  first_view_animations = (const vostok::configs::binary_config_value *)(HIBYTE(data) + fire_pfx_count + 4);
  v10 = 0;
  if ( vostok::configs::binary_config_value::value_exists(m_root, "addons") )
  {
    v11 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "addons");
    if ( vostok::configs::binary_config_value::value_exists(v11, "rifle_scope_dict_id") )
    {
      v12 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "addons");
      v13 = (unsigned int *)vostok::configs::binary_config_value::operator[](v12, "rifle_scope_dict_id");
      m_object = a1->m_game->m_items_dictionary.m_object;
      v15 = *v13;
      requests = 0;
      v10 = *(_DWORD *)&survarium::items_dictionary::item_by_id(m_object, v15)[8].gap0;
    }
  }
  v16 = alloca(8 * ((_DWORD)first_view_animations + (v10 != 0)));
  v17 = v64;
  requests = (const vostok::resources::request *)v64;
  if ( v10 )
  {
    if ( v64 )
    {
      v64[0] = (int)"gameplay/items/scopes/leupold";
      v64[1] = 90;
    }
    v17 = &v65;
  }
  v18 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](m_root, "object");
  v19 = vostok::configs::binary_config_value::operator[](v18, "model")->data.pointer;
  if ( v17 )
  {
    *v17 = (int)v19;
    v17[1] = 20;
  }
  v20 = (char *)(v17 + 2);
  v21 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  m_root,
                                                  "user_animations_in_place");
  v22 = vostok::configs::binary_config_value::operator[](v21, "death_hud");
  v23 = 24 * v22->count / 24;
  first_view_animations = v22;
  if ( v23 )
  {
    v24 = 0;
    do
    {
      if ( v20 )
      {
        *(_DWORD *)v20 = *(_DWORD *)((char *)v22->data.pointer + v24);
        *((_DWORD *)v20 + 1) = 61;
      }
      v20 += 8;
      v24 += 24;
      --v23;
    }
    while ( v23 );
  }
  v25 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  m_root,
                                                  "user_animations_in_place");
  v26 = vostok::configs::binary_config_value::operator[](v25, "death");
  if ( 24 * v26->count / 24 )
  {
    v27 = 0;
    v28 = 24 * v26->count / 24;
    do
    {
      if ( v20 )
      {
        *(_DWORD *)v20 = *(_DWORD *)((char *)v26->data.pointer + v27);
        *((_DWORD *)v20 + 1) = 61;
      }
      v20 += 8;
      v27 += 24;
      --v28;
    }
    while ( v28 );
  }
  v29 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  (vostok::configs::binary_config_value *)config,
                                                  "user_animations_in_place");
  v30 = vostok::configs::binary_config_value::operator[](v29, "preview");
  if ( 24 * v30->count / 24 )
  {
    v31 = 0;
    v32 = 24 * v30->count / 24;
    do
    {
      if ( v20 )
      {
        *(_DWORD *)v20 = *(_DWORD *)((char *)v30->data.pointer + v31);
        *((_DWORD *)v20 + 1) = 61;
      }
      v20 += 8;
      v31 += 24;
      --v32;
    }
    while ( v32 );
  }
  first_view_death_animations_count = 24 * first_view_animations->count / 24;
  first_view_death_animations_count += ((int)((unsigned __int64)(17179869192LL * v26->count) >> 32) >> 2)
                                     + ((unsigned int)((unsigned __int64)(17179869192LL * v26->count) >> 32) >> 31);
  first_view_death_animations_count = (unsigned int)vostok::memory::doug_lea_allocator::malloc_impl(
                                                      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                                      4
                                                    * (((int)((unsigned __int64)(17179869192LL * v30->count) >> 32) >> 2)
                                                     + first_view_death_animations_count
                                                     + ((unsigned int)((unsigned __int64)(17179869192LL * v30->count) >> 32) >> 31))
                                                    + 4080);
  if ( first_view_death_animations_count )
  {
    v33 = 24 * v30->count / 24;
    survarium::weapon::weapon(
      (survarium::weapon *)v33,
      (survarium::weapon *)first_view_death_animations_count,
      24 * first_view_animations->count / 24,
      24 * v26->count / 24,
      v33);
    v35 = v34;
  }
  else
  {
    v35 = 0;
  }
  v36 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v37 = v75;
  v38 = vostok::memory::doug_lea_allocator::malloc_impl(v36, 4 * (_DWORD)v75 + 8);
  *v38 = v37;
  v39 = v38 + 2;
  *(v39 - 1) = 4;
  v40 = &v39[(_DWORD)v37];
  for ( i = v39; i != v40; ++i )
  {
    if ( i )
      *i = 0;
  }
  v42 = HIBYTE(data);
  *(_DWORD *)(v35 + 4012) = v39;
  f = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
  *(_BYTE *)(v35 + 4017) = v42;
  v43 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>(f);
  v44 = v74;
  v45 = vostok::memory::doug_lea_allocator::malloc_impl(v43, 4 * (_DWORD)v74 + 8);
  *v45 = v44;
  v46 = v45 + 2;
  *(v46 - 1) = 4;
  v47 = &v46[(_DWORD)v44];
  for ( j = v46; j != v47; ++j )
  {
    if ( j )
      *j = 0;
  }
  v49 = HIBYTE(data) == 0;
  v50 = fire_pfx_count;
  *(_DWORD *)(v35 + 4008) = v46;
  *(_BYTE *)(v35 + 4016) = v50;
  if ( v49 )
  {
    v51 = (vostok::configs::binary_config_value *)config;
  }
  else
  {
    data = v75;
    do
    {
      v51 = (vostok::configs::binary_config_value *)config;
      v52 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      (vostok::configs::binary_config_value *)config,
                                                      "particles");
      v53 = vostok::configs::binary_config_value::operator[](v52, "bullet_shells")->data.pointer;
      if ( v20 )
      {
        *(_DWORD *)v20 = v53;
        *((_DWORD *)v20 + 1) = 72;
      }
      v20 += 8;
      data = (vostok::configs::binary_config *)((char *)data - 1);
    }
    while ( data );
  }
  if ( fire_pfx_count )
  {
    first_view_death_animations_count = 72;
    data = v74;
    do
    {
      v54 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v51, "particles");
      v55 = vostok::configs::binary_config_value::operator[](v54, "shoot")->data.pointer;
      if ( v20 )
      {
        v56 = first_view_death_animations_count;
        *(_DWORD *)v20 = v55;
        *((_DWORD *)v20 + 1) = v56;
      }
      v20 += 8;
      data = (vostok::configs::binary_config *)((char *)data - 1);
    }
    while ( data );
  }
  v63 = config_ptr.m_object;
  _InterlockedExchangeAdd(&config_ptr.m_object->m_reference_count, 1u);
  boost::bind<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *,survarium::weapon_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon *>(
    (const vostok::configs::binary_config_value *)v35,
    v67,
    (void (__thiscall *__ptr64)(survarium::weapon_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>, survarium::weapon_core *))(unsigned int)survarium::weapon_cook::on_weapon_subresources_ready,
    a1,
    1_108,
    (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)v63);
  *(vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v60 = v67[0];
  *(vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v60[4] = v67[1];
  *(vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v60[8] = v67[2];
  *(_DWORD *)&v60[12] = 0;
  if ( resource )
  {
    *(_DWORD *)&v60[12] = resource;
    _InterlockedExchangeAdd(&resource->m_reference_count, 1u);
  }
  *(_DWORD *)&v60[16] = v69;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    v69,
    &callback,
    *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::weapon_core *>,boost::_bi::list4<boost::_bi::value<survarium::weapon_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::weapon *> > > *)v60,
    v64[0]);
  if ( resource && !_InterlockedExchangeAdd(&resource->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &resource->vostok::resources::unmanaged_intrusive_base,
      resource);
  vostok::resources::query_resources(
    requests,
    (v20 - (char *)requests) >> 3,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    parent,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v57 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v57 )
        v57(&callback.functor, &callback.functor, 2);
    }
  }
  v58 = config_ptr.m_object;
  v59 = &config_ptr.m_object->vostok::resources::unmanaged_intrusive_base;
  if ( !_InterlockedExchangeAdd(&config_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(v59, v58);
}
