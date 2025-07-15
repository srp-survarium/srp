char __thiscall survarium::redundant_bullet_predicate::operator()(
        survarium::redundant_bullet_predicate *this,
        survarium::bullet *bullet)
{
  const vostok::math::float3_pod *v2; // eax
  vostok::math::float3 v5; // [esp+10h] [ebp-Ch] BYREF

  vostok::math::float3::float3(&v5, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  if ( !vostok::math::operator==(v2, &bullet->m_start_velocity) )
    return 0;
  survarium::bullet_manager::free_bullet(this->bullet_manager, bullet);
  return 1;
}
