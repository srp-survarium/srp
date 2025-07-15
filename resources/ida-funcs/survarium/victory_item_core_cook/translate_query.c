void __thiscall survarium::victory_item_core_cook::translate_query(
        survarium::victory_item_core_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::buffer_string *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::variant<32> *v6; // [esp-4h] [ebp-15Ch]
  vostok::physics::world *v7; // [esp+Ch] [ebp-14Ch] BYREF
  int v8[2]; // [esp+10h] [ebp-148h] BYREF
  survarium::victory_item_core_cook *v9; // [esp+18h] [ebp-140h]
  vostok::physics::world *v10; // [esp+1Ch] [ebp-13Ch]
  unsigned __int64 v11; // [esp+20h] [ebp-138h]
  int (__thiscall *v12)(void *); // [esp+30h] [ebp-128h]
  vostok::physics::world *v13; // [esp+34h] [ebp-124h]
  unsigned __int64 v14; // [esp+38h] [ebp-120h]
  const char *v15[3]; // [esp+40h] [ebp-118h] BYREF
  _BYTE v16[260]; // [esp+4Ch] [ebp-10Ch] BYREF
  char v17; // [esp+150h] [ebp-8h] BYREF

  v15[0] = v16;
  v15[1] = v16;
  v15[2] = &v17;
  v16[0] = 0;
  v17 = 47;
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(v15, v4, (vostok::buffer_string *)"resources/%s", requested_path);
  vostok::variant<32>::try_get<vostok::physics::world *>(v6, (int)parent->m_user_data->m_helper_storage, &v7);
  v9 = this;
  v10 = v7;
  v8[0] = (int) __thiscall survarium::weapon_core_cook::`vcall'{36,{flat}};
  v8[1] = 0;
  v12 =  __thiscall survarium::weapon_core_cook::`vcall'{36,{flat}};
  v13 = 0;
  v14 = __PAIR64__((unsigned int)v7, (unsigned int)this);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *) __thiscall survarium::weapon_core_cook::`vcall'{36,{flat}}) )
  {
    v8[0] = 0;
  }
  else
  {
    v9 = (survarium::victory_item_core_cook *)v12;
    v10 = v13;
    v11 = v14;
    v8[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::victory_item_core_cook,vostok::resources::queries_result &,vostok::physics::world &>,boost::_bi::list3<boost::_bi::value<survarium::victory_item_core_cook *>,boost::arg<1>,boost::reference_wrapper<vostok::physics::world>>>>'::`2'::stored_vtable
          + 1;
  }
  vostok::resources::query_resource(
    v15[0],
    (vostok::variant<32> *)0x20,
    survarium::g_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, v8);
}
