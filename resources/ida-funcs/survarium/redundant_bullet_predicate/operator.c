bool __userpurge survarium::redundant_bullet_predicate::operator()@<al>(
        survarium::bullet *bullet@<esi>,
        survarium::redundant_bullet_predicate *this)
{
  bool result; // al
  vostok::math::float3_pod v3; // [esp+0h] [ebp-Ch] BYREF

  memset(&v3, 0, sizeof(v3));
  result = vostok::math::operator==(&v3, &bullet->m_start_velocity);
  if ( result )
  {
    survarium::bullet_manager::free_bullet(this->bullet_manager, bullet, 1);
    return 1;
  }
  return result;
}
