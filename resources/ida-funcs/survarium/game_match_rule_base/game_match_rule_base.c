void __userpurge survarium::game_match_rule_base::game_match_rule_base(
        survarium::game_match_rule_base *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::game_match_rule_type rule_type)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  a2[66] = &survarium::link_resolver::`vftable';
  a2[66] = &survarium::game_match_rule_base::`vftable'{for `survarium::link_resolver'};
  a2[67] = rule_type;
  *a2 = &survarium::game_match_rule_base::`vftable'{for `vostok::resources::unmanaged_resource'};
}
