void __thiscall survarium::scaleform_movie_cook::translate_query(
        survarium::scaleform_movie_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // [esp-10h] [ebp-50h]
  int v5[2]; // [esp+10h] [ebp-30h] BYREF
  survarium::scaleform_movie_cook *v6; // [esp+18h] [ebp-28h]
  vostok::resources::query_result_for_cook *v7; // [esp+1Ch] [ebp-24h]
  unsigned __int64 v8; // [esp+20h] [ebp-20h]
  void (__thiscall *v9)(survarium::scaleform_movie_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *); // [esp+30h] [ebp-10h]
  vostok::resources::query_result_for_cook *v10; // [esp+34h] [ebp-Ch]
  unsigned __int64 v11; // [esp+38h] [ebp-8h]

  v6 = this;
  v5[0] = (int)survarium::scaleform_movie_cook::on_raw_data_loaded;
  v5[1] = 0;
  v7 = parent;
  v9 = survarium::scaleform_movie_cook::on_raw_data_loaded;
  v10 = 0;
  v11 = __PAIR64__((unsigned int)parent, (unsigned int)this);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    v5[0] = 0;
  }
  else
  {
    v6 = (survarium::scaleform_movie_cook *)v9;
    v7 = v10;
    v8 = v11;
    v5[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::scaleform_movie_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::scaleform_movie_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>'::`2'::stored_vtable
          + 1;
  }
  v4 = survarium::g_allocator;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::resources::query_resource(
    requested_path,
    (vostok::variant<32> *)3,
    v4,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, v5);
}
