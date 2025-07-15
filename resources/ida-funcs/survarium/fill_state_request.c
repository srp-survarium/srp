void __cdecl survarium::fill_state_request(
        vostok::buffer_vector<vostok::resources::request> *requests,
        vostok::configs::binary_config_value cfg)
{
  const char **v2; // ebx
  _DWORD v3[6]; // [esp+10h] [ebp-2Ch] BYREF
  vostok::resources::request v4; // [esp+2Ch] [ebp-10h] BYREF
  int v5; // [esp+34h] [ebp-8h]

  qmemcpy(v3, vostok::configs::binary_config_value::operator[](&cfg, "user_animations"), sizeof(v3));
  v2 = (const char **)v3[0];
  v5 = 4;
  do
  {
    v4.path = *v2;
    v4.id = animation_class;
    vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v4);
    v2 += 6;
    --v5;
  }
  while ( v5 );
}
