void __thiscall survarium::legs_ik_drawer::draw_leg(
        survarium::legs_ik_drawer *this,
        const vostok::math::float4x4 *up_leg,
        const vostok::math::float4x4 *knee,
        const vostok::math::float4x4 *leg,
        const vostok::math::float4x4 *foot,
        const vostok::math::color *up_leg_color,
        const vostok::math::color *knee_color,
        const vostok::math::color *leg_color,
        const vostok::math::color *foot_color,
        float cross_half_size)
{
  survarium::game_camera *v10; // ecx
  const vostok::math::float3 *v11; // eax
  const vostok::math::float3 *v12; // esi
  survarium::game_camera *v13; // ecx
  const vostok::math::float3 *v14; // eax
  survarium::game_camera *v15; // ecx
  const vostok::math::float3 *v16; // eax
  const vostok::math::float3 *v17; // esi
  survarium::game_camera *v18; // ecx
  const vostok::math::float3 *v19; // eax
  survarium::game_camera *v20; // ecx
  const vostok::math::float3 *v21; // eax
  const vostok::math::float3 *v22; // esi
  survarium::game_camera *v23; // ecx
  const vostok::math::float3 *v24; // eax
  survarium::game_camera *v25; // ecx
  const vostok::math::float3 *v26; // eax
  const vostok::math::float3 *v27; // esi
  survarium::game_camera *v28; // ecx
  const vostok::math::float3 *v29; // eax

  vostok::render::debug::renderer::draw_origin(&up_leg->i.x, (int)this->m_renderer, cross_half_size, &this->m_scene, 0);
  vostok::render::debug::renderer::draw_origin(&knee->i.x, (int)this->m_renderer, cross_half_size, &this->m_scene, 0);
  vostok::render::debug::renderer::draw_origin(&leg->i.x, (int)this->m_renderer, cross_half_size, &this->m_scene, 0);
  vostok::render::debug::renderer::draw_origin(&foot->i.x, (int)this->m_renderer, cross_half_size, &this->m_scene, 0);
  survarium::weapon_user_dead_state::finalize(v10);
  v12 = v11;
  survarium::weapon_user_dead_state::finalize(v13);
  vostok::render::debug::renderer::draw_line(v14, v12, this->m_renderer, &this->m_scene, up_leg_color, 0);
  survarium::weapon_user_dead_state::finalize(v15);
  v17 = v16;
  survarium::weapon_user_dead_state::finalize(v18);
  vostok::render::debug::renderer::draw_line(v19, v17, this->m_renderer, &this->m_scene, knee_color, 0);
  survarium::weapon_user_dead_state::finalize(v20);
  v22 = v21;
  survarium::weapon_user_dead_state::finalize(v23);
  vostok::render::debug::renderer::draw_line(v24, v22, this->m_renderer, &this->m_scene, leg_color, 0);
  survarium::weapon_user_dead_state::finalize(v25);
  v27 = v26;
  survarium::weapon_user_dead_state::finalize(v28);
  vostok::render::debug::renderer::draw_line(v29, v27, this->m_renderer, &this->m_scene, foot_color, 0);
}
