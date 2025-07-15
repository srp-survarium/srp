void __thiscall survarium::items_dictionary::~items_dictionary(survarium::items_dictionary *this)
{
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *p_m_items_dict; // [esp+8h] [ebp-4h]

  p_m_items_dict = &this->m_items_dict;
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::dictionary_item>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::dictionary_item>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::dictionary_item>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item>>>::clear(&this->m_items_dict._M_t);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&p_m_items_dict->_M_t._M_key_compare);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&this->dict_config);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->dict_config);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
