void __thiscall survarium::game_material_manager::~game_material_manager(survarium::game_material_manager *this)
{
  survarium::game_camera *v1; // ecx

  this->__vftable = (survarium::game_material_manager_vtbl *)&survarium::game_material_manager::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>>>::clear(&this->m_pairs._M_t);
  stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::material_pair const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::material_pair const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::material_pair const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::material_pair const *>>>::clear(&this->m_materials._M_t);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_materials);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
