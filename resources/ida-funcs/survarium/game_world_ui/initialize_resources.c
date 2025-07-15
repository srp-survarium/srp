void __userpurge survarium::game_world_ui::initialize_resources(
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *game_hud@<eax>,
        survarium::game_world_ui *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *cursor_ui,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *player_icons)
{
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *p_m_game_hud_ui; // ebx
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v6; // eax
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v7; // eax
  survarium::flash_movie *v8; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Movie *v10; // ecx
  survarium::flash_movie *v11; // ecx
  Scaleform::GFx::Movie *v12; // ecx
  Scaleform::GFx::Movie *v13; // ecx
  survarium::flash_movie *v14; // ecx
  Scaleform::GFx::Movie *v15; // ecx
  Scaleform::GFx::Movie *v16; // ecx
  survarium::base_network_client *m_network_client; // ecx
  survarium::chat_handler *v18; // ecx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> v19; // eax
  Scaleform::GFx::Movie *v20; // ecx
  survarium::flash_movie *v21; // ecx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> v22; // eax
  survarium::flash_value *v23; // ecx
  survarium::flash_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  char *v26[8]; // [esp+Ch] [ebp-70h]
  Scaleform::GFx::Value pvalue; // [esp+2Ch] [ebp-50h] BYREF
  Scaleform::GFx::Value v28; // [esp+44h] [ebp-38h] BYREF
  survarium::flash_value value; // [esp+5Ch] [ebp-20h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v30; // [esp+74h] [ebp-8h] BYREF
  unsigned int handler; // [esp+84h] [ebp+8h]

  p_m_game_hud_ui = &this->m_game_hud_ui;
  v5 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(game_hud, &v30);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v5,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_game_hud_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v30);
  v6 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(cursor_ui, (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cursor_ui);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v6,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_cursor_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cursor_ui);
  v7 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(player_icons, (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cursor_ui);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v7,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_player_icons_ui);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&cursor_ui);
  survarium::flash_movie::SetExternalInterface(this->m_game_hud_ui.m_object->movie, this);
  survarium::flash_movie::SetBackgroundAlpha(v8, (int)this->m_game_hud_ui.m_object->movie);
  m_movie = this->m_game_hud_ui.m_object->movie->m_movie;
  m_movie->SetViewAlignment(m_movie, Align_TopLeft);
  v10 = this->m_game_hud_ui.m_object->movie->m_movie;
  v10->SetViewScaleMode(v10, SM_NoScale);
  this->m_game_hud_ui.m_object->movie->m_priority = 10;
  survarium::flash_movie::SetBackgroundAlpha(v11, (int)this->m_cursor_ui.m_object->movie);
  v12 = this->m_cursor_ui.m_object->movie->m_movie;
  v12->SetViewAlignment(v12, Align_TopLeft);
  v13 = this->m_cursor_ui.m_object->movie->m_movie;
  v13->SetViewScaleMode(v13, SM_NoScale);
  this->m_cursor_ui.m_object->movie->m_priority = 100;
  survarium::flash_movie::SetBackgroundAlpha(v14, (int)this->m_player_icons_ui.m_object->movie);
  v15 = this->m_player_icons_ui.m_object->movie->m_movie;
  v15->SetViewAlignment(v15, Align_TopLeft);
  v16 = this->m_player_icons_ui.m_object->movie->m_movie;
  v16->SetViewScaleMode(v16, SM_NoScale);
  this->m_player_icons_ui.m_object->movie->m_priority = 5;
  m_network_client = this->m_game_world->m_game->m_network_client;
  if ( m_network_client->has_bandwidth(m_network_client) && vostok::core::journal_usage() != replay_journal )
    survarium::chat_handler::initialize(
      v18,
      (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)this->m_game_world->m_game->m_chat_handler,
      p_m_game_hud_ui,
      1);
  v19.m_object = p_m_game_hud_ui->m_object;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  v20 = v19.m_object->movie->m_movie;
  v26[0] = "left_hand";
  v26[1] = "right_hand";
  v26[2] = "left_leg";
  v26[3] = "right_leg";
  v26[4] = "head";
  v26[5] = "body";
  v26[6] = "pain";
  v26[7] = "infection";
  Scaleform::GFx::Movie::CreateArray(v20, &pvalue);
  for ( handler = 0; handler < 8; ++handler )
  {
    v22.m_object = p_m_game_hud_ui->m_object;
    v28.pObjectInterface = 0;
    v28.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v21, (survarium::flash_value *)v22.m_object->movie, &v28);
    *(_DWORD *)value.body = 0;
    *(_DWORD *)&value.body[4] = 0;
    survarium::flash_value::SetUInt(v23, (int)&value, handler);
    survarium::flash_value::SetMember(v24, &v28, "index", &value);
    survarium::flash_value::SetString(&value, v26[handler]);
    survarium::flash_value::SetMember(v25, &v28, "name", &value);
    pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v28);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
    Scaleform::GFx::Value::~Value(&v28);
  }
  Scaleform::GFx::Movie::Invoke(p_m_game_hud_ui->m_object->movie->m_movie, "root.damage_fill_names", 0, &pvalue, 1u);
  Scaleform::GFx::Value::~Value(&pvalue);
}
