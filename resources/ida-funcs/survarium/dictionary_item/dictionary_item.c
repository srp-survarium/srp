void __thiscall survarium::dictionary_item::dictionary_item(
        survarium::dictionary_item *this,
        const survarium::dictionary_item *__that,
        int a3)
{
  __that->item_id = *(_DWORD *)a3;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that->item_cfg,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a3 + 4));
  vostok::fixed_string<260>::fixed_string<260>(&__that->item_cfg_name, (const vostok::fixed_string<260> *)(a3 + 8));
  __that->item_category = *(_BYTE *)(a3 + 280);
  __that->combat_log_icon = *(_BYTE *)(a3 + 281);
  __that->is_premium = *(_BYTE *)(a3 + 282);
  __that->is_stack = *(_BYTE *)(a3 + 283);
  qmemcpy(__that->modifiers, (const void *)(a3 + 284), 0x60u);
}
