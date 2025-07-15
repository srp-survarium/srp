void __thiscall survarium::damage_zone_core::hit_on_motion_inside(
        survarium::damage_zone_core *this,
        unsigned int frame_delta,
        survarium::game_camera *current_time)
{
  _BYTE *v3; // eax
  vostok::memory::base_allocator **v4; // eax
  vostok::memory::base_allocator **v5; // eax
  stlp_std::pair<vostok::collision::bone_collision_data *,float> *v6; // ecx
  survarium::hit_initiator *v7; // ecx
  const vostok::variant<32> **v8; // eax
  float time; // [esp+0h] [ebp-108h]
  float timea; // [esp+0h] [ebp-108h]
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > var100; // [esp+8h] [ebp-100h]
  float v12; // [esp+8h] [ebp-100h]
  float left_range_alpha; // [esp+Ch] [ebp-FCh]
  survarium::hit_initiator *v14; // [esp+14h] [ebp-F4h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v16; // [esp+84h] [ebp-84h] BYREF
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > v17; // [esp+88h] [ebp-80h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *f; // [esp+8Ch] [ebp-7Ch]
  vostok::memory::base_allocator **v19; // [esp+90h] [ebp-78h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v20; // [esp+94h] [ebp-74h] BYREF
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > __a; // [esp+98h] [ebp-70h] BYREF
  survarium::hit_receiver_info *M_finish; // [esp+9Ch] [ebp-6Ch]
  survarium::hit_receiver_info *M_start; // [esp+A0h] [ebp-68h]
  survarium::vector<survarium::hit_receiver_info> *p_m_receivers; // [esp+A4h] [ebp-64h]
  char v25; // [esp+ABh] [ebp-5Dh]
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > result; // [esp+ACh] [ebp-5Ch] BYREF
  char v27; // [esp+B6h] [ebp-52h]
  char v28; // [esp+B7h] [ebp-51h]
  float on_bound_hit; // [esp+B8h] [ebp-50h]
  float hit_val; // [esp+BCh] [ebp-4Ch]
  float on_center_hit; // [esp+C0h] [ebp-48h]
  const stlp_std::pair<vostok::collision::bone_collision_data *,float> *ub_it; // [esp+C4h] [ebp-44h]
  vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > unique_bones; // [esp+C8h] [ebp-40h] BYREF
  survarium::dz_bone_data_contact_test_predicate predicate; // [esp+D8h] [ebp-30h] BYREF
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > insert_it; // [esp+E4h] [ebp-24h]
  const stlp_std::pair<vostok::collision::bone_collision_data *,float> *ub_end; // [esp+ECh] [ebp-1Ch]
  vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > results; // [esp+F0h] [ebp-18h] BYREF
  survarium::hit_receiver_info *end; // [esp+100h] [ebp-8h]
  survarium::hit_receiver_info *it; // [esp+104h] [ebp-4h]

  v28 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(current_time);
  p_m_receivers = &this->m_receivers;
  if ( this->m_receivers._M_impl._M_start != this->m_receivers._M_impl._M_finish )
  {
    M_start = this->m_receivers._M_impl._M_start;
    it = M_start;
    M_finish = this->m_receivers._M_impl._M_finish;
    end = M_finish;
    while ( it != end )
    {
      it->m_was_hit = 0;
      f = (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_;
      stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
        (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_,
        &v20);
      v19 = v4;
      __a.m_allocator = *v4;
      stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&results,
        &__a);
      predicate.__vftable = (survarium::dz_bone_data_contact_test_predicate_vtbl *)&survarium::dz_bone_data_contact_test_predicate::`vftable';
      predicate.m_result = &results;
      predicate.m_body_parts_filter = &this->m_body_parts_filter;
      v27 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&results);
      survarium::collision_sensor::contact_test(this, it->m_rigid_body, &predicate);
      stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
        (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_,
        &v16);
      v17.m_allocator = *v5;
      stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&unique_bones,
        &v17);
      insert_it.container = &unique_bones;
      insert_it._M_iter = unique_bones._M_impl._M_start;
      var100._M_iter = unique_bones._M_impl._M_start;
      var100.container = &unique_bones;
      stlp_std::unique_copy<stlp_std::pair<vostok::collision::bone_collision_data *,float> *,stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float>>>,bool (__cdecl *)(stlp_std::pair<vostok::collision::bone_collision_data *,float> const &,stlp_std::pair<vostok::collision::bone_collision_data *,float> const &)>(
        &result,
        results._M_impl._M_start,
        results._M_impl._M_finish,
        var100,
        survarium::compare_bone_data_predicate);
      v6 = unique_bones._M_impl._M_start;
      ub_it = unique_bones._M_impl._M_start;
      ub_end = unique_bones._M_impl._M_finish;
      while ( ub_it != ub_end )
      {
        if ( *(float *)&clear_value >= ub_it->second )
        {
          time = it->m_receiver->get_speed(it->m_receiver);
          on_bound_hit = vostok::math::curve_line_points<float,0>::evaluate(
                           &this->m_motion_on_bound_curve,
                           time,
                           0.0,
                           range_time_type,
                           0.0,
                           0.0);
          timea = it->m_receiver->get_speed(it->m_receiver);
          on_center_hit = vostok::math::curve_line_points<float,0>::evaluate(
                            &this->m_motion_on_center_curve,
                            timea,
                            0.0,
                            range_time_type,
                            0.0,
                            0.0);
          hit_val = vostok::math::lerp<float>(
                      &this->m_min_hit,
                      &this->m_max_hit,
                      (float)(on_bound_hit + on_center_hit) / 2.0);
          if ( this )
          {
            v7 = &this->survarium::hit_initiator;
            v14 = &this->survarium::hit_initiator;
          }
          else
          {
            v14 = 0;
          }
          left_range_alpha = this->m_max_armor_piercing;
          v12 = hit_val;
          v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                 (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v7,
                 (int)&this->m_damage_type);
          ((void (__thiscall *)(survarium::hit_receiver *, survarium::hit_initiator *, vostok::collision::bone_collision_data *, const vostok::variant<32> **, _DWORD, _DWORD, _DWORD))it->m_receiver->hit)(
            it->m_receiver,
            v14,
            ub_it->first,
            v8,
            LODWORD(v12),
            LODWORD(left_range_alpha),
            0);
          it->m_was_hit = 1;
        }
        v6 = (stlp_std::pair<vostok::collision::bone_collision_data *,float> *)&ub_it[1];
        ++ub_it;
      }
      v25 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v6);
      if ( it->m_was_hit && this->m_owner )
        survarium::zone_group::on_zone_act(this->m_owner, this, it->m_receiver);
      stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>((stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *)&unique_bones);
      stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>((stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *)&results);
      ++it;
    }
  }
}
