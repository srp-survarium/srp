int __thiscall boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::jump_logic>,boost::_bi::list1<boost::_bi::value<survarium::jump_logic *>>>::operator()(
        boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::jump_logic>,boost::_bi::list1<boost::_bi::value<survarium::jump_logic *> > > *this)
{
  survarium::jump_logic *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v1 = (survarium::jump_logic *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)this->l_.a1_.t_);
  return this->f_.f_(v1);
}
