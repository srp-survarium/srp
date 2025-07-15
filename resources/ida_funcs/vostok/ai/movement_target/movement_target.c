void __thiscall vostok::ai::movement_target::movement_target(
        vostok::ai::movement_target *this,
        const vostok::math::float3 *position,
        const vostok::math::float3 *eyes_direction,
        const vostok::math::float3 *preferable_velocity,
        const vostok::ai::animation_item *const animation)
{
  char *v5; // eax
  double x; // [esp+0h] [ebp-28h]
  double y; // [esp+8h] [ebp-20h]
  double z; // [esp+10h] [ebp-18h]

  this->target_position = *position;
  this->direction = *eyes_direction;
  this->velocity = *preferable_velocity;
  this->preferable_animation = animation;
  vostok::fixed_string<42>::fixed_string<42>(&this->caption);
  z = this->target_position.z;
  y = this->target_position.y;
  x = this->target_position.x;
  v5 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                 (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                 (int)&this->caption);
  vostok::sprintf(v5, 0x2Au, "target position: %.2f %.2f %.2f", x, y, z);
}
