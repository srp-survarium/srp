void __thiscall vostok::render::binary_shader_key_type::binary_shader_key_type(
        vostok::render::binary_shader_key_type *this,
        const vostok::render::binary_shader_key_type *__that,
        int a3)
{
  __that->configuration.configuration[0] = *(_QWORD *)a3;
  __that->configuration.configuration[1] = *(_QWORD *)(a3 + 8);
  vostok::fixed_string<260>::fixed_string<260>(
    &__that->shader_name.m_string,
    (const vostok::fixed_string<260> *)(a3 + 16));
  __that->shader_name.m_separator = 47;
  __that->type = *(_DWORD *)(a3 + 292);
}


void __thiscall vostok::render::binary_shader_key_type::binary_shader_key_type(
        vostok::render::binary_shader_key_type *this,
        char *in_shader_name,
        char *in_type,
        vostok::render::shader_configuration in_configuration,
        int a5)
{
  *(_DWORD *)in_shader_name = HIDWORD(in_configuration.configuration[0]);
  *((_DWORD *)in_shader_name + 1) = in_configuration.configuration[1];
  *((_DWORD *)in_shader_name + 2) = HIDWORD(in_configuration.configuration[1]);
  *((_DWORD *)in_shader_name + 3) = a5;
  vostok::fixed_string<260>::fixed_string<260>(
    (vostok::fixed_string<260> *)this,
    (vostok::buffer_string *)(in_shader_name + 16),
    in_type);
  in_shader_name[288] = 47;
  *((_DWORD *)in_shader_name + 73) = in_configuration.0;
}
