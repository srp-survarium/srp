void __thiscall survarium::generic_anomaly_core::spawn_artefacts(survarium::generic_anomaly_core *this)
{
  void *v1; // esp
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // eax
  survarium::game_camera *v4; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  const void **v9; // eax
  survarium::game_camera *v10; // ecx
  int v11; // [esp+0h] [ebp-5Ch] BYREF
  survarium::generic_anomaly_core *thisa; // [esp+4h] [ebp-58h]
  survarium::artefact_container_core **j; // [esp+8h] [ebp-54h]
  char v14; // [esp+Fh] [ebp-4Dh]
  survarium::artefact_container_core **__last; // [esp+10h] [ebp-4Ch]
  boost::arg<1> *v16; // [esp+20h] [ebp-3Ch]
  char v17; // [esp+27h] [ebp-35h]
  vostok::sound::encoded_sound_interface *(__thiscall *v18)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+28h] [ebp-34h]
  boost::arg<1> *v19; // [esp+2Ch] [ebp-30h]
  boost::arg<1> *result; // [esp+30h] [ebp-2Ch]
  char v21; // [esp+37h] [ebp-25h]
  survarium::game_camera *v22; // [esp+38h] [ebp-24h]
  char v23; // [esp+3Eh] [ebp-1Eh]
  char v24; // [esp+3Fh] [ebp-1Dh]
  unsigned int i; // [esp+40h] [ebp-1Ch]
  unsigned int a; // [esp+44h] [ebp-18h]
  unsigned int respawn_cnt; // [esp+48h] [ebp-14h]
  vostok::buffer_vector<survarium::artefact_container_core *> empty_artefact_containers; // [esp+4Ch] [ebp-10h] BYREF
  unsigned int cont_total; // [esp+54h] [ebp-8h]
  unsigned int artefacts_current; // [esp+58h] [ebp-4h]

  thisa = this;
  v24 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  cont_total = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&thisa->m_artefact_containers._M_impl);
  v1 = alloca(4 * cont_total);
  v11 = (int)&v11;
  survarium::weapon_user_dead_state::finalize(v2);
  v22 = v3;
  empty_artefact_containers.m_begin = (survarium::artefact_container_core **)v3;
  empty_artefact_containers.m_end = (survarium::artefact_container_core **)v3;
  v23 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  for ( a = 0; a < cont_total; ++a )
  {
    v21 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
           v5,
           (int)&thisa->m_artefact_containers);
    result = (boost::arg<1> *)&v6[a];
    v19 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
    if ( *(_DWORD *)(*(_DWORD *)v19 + 32) )
      v18 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
    else
      v18 = 0;
    if ( !v18 )
    {
      v17 = 0;
      survarium::weapon_user_dead_state::finalize(0);
      v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             v7,
             (int)&thisa->m_artefact_containers);
      v16 = (boost::arg<1> *)&v8[a];
      v9 = (const void **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v16);
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        (vostok::buffer_vector<void const *> *)&empty_artefact_containers,
        v9);
    }
    v4 = (survarium::game_camera *)(a + 1);
  }
  artefacts_current = cont_total - (empty_artefact_containers.m_end - empty_artefact_containers.m_begin);
  respawn_cnt = thisa->artefacts_max_count - artefacts_current;
  if ( respawn_cnt )
  {
    __last = empty_artefact_containers.m_end;
    stlp_std::random_shuffle<survarium::artefact_container_core * *>(
      empty_artefact_containers.m_begin,
      empty_artefact_containers.m_end);
    for ( i = 0; i < respawn_cnt; ++i )
    {
      v14 = 0;
      survarium::weapon_user_dead_state::finalize(v10);
      survarium::artefact_container_core::spawn_artefact(empty_artefact_containers.m_begin[i]);
    }
  }
  thisa->m_artefact_grab_time_ms = 0;
  for ( j = empty_artefact_containers.m_begin; j != empty_artefact_containers.m_end; ++j )
    ;
}
