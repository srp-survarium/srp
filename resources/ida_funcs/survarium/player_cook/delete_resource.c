void __thiscall survarium::player_cook::delete_resource(
        survarium::player_cook *this,
        vostok::resources::resource_base *resource)
{
  void **p_m_target_quality_level; // esi
  int f; // ebx
  _BYTE *v4; // edi
  void *v5; // esi

  if ( resource )
    p_m_target_quality_level = (void **)&resource[-2].m_target_quality_level;
  else
    p_m_target_quality_level = 0;
  f = (int)survarium::g_allocator.f_.f_;
  if ( p_m_target_quality_level )
  {
    v4 = __RTCastToVoid(p_m_target_quality_level);
    (*(void (__thiscall **)(void **, _DWORD))*p_m_target_quality_level)(p_m_target_quality_level, 0);
    if ( v4 )
    {
      v5 = *(void **)(f + 20);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(v5, v4);
    }
  }
}
