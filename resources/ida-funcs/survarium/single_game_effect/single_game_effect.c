void __thiscall survarium::single_game_effect::single_game_effect(
        survarium::single_game_effect *this,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> emitter,
        const float length,
        float a4)
{
  survarium::game_effect *v4; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v5; // [esp-4h] [ebp-14h] BYREF
  float v6; // [esp+0h] [ebp-10h]

  v5.m_object = (survarium::pure_game_effect_emitter_base *)this;
  v6 = a4;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v5,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&length);
  survarium::game_effect::game_effect(v4, emitter, *(const float *)&v5.m_object, SLODWORD(v6));
  emitter.m_object->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&survarium::single_game_effect::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&length);
}
