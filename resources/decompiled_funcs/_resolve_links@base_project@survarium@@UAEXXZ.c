void __thiscall survarium::base_project::resolve_links(survarium::base_project *this)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v1; // ecx
  survarium::base_project::resolve_link_object *end; // [esp+Ch] [ebp-8h]
  const vostok::variant<32> **it; // [esp+10h] [ebp-4h]

  it = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&this->m_objects_to_resolve);
  end = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
          v1,
          (int)&this->m_objects_to_resolve);
  while ( it != (const vostok::variant<32> **)end )
  {
    (**(void (__thiscall ***)(const vostok::variant<32> *, survarium::base_project *, const vostok::variant<32> *, const vostok::variant<32> *, const vostok::variant<32> *, const vostok::variant<32> *, const vostok::variant<32> *, const vostok::variant<32> *))it[6]->m_helper_storage)(
      it[6],
      this,
      *it,
      it[1],
      it[2],
      it[3],
      it[4],
      it[5]);
    it += 8;
  }
  stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260>>,stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::clear(&this->m_objects_registry._M_t);
}
