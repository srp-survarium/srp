void __thiscall survarium::artefact_base::artefact_base(
        survarium::artefact_base *this,
        const survarium::artefact_base::config *config,
        const vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *emitter,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a4)
{
  __int16 m_object; // ax
  vostok::fixed_string<64> *v5; // ecx
  vostok::fixed_string<64> *v6; // ecx

  survarium::inventory_item::inventory_item(this, (int)config, use_silent, 0);
  *(_DWORD *)&config->amount = &survarium::artefact_base::`vftable';
  LODWORD(config[14].spawn_sec) = (unsigned __int64)(*(float *)&emitter[1].m_object * 1000.0);
  config[14].pickup_hint = (const char *)(unsigned __int64)(1000.0 * *(float *)&emitter[2].m_object);
  m_object = (__int16)emitter->m_object;
  config[15].spawn_sec = NAN;
  *(_DWORD *)&config[15].amount = 0;
  config[15].pickup_hint = 0;
  LOWORD(config[14].activation_hint) = m_object;
  BYTE2(config[14].activation_hint) = -1;
  LOBYTE(config[15].cooldown_sec) = -1;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&config[15].activation_hint,
    a4);
  *(_DWORD *)&config[16].amount = 0;
  vostok::fixed_string<64>::fixed_string<64>(
    v5,
    (vostok::buffer_string *)&config[16].cooldown_sec,
    (char *)emitter[3].m_object);
  vostok::fixed_string<64>::fixed_string<64>(v6, (vostok::buffer_string *)&config[20], (char *)emitter[4].m_object);
}
