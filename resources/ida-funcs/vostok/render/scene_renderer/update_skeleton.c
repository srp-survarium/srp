void __userpurge vostok::render::scene_renderer::update_skeleton(
        vostok::render::scene_renderer *this@<ecx>,
        int a2@<eax>,
        const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v,
        const vostok::math::float4x4 *matrices,
        unsigned int count)
{
  vostok::render::update_skeleton_command *v6; // esi
  __int32 v7; // eax
  int v8; // ecx
  bool v9; // zf
  vostok::render::render_model_instance *m_object; // [esp-8h] [ebp-10h]

  v6 = (vostok::render::update_skeleton_command *)(*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 8) + 16))(
                                                    *(_DWORD *)(a2 + 8),
                                                    5216);
  if ( v6 )
  {
    m_object = 0;
    if ( v->m_object )
    {
      m_object = v->m_object;
      _InterlockedExchangeAdd(&v->m_object->m_reference_count, 1u);
    }
    vostok::render::update_skeleton_command::update_skeleton_command(
      v6,
      *(vostok::render::engine::world **)a2,
      (vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base>)m_object,
      matrices,
      count);
  }
  else
  {
    v7 = 0;
  }
  v8 = *(_DWORD *)(a2 + 4);
  v9 = *(_DWORD *)(*(_DWORD *)(v8 + 64) + 4) == 0;
  *(_DWORD *)(v7 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)(*(_DWORD *)v8 + 4), v7);
  *(_DWORD *)v8 = v7;
  if ( v9 )
    SetEvent(*(HANDLE *)(v8 + 144));
}
