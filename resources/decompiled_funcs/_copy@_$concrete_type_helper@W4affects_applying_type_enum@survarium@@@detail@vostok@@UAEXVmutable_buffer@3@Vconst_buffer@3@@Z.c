void __thiscall vostok::detail::concrete_type_helper<enum survarium::affects_applying_type_enum>::copy(
        vostok::detail::concrete_type_helper<vostok::physics::world *> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  *(_DWORD *)dest_buffer.m_data = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer)->__vftable;
}
