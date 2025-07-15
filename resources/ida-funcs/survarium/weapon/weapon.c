void __userpurge survarium::weapon::weapon(
        survarium::base_game_scene *game_scene@<eax>,
        survarium::weapon_core *a2@<ecx>,
        survarium::weapon *this,
        vostok::math::float4x4 *preview_animations_count)
{
  vostok::particle::particle_action *v5; // ecx
  vostok::math::float4x4 *v6; // eax
  vostok::math::float4x4 v7; // [esp+10h] [ebp-40h] BYREF

  survarium::weapon_core::weapon_core(a2, (int)this);
  this->survarium::weapon_core::survarium::interactive_object::__vftable = (survarium::weapon_vtbl *)&survarium::weapon::`vftable'{for `survarium::interactive_object'};
  this->survarium::weapon_core::survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::inventory_item_vtbl *)&survarium::weapon::`vftable'{for `survarium::inventory_item'};
  survarium::breath_holding_sound_effect::breath_holding_sound_effect(
    &this->m_breath_holding_sound_effect,
    game_scene,
    v5,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_breath_vibration_calculator);
  this->m_barrel_locator.m_bone = -1;
  this->m_scope_locator.m_bone = -1;
  this->m_fire_pfx_list = 0;
  this->m_shells_pfx_list = 0;
  this->m_fire_pfx_count = 0;
  this->m_shells_pfx_count = 0;
  this->m_current_shell_pfx_id = 0;
  this->m_current_fire_pfx_id = 0;
  this->m_fx_history.m_head = 0;
  this->m_fx_history.m_tail = 0;
  this->m_rifle_scope.m_object = 0;
  this->m_game_scene = game_scene;
  this->m_model.m_object = 0;
  this->m_aimed_scope_added = 0;
  this->m_is_scope_aimed = 0;
  this->m_fire_light_anim_length = 200;
  this->m_preview_animations_count = (const unsigned int)preview_animations_count;
  qmemcpy(
    &this->m_current_transform,
    vostok::math::float4x4::identity(preview_animations_count, &v7),
    sizeof(this->m_current_transform));
  v6 = vostok::math::float4x4::identity(0, &v7);
  qmemcpy(&this->m_barrel_transform, v6, sizeof(this->m_barrel_transform));
  qmemcpy(&this->m_scope_transform, v6, sizeof(this->m_scope_transform));
}
