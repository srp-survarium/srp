void __thiscall survarium::game_world_ui::~game_world_ui(survarium::game_world_ui *this)
{
  survarium::profile_slot_enum *M_start; // eax
  void *v3; // esi
  survarium::flash_movie_resource *m_object; // eax

  this->__vftable = (survarium::game_world_ui_vtbl *)&survarium::game_world_ui::`vftable';
  M_start = this->m_slots_to_update._M_impl._M_start;
  if ( M_start )
  {
    v3 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v3, M_start);
  }
  if ( this->m_base_points._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)&this->m_base_points,
      this->m_base_points._M_t._M_header._M_data._M_parent);
    this->m_base_points._M_t._M_header._M_data._M_left = &this->m_base_points._M_t._M_header._M_data;
    this->m_base_points._M_t._M_header._M_data._M_parent = 0;
    this->m_base_points._M_t._M_header._M_data._M_right = &this->m_base_points._M_t._M_header._M_data;
    this->m_base_points._M_t._M_node_count = 0;
  }
  m_object = this->m_game_hud_ui.m_object;
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_game_hud_ui.m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_game_hud_ui.m_object);
  }
}
