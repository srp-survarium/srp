void __thiscall survarium::grenade_core::tick(
        survarium::grenade_core *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  vostok::math::float4x4 *v4; // esi
  vostok::physics::bt_dynamic_rigid_body *m_rigid_body; // eax
  long double v6; // rdi
  vostok::math::float4x4 *p_result; // esi
  vostok::math::float4x4 *v8; // eax
  survarium::grenade_core_vtbl *v9; // edx
  vostok::math::float4x4 result; // [esp+10h] [ebp-40h] BYREF

  if ( this->m_physics_world )
  {
    v4 = this->m_rigid_body->get_transform(this->m_rigid_body, &result);
    m_rigid_body = this->m_rigid_body;
    qmemcpy(&this->m_transform, v4, sizeof(this->m_transform));
    LODWORD(v6) = &this->m_render_transform;
    HIDWORD(v6) = &m_rigid_body->m_bt_body->m_worldTransform;
    vostok::physics::from_bullet(v6, &result);
    p_result = &result;
  }
  else
  {
    v8 = survarium::grenade_set_core::logic_transform((survarium::grenade_set_core *)this, (int)this->m_owner, &result);
    qmemcpy(&this->m_transform, v8, sizeof(this->m_transform));
    p_result = v8;
  }
  v9 = this->survarium::tickable_object::__vftable;
  qmemcpy(&this->m_render_transform, p_result, sizeof(this->m_render_transform));
  if ( this->m_explode_time_ms == current_time_ms )
    v9->explode(this, time_delta_ms, current_time_ms);
  else
    v9->active_tick(this, time_delta_ms, current_time_ms);
}
