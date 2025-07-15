void __thiscall survarium::artefact_spring_core::add_passive_modifiers(survarium::artefact_spring_core *this, int a2)
{
  vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> **v2; // ebp
  vostok::threading::mutex *v3; // ecx
  vostok::threading::mutex *v4; // ecx

  v2 = (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> **)((char *)&loc_11066 + (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 272) + 376) + 12))(*(_DWORD *)(*(_DWORD *)(a2 + 272) + 376)) + 2);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    *v2 + 15,
    (survarium::player_params_modifier *)(a2 + 500),
    v3);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    *v2 + 16,
    (survarium::player_params_modifier *)(a2 + 508),
    v4);
}
