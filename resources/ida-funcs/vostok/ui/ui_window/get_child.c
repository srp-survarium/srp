vostok::sound::sound_world_vtbl *__thiscall vostok::ui::ui_window::get_child(
        vostok::ui::ui_window *this,
        unsigned int idx)
{
  return boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)&this->m_children._M_impl._M_start[idx])->__vftable;
}
