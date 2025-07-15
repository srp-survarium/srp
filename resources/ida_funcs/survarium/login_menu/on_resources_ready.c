void __thiscall survarium::login_menu::on_resources_ready(
        survarium::login_menu *this,
        vostok::resources::queries_result *data)
{
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v4; // eax
  vostok::resources::unmanaged_intrusive_base *v5; // ecx
  vostok::configs::binary_config *v6; // esi
  vostok::configs::binary_config *v7; // eax
  vostok::resources::unmanaged_intrusive_base *v8; // ecx
  vostok::configs::binary_config *v9; // edi
  vostok::configs::binary_config *v10; // esi
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *p_m_login_menu_ui; // ebx
  vostok::configs::binary_config *v12; // eax
  survarium::flash_movie_resource *v13; // ecx
  vostok::resources::unmanaged_resource *v14; // eax
  vostok::configs::binary_config *v15; // esi
  vostok::configs::binary_config *v16; // edi
  vostok::configs::binary_config *v17; // eax
  vostok::configs::binary_config *v18; // ecx
  vostok::resources::unmanaged_resource *v19; // eax
  survarium::base_game_scene *v20; // edi
  int *v21; // esi
  vostok::configs::binary_config *v22; // edx
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Movie *v24; // ecx
  Scaleform::GFx::Movie *v25; // ecx
  int v26; // ecx
  int v27; // ecx
  survarium::base_game_scene *v28; // ecx
  survarium::login_menu *v29; // esi
  survarium::base_game_scene *v30; // ecx
  Scaleform::GFx::Movie *v31; // ecx
  survarium::login_menu *v32; // ecx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> v33; // eax
  survarium::game *v34; // ecx
  survarium::game *m_game; // esi
  bool v36; // zf
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v37; // [esp+1Ch] [ebp-24h] BYREF
  survarium::base_game_scene *v38; // [esp+20h] [ebp-20h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v39; // [esp+24h] [ebp-1Ch] BYREF
  survarium::flash_value v; // [esp+28h] [ebp-18h] BYREF

  v38 = this;
  v39.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v39,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v39.m_object;
  v37.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v37,
    v39.m_object);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene,
    (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&v37);
  v4 = v37.m_object;
  if ( v37.m_object )
  {
    v5 = &v37.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v37.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, v4);
  }
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  v39.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v39,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  v6 = v39.m_object;
  v37.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v37,
    v39.m_object);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_scene_view,
    (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&v37);
  v7 = v37.m_object;
  if ( v37.m_object )
  {
    v8 = &v37.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v37.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v8, v7);
  }
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  v37.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v37,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[2].m_unmanaged_resource);
  v9 = v37.m_object;
  v10 = 0;
  if ( v37.m_object )
  {
    v10 = v37.m_object;
    _InterlockedExchangeAdd(&v37.m_object->m_reference_count, 1u);
  }
  p_m_login_menu_ui = &this->m_login_menu_ui;
  v12 = 0;
  if ( v10 )
  {
    v12 = v10;
    _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
  }
  v13 = (survarium::flash_movie_resource *)v12;
  v14 = p_m_login_menu_ui->m_object;
  p_m_login_menu_ui->m_object = v13;
  if ( v14 )
  {
    if ( !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v14->vostok::resources::unmanaged_intrusive_base, v14);
    v9 = v37.m_object;
  }
  if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
  if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
  ((void (__stdcall *)(_DWORD))p_m_login_menu_ui->m_object->movie->m_movie->SetBackgroundAlpha)(0.0);
  v15 = 0;
  v39.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v39,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[3].m_unmanaged_resource);
  v16 = v39.m_object;
  if ( v39.m_object )
  {
    v15 = v39.m_object;
    _InterlockedExchangeAdd(&v39.m_object->m_reference_count, 1u);
  }
  v17 = 0;
  if ( v15 )
  {
    v17 = v15;
    _InterlockedExchangeAdd(&v15->m_reference_count, 1u);
  }
  v18 = v17;
  v19 = *(vostok::resources::unmanaged_resource **)&v38[1].gap10;
  *(_DWORD *)&v38[1].gap10 = v18;
  if ( v19 && !_InterlockedExchangeAdd(&v19->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v19->vostok::resources::unmanaged_intrusive_base, v19);
  if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
  if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v16->vostok::resources::unmanaged_intrusive_base, v16);
  v20 = v38;
  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(*(_DWORD *)&v38[1].gap10 + 264) + 4) + 128))(0.0);
  v21 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
          0x10u);
  if ( v21 )
  {
    v39.m_object = (vostok::configs::binary_config *)v20->m_game;
    survarium::flash_external_handler::flash_external_handler((survarium::flash_external_handler *)v39.m_object, v21);
    v22 = v39.m_object;
    *v21 = (int)&survarium::login_menu_external_handler::`vftable';
    v21[2] = (int)v22;
    v21[3] = (int)v20;
  }
  else
  {
    v21 = 0;
  }
  m_movie = p_m_login_menu_ui->m_object->movie->m_movie;
  m_movie->SetState(&m_movie->Scaleform::GFx::StateBag, State_ExternalInterface, (Scaleform::GFx::State *)v21[1]);
  v24 = p_m_login_menu_ui->m_object->movie->m_movie;
  v24->SetViewAlignment(v24, Align_Center);
  v25 = p_m_login_menu_ui->m_object->movie->m_movie;
  v25->SetViewScaleMode(v25, SM_NoScale);
  v26 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&v20[1].gap10 + 264) + 4);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v26 + 60))(v26, 5);
  v27 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&v20[1].gap10 + 264) + 4);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v27 + 52))(v27, 0);
  survarium::base_game_scene::show_movie(p_m_login_menu_ui, v28, v20);
  v29 = (survarium::login_menu *)v38;
  survarium::base_game_scene::show_movie(
    (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&v38[1].gap10,
    v30,
    v38);
  v31 = p_m_login_menu_ui->m_object->movie->m_movie;
  v31->ForceCollectGarbage(v31, 2u);
  survarium::login_menu::fill_labels(v32, v29);
  v33.m_object = p_m_login_menu_ui->m_object;
  *(_DWORD *)v.body = 0;
  *(_DWORD *)&v.body[4] = 2;
  v.body[8] = survarium::s_store_user_pass;
  Scaleform::GFx::Movie::SetVariable(
    v33.m_object->movie->m_movie,
    "root.save_checkbox.selected",
    (const Scaleform::GFx::Value *)&v,
    SV_Sticky);
  m_game = v29->m_game;
  v36 = !m_game->m_login_scene_ready;
  m_game->m_lobby_scene_ready = 1;
  if ( !v36 )
    survarium::game::create_network_client(v34, m_game, 0);
  if ( (v.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)v.body + 8))(
      *(_DWORD *)v.body,
      &v,
      *(_DWORD *)&v.body[8]);
}
