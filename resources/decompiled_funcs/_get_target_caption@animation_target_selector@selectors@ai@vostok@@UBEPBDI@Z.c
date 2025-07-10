vostok::render::skeleton_model_instance *__thiscall vostok::ai::selectors::animation_target_selector::get_target_caption(
        vostok::ai::selectors::animation_target_selector *this,
        unsigned int target_index)
{
  const vostok::ai::animation_item *target; // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  target = this->m_selected_animations.m_begin[target_index];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)target);
  return vostok::fs_new::file_name_from_path<vostok::fs_new::virtual_path_string>((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&target->name);
}
