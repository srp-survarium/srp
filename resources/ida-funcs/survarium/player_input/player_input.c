void __thiscall survarium::player_input::player_input(survarium::player_input *this)
{
  vostok::math::float2 *v1; // ecx
  survarium::player_input *thisa; // [esp+4h] [ebp-4h]
  survarium::player_input *thisb; // [esp+4h] [ebp-4h]

  vostok::math::float2::float2(&this->angular_velocity, (int)this, *(int *)&FLOAT_0_0, 0.0, *(float *)&this);
  vostok::math::float2::float2(v1, (int)&thisa->angular_acceleration, *(int *)&FLOAT_0_0, 0.0, *(float *)&thisa);
  thisb->actions_mask = 0;
}
