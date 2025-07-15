void __thiscall vostok::render::ambient_volume::set_properties(
        vostok::render::ambient_volume *this,
        const vostok::render::ambient_volume_properties *in_properties,
        vostok::math::aabb *a3)
{
  vostok::math::aabb v3; // [esp+10h] [ebp-18h] BYREF

  qmemcpy(&in_properties->transform.e01, a3, sizeof(const vostok::render::ambient_volume_properties));
  qmemcpy(&in_properties[1].transform.e01, vostok::math::create_identity_aabb(&v3), 0x18u);
  vostok::math::aabb::modify(a3, (vostok::math::aabb *)&in_properties[1].transform.e01);
}
