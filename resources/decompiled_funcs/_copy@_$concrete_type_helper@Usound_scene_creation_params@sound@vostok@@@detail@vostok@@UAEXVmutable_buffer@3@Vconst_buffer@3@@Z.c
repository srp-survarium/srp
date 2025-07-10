void __thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params>::copy(
        vostok::detail::concrete_type_helper<vostok::sound::sound_scene_creation_params> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::sound::encoded_sound_interface *v3; // eax

  v3 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  *(vostok::vfs::vfs_association *)dest_buffer.m_data = v3->vostok::vfs::vfs_association;
  *((_DWORD *)dest_buffer.m_data + 2) = v3->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
}
