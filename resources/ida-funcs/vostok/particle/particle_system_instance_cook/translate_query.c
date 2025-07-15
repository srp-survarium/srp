void __thiscall vostok::particle::particle_system_instance_cook::translate_query(
        vostok::particle::particle_system_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::memory::base_allocator *m_allocator; // [esp-10h] [ebp-50h]
  int v6[2]; // [esp+10h] [ebp-30h] BYREF
  __int64 v7; // [esp+18h] [ebp-28h]
  __int64 v8; // [esp+20h] [ebp-20h]
  __int64 v9; // [esp+30h] [ebp-10h]
  __int64 v10; // [esp+38h] [ebp-8h]

  v6[0] = (int)vostok::particle::particle_system_instance_cook::on_sub_resources_loaded;
  v6[1] = 0;
  LODWORD(v7) = this;
  LODWORD(v9) = vostok::particle::particle_system_instance_cook::on_sub_resources_loaded;
  HIDWORD(v9) = 0;
  v10 = v7;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v6[0] = 0;
  }
  else
  {
    v7 = v9;
    v8 = v10;
    v6[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::particle::particle_system_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::particle::particle_system_instance_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
          + 1;
  }
  m_allocator = this->m_allocator;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    (vostok::variant<32> *)0x3B,
    m_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v6);
}
