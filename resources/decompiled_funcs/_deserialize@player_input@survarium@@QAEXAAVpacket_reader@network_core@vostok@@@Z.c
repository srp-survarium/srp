void __thiscall survarium::player_input::deserialize(
        survarium::player_input *this,
        vostok::network_core::packet_reader *reader)
{
  vostok::math::float2 v2; // kr00_8
  float y; // eax
  unsigned int v4; // [esp+0h] [ebp-3Ch]
  unsigned int v5; // [esp+0h] [ebp-3Ch]
  vostok::math::float2 v7; // [esp+18h] [ebp-24h] BYREF
  vostok::math::float2 destination; // [esp+24h] [ebp-18h] BYREF
  vostok::math::float2 v9; // [esp+2Ch] [ebp-10h] BYREF
  vostok::math::float2 v10; // [esp+34h] [ebp-8h] BYREF

  vostok::math::float2::float2(&this->angular_velocity, &destination.x);
  vostok::network_core::packet_reader::r(reader, 8u, (unsigned __int8 *)&destination, v4);
  Wm4::Vector2<float>::operator=(&destination, &v10);
  v2 = v10;
  this->angular_velocity = v10;
  vostok::math::float2::float2((vostok::math::float2 *)LODWORD(v2.x), &v7.x);
  vostok::network_core::packet_reader::r(reader, 8u, (unsigned __int8 *)&v7, v5);
  Wm4::Vector2<float>::operator=(&v7, &v9);
  y = v9.y;
  this->angular_acceleration.x = v9.x;
  this->angular_acceleration.y = y;
  this->actions_mask = vostok::network_core::packet_reader::r<unsigned int>(
                         (vostok::network_core::packet_reader *)this,
                         (int)reader);
}
