void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  _BYTE v3[136]; // [esp-88h] [ebp-124h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x6D5586);
}
