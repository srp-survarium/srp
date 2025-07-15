void __userpurge survarium::npc_stats::draw(
        survarium::npc_stats *this@<ecx>,
        int a2@<eax>,
        vostok::render::ui::renderer *ui_renderer,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  (*(void (__thiscall **)(_DWORD, vostok::render::ui::renderer *, const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *))(**(_DWORD **)(a2 + 4) + 24))(
    *(_DWORD *)(a2 + 4),
    ui_renderer,
    scene_view);
}
