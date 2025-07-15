const vostok::math::float4x4 *__thiscall survarium::base_player::transform(survarium::base_player *this)
{
  return (const vostok::math::float4x4 *)((char *)&dword_10D1C + (_DWORD)this);
}


const vostok::math::float4x4 *__thiscall survarium::base_player::transform(char *this)
{
  return survarium::base_player::transform((survarium::base_player *)(this - 36));
}
