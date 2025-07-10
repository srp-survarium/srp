void __thiscall vostok::ai::planning::oracle_holder::add(
        vostok::ai::planning::oracle_holder *this,
        unsigned int *oracle_id,
        vostok::ai::planning::oracle *oracle)
{
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> > >,bool> result; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v5; // [esp+14h] [ebp-14h]
  vostok::ai::planning::oracle *v6; // [esp+18h] [ebp-10h]
  stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> __val; // [esp+1Ch] [ebp-Ch] BYREF
  char v8; // [esp+27h] [ebp-1h]

  v8 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v5 = *oracle_id;
  v6 = oracle;
  __val.first = v5;
  __val.second = oracle;
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::oracle *>>>::insert_unique(
    &this->m_objects._M_t,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&result,
    &__val);
}
