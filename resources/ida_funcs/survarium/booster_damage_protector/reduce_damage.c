double __thiscall survarium::booster_damage_protector::reduce_damage(
        survarium::booster_damage_protector *this,
        const char *__formal,
        const char *damage_type,
        float amount,
        const float a5)
{
  if ( vostok::strings::equal(damage_type, this->m_hit_type) )
  {
    vostok::math::max();
    return *(float *)&FLOAT_0_0;
  }
  else
  {
    return amount;
  }
}
