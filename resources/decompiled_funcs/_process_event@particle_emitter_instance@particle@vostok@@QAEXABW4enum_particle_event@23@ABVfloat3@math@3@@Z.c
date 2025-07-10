void __thiscall vostok::particle::particle_emitter_instance::process_event(
        vostok::particle::particle_emitter_instance *this,
        const vostok::particle::enum_particle_event *event_type,
        const vostok::math::float3 *location)
{
  vostok::math::float4x4 *v3; // eax
  vostok::math::float4x4 result; // [esp+D4h] [ebp-C8h] BYREF
  _BYTE v6[128]; // [esp+114h] [ebp-88h] BYREF
  vostok::particle::particle_event *evt; // [esp+194h] [ebp-8h]
  vostok::particle::particle_action *action; // [esp+198h] [ebp-4h]

  action = this->m_emitter->m_actions.pointer;
  while ( action )
  {
    evt = (vostok::particle::particle_event *)__RTDynamicCast(
                                                (void **)&action->__vftable,
                                                0,
                                                (TypeDescriptor *)&vostok::particle::particle_action `RTTI Type Descriptor',
                                                (TypeDescriptor *)&vostok::particle::particle_event `RTTI Type Descriptor',
                                                0);
    if ( evt )
    {
      if ( evt->get_event_type(evt) == *event_type && evt->m_visibility )
      {
        v3 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)v6);
        qmemcpy(&v6[64], vostok::math::float4x4::identity(v3), 0x40u);
        if ( evt->m_inherit_position )
          qmemcpy(&v6[64], vostok::math::create_translation(&result, location), 0x40u);
        vostok::particle::particle_emitter_instance::play_child(this, evt, (const vostok::math::float4x4 *)&v6[64]);
      }
      action = action->m_next.pointer;
    }
    else
    {
      action = action->m_next.pointer;
    }
  }
}
