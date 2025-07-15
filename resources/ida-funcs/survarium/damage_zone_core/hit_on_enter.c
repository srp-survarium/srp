void __thiscall survarium::damage_zone_core::hit_on_enter(
        survarium::damage_zone_core *this,
        unsigned int frame_delta,
        survarium::game_camera *current_time)
{
  _BYTE *v3; // eax
  vostok::memory::base_allocator **v4; // eax
  survarium::game_camera *v5; // ecx
  vostok::memory::base_allocator **v6; // eax
  survarium::game_camera *v7; // ecx
  const vostok::variant<32> **v8; // eax
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > v9; // [esp+0h] [ebp-154h]
  float m_max_hit; // [esp+0h] [ebp-154h]
  float m_max_armor_piercing; // [esp+4h] [ebp-150h]
  survarium::hit_initiator *v12; // [esp+Ch] [ebp-148h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v14; // [esp+DCh] [ebp-78h] BYREF
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > v15; // [esp+E0h] [ebp-74h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *f; // [esp+E4h] [ebp-70h]
  vostok::memory::base_allocator **v17; // [esp+E8h] [ebp-6Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v18; // [esp+ECh] [ebp-68h] BYREF
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > __a; // [esp+F0h] [ebp-64h] BYREF
  survarium::hit_receiver_info *M_finish; // [esp+F4h] [ebp-60h]
  survarium::hit_receiver_info *M_start; // [esp+F8h] [ebp-5Ch]
  survarium::vector<survarium::hit_receiver_info> *p_m_receivers; // [esp+FCh] [ebp-58h]
  char v23; // [esp+103h] [ebp-51h]
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > result; // [esp+104h] [ebp-50h] BYREF
  char v25; // [esp+10Eh] [ebp-46h]
  char v26; // [esp+10Fh] [ebp-45h]
  const stlp_std::pair<vostok::collision::bone_collision_data *,float> *ub_it; // [esp+110h] [ebp-44h]
  vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > unique_bones; // [esp+114h] [ebp-40h] BYREF
  survarium::dz_bone_data_contact_test_predicate predicate; // [esp+124h] [ebp-30h] BYREF
  stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > > insert_it; // [esp+130h] [ebp-24h]
  const stlp_std::pair<vostok::collision::bone_collision_data *,float> *ub_end; // [esp+138h] [ebp-1Ch]
  vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float> > results; // [esp+13Ch] [ebp-18h] BYREF
  survarium::hit_receiver_info *end; // [esp+14Ch] [ebp-8h]
  survarium::hit_receiver_info *it; // [esp+150h] [ebp-4h]

  v26 = 0;
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
      if ( !it->m_was_hit )
      {
        f = (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_;
        stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
          (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_,
          &v18);
        v17 = v4;
        __a.m_allocator = *v4;
        stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
          (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&results,
          &__a);
        predicate.__vftable = (survarium::dz_bone_data_contact_test_predicate_vtbl *)&survarium::dz_bone_data_contact_test_predicate::`vftable';
        predicate.m_result = &results;
        predicate.m_body_parts_filter = &this->m_body_parts_filter;
        v25 = 0;
        survarium::weapon_user_dead_state::finalize(v5);
        survarium::collision_sensor::contact_test(this, it->m_rigid_body, &predicate);
        stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
          (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_,
          &v14);
        v15.m_allocator = *v6;
        stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
          (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&unique_bones,
          &v15);
        insert_it.container = &unique_bones;
        insert_it._M_iter = unique_bones._M_impl._M_start;
        v9._M_iter = unique_bones._M_impl._M_start;
        v9.container = &unique_bones;
        stlp_std::unique_copy<stlp_std::pair<vostok::collision::bone_collision_data *,float> *,stlp_std::insert_iterator<vostok::vectora<stlp_std::pair<vostok::collision::bone_collision_data *,float>>>,bool (__cdecl *)(stlp_std::pair<vostok::collision::bone_collision_data *,float> const &,stlp_std::pair<vostok::collision::bone_collision_data *,float> const &)>(
          &result,
          results._M_impl._M_start,
          results._M_impl._M_finish,
          v9,
          survarium::compare_bone_data_predicate);
        ub_it = unique_bones._M_impl._M_start;
        v7 = (survarium::game_camera *)unique_bones._M_impl._M_finish;
        ub_end = unique_bones._M_impl._M_finish;
        while ( ub_it != ub_end )
        {
          v7 = (survarium::game_camera *)ub_it;
          if ( *(float *)&clear_value >= ub_it->second )
          {
            if ( this )
              v12 = &this->survarium::hit_initiator;
            else
              v12 = 0;
            m_max_armor_piercing = this->m_max_armor_piercing;
            m_max_hit = this->m_max_hit;
            v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                   (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                   (int)&this->m_damage_type);
            ((void (__thiscall *)(survarium::hit_receiver *, survarium::hit_initiator *, vostok::collision::bone_collision_data *, const vostok::variant<32> **, _DWORD, _DWORD, _DWORD))it->m_receiver->hit)(
              it->m_receiver,
              v12,
              ub_it->first,
              v8,
              LODWORD(m_max_hit),
              LODWORD(m_max_armor_piercing),
              0);
            v7 = (survarium::game_camera *)it;
            it->m_was_hit = 1;
          }
          ++ub_it;
        }
        v23 = 0;
        survarium::weapon_user_dead_state::finalize(v7);
        if ( it->m_was_hit && this->m_owner )
          survarium::zone_group::on_zone_act(this->m_owner, this, it->m_receiver);
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>((stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *)&unique_bones);
        stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>((stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64> > *)&results);
      }
      ++it;
    }
  }
}
