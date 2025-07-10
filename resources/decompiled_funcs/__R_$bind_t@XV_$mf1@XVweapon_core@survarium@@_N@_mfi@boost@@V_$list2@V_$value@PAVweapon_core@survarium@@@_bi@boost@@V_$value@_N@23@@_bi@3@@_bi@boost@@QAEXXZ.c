void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core,bool>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<bool> > > *this)
{
  survarium::game_camera *v1; // ecx
  unsigned __int8 *v2; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  LOBYTE(v1) = 0;
  survarium::weapon_user_dead_state::finalize(v1);
  ((void (__thiscall *)(char *, _DWORD))LODWORD(this->f_.f_))((char *)this->l_.a1_.t_ + HIDWORD(this->f_.f_), *v2);
}
