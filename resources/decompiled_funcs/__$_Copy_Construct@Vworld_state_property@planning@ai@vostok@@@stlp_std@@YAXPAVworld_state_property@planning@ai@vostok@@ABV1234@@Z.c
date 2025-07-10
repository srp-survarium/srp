void __cdecl stlp_std::_Copy_Construct<vostok::ai::planning::world_state_property>(
        vostok::ai::planning::world_state_property *__p,
        const vostok::ai::planning::world_state_property *__val)
{
  vostok::ai::planning::world_state_property *v2; // [esp+4h] [ebp-8h]

  v2 = (vostok::ai::planning::world_state_property *)operator new(0xCu, __p);
  if ( v2 )
    *v2 = *__val;
}
