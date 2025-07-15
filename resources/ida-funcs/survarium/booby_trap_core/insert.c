void __userpurge survarium::booby_trap_core::insert(
        survarium::booby_trap_core *this@<ecx>,
        int a2@<esi>,
        const vostok::math::float4x4 *transform,
        const unsigned int deploy_time_in_ms)
{
  survarium::game_world_core *v4; // ecx
  survarium::booby_trap_core *v5; // ecx
  survarium::booby_trap_core *v6; // ecx
  survarium::booby_trap_core *v7; // ecx

  if ( a2 )
    v4 = (survarium::game_world_core *)(a2 + 120);
  else
    v4 = 0;
  survarium::game_world_core::register_tickable_object(v4, *(_DWORD *)(a2 + 412));
  survarium::booby_trap_core::switch_to_state((survarium::booby_trap_core *)a2, booby_trap_state_armed, v5);
  survarium::booby_trap_core::insert_collision(v6, a2);
  survarium::booby_trap_core::set_transform(v7, (const vostok::math::float4x4 *)a2, transform);
  *(_DWORD *)(a2 + 492) = deploy_time_in_ms;
}
