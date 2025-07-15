void __userpurge vostok::render::singletons_on_preinitialize::singletons_on_preinitialize(
        vostok::render::singletons_on_preinitialize *this@<ecx>,
        UINT a2@<esi>,
        vostok::render::resource_manager *in_config,
        unsigned __int64 video_memory_size,
        bool is_editor)
{
  vostok::render::backend *v5; // ecx
  vostok::render::effect_manager *v6; // ecx
  _DWORD *v7; // eax
  char *v8; // ecx

  *(_DWORD *)(a2 + 348) = HIDWORD(video_memory_size);
  vostok::quasi_singleton<vostok::render::device>::pinst = (vostok::render::device *)a2;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(_DWORD *)(a2 + 340) = 0;
  *(_DWORD *)(a2 + 344) = video_memory_size;
  *(_BYTE *)(a2 + 356) = is_editor;
  *(_BYTE *)(a2 + 358) = 0;
  vostok::render::device::create(&this->device, a2);
  vostok::render::resource_manager::resource_manager(
    in_config,
    (vostok::render::resource_manager *)(a2 + 360),
    video_memory_size);
  vostok::render::backend::backend(v5, (vostok::render::vertex_buffer *)((char *)&loc_96CE7 + a2 + 1));
  *(_DWORD *)(a2 + 625296) = a2 + 625308;
  *(_DWORD *)(a2 + 625300) = a2 + 625308;
  *(_DWORD *)(a2 + 625304) = a2 + 625372;
  *(_DWORD *)(a2 + 625372) = a2 + 625384;
  *(_DWORD *)(a2 + 625376) = a2 + 625384;
  *(_DWORD *)(a2 + 625380) = a2 + 625448;
  vostok::quasi_singleton<vostok::render::scene_manager>::pinst = (vostok::render::scene_manager *)(a2 + 625296);
  *(_DWORD *)(a2 + 625448) = a2 + 625460;
  *(_DWORD *)(a2 + 625452) = a2 + 625460;
  *(_DWORD *)(a2 + 625456) = a2 + 625524;
  *(_DWORD *)(a2 + 625524) = a2 + 625536;
  *(_DWORD *)(a2 + 625528) = a2 + 625536;
  *(_DWORD *)(a2 + 625532) = a2 + 626048;
  *(_DWORD *)(a2 + 626048) = a2 + 626060;
  *(_DWORD *)(a2 + 626052) = a2 + 626060;
  vostok::quasi_singleton<vostok::render::shader_macros>::pinst = (vostok::render::shader_macros *)(a2 + 625524);
  *(_DWORD *)(a2 + 626056) = (char *)decode_finger_print + a2 + 626060;
  vostok::render::shader_macros::register_available_macros(
    (vostok::render::shader_macros *)(a2 + 626048),
    (const char ***)(a2 + 625524));
  vostok::render::effect_manager::effect_manager(v6, (int)&loc_A9D8B + a2 + 1);
  v7 = (_DWORD *)((char *)&loc_EF532 + a2 + 2);
  v8 = (char *)&loc_EF532 + a2 + 14;
  *v7 = v8;
  v7[1] = v8;
  v7[4099] = 0;
  LODWORD(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.x) = (char *)&loc_EF532 + a2 + 2;
  v7[2] = (char *)&loc_EF532 + a2 + 16398;
}
