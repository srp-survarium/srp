void __usercall survarium::game_world_ui::initialize_resources(
        survarium::game_world_ui *this@<esi>,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *game_hud@<eax>)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource *v3; // edi
  survarium::flash_movie_resource *v4; // eax
  survarium::flash_movie_resource *v5; // ecx
  survarium::flash_movie_resource *v6; // eax
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Movie *v8; // ecx

  m_object = game_hud->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = 0;
  if ( v3 )
  {
    v4 = (survarium::flash_movie_resource *)v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  v5 = v4;
  v6 = this->m_game_hud_ui.m_object;
  this->m_game_hud_ui.m_object = v5;
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  ((void (__stdcall *)(_DWORD))this->m_game_hud_ui.m_object->movie->m_movie->SetBackgroundAlpha)(0.0);
  m_movie = this->m_game_hud_ui.m_object->movie->m_movie;
  m_movie->SetViewAlignment(m_movie, Align_TopLeft);
  v8 = this->m_game_hud_ui.m_object->movie->m_movie;
  v8->SetViewScaleMode(v8, SM_NoScale);
}
