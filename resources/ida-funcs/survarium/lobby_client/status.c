vostok::lobby::client_state_enum __userpurge survarium::lobby_client::status@<eax>(
        survarium::lobby_client *this@<ecx>,
        int a2@<esi>,
        vostok::fixed_string<128> *dest)
{
  int v3; // eax
  int v4; // eax

  v3 = *(_DWORD *)(a2 + 432);
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
        vostok::fs_new::path_string_impl::assignf(
          dest,
          (vostok::buffer_string *)this,
          (vostok::buffer_string *)"Waiting for match served[%d] order[%d] %s",
          *(const char **)(a2 + 440),
          *(_DWORD *)(a2 + 444),
          *(_DWORD *)(a2 + 468));
    }
    else
    {
      vostok::fs_new::path_string_impl::assignf(
        dest,
        (vostok::buffer_string *)this,
        (vostok::buffer_string *)"In match making. match [%d] order[%d] %s",
        *(const char **)(a2 + 440),
        *(_DWORD *)(a2 + 444),
        *(_DWORD *)(a2 + 468));
    }
  }
  else
  {
    vostok::fs_new::path_string_impl::assignf(
      dest,
      (vostok::buffer_string *)this,
      (vostok::buffer_string *)"Lobby menu. %s",
      *(const char **)(a2 + 468));
  }
  return *(_DWORD *)(a2 + 432);
}
