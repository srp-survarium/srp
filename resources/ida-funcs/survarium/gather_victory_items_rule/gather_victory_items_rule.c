void __userpurge survarium::gather_victory_items_rule::gather_victory_items_rule(
        survarium::gather_victory_items_rule *this@<ecx>,
        int a2@<eax>,
        const unsigned int seed)
{
  vostok::memory::doug_lea_allocator *v4; // eax

  survarium::game_match_rule_base::game_match_rule_base(this, (_DWORD *)a2, gather_victory_items_rule_type);
  v4 = survarium::g_allocator;
  *(_DWORD *)a2 = &survarium::gather_victory_items_rule::`vftable'{for `vostok::resources::unmanaged_resource'};
  *(_DWORD *)(a2 + 264) = &survarium::gather_victory_items_rule::`vftable'{for `survarium::link_resolver'};
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 280) = v4;
  *(_DWORD *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = v4;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = v4;
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = v4;
  *(_DWORD *)(a2 + 332) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(_DWORD *)(a2 + 340) = seed;
  *(_DWORD *)(a2 + 344) = -1;
  *(_BYTE *)(a2 + 348) = 0;
  *(_BYTE *)(a2 + 349) = 0;
}
