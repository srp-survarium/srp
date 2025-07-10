void __thiscall vostok::ai::sensors::vision_sensor::check_frustum(vostok::ai::sensors::vision_sensor *this)
{
  const vostok::math::float4x4 *v1; // eax
  const vostok::math::float4x4 *v2; // eax
  float aspect_ratio; // [esp+0h] [ebp-1D0h]
  float near_plane_distance; // [esp+4h] [ebp-1CCh]
  float far_plane; // [esp+8h] [ebp-1C8h]
  float v6; // [esp+Ch] [ebp-1C4h]
  vostok::ai::sensors::vision_sensor *thisa; // [esp+10h] [ebp-1C0h]
  float v9; // [esp+14h] [ebp-1BCh]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v10; // [esp+1Ch] [ebp-1B4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+60h] [ebp-170h] BYREF
  void (__userpurge *f)(vostok::ai::sensors::vision_sensor *@<ecx>, float@<xmm0>, const vostok::ai::game_object *); // [esp+70h] [ebp-160h]
  int f_4; // [esp+74h] [ebp-15Ch]
  vostok::math::float4x4 v14; // [esp+B8h] [ebp-118h] BYREF
  boost::function<void __cdecl(vostok::ai::game_object const &)> callback; // [esp+F8h] [ebp-D8h] BYREF
  vostok::math::frustum view_frustum; // [esp+118h] [ebp-B8h] BYREF
  vostok::math::float4x4 projection; // [esp+190h] [ebp-40h] BYREF

  far_plane = this->m_parameters.far_plane_distance;
  near_plane_distance = this->m_parameters.near_plane_distance;
  aspect_ratio = this->m_parameters.aspect_ratio;
  vostok::math::deg2rad();
  vostok::math::create_perspective_projection(
    (vostok::math *)LODWORD(aspect_ratio),
    (struct vostok::math::float4x4 *)LODWORD(near_plane_distance),
    far_plane,
    v6,
    *(float *)&this,
    v9);
  v1 = thisa->m_npc->get_eyes_matrix(thisa->m_npc, &v14);
  v2 = vostok::math::mul4x4(v1, &projection);
  vostok::math::frustum::frustum(&view_frustum, v2);
  f = vostok::ai::sensors::vision_sensor::update_frustum_objects;
  f_4 = 0;
  v10 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::sensors::vision_sensor::update_frustum_objects,
           (survarium::weapon_core_animation_end_aware_state *)thisa);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v10.l_.a1_.t_,
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&stru_9803D4.m_buffer[8],
         (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > >)v10,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)&stru_9803D4.m_buffer[9];
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::ai::ai_world::get_visible_objects(thisa->m_world, &view_frustum, &callback);
  boost::function1<void,vostok::ai::game_object const &>::clear(&callback.boost::function1<void,vostok::ai::game_object const &>);
}
