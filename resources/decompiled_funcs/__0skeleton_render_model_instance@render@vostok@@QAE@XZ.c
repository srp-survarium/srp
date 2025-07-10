void __usercall vostok::render::skeleton_render_model_instance::skeleton_render_model_instance(
        vostok::render::skeleton_render_model_instance *this@<ecx>,
        int a2@<esi>)
{
  vostok::collision::object *v2; // ecx

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = 0;
  *(_BYTE *)(a2 + 268) = -1;
  vostok::collision::object::object(v2, a2 + 272);
  *(_DWORD *)(a2 + 272) = &stru_962594.m_input_layouts._M_t._M_key_compare;
  *(_DWORD *)(a2 + 320) = a2;
  *(_DWORD *)(a2 + 312) = 1;
  *(_DWORD *)a2 = &vostok::render::skeleton_render_model_instance::`vftable';
  *(_DWORD *)(a2 + 392) = 0;
  *(_DWORD *)(a2 + 396) = 0;
  *(_DWORD *)(a2 + 400) = 0;
  *(_DWORD *)(a2 + 404) = 0;
  *(_DWORD *)(a2 + 408) = 0;
  *(_DWORD *)(a2 + 412) = 0;
  *(_DWORD *)(a2 + 416) = 0;
  *(_BYTE *)(a2 + 420) = 0;
  *(_DWORD *)(a2 + 424) = 0;
}
