void __cdecl survarium::create_requests_for_animations(
        vostok::configs::binary_config_value *cfg,
        unsigned int requests_count,
        vostok::buffer_vector<vostok::resources::request> *requests)
{
  survarium::game_camera *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  survarium::game_camera *v6; // ecx
  const char *v7; // eax
  vostok::resources::class_id_enum v8; // edx
  vostok::resources::request value; // [esp+24h] [ebp-10h] BYREF
  char v10; // [esp+2Fh] [ebp-5h]
  unsigned int i; // [esp+30h] [ebp-4h]

  v10 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  for ( i = 0; i < requests_count; ++i )
  {
    v4 = vostok::configs::binary_config_value::operator[](cfg, i);
    stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)v4);
    survarium::weapon_user_dead_state::finalize(v6);
    value.path = v7;
    value.id = v8;
    vostok::buffer_vector<vostok::resources::request>::push_back(requests, &value);
  }
}
