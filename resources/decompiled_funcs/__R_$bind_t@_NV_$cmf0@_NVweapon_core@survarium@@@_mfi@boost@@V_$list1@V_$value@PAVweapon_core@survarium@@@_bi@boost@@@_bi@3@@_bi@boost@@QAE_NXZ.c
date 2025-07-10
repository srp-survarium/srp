int __thiscall boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>::operator()(
        boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *this)
{
  vostok::sound::sound_world *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v1 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)this->l_.a1_.t_);
  return ((int (__thiscall *)(int))LODWORD(this->f_.f_))((int)v1 + HIDWORD(this->f_.f_));
}
