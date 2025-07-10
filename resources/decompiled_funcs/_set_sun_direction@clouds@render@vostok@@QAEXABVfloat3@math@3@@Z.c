void __fastcall vostok::render::clouds::set_sun_direction(
        vostok::render::clouds *this,
        const vostok::math::float3 *sun_direction)
{
  if ( this->m_sun_direction.x != sun_direction->x
    || this->m_sun_direction.y != sun_direction->y
    || this->m_sun_direction.z != sun_direction->z )
  {
    this->m_current_key_0 = -1;
    this->m_current_key_1 = -1;
  }
  this->m_sun_direction = *sun_direction;
}
