void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::oxygen_tank,unsigned int>,boost::_bi::list2<boost::_bi::value<survarium::oxygen_tank *>,boost::arg<1>>>::operator()<unsigned int,unsigned int>(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::oxygen_tank,unsigned int>,boost::_bi::list2<boost::_bi::value<survarium::oxygen_tank *>,boost::arg<1> > > *this,
        unsigned __int8 *a1,
        unsigned int *a2)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6[2]; // [esp+17h] [ebp-9h] BYREF

  boost::_bi::list2<unsigned int &,unsigned int &>::list2<unsigned int &,unsigned int &>(
    (boost::_bi::list2<unsigned int &,unsigned int &> *)((char *)v6 + 1),
    a1,
    a2);
  LOBYTE(v3) = 0;
  v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v6 + 1);
  ((void (__thiscall *)(char *, const vostok::variant<32> *))LODWORD(this->f_.f_))(
    (char *)this->l_.a1_.t_ + HIDWORD(this->f_.f_),
    *v4);
}


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_core *>,boost::arg<1>,boost::arg<2>>>::operator()<unsigned int,unsigned int>(
        boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::damage_zone_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::damage_zone_core *>,boost::arg<1>,boost::arg<2> > > *this,
        unsigned __int8 *a1,
        unsigned int *a2)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // eax
  const void *pointer; // [esp+Ch] [ebp-18h]
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v8[2]; // [esp+1Bh] [ebp-9h] BYREF

  boost::_bi::list2<unsigned int &,unsigned int &>::list2<unsigned int &,unsigned int &>(
    (boost::_bi::list2<unsigned int &,unsigned int &> *)((char *)v8 + 1),
    a1,
    a2);
  LOBYTE(v3) = 0;
  pointer = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
              v3,
              (int)v8 + 1)->config.data.pointer;
  v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)v8 + 1);
  ((void (__thiscall *)(char *, const vostok::variant<32> *, const void *))LODWORD(this->f_.f_))(
    (char *)this->l_.a1_.t_ + HIDWORD(this->f_.f_),
    *v5,
    pointer);
}


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,char const *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1>>>::operator()<char const *>(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::bullet_manager,char const *>,boost::_bi::list2<boost::_bi::value<survarium::bullet_manager *>,boost::arg<1> > > *this,
        const char **a1)
{
  this->f_.f_(this->l_.a1_.t_, *a1);
}


void __thiscall boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1>>>::operator()<vostok::ai::brain_unit const *>(
        boost::_bi::bind_t<void,boost::_mfi::cmf0<void,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *this,
        const vostok::ai::brain_unit **a1)
{
  vostok::sound::sound_world *v2; // eax

  v2 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)*a1);
  ((void (__thiscall *)(int))LODWORD(this->f_.f_))((int)v2 + HIDWORD(this->f_.f_));
}


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1>>>::operator()<bool>(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1> > > *this,
        bool *a1)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1> > > *thisa; // [esp+0h] [ebp-14h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // [esp+Fh] [ebp-5h] BYREF

  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)a1,
    (vostok::network_core::packet_reader *)this);
  LOBYTE(v2) = 0;
  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)&v5 + 1);
  ((void (__thiscall *)(int, _DWORD))LODWORD(thisa->f_.f_))(
    (int)thisa->l_.a1_.t_ + HIDWORD(thisa->f_.f_),
    *(unsigned __int8 *)v3);
}


void __thiscall boost::_bi::bind_t<void,void (__cdecl *)(vostok::network_core::http_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::http_client *>>>::operator()(
        boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::tcp_packet_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->f_(this->l_.a1_.t_);
}


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::login_client>,boost::_bi::list1<boost::_bi::value<vostok::network::login_client *>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::player_logic_sprint_state>,boost::_bi::list1<boost::_bi::value<survarium::player_logic_sprint_state *> > > *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->f_.f_(this->l_.a1_.t_);
}


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client_impl>,boost::_bi::list1<boost::reference_wrapper<vostok::network::match_client_impl *>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::match_client_impl>,boost::_bi::list1<boost::reference_wrapper<vostok::network::match_client_impl *> > > *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->f_.f_(*this->l_.a1_.t_);
}


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > *this)
{
  ((void (__thiscall *)(vostok::sound::sound_debug_stats *, boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > *))this->f_.f_)(
    this->l_.a1_.t_,
    this);
}


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


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_voice,void *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_voice *>,boost::_bi::value<void *> > > *this)
{
  this->f_.f_(this->l_.a1_.t_, this->l_.a2_.t_);
}


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,float>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<float>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,float>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<float> > > *this)
{
  ((void (__thiscall *)(char *, _DWORD))LODWORD(this->f_.f_))(
    (char *)this->l_.a1_.t_ + HIDWORD(this->f_.f_),
    LODWORD(this->l_.a2_.t_));
}


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


void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64>>>::operator()(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64> > > *this)
{
  ((void (__thiscall *)(vostok::sound::world_user *, _DWORD, _DWORD))this->f_.f_)(
    this->l_.a1_.t_,
    this->l_.a2_.t_,
    HIDWORD(this->l_.a2_.t_));
}


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


int __thiscall boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::jump_logic>,boost::_bi::list1<boost::_bi::value<survarium::jump_logic *>>>::operator()(
        boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::jump_logic>,boost::_bi::list1<boost::_bi::value<survarium::jump_logic *> > > *this)
{
  survarium::jump_logic *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v1 = (survarium::jump_logic *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)this->l_.a1_.t_);
  return this->f_.f_(v1);
}


int __thiscall boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>::operator()(
        boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *this)
{
  vostok::sound::sound_world *v1; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v1 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)this->l_.a1_.t_);
  return ((int (__thiscall *)(int))LODWORD(this->f_.f_))((int)v1 + HIDWORD(this->f_.f_));
}
