void __usercall vostok::vfs::async_callbacks_data::delete_this(
        vostok::vfs::async_callbacks_data *this@<ecx>,
        int a2@<edi>)
{
  int v2; // ebx

  v2 = *(_DWORD *)(a2 + 88);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)(a2 + 40));
  (*(void (__thiscall **)(int, int, const char *, const char *, int))(*(_DWORD *)v2 + 24))(
    v2,
    a2,
    "vostok::vfs::async_callbacks_data::delete_this",
    ".\\find_async_callbacks.cpp",
    184);
}
