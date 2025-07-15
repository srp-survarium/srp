void __thiscall survarium::artefact_spring_core::add_active_modifiers(survarium::artefact_spring_core *this, int a2)
{
  int v2; // ebp
  vostok::threading::mutex *v3; // ecx
  vostok::threading::mutex *v4; // ecx
  vostok::threading::mutex *v5; // ecx

  v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 272) + 376) + 12))(*(_DWORD *)(*(_DWORD *)(a2 + 272) + 376));
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(*(_DWORD *)((char *)&loc_11066 + v2 + 2) + 720),
    (survarium::player_params_modifier *)(a2 + 516),
    v3);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(*(_DWORD *)((char *)&loc_11066 + v2 + 2) + 672),
    (survarium::player_params_modifier *)(a2 + 524),
    v4);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(*(_DWORD *)((char *)&loc_11066 + v2 + 2) + 1440),
    (survarium::player_params_modifier *)(a2 + 532),
    v5);
}
