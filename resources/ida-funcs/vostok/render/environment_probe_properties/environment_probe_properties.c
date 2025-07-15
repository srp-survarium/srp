void __thiscall vostok::render::environment_probe_properties::environment_probe_properties(
        vostok::render::environment_probe_properties *this,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *__that,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    __that,
    other);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    __that + 1,
    other + 1);
  vostok::fixed_string<260>::fixed_string<260>(
    (vostok::fixed_string<260> *)&__that[2],
    (const vostok::fixed_string<260> *)&other[2]);
  qmemcpy(&__that[70], &other[70], 0x40u);
  qmemcpy(&__that[86], &other[86], 0x40u);
  qmemcpy(&__that[102], &other[102], 0x87u);
  __that[136].m_object = other[136].m_object;
}
