void __thiscall vostok::ai::navigation::navigation_world::navigation_world(
        vostok::ai::navigation::navigation_world *this,
        vostok::ai::navigation::engine *engine,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer)
{
  const vostok::math::float3 *v4; // eax
  vostok::math::float3 v6; // [esp+90h] [ebp-4Ch] BYREF
  vostok::math::float4x4 transform; // [esp+9Ch] [ebp-40h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_graph_generator);
  this->__vftable = (vostok::ai::navigation::navigation_world_vtbl *)&vostok::ai::navigation::navigation_world::`vftable';
  this->m_graph_generator = 0;
  this->m_engine = engine;
  this->m_renderer = renderer;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_start_position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_goal_position);
  vostok::math::float3::float3(&v6, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  vostok::math::create_translation(&transform, v4);
}
