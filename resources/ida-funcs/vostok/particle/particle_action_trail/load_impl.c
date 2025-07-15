void __userpurge vostok::particle::particle_action_trail::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_trail *this@<ecx>,
        int a2@<edi>,
        const vostok::configs::binary_config_value allocator)
{
  const vostok::configs::binary_config_value *pointer; // ebx
  char *v4; // eax
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  const vostok::configs::binary_config_value *v8; // [esp-8h] [ebp-9Ch]
  vostok::fixed_string<128> *v9; // [esp-4h] [ebp-98h]
  vostok::fixed_string<128> name; // [esp+8h] [ebp-8Ch] BYREF

  pointer = (const vostok::configs::binary_config_value *)allocator.data.pointer;
  v8 = (const vostok::configs::binary_config_value *)allocator.data.pointer;
  allocator.data.pointer = uri;
  v4 = (char *)vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                 "ScreenAlignment",
                 (vostok::configs::binary_config_value *)this,
                 v8,
                 &allocator);
  vostok::fixed_string<128>::fixed_string<128>(v9, &name, v4);
  *(_DWORD *)(a2 + 40) = vostok::particle::screen_alignment_name_to_type(&name);
  *(_DWORD *)(a2 + 24) = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                           "SheetsCount",
                           v5,
                           pointer,
                           (const vostok::configs::binary_config_value *)(a2 + 24));
  *(_DWORD *)(a2 + 28) = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                           "TextureTile",
                           v6,
                           pointer,
                           (const vostok::configs::binary_config_value *)(a2 + 28));
  *(_BYTE *)(a2 + 36) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                          "ContinuousUV",
                          v7,
                          pointer,
                          (const bool *)(a2 + 36));
}
