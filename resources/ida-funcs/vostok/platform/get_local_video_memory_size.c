unsigned int __cdecl vostok::platform::get_local_video_memory_size()
{
  unsigned int v0; // ebx
  unsigned int v1; // esi
  unsigned __int64 local_video_memory_size_impl; // kr00_8
  vostok::command_line::key *v3; // ecx
  vostok::command_line::key *v4; // ecx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // kr08_8
  unsigned __int64 v7; // kr10_8
  unsigned int out_value; // [esp+Ch] [ebp-4h] BYREF

  local_video_memory_size_impl = get_local_video_memory_size_impl();
  v0 = HIDWORD(local_video_memory_size_impl);
  v1 = local_video_memory_size_impl;
  if ( vostok::command_line::key::is_set(v3, (int)&s_max_video_memory)
    && vostok::command_line::key::is_set_as_number<unsigned int>(v4, (int)&s_max_video_memory, &out_value) )
  {
    v5 = vostok::math::max(0x10000000u, (unsigned int)&loc_100000 * (unsigned __int64)out_value);
    v6 = vostok::math::min(v5, local_video_memory_size_impl);
    v0 = HIDWORD(v6);
    v1 = v6;
  }
  if ( vostok::platform::is_address_space_or_ram_under_2_gb() )
  {
    v7 = vostok::math::min(__PAIR64__(v0, v1), 0x20000000u);
    v0 = HIDWORD(v7);
    v1 = v7;
  }
  __FUnloadDelayLoadedDLL2("d3d9.dll");
  if ( !(v0 | v1) )
    return 0x10000000;
  if ( !v0 && v1 < 0x10000000 )
    vostok::debug::terminate(
      "Vostok Engine v1.0 doesn't support video cards with onboard memory less than %d Mb, please upgrade your hardware.",
      256);
  return v1;
}
