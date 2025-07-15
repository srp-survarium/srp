void __thiscall survarium::player::apply_new_input(
        survarium::player *this,
        unsigned int current_time_in_ms,
        const survarium::player_input *input)
{
  const survarium::player_input *v4; // edx
  _DWORD *v5; // esi
  survarium::player_input_handler *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // esi

  if ( this->m_is_alive )
  {
    v4 = input;
    v5 = (survarium::player_vtbl **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                   + (_DWORD)&loc_11403
                                   + 5);
    v6 = *(survarium::player_input_handler **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                             + (_DWORD)&loc_11403
                                             + 5);
    if ( v6 )
    {
      survarium::player_input_handler::set_input(v6, input);
      v7 = (_DWORD *)*v5;
      v8 = (_DWORD *)(*v5 + 824);
      v7[209] = *v8++;
      v7[210] = *v8;
      v7[211] = v8[1];
    }
    survarium::base_player::apply_new_input(this, current_time_in_ms, v4);
  }
}
