int __thiscall vostok::physics::calculate_bt_animated_body_size_from_hit_targets_config(
        vostok::configs::binary_config_value *config)
{
  const vostok::configs::binary_config_value *v1; // ebx
  unsigned int v2; // edi
  int v3; // ebp
  int v4; // esi
  int v5; // eax
  unsigned int i; // [esp+10h] [ebp-Ch]

  v1 = vostok::configs::binary_config_value::operator[](config, "hit_targets");
  v2 = 24 * v1->count / 24;
  v3 = 0;
  v4 = 112 * v2 + 96;
  for ( i = 0; i < v2; ++i )
  {
    switch ( (unsigned int)vostok::configs::binary_config_value::operator[](
                             (vostok::configs::binary_config_value *)((char *)v1->data.pointer + v3),
                             "type")->data.pointer )
    {
      case 0u:
        v5 = 64;
        break;
      case 1u:
      case 2u:
      case 3u:
        v5 = 80;
        break;
    }
    v4 += v5 + 96;
    v3 += 24;
  }
  return v4;
}
