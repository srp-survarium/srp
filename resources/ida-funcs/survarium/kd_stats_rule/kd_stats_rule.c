void __userpurge survarium::kd_stats_rule::kd_stats_rule(
        survarium::kd_stats_rule *this@<ecx>,
        int a2@<eax>,
        const survarium::match_options *match_options)
{
  survarium::game_match_rule_base::game_match_rule_base(this, (_DWORD *)a2, kd_stats_rule_type);
  *(_DWORD *)a2 = &survarium::kd_stats_rule::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 264) = &survarium::kd_stats_rule::`vftable'{for `survarium::link_resolver'};
  *(_BYTE *)(a2 + 432) = match_options->players_count;
  memset(a2 + 272, 0, 0xA0u);
}
