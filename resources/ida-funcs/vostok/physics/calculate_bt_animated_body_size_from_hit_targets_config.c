int __usercall vostok::physics::calculate_bt_animated_body_size_from_hit_targets_config@<eax>(
        const vostok::configs::binary_config_value *config@<eax>)
{
  const vostok::configs::binary_config_value *v1; // ebx
  int v2; // eax
  int v3; // esi
  int v5; // [esp-4h] [ebp-24h]
  unsigned int v6; // [esp+14h] [ebp-Ch]
  unsigned int v7; // [esp+18h] [ebp-8h]
  int v8; // [esp+1Ch] [ebp-4h]

  v1 = vostok::configs::binary_config_value::operator[](config, "hit_targets");
  v2 = 24 * v1->count / 24;
  v7 = 0;
  v3 = 108 * v2 + 536;
  v6 = v2;
  if ( v2 )
  {
    v8 = 0;
    do
    {
      if ( vostok::configs::binary_config_value::operator[](
             (vostok::configs::binary_config_value *)((char *)v1->data.pointer + v8),
             "type")->data.pointer )
        v5 = 80;
      else
        v5 = 64;
      ++v7;
      v8 += 24;
      v3 += v5 + 96;
    }
    while ( v7 < v6 );
  }
  return v3;
}
