void __thiscall vostok::detail::concrete_type_helper<unsigned char>::copy(
        vostok::detail::concrete_type_helper<unsigned char> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  *dest_buffer.m_data = *src_buffer.m_data;
}


void __thiscall vostok::detail::concrete_type_helper<unsigned short>::copy(
        vostok::detail::concrete_type_helper<unsigned short> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const char *m_data; // [esp+4h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)&dest_buffer);
  m_data = src_buffer.m_data;
  *(_WORD *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)src_buffer.m_data,
              (int)&dest_buffer) = *(_WORD *)m_data;
}


void __thiscall vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::copy(
        vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *m_data; // esi
  const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v4; // eax

  m_data = (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    m_data = (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)dest_buffer.m_data;
  }
  v4 = (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  m_data->m_object = v4->m_object;
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    m_data + 1,
    v4 + 1);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params>::copy(
        vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    m_data = dest_buffer.m_data;
  }
  *(_DWORD *)m_data = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer)->__vftable;
}


void __thiscall vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::copy(
        vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  __int16 v4; // si

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)&dest_buffer);
  v4 = *(_WORD *)src_buffer.m_data;
  *(_WORD *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)src_buffer.m_data,
              (int)&dest_buffer) = v4;
}


void __thiscall vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params>::copy(
        vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_data; // esi
  const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // edi

  m_data = (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    m_data = (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)dest_buffer.m_data;
  }
  v4 = (const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  m_data->m_object = v4->m_object;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    m_data + 1,
    v4 + 1);
  m_data[2].m_object = v4[2].m_object;
}


void __thiscall vostok::detail::concrete_type_helper<vostok::render::output_window_configuration>::copy(
        vostok::detail::concrete_type_helper<vostok::render::output_window_configuration> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax
  char *v4; // esi
  vostok::sound::encoded_sound_interface *v5; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    dest_buffer.m_data[12] = 0;
    dest_buffer.m_data[13] = 1;
    *((_DWORD *)dest_buffer.m_data + 4) = 0;
    m_data = dest_buffer.m_data;
  }
  v4 = m_data;
  v5 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  *(vostok::vfs::vfs_association *)v4 = v5->vostok::vfs::vfs_association;
  *((_QWORD *)v4 + 1) = *(_QWORD *)&v5->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  *((_DWORD *)v4 + 4) = v5->m_reconstruction_info_actuality_tick;
}


void __thiscall vostok::detail::concrete_type_helper<survarium::player_initial_info>::copy(
        vostok::detail::concrete_type_helper<survarium::player_initial_info> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax
  _QWORD *v4; // esi
  vostok::sound::encoded_sound_interface *v5; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    dest_buffer.m_data[4] = -1;
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    dest_buffer.m_data[12] = 0;
    m_data = dest_buffer.m_data;
  }
  v4 = m_data;
  v5 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  *v4 = v5->vostok::vfs::vfs_association;
  v4[1] = *(_QWORD *)&v5->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
}


void __thiscall vostok::detail::concrete_type_helper<vostok::render::scene_configuration>::copy(
        vostok::detail::concrete_type_helper<vostok::render::scene_configuration> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *dest_buffer.m_data &= 0x80u;
    m_data = dest_buffer.m_data;
  }
  *m_data = (char)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer)->__vftable;
}


void __thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::copy(
        vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  int *v3; // eax
  int v4; // [esp+1Ch] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v5; // [esp+30h] [ebp-18h] BYREF
  const char *v6; // [esp+34h] [ebp-14h]
  char *m_data; // [esp+38h] [ebp-10h]
  char *v8; // [esp+3Ch] [ebp-Ch]
  char *v9; // [esp+40h] [ebp-8h]
  char v10; // [esp+47h] [ebp-1h]

  v10 = 0;
  m_data = dest_buffer.m_data;
  v9 = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    v8 = v9 + 4;
    *((_DWORD *)v9 + 1) = 0;
  }
  v6 = src_buffer.m_data;
  *(_DWORD *)dest_buffer.m_data = *(_DWORD *)src_buffer.m_data;
  boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
    &v5,
    (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)v6
  + 1);
  v4 = *v3;
  *v3 = *((_DWORD *)dest_buffer.m_data + 1);
  *((_DWORD *)dest_buffer.m_data + 1) = v4;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v5);
}


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


void __thiscall vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data>::copy(
        vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_data; // esi
  const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // eax

  m_data = (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *((_DWORD *)dest_buffer.m_data + 2) = 0;
    m_data = (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)dest_buffer.m_data;
  }
  v4 = (const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  m_data->m_object = v4->m_object;
  m_data[1].m_object = v4[1].m_object;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    m_data + 2,
    v4 + 2);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::copy(
        vostok::detail::concrete_type_helper<vostok::configs::binary_config_value> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // esi
  vostok::sound::encoded_sound_interface *v4; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    *((_DWORD *)dest_buffer.m_data + 1) = 0;
    *(_DWORD *)dest_buffer.m_data = 0;
    vostok::platform_pointer_selector<char const,1>::helper::helper(
      (vostok::platform_pointer_selector<char const ,1>::helper *)dest_buffer.m_data + 1,
      0);
    *((_DWORD *)dest_buffer.m_data + 4) = 0;
    *((_WORD *)dest_buffer.m_data + 10) = 0;
    *((_WORD *)dest_buffer.m_data + 11) = 0;
    m_data = dest_buffer.m_data;
  }
  v4 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  *(_DWORD *)m_data = v4->__vftable;
  *((_DWORD *)m_data + 1) = v4->type;
  *((_DWORD *)m_data + 2) = v4->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  *((_DWORD *)m_data + 3) = *((_DWORD *)&v4->vostok::resources::resource_flags + 3);
  *((_DWORD *)m_data + 4) = v4->m_reconstruction_info_actuality_tick;
  *((_WORD *)m_data + 10) = WORD2(v4->m_reconstruction_info_actuality_tick);
  *((_WORD *)m_data + 11) = HIWORD(v4->m_reconstruction_info_actuality_tick);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::copy(
        vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  char *m_data; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v4; // esi
  const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v5; // eax

  m_data = dest_buffer.m_data;
  if ( dest_buffer.m_data )
  {
    *(_DWORD *)dest_buffer.m_data = 0;
    m_data = dest_buffer.m_data;
  }
  v4 = (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)m_data;
  v5 = (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    v4,
    v5);
}


void __thiscall vostok::detail::concrete_type_helper<enum survarium::affects_applying_type_enum>::copy(
        vostok::detail::concrete_type_helper<vostok::physics::world *> *this,
        vostok::mutable_buffer dest_buffer,
        vostok::const_buffer src_buffer)
{
  *(_DWORD *)dest_buffer.m_data = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src_buffer)->__vftable;
}
