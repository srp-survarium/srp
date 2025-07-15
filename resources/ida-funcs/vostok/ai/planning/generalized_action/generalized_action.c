void __userpurge vostok::ai::planning::generalized_action::generalized_action(
        vostok::ai::planning::generalized_action *this@<ecx>,
        int a2@<edi>,
        const vostok::ai::planning::pddl_domain *domain,
        const unsigned int type,
        char *name,
        const unsigned int cost)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = a2 + 40;
  *(_DWORD *)(a2 + 32) = a2 + 40;
  *(_DWORD *)(a2 + 36) = a2 + 56;
  *(_DWORD *)(a2 + 56) = a2 + 68;
  *(_DWORD *)(a2 + 60) = a2 + 68;
  *(_DWORD *)(a2 + 64) = a2 + 132;
  *(_DWORD *)(a2 + 132) = 0;
  vostok::fixed_string<32>::fixed_string<32>(0, (vostok::buffer_string *)(a2 + 136), name);
  *(_DWORD *)(a2 + 180) = type;
  *(_DWORD *)(a2 + 184) = cost;
  *(_DWORD *)(a2 + 188) = domain;
}
