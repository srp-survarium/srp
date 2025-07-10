void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::network::match_client_impl *>,boost::_bi::value<unsigned int>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::match_client_impl,unsigned int>,boost::_bi::list2<boost::reference_wrapper<vostok::network::match_client_impl *>,boost::_bi::value<unsigned int> > > *this)
{
  unsigned int *v1; // eax
  vostok::network::match_client_impl **t; // [esp+14h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  t = this->l_.a1_.t_;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)t);
  this->f_.f_(*t, *v1);
}
