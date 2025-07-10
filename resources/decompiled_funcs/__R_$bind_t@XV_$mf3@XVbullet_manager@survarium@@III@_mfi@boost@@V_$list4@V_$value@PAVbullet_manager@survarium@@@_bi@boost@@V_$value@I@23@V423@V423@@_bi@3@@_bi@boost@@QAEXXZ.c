void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > *this)
{
  boost::_bi::list0 a; // [esp+17h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  boost::_bi::list4<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>::operator()<boost::_mfi::mf3<void,survarium::bullet_manager,unsigned int,unsigned int,unsigned int>,boost::_bi::list0>(
    &this->l_,
    0,
    &this->f_,
    &a,
    0);
}
