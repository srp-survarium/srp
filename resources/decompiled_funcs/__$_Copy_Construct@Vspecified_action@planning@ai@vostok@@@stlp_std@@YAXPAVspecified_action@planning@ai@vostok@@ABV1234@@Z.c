void __cdecl stlp_std::_Copy_Construct<vostok::ai::planning::specified_action>(
        vostok::ai::planning::specified_action *__p,
        const vostok::ai::planning::specified_action *__val)
{
  vostok::ai::planning::specified_action *v2; // [esp+54h] [ebp-8h]

  v2 = (vostok::ai::planning::specified_action *)operator new(0x34u, __p);
  if ( v2 )
    vostok::ai::planning::specified_action::specified_action(v2, __val);
}
