unsigned int __fastcall vostok::render::calc_config_memory_usage(
        int a1,
        vostok::render::effect_options_descriptor *value)
{
  int num_total_fields; // esi
  vostok::render::effect_options_descriptor *v3; // edx
  unsigned int data_memory_usage; // eax
  unsigned int need_bytes_to_align4; // [esp+4h] [ebp-8h] BYREF
  unsigned int last_align_value; // [esp+8h] [ebp-4h] BYREF

  num_total_fields = vostok::render::effect_options_descriptor::get_num_total_fields(value);
  need_bytes_to_align4 = 0;
  last_align_value = 0;
  data_memory_usage = vostok::render::effect_options_descriptor::get_data_memory_usage(
                        v3,
                        &need_bytes_to_align4,
                        &last_align_value);
  return need_bytes_to_align4 + data_memory_usage + 20 * num_total_fields + 32;
}
