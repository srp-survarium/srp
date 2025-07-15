void __thiscall vostok::particle::particle_emitter_instance::process_event(
        vostok::particle::particle_emitter_instance *this,
        vostok::particle::particle_event *event_type,
        vostok::math::float4x4 *location,
        const vostok::math::float3 *a4)
{
  vostok::particle::particle_action *i; // ebx
  vostok::particle::particle_event *v5; // esi
  vostok::math::float4x4 *v6; // esi
  bool v7; // zf
  vostok::math::float4x4 v8; // [esp+10h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v9; // [esp+50h] [ebp-4Ch] BYREF
  vostok::particle::particle_event *v10; // [esp+94h] [ebp-8h]

  for ( i = event_type[15].m_next.pointer[12].m_next.pointer; i; i = i->m_next.pointer )
  {
    v5 = i->get_particle_event_action(i);
    v10 = v5;
    if ( v5 && v5->get_event_type(v5) == LODWORD(location->i.x) && v5->m_visibility )
    {
      v6 = vostok::math::float4x4::identity(location, &v8);
      v7 = !v10->m_inherit_position;
      qmemcpy(&v9, v6, sizeof(v9));
      if ( !v7 )
        qmemcpy(&v9, vostok::math::create_translation(a4, &v8), sizeof(v9));
      vostok::particle::particle_emitter_instance::play_child(0, event_type, v10, &v9);
    }
  }
}
