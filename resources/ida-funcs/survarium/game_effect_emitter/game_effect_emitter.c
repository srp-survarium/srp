void __thiscall survarium::game_effect_emitter::game_effect_emitter(
        survarium::game_effect_emitter *this,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> emitter,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a3)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, emitter.m_object, fs_iterator_class);
  emitter.m_object->__vftable = (survarium::pure_game_effect_emitter_vtbl *)&survarium::game_effect_emitter::`vftable';
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&emitter.m_object[1],
    &a3);
  emitter.m_object[1].type = 0;
  emitter.m_object[1].survarium::pure_game_effect_emitter_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.survarium::pure_game_effect_emitter_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = 0;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
}
