void __thiscall vostok::network::match_client_impl::~match_client_impl(vostok::network::match_client_impl *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::network_core::udp_network_flow_emulator **v6; // [esp-4h] [ebp-20h]

  v6 = (vostok::network_core::udp_network_flow_emulator **)((char *)&dword_258030 + (_DWORD)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::network_core::udp_network_flow_emulator>(
    v1,
    v6);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)((char *)this + (_DWORD)&loc_258B7F + 1));
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v3,
    (int *)((char *)Scaleform::Render::TreeNode::NodeData::operator= + (_DWORD)this));
  vostok::network_core::udp_match_client::~udp_match_client((vostok::network_core::udp_match_client *)((char *)this + (_DWORD)&loc_258034 + 4));
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (int *)((char *)this + (_DWORD)&loc_25800F + 1));
  survarium::weapon_user_dead_state::finalize(v5);
}
