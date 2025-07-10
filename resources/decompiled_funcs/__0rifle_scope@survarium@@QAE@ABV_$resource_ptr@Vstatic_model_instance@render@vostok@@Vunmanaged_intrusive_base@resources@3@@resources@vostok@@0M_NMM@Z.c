void __userpurge survarium::rifle_scope::rifle_scope(
        survarium::rifle_scope *this@<ecx>,
        int a2@<esi>,
        const vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *idle_scope,
        const vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *aimed_scope,
        float change_scope_factor,
        bool hide_weapon_on_aim,
        float fov_factor,
        float near_plane_factor)
{
  vostok::render::static_model_instance *m_object; // eax
  vostok::render::static_model_instance *v9; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &survarium::rifle_scope::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  m_object = idle_scope->m_object;
  if ( idle_scope->m_object )
  {
    *(_DWORD *)(a2 + 264) = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  *(_DWORD *)(a2 + 268) = 0;
  v9 = aimed_scope->m_object;
  if ( aimed_scope->m_object )
  {
    *(_DWORD *)(a2 + 268) = v9;
    _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
  }
  *(float *)(a2 + 272) = change_scope_factor;
  *(float *)(a2 + 276) = fov_factor;
  *(float *)(a2 + 280) = near_plane_factor;
  *(_BYTE *)(a2 + 284) = hide_weapon_on_aim;
}
