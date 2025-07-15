void __thiscall vostok::ai::planning::animation_filter::add_filtered_item(
        vostok::ai::planning::animation_filter *this,
        const char *item)
{
  survarium::game_camera *v2; // ecx
  const vostok::fs_new::virtual_path_string *v3; // eax
  vostok::fs_new::path_string_impl v5; // [esp+48h] [ebp-114h] BYREF

  vostok::fs_new::path_string_impl::path_string_impl(&v5, 47, &item);
  survarium::weapon_user_dead_state::finalize(v2);
  stlp_std::priv::_Impl_list<vostok::fs_new::virtual_path_string,vostok::ai::std_allocator<vostok::fs_new::virtual_path_string>>::push_back(
    &this->m_filtered_items._M_impl,
    v3);
}
