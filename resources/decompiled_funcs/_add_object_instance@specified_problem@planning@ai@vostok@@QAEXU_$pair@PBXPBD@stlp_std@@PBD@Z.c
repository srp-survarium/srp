void __thiscall vostok::ai::planning::specified_problem::add_object_instance(
        vostok::ai::planning::specified_problem *this,
        stlp_std::pair<void const *,char const *> instance,
        char *caption)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  boost::_bi::list1<vostok::network_core::packet_reader &> *v6; // [esp+8h] [ebp-242Ch]
  vostok::ai::planning::object_instance value; // [esp+2318h] [ebp-11Ch] BYREF
  char v8; // [esp+242Fh] [ebp-5h]
  unsigned int type; // [esp+2430h] [ebp-4h] BYREF

  type = vostok::ai::planning::pddl_domain::get_registered_type(this->m_domain, instance.second);
  v8 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( vostok::ai::planning::specified_problem::get_object_index(this, type, &instance.first) == -1 )
  {
    value.m_type = type;
    value.m_instance = instance.first;
    vostok::fixed_string<256>::fixed_string<256>(&value.m_caption, caption);
    v6 = stlp_std::map<unsigned int,vostok::fixed_vector<vostok::ai::planning::object_instance,16>,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>>::operator[]<unsigned int>(
           &this->m_objects,
           &type);
    survarium::weapon_user_dead_state::finalize(v4);
    vostok::buffer_vector<vostok::ai::planning::object_instance>::construct(
      (vostok::ai::planning::object_instance *)v6[1].a1_,
      &value);
    v6[1].a1_ = (vostok::network_core::packet_reader *)((char *)v6[1].a1_ + 276);
  }
}
