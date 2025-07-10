int __cdecl boost::detail::function::function_obj_invoker0<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>,bool>::invoke(
        boost::detail::function::function_buffer *function_obj_ptr)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)function_obj_ptr);
  return ((int (*)(void))function_obj_ptr->obj_ptr)();
}
