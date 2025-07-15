void __userpurge vostok::sound::sound_scene::sound_scene(
        vostok::sound::sound_scene *this@<ecx>,
        int a2@<edi>,
        vostok::sound::sound_world *world_,
        vostok::threading::mutex_tasks_unaware *creation_params,
        IXAudio2SubmixVoice *submix_voice,
        unsigned int dbg_id,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::sound::atomic_half3 *v7; // ecx
  vostok::sound::atomic_half3 *v8; // ecx
  vostok::sound::atomic_half3 *v9; // ecx
  int v10; // eax
  vostok::threading::mutex_tasks_unaware *v11; // ecx
  vostok::sound::sound_scene *v12; // ecx

  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  v7 = (vostok::sound::atomic_half3 *)vostok::sound::g_allocator;
  *(_DWORD *)a2 = &vostok::sound::sound_scene::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = v7;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = world_;
  vostok::sound::atomic_half3::atomic_half3(v7, (_WORD *)(a2 + 288));
  vostok::sound::atomic_half3::atomic_half3(v8, (_WORD *)(a2 + 296));
  vostok::sound::atomic_half3::atomic_half3(v9, (_WORD *)(a2 + 304));
  v10 = creation_params->m_mutex[0];
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = v10;
  *(_DWORD *)(a2 + 384) = a2 + 328;
  *(_DWORD *)(a2 + 388) = 0;
  *(_DWORD *)(a2 + 392) = 0;
  *(_DWORD *)(a2 + 400) = HIDWORD(creation_params->m_mutex[0]);
  *(_DWORD *)(a2 + 456) = a2 + 408;
  *(_DWORD *)(a2 + 460) = 0;
  *(_DWORD *)(a2 + 464) = 0;
  *(_DWORD *)(a2 + 472) = creation_params->m_mutex[1];
  *(_DWORD *)(a2 + 528) = a2 + 480;
  *(_DWORD *)(a2 + 532) = 0;
  *(_DWORD *)(a2 + 536) = 0;
  *(_DWORD *)(a2 + 592) = a2 + 544;
  *(_DWORD *)(a2 + 596) = 0;
  *(_DWORD *)(a2 + 600) = 0;
  *(_DWORD *)(a2 + 608) = 0;
  *(_DWORD *)(a2 + 612) = 0;
  *(_DWORD *)(a2 + 616) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(creation_params, (_RTL_CRITICAL_SECTION *)(a2 + 624));
  *(_DWORD *)(a2 + 652) = 0;
  *(_DWORD *)(a2 + 656) = 0;
  *(_DWORD *)(a2 + 664) = 0;
  *(_DWORD *)(a2 + 672) = 0;
  *(_DWORD *)(a2 + 676) = 0;
  *(_DWORD *)(a2 + 680) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v11, (_RTL_CRITICAL_SECTION *)(a2 + 688));
  *(_DWORD *)(a2 + 716) = 0;
  *(_DWORD *)(a2 + 720) = 0;
  *(_DWORD *)(a2 + 728) = submix_voice;
  *(_DWORD *)(a2 + 740) = 10;
  *(_DWORD *)(a2 + 744) = 10;
  *(_DWORD *)(a2 + 732) = 0;
  *(float *)(a2 + 736) = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 748) = dbg_id;
  *(_BYTE *)(a2 + 752) = 0;
  *(_BYTE *)(a2 + 753) = 0;
  *(_BYTE *)(a2 + 754) = 0;
  *(_DWORD *)(a2 + 756) = 0;
  *(float *)(a2 + 760) = default_fps_4;
  vostok::sound::sound_scene::init_allocators(v12, (vostok::resources::query_result_for_cook *)a2, parent);
  *(_DWORD *)(a2 + 608) = vostok::sound::new_tree(0x400u);
  *(_DWORD *)(a2 + 612) = vostok::sound::new_tree(0x40u);
}
