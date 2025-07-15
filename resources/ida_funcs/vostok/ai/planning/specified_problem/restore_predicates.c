void __thiscall vostok::ai::planning::specified_problem::restore_predicates(
        vostok::ai::planning::specified_problem *this)
{
  survarium::game_camera *v1; // ecx
  const vostok::ai::planning::pddl_predicate *v2; // esi
  stlp_std::priv::_Rb_tree_node_base **v3; // eax
  const vostok::ai::planning::pddl_predicate **j; // [esp+10h] [ebp-84h]
  unsigned int __k; // [esp+88h] [ebp-Ch] BYREF
  const vostok::ai::planning::pddl_predicate *current_predicate; // [esp+8Ch] [ebp-8h]
  unsigned int i; // [esp+90h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v1 = (survarium::game_camera *)(this->m_excluded_predicates.m_end - this->m_excluded_predicates.m_begin);
    if ( i >= (unsigned int)v1 )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    current_predicate = this->m_excluded_predicates.m_begin[i];
    __k = current_predicate->m_type;
    v2 = current_predicate;
    v3 = stlp_std::map<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::operator[]<unsigned int>(
           &this->m_predicates,
           &__k);
    *v3 = (stlp_std::priv::_Rb_tree_node_base *)v2;
    v3[1] = (stlp_std::priv::_Rb_tree_node_base *)-1;
  }
  for ( j = this->m_excluded_predicates.m_begin; j != this->m_excluded_predicates.m_end; ++j )
    ;
  this->m_excluded_predicates.m_end = this->m_excluded_predicates.m_begin;
}
