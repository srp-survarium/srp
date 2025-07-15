vostok::math::float4x4 *__thiscall vostok::animation::hand_to_weapon_ik_solver::get_locator_transform_in_item_space(
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *h,
        vostok::animation::hand_to_weapon_ik_solver::ik_locator_id_enum locator_id,
        const vostok::math::float4x4 *item_matrices,
        int is_first_view,
        char a6)
{
  int v6; // eax

  v6 = locator_id + 100 * ((_DWORD)item_matrices + 3 * (a6 == 0));
  vostok::math::mul4x3(
    (const vostok::math::float4x4 *)(is_first_view + (*(unsigned __int16 *)(v6 + 96) << 6)),
    (const vostok::math::float4x4 *)(v6 + 32),
    h);
  return h;
}
