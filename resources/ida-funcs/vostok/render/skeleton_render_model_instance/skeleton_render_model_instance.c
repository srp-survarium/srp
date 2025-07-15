void __usercall vostok::render::skeleton_render_model_instance::skeleton_render_model_instance(
        vostok::render::skeleton_render_model_instance *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::render_model_instance_impl::render_model_instance_impl(
    &this->vostok::render::render_model_instance_impl,
    a2);
  *(_DWORD *)a2 = &vostok::render::skeleton_render_model_instance::`vftable';
  *(_DWORD *)(a2 + 608) = a2 + 620;
  *(_DWORD *)(a2 + 612) = a2 + 620;
  *(_DWORD *)(a2 + 616) = a2 + 8812;
  *(_DWORD *)(a2 + 8812) = a2 + 8824;
  *(_DWORD *)(a2 + 8816) = a2 + 8824;
  *(_DWORD *)(a2 + 8820) = a2 + 17016;
  *(_DWORD *)(a2 + 17016) = a2 + 17028;
  *(_DWORD *)(a2 + 17020) = a2 + 17028;
  *(_DWORD *)(a2 + 17024) = a2 + 25220;
  *(_DWORD *)(a2 + 25220) = 0;
  *(_BYTE *)(a2 + 25224) = 0;
  *(_DWORD *)(a2 + 25228) = 0;
  *(_BYTE *)(a2 + 25232) = 1;
  *(_DWORD *)(a2 + 25240) = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)(a2 + 25220),
    (_RTL_CRITICAL_SECTION *)(a2 + 25248));
  *(_DWORD *)(a2 + 25276) = 0;
  *(_DWORD *)(a2 + 25280) = 0;
}
