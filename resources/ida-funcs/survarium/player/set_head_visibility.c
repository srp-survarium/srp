void __usercall survarium::player::set_head_visibility(survarium::player *this@<esi>, char is_visible@<al>)
{
  int v2; // ecx
  vostok::render::scene_renderer *v3; // [esp-10h] [ebp-14h]
  vostok::render::scene_renderer *v4; // [esp-10h] [ebp-14h]

  if ( byte_10F78[(_DWORD)this] != is_visible )
  {
    byte_10F78[(_DWORD)this] = is_visible;
    v3 = *(vostok::render::scene_renderer **)(*(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F00 + (_DWORD)this) + 168)
                                                        + 148)
                                            + 16);
    vostok::render::scene_renderer::set_model_visible(
      v3,
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)v3,
      (unsigned int)&this->m_current.model.m_object->m_render_model,
      0);
    vostok::render::scene_renderer::set_model_visible(
      *(vostok::render::scene_renderer **)(*(int *)((char *)&dword_10F00 + (_DWORD)this) + 168),
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)(*(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F00 + (_DWORD)this) + 168) + 148) + 16),
      (unsigned int)&this->m_current.model.m_object->m_render_model,
      6u);
    v2 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F00 + (_DWORD)this) + 168) + 148);
    vostok::render::scene_renderer::set_model_visible(
      (vostok::render::scene_renderer *)v2,
      *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)(v2 + 16),
      (unsigned int)&this->m_current.model.m_object->m_render_model,
      7u);
    v4 = *(vostok::render::scene_renderer **)(*(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F00 + (_DWORD)this) + 168)
                                                        + 148)
                                            + 16);
    vostok::render::scene_renderer::set_model_visible(
      v4,
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)v4,
      (unsigned int)&this->m_current.model.m_object->m_render_model,
      5u);
  }
}
