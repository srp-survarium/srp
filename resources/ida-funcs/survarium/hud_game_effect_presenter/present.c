void __thiscall survarium::hud_game_effect_presenter::present(
        survarium::hud_game_effect_presenter *this,
        survarium::base_player *player)
{
  survarium::hud_game_effect_presenter::effect_data *m_begin; // edx
  survarium::hud_game_effect_presenter::effect_data *m_end; // edi
  survarium::hud_game_effect_presenter::effect_data *v5; // ecx
  vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *v6; // ecx
  int v7; // ecx
  int v8; // edi
  survarium::hud_game_effect_presenter::effect_data *v9; // edx
  survarium::hud_game_effect_presenter::effect_data *v10; // edi
  survarium::hud_game_effect_presenter::effect_data *v11; // ecx
  vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *v12; // ecx
  int v13; // edi
  survarium::loose_ptr_base *m_pointer; // ecx
  survarium::loose_ptr_base *v15; // ecx
  int v16; // ecx
  survarium::hud_game_effect_presenter::effect_data *v17; // eax
  vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *v18; // ecx
  survarium::hud_game_effect_presenter::effect_data *i; // esi
  survarium::hud_game_effect_presenter::effect_data *begin; // [esp+10h] [ebp-54h] BYREF
  survarium::hud_game_effect_presenter::effect_data *end; // [esp+14h] [ebp-50h] BYREF
  stlp_std::less<survarium::hud_game_effect_presenter::effect_data> __comp[4]; // [esp+18h] [ebp-4Ch]
  survarium::hud_game_effect_presenter::effect_data *__result; // [esp+1Ch] [ebp-48h] BYREF
  survarium::hud_game_effect_presenter::effect_data *v24; // [esp+20h] [ebp-44h]
  char *v25; // [esp+24h] [ebp-40h]
  _BYTE v26[60]; // [esp+28h] [ebp-3Ch] BYREF
  char vars0; // [esp+64h] [ebp+0h] BYREF

  if ( this->m_ui )
  {
    stlp_std::sort<survarium::hud_game_effect_presenter::effect_data *>(
      this->m_new_effects.m_begin,
      this->m_new_effects.m_end);
    __result = (survarium::hud_game_effect_presenter::effect_data *)v26;
    v24 = (survarium::hud_game_effect_presenter::effect_data *)v26;
    v25 = &vars0;
    vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::resize(
      (vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *)0xC,
      (int *)&__result,
      this->m_old_effects.m_end - this->m_old_effects.m_begin);
    m_begin = this->m_new_effects.m_begin;
    m_end = this->m_old_effects.m_end;
    v5 = this->m_old_effects.m_begin;
    end = v24;
    begin = stlp_std::priv::__set_difference<survarium::hud_game_effect_presenter::effect_data *,survarium::hud_game_effect_presenter::effect_data *,survarium::hud_game_effect_presenter::effect_data *,stlp_std::less<survarium::hud_game_effect_presenter::effect_data>>(
              v5,
              __result,
              m_end,
              (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)m_begin,
              (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)this->m_new_effects.m_end);
    vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::erase(
      v6,
      &__result,
      (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&begin,
      (const survarium::hud_game_effect_presenter::effect_data **)&end);
    v7 = 12;
    if ( v24 - __result )
    {
      v8 = 0;
      begin = (survarium::hud_game_effect_presenter::effect_data *)(v24 - __result);
      do
      {
        survarium::game_world_ui::remove_effect(
          (survarium::game_world_ui *)v7,
          (const survarium::hud_effects_enum)this->m_ui,
          __result[v8++].effect_type);
        begin = (survarium::hud_game_effect_presenter::effect_data *)((char *)begin - 1);
      }
      while ( begin );
    }
    vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::resize(
      (vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *)0xC,
      (int *)&__result,
      this->m_new_effects.m_end - this->m_new_effects.m_begin);
    v9 = this->m_old_effects.m_begin;
    v10 = this->m_new_effects.m_end;
    v11 = this->m_new_effects.m_begin;
    end = v24;
    begin = stlp_std::priv::__set_difference<survarium::hud_game_effect_presenter::effect_data *,survarium::hud_game_effect_presenter::effect_data *,survarium::hud_game_effect_presenter::effect_data *,stlp_std::less<survarium::hud_game_effect_presenter::effect_data>>(
              v11,
              __result,
              v10,
              (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v9,
              (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)this->m_old_effects.m_end);
    vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::erase(
      v12,
      &__result,
      (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&begin,
      (const survarium::hud_game_effect_presenter::effect_data **)&end);
    if ( v24 - __result )
    {
      v13 = 0;
      begin = (survarium::hud_game_effect_presenter::effect_data *)(v24 - __result);
      do
      {
        m_pointer = __result[v13].effect.m_object->m_pointer;
        if ( m_pointer )
          v15 = m_pointer - 1;
        else
          v15 = 0;
        survarium::game_world_ui::add_effect(
          (survarium::game_world_ui *)LOBYTE(v15[8].m_pointer),
          (const survarium::hud_effects_enum)this->m_ui,
          __result[v13++].effect_type,
          (unsigned __int8)v15[8].m_pointer);
        begin = (survarium::hud_game_effect_presenter::effect_data *)((char *)begin - 1);
      }
      while ( begin );
    }
    v16 = 12;
    v17 = (survarium::hud_game_effect_presenter::effect_data *)(this->m_new_effects.m_end - this->m_new_effects.m_begin);
    *(_DWORD *)&__comp[0].gap0 = &this->m_new_effects;
    if ( v17 )
    {
      begin = 0;
      end = v17;
      do
      {
        survarium::game_world_ui::update_effect(
          (survarium::game_world_ui *)begin,
          (const survarium::hud_effects_enum)this->m_ui,
          *(survarium::hud_effects_enum *)((char *)&begin->effect_type + (unsigned int)this->m_new_effects.m_begin),
          *(float *)((char *)&begin->frame_id + (unsigned int)this->m_new_effects.m_begin));
        ++begin;
        end = (survarium::hud_game_effect_presenter::effect_data *)((char *)end - 1);
      }
      while ( end );
    }
    stlp_std::swap<vostok::fixed_vector<survarium::hud_game_effect_presenter::effect_data,5>>(
      &this->m_old_effects,
      &this->m_new_effects,
      (vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *)v16);
    vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::clear(
      v18,
      *(survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> ***)&__comp[0].gap0);
    for ( i = __result; i != v24; ++i )
      survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>((survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)i);
  }
}
