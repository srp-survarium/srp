void __thiscall survarium::base_player::on_fire(survarium::base_player *this, int bullets_fired)
{
  void (__stdcall ****v3)(vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *, int, _DWORD); // ebx
  void (__stdcall ****i)(vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *, int, _DWORD); // edi
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *p_m_flags; // eax
  _DWORD *v6; // ebx
  void (__thiscall **v7)(_DWORD *, _DWORD, int, int); // edi
  int v8; // eax
  int v9; // [esp+10h] [ebp-4h]

  v3 = *(void (__stdcall *****)(vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *, int, _DWORD))((char *)&dword_10D80 + (_DWORD)this);
  for ( i = *(void (__stdcall *****)(vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *, int, _DWORD))((char *)&dword_10D7C + (_DWORD)this);
        i != v3;
        ++i )
  {
    if ( this == (survarium::base_player *)300 )
      p_m_flags = 0;
    else
      p_m_flags = &this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    (***i)(p_m_flags, 3, 0.0);
  }
  v6 = *(_DWORD **)(LODWORD(this->m_reconstruction_info_actuality_tick) + 51168);
  if ( v6 )
  {
    v9 = *(_DWORD *)(this[-1].m_stamina.m_current_time_in_ms + 372);
    v7 = (void (__thiscall **)(_DWORD *, _DWORD, int, int))(*v6 + 8);
    v8 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)HIDWORD(this->m_reconstruction_info_actuality_tick) + 108))(
           HIDWORD(this->m_reconstruction_info_actuality_tick),
           bullets_fired);
    (*v7)(v6, LOBYTE(this->type), v9, v8);
  }
}
