int __thiscall vostok::collision::get_bones_count_from_hit_targets_config<vostok::configs::binary_config_value>(
        vostok::configs::binary_config_value *config)
{
  return 24 * HIWORD(*(_DWORD *)&vostok::configs::binary_config_value::operator[](config, "hit_targets")->type) / 24;
}
