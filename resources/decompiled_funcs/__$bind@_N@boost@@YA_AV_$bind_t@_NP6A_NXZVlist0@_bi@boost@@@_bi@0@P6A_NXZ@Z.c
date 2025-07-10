boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *__cdecl boost::bind<bool>(
        boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> *result,
        bool (__cdecl *f)())
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize(v2);
  result->f_ = f;
  return result;
}
