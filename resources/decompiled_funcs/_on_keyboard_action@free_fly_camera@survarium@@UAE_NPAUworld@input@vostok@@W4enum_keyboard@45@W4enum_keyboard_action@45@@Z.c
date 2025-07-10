bool __thiscall survarium::free_fly_camera::on_keyboard_action(
        survarium::free_fly_camera *this,
        vostok::input::world *input_world,
        survarium::key_binder **key,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *action)
{
  survarium::game_action_id binded_action; // eax
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v6; // ecx
  __int32 v7; // eax
  __int32 v8; // eax
  float x; // eax
  stlp_std::priv::_Impl_vector<void const *,survarium::std_allocator<void const *> > *v10; // edi
  const stlp_std::__true_type *v12; // [esp+0h] [ebp-18h]
  unsigned int v13; // [esp+4h] [ebp-14h]
  bool v14; // [esp+8h] [ebp-10h]
  survarium::toggle_action_enum actions_mask_type; // [esp+10h] [ebp-8h] BYREF
  survarium::key_binder **__x; // [esp+14h] [ebp-4h] BYREF

  __x = (survarium::key_binder **)this[-1].m_mouse_events._M_impl._M_end_of_storage._M_data[42];
  binded_action = survarium::key_binder::get_binded_action(__x[30], (int)key, &actions_mask_type, 1);
  v6 = action;
  if ( action != (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)1 )
  {
    if ( action == (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)3
      && actions_mask_type == hold_action )
    {
      x = this->m_inverted_view_matrix.j.x;
      v10 = (stlp_std::priv::_Impl_vector<void const *,survarium::std_allocator<void const *> > *)&this->m_inverted_view_matrix.lines[0].elements[3];
      __x = key;
      if ( LODWORD(x) != LODWORD(this->m_inverted_view_matrix.j.y) )
        goto LABEL_10;
      stlp_std::priv::_Impl_vector<int,survarium::std_allocator<int>>::_M_insert_overflow(
        v10,
        (const void **)LODWORD(x),
        (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)&__x,
        (const void **)&__x,
        v12,
        v13,
        v14);
    }
    return 0;
  }
  v7 = binded_action - 43;
  if ( v7 )
  {
    v8 = v7 - 3;
    if ( v8 )
    {
      if ( v8 == 1 )
        vostok::console_commands::execute("deserialize_player_state", execution_filter_all);
    }
    else
    {
      vostok::console_commands::execute("serialize_player_state", execution_filter_all);
    }
  }
  else
  {
    survarium::game::toggle_pause((survarium::game *)1);
  }
  if ( actions_mask_type != toggle_action )
    return 0;
  x = this->m_inverted_view_matrix.j.x;
  v10 = (stlp_std::priv::_Impl_vector<void const *,survarium::std_allocator<void const *> > *)&this->m_inverted_view_matrix.lines[0].elements[3];
  __x = key;
  if ( LODWORD(x) != LODWORD(this->m_inverted_view_matrix.j.y) )
  {
LABEL_10:
    *(_DWORD *)LODWORD(x) = key;
    ++v10->_M_finish;
    return 0;
  }
  stlp_std::priv::_Impl_vector<int,survarium::std_allocator<int>>::_M_insert_overflow(
    v10,
    (const void **)LODWORD(x),
    v6,
    (const void **)&__x,
    v12,
    v13,
    v14);
  return 0;
}
