void __thiscall vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(
        vostok::buffer_vector<vostok::ai::planning::action_parameter *> *this,
        vostok::ai::planning::action_parameter ***begin,
        vostok::ai::planning::action_parameter ***end)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::ai::planning::action_parameter **k; // [esp+8h] [ebp-24h]
  vostok::ai::planning::action_parameter **v9; // [esp+Ch] [ebp-20h]
  vostok::ai::planning::action_parameter **j; // [esp+18h] [ebp-14h]
  vostok::ai::planning::action_parameter **i; // [esp+1Ch] [ebp-10h]
  unsigned int size; // [esp+20h] [ebp-Ch]
  unsigned int count; // [esp+28h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::weapon_user_dead_state::finalize(v6);
  if ( *begin != *end )
  {
    i = *begin;
    for ( j = *end; j != this->m_end; ++j )
    {
      v9 = (vostok::ai::planning::action_parameter **)operator new(4u, i);
      if ( v9 )
        *v9 = *j;
      ++i;
    }
    count = *end - *begin;
    size = this->m_end - this->m_begin;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    for ( k = &this->m_begin[size - count]; k != this->m_end; ++k )
      ;
    this->m_end = &this->m_begin[size - count];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  }
}


void __thiscall vostok::buffer_vector<void const *>::erase(
        vostok::buffer_vector<void const *> *this,
        vostok::buffer_vector<void const *> *begin,
        const void ***end,
        const void **const *enda)
{
  const void **v4; // ebx
  const void **v5; // esi
  const void ***i; // edi
  signed int v7; // esi
  int v8; // esi

  v4 = *end;
  v5 = *enda;
  if ( *end != *enda )
  {
    for ( i = &begin->m_end; v5 != *i; ++v4 )
    {
      boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>();
      vostok::buffer_vector<void const *>::construct(v4, v5++);
    }
    v7 = *enda - *end;
    v8 = vostok::buffer_vector<void const *>::size(begin) - v7;
    vostok::buffer_vector<void const *>::destroy(&begin->m_begin[v8], &begin->m_end);
    *i = &begin->m_begin[v8];
  }
}


void __thiscall vostok::buffer_vector<survarium::client_player_update>::erase(
        vostok::buffer_vector<survarium::client_player_update> *this,
        vostok::buffer_vector<survarium::client_player_update> *begin,
        survarium::client_player_update *const *end,
        survarium::client_player_update *const *enda)
{
  unsigned int v4; // edx
  survarium::client_player_update *v5; // eax

  v4 = (unsigned int)*end;
  v5 = *enda;
  if ( *end != *enda )
  {
    for ( ; v5 != begin->m_end; v4 += 92 )
    {
      if ( v4 )
      {
        *(float *)v4 = v5->input.angular_velocity.x;
        *(float *)(v4 + 4) = v5->input.angular_velocity.y;
        *(float *)(v4 + 8) = v5->input.angular_acceleration.x;
        *(float *)(v4 + 12) = v5->input.angular_acceleration.y;
        *(_DWORD *)(v4 + 16) = v5->input.actions_mask;
        qmemcpy((void *)(v4 + 20), &v5->state, 0x48u);
      }
      ++v5;
    }
    begin->m_end = &begin->m_begin[begin->m_end - begin->m_begin - (*enda - *end)];
  }
}


void __usercall vostok::buffer_vector<vostok::memory::platform::region>::erase(
        vostok::buffer_vector<vostok::memory::platform::region> *this@<edx>,
        vostok::memory::platform::region *const *begin@<edi>,
        vostok::memory::platform::region *const *end@<eax>)
{
  _QWORD *v3; // ecx
  int v5; // eax

  v3 = *begin;
  v5 = (int)*end;
  if ( *begin != (vostok::memory::platform::region *const)v5 )
  {
    for ( ; (vostok::memory::platform::region *)v5 != this->m_end; v3 += 2 )
    {
      if ( v3 )
      {
        *v3 = *(_QWORD *)v5;
        v3[1] = *(_QWORD *)(v5 + 8);
      }
      v5 += 16;
    }
    this->m_end = &this->m_begin[this->m_end - this->m_begin - (*end - *begin)];
  }
}


void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum>>::erase(
        vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *this,
        stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> **begin,
        stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> **end)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *k; // [esp+8h] [ebp-24h]
  survarium::hit_affects_type_enum *v9; // [esp+Ch] [ebp-20h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *j; // [esp+18h] [ebp-14h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *i; // [esp+1Ch] [ebp-10h]
  unsigned int size; // [esp+20h] [ebp-Ch]
  unsigned int count; // [esp+28h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::weapon_user_dead_state::finalize(v6);
  if ( *begin != *end )
  {
    i = *begin;
    for ( j = *end; j != this->m_end; ++j )
    {
      v9 = (survarium::hit_affects_type_enum *)operator new(8u, i);
      if ( v9 )
      {
        *v9 = j->first;
        v9[1] = (survarium::hit_affects_type_enum)j->second;
      }
      ++i;
    }
    count = *end - *begin;
    size = this->m_end - this->m_begin;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
    for ( k = &this->m_begin[size - count]; k != this->m_end; ++k )
      ;
    this->m_end = &this->m_begin[size - count];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  }
}


void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float>>::erase(
        vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float> > *this,
        stlp_std::pair<vostok::ai::npc const *,float> **begin,
        stlp_std::pair<vostok::ai::npc const *,float> **end)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  stlp_std::pair<vostok::ai::npc const *,float> *k; // [esp+8h] [ebp-24h]
  float *v9; // [esp+Ch] [ebp-20h]
  stlp_std::pair<vostok::ai::npc const *,float> *j; // [esp+18h] [ebp-14h]
  stlp_std::pair<vostok::ai::npc const *,float> *i; // [esp+1Ch] [ebp-10h]
  survarium::game_camera *size; // [esp+20h] [ebp-Ch]
  unsigned int new_size; // [esp+24h] [ebp-8h]
  unsigned int count; // [esp+28h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::weapon_user_dead_state::finalize(v6);
  if ( *begin != *end )
  {
    i = *begin;
    for ( j = *end; j != this->m_end; ++j )
    {
      v9 = (float *)operator new(8u, i);
      if ( v9 )
      {
        *v9 = *(float *)&j->first;
        v9[1] = j->second;
      }
      ++i;
    }
    count = *end - *begin;
    size = (survarium::game_camera *)(this->m_end - this->m_begin);
    survarium::weapon_user_dead_state::finalize(size);
    new_size = (unsigned int)size - count;
    for ( k = &this->m_begin[(unsigned int)size - count]; k != this->m_end; ++k )
      ;
    this->m_end = &this->m_begin[new_size];
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)new_size);
  }
}


void __userpurge vostok::buffer_vector<vostok::memory::tester_pinned_resource>::erase(
        vostok::memory::tester_pinned_resource **end@<edi>,
        vostok::buffer_vector<vostok::memory::tester_pinned_resource> *this,
        vostok::memory::tester_pinned_resource *const *begin)
{
  vostok::memory::tester_pinned_resource *v3; // ecx
  vostok::memory::tester_pinned_resource *m_begin; // edx
  vostok::memory::tester_pinned_resource *i; // eax

  v3 = *end;
  m_begin = this->m_begin;
  if ( this->m_begin != *end )
  {
    for ( i = vostok::memory::s_pinned.m_end; v3 != i; ++m_begin )
    {
      if ( m_begin )
      {
        *(_QWORD *)&m_begin->res = *(_QWORD *)&v3->res;
        m_begin->unpin_time = v3->unpin_time;
        i = vostok::memory::s_pinned.m_end;
      }
      ++v3;
    }
    vostok::memory::s_pinned.m_end = &vostok::memory::s_pinned.m_begin[i
                                                                     - vostok::memory::s_pinned.m_begin
                                                                     - (*end
                                                                      - this->m_begin)];
  }
}
