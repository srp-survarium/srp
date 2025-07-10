void __thiscall vostok::render::stage_light_propagation_volumes::execute(
        vostok::render::stage_light_propagation_volumes *this)
{
  unsigned int v2; // edi
  vostok::render::stage_light_propagation_volumes *v3; // ecx
  survarium::game_action_id *M_start; // ecx
  float v5; // ebp
  unsigned int v6; // edx
  vostok::math::float4x4 *v7; // ebx
  float propagation_step_index; // [esp+14h] [ebp-4h]

  if ( vostok::render::stage_light_propagation_volumes::is_effects_ready(this, this) )
  {
    v2 = 0;
    if ( *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 49)
      && this->is_enabled(this) )
    {
      if ( s_use_smooothed_lpv_value )
      {
        M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
        LODWORD(v5) = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                      + 35)
                    + 3;
        v6 = LODWORD(this->m_context->m_scene_view.m_object[4].m_current_satisfaction_update_tick) % LODWORD(v5);
        propagation_step_index = 0.0;
        v7 = (vostok::math::float4x4 *)v6;
        if ( v6 > 2 )
        {
          M_start = (survarium::game_action_id *)(v6 - 3);
          LODWORD(propagation_step_index) = v6 - 3;
        }
        if ( this->m_num_cascades )
        {
          do
            vostok::render::stage_light_propagation_volumes::execute_smoothed_impl(
              (vostok::render::stage_light_propagation_volumes *)M_start,
              (int)this,
              v2++,
              (unsigned int)v7,
              propagation_step_index,
              v7,
              v5);
          while ( v2 < this->m_num_cascades );
        }
      }
      else
      {
        vostok::render::stage_light_propagation_volumes::execute_impl(v3, this);
      }
    }
    else
    {
      this->execute_disabled(this);
    }
  }
}
