void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  vostok::collision::intersection_double_dispatcher *v3; // ecx
  _BYTE v4[136]; // [esp-88h] [ebp-D8h] BYREF
  _BYTE v5[72]; // [esp+0h] [ebp-50h] BYREF

  qmemcpy(v5, testee, sizeof(v5));
  qmemcpy(v4, bounding_volume, sizeof(v4));
  survarium::weapon_user_dead_state::finalize(0);
  vostok::collision::intersection_double_dispatcher::dispatch(v3, bounding_volume, testee);
}
