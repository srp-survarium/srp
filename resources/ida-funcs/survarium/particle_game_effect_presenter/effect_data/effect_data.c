void __thiscall survarium::particle_game_effect_presenter::effect_data::effect_data(
        survarium::particle_game_effect_presenter::effect_data *this,
        const survarium::particle_game_effect_presenter::effect_data *__that,
        int a3)
{
  survarium::loose_ptr_data *v3; // eax

  __that->effect.m_object = 0;
  v3 = *(survarium::loose_ptr_data **)a3;
  if ( *(_DWORD *)a3 )
  {
    __that->effect.m_object = v3;
    ++v3->m_reference_count;
  }
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&__that->particle_system,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(a3 + 4));
  __that->time_to_finish = *(float *)(a3 + 8);
  __that->time = *(float *)(a3 + 12);
}
