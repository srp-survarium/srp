void __thiscall survarium::damage_zone_core::hit_on_inside(
        survarium::damage_zone_core *this,
        unsigned int frame_delta,
        unsigned int current_time)
{
  vostok::memory::base_allocator **v3; // eax
  vostok::memory::base_allocator **v4; // eax
  stlp_std::pair<vostok::collision::bone_collision_data *,float> *v5; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > var110; // [esp+8h] [ebp-110h]
  float v9; // [esp+8h] [ebp-110h]
  float left_range_alpha; // [esp+Ch] [ebp-10Ch]
  survarium::hit_initiator *v11; // [esp+14h] [ebp-104h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v13; // [esp+94h] [ebp-84h] BYREF
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > v14; // [esp+98h] [ebp-80h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *f; // [esp+9Ch] [ebp-7Ch]
  vostok::memory::base_allocator **v16; // [esp+A0h] [ebp-78h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v17; // [esp+A4h] [ebp-74h] BYREF
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > __a; // [esp+A8h] [ebp-70h] BYREF
  survarium::hit_receiver_info *M_finish; // [esp+ACh] [ebp-6Ch]
  survarium::hit_receiver_info *M_start; // [esp+B0h] [ebp-68h]
  survarium::vector<survarium::hit_receiver_info> *p_m_receivers; // [esp+B4h] [ebp-64h]
  char v22; // [esp+BBh] [ebp-5Dh]
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > result; // [esp+BCh] [ebp-5Ch] BYREF
  char v24; // [esp+C7h] [ebp-51h]
  float hit_value; // [esp+C8h] [ebp-50h]
  float armor_piercing_value; // [esp+CCh] [ebp-4Ch]
  float hit_coeff; // [esp+D0h] [ebp-48h] BYREF
  const stlp_std::pair<vostok::collision::bone_collision_data *,float> *ub_it; // [esp+D4h] [ebp-44h]
  vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > unique_bones; // [esp+D8h] [ebp-40h] BYREF
  survarium::dz_bone_data_contact_test_predicate predicate; // [esp+E8h] [ebp-30h] BYREF
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > insert_it; // [esp+F4h] [ebp-24h]
  const stlp_std::pair<vostok::collision::bone_collision_data *,float> *ub_end; // [esp+FCh] [ebp-1Ch]
  vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > results; // [esp+100h] [ebp-18h] BYREF
  survarium::hit_receiver_info *end; // [esp+110h] [ebp-8h]
  survarium::hit_receiver_info *it; // [esp+114h] [ebp-4h]

  this->m_accumulated_hit_time_ms += frame_delta;
  p_m_receivers = &this->m_receivers;
  if ( this->m_receivers._M_impl._M_start != this->m_receivers._M_impl._M_finish
    && this->m_accumulated_hit_time_ms >= this->m_hit_interval_ms )
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
        &v17);
      v16 = v3;
      __a.m_allocator = *v3;
      stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&results,
        &__a);
      predicate.__vftable = (survarium::dz_bone_data_contact_test_predicate_vtbl *)&survarium::dz_bone_data_contact_test_predicate::`vftable';
      predicate.m_result = &results;
      predicate.m_body_parts_filter = &this->m_body_parts_filter;
      v24 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&results);
      survarium::collision_sensor::contact_test(this, it->m_rigid_body, &predicate);
      stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
        (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_,
        &v13);
      v14.m_allocator = *v4;
      stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&unique_bones,
        &v14);
      insert_it.container = &unique_bones;
      insert_it._M_iter = unique_bones._M_impl._M_start;
      var110._M_iter = unique_bones._M_impl._M_start;
      var110.container = &unique_bones;
      stlp_std::unique_copy<stlp_std::pair<vostok::collision::bone_collision_data *,float> *,stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float>>>,bool (__cdecl *)(stlp_std::pair<vostok::collision::bone_collision_data *,float> const &,stlp_std::pair<vostok::collision::bone_collision_data *,float> const &)>(
        &result,
        results._M_impl._M_start,
        results._M_impl._M_finish,
        var110,
        survarium::compare_bone_data_predicate);
      v5 = unique_bones._M_impl._M_start;
      ub_it = unique_bones._M_impl._M_start;
      ub_end = unique_bones._M_impl._M_finish;
      while ( ub_it != ub_end )
      {
        if ( *(float *)&clear_value >= ub_it->second )
        {
          hit_coeff = vostok::math::curve_line_points<float,0>::evaluate(
                        &this->m_hit_curve,
                        ub_it->second,
                        0.0,
                        range_time_type,
                        0.0,
                        0.0);
          vostok::math::clamp<float>(&hit_coeff, 0.0, 1.0);
          hit_value = vostok::math::lerp<float>(&this->m_min_hit, &this->m_max_hit, hit_coeff);
          armor_piercing_value = vostok::math::lerp<float>(
                                   &this->m_min_armor_piercing,
                                   &this->m_max_armor_piercing,
                                   hit_coeff);
          if ( this )
            v11 = &this->survarium::hit_initiator;
          else
            v11 = 0;
          left_range_alpha = armor_piercing_value;
          v9 = hit_value;
          v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                 v6,
                 (int)&this->m_damage_type);
          ((void (__thiscall *)(survarium::hit_receiver *, survarium::hit_initiator *, vostok::collision::bone_collision_data *, const vostok::variant<32> **, _DWORD, _DWORD, _DWORD))it->m_receiver->hit)(
            it->m_receiver,
            v11,
            ub_it->first,
            v7,
            LODWORD(v9),
            LODWORD(left_range_alpha),
            0);
          it->m_was_hit = 1;
        }
        v5 = (stlp_std::pair<vostok::collision::bone_collision_data *,float> *)&ub_it[1];
        ++ub_it;
      }
      v22 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
      if ( it->m_was_hit && this->m_owner )
        survarium::zone_group::on_zone_act(this->m_owner, this, it->m_receiver);
      stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>((stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *)&unique_bones);
      stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>((stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *)&results);
      ++it;
    }
    this->m_accumulated_hit_time_ms = 0;
  }
}
