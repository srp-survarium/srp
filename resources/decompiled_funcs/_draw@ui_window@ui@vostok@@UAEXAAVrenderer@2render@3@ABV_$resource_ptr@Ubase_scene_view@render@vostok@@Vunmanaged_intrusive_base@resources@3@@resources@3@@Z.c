void __thiscall vostok::ui::ui_window::draw(
        vostok::ui::ui_window *this,
        vostok::render::ui::renderer *render,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  void **M_finish; // ebx
  void **i; // edi
  void *v5; // esi

  M_finish = this->m_children._M_impl._M_finish;
  for ( i = this->m_children._M_impl._M_start; i != M_finish; ++i )
  {
    v5 = *i;
    if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)*i + 20))(*i) )
      (*(void (__thiscall **)(void *, vostok::render::ui::renderer *, const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *))(*(_DWORD *)v5 + 24))(
        v5,
        render,
        scene_view);
  }
}
