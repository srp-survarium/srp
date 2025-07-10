void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  _BYTE v3[148]; // [esp-94h] [ebp-130h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x736566);
}
