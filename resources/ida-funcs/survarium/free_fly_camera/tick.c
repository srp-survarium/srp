void __thiscall survarium::free_fly_camera::tick(survarium::free_fly_camera *this)
{
  unsigned int m_permanent_time_in_ms; // eax
  int *v3; // ecx
  float m_prev_delta_sec; // xmm0_4
  float v5; // xmm0_4
  int *M_start; // eax
  bool v7; // al
  bool v8; // al
  bool v9; // al
  survarium::free_fly_camera *v10; // ecx
  survarium::free_fly_camera *v11; // ecx
  survarium::free_fly_camera *v12; // ecx
  int *v13; // eax
  int *M_finish; // ebx
  int *v15; // eax
  survarium::free_fly_camera *v16; // ecx
  survarium::free_fly_camera *v17; // ecx
  survarium::free_fly_camera *v18; // ecx
  survarium::free_fly_camera *v19; // ecx
  int v20; // xmm0_4
  int *v21; // eax
  survarium::game_effect_player *v22; // ecx
  int *v23; // eax
  survarium::free_fly_camera *v24; // [esp+8h] [ebp-30h]
  int *v25; // [esp+10h] [ebp-28h]
  int *v26; // [esp+10h] [ebp-28h]
  int *v27; // [esp+10h] [ebp-28h]
  unsigned int v28; // [esp+18h] [ebp-20h]
  float v29; // [esp+1Ch] [ebp-1Ch] BYREF
  int v30; // [esp+20h] [ebp-18h] BYREF
  float v31; // [esp+24h] [ebp-14h]
  float v32; // [esp+28h] [ebp-10h] BYREF
  float v33; // [esp+2Ch] [ebp-Ch]
  float v34; // [esp+30h] [ebp-8h]
  float v35; // [esp+34h] [ebp-4h]

  m_permanent_time_in_ms = this->m_game_scene->m_game->m_permanent_time_in_ms;
  v3 = (int *)(m_permanent_time_in_ms - this->m_prev_time_ms);
  v28 = m_permanent_time_in_ms;
  v30 = (int)v3;
  m_prev_delta_sec = this->m_prev_delta_sec;
  v32 = (float)(unsigned int)v3;
  if ( m_prev_delta_sec >= 0.0 )
    v5 = (float)(m_prev_delta_sec * 0.89999998) + (float)(v32 * 0.1);
  else
    v5 = v32;
  this->m_prev_delta_sec = v5;
  this->m_prev_time_ms = m_permanent_time_in_ms;
  M_start = this->m_keyb_events._M_impl._M_start;
  v35 = v5 * 0.060000002;
  v31 = c_anim_center;
  if ( M_start != this->m_keyb_events._M_impl._M_finish )
    goto LABEL_37;
  v3 = this->m_mouse_events._M_impl._M_start;
  if ( v3 != this->m_mouse_events._M_impl._M_finish )
    goto LABEL_37;
  v32 = 0.0;
  v7 = vostok::math::is_similar<float>(&this->m_mouse_move.x, &v32, 0.0000099999997);
  v3 = v25;
  if ( !v7
    || (v32 = 0.0, v8 = vostok::math::is_similar<float>(&this->m_mouse_move.y, &v32, 0.0000099999997), v3 = v26, !v8)
    || (v32 = 0.0, v9 = vostok::math::is_similar<float>(&this->m_mouse_move.z, &v32, 0.0000099999997), v3 = v27, !v9) )
  {
LABEL_37:
    if ( survarium::free_fly_camera::keyb_event_present((survarium::free_fly_camera *)v3, (int)this, 29)
      || survarium::free_fly_camera::keyb_event_present(v10, (int)this, 157) )
    {
      v35 = v35 * 20.0;
    }
    if ( survarium::free_fly_camera::keyb_event_present(v10, (int)this, 42)
      || survarium::free_fly_camera::keyb_event_present(v11, (int)this, 54) )
    {
      v35 = v35 * 0.1;
    }
    if ( survarium::free_fly_camera::keyb_event_present(v11, (int)this, 56)
      || survarium::free_fly_camera::keyb_event_present(v12, (int)this, 184) )
    {
      v31 = satisfaction_equality_tolerance;
    }
    v13 = this->m_mouse_events._M_impl._M_start;
    M_finish = this->m_mouse_events._M_impl._M_finish;
    v32 = 0.0;
    v33 = 0.0;
    v34 = 0.0;
    v30 = 337;
    if ( stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
           (char *)v13,
           &v30,
           (char *)M_finish) != (char *)M_finish )
      v32 = v35 * 0.1;
    v15 = this->m_mouse_events._M_impl._M_start;
    v30 = 338;
    if ( stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
           (char *)v15,
           &v30,
           (char *)M_finish) != (char *)M_finish )
      v32 = v32 - (float)(v35 * 0.1);
    if ( survarium::free_fly_camera::keyb_event_present(v24, (int)this, 32) )
      v33 = v35 * 0.1;
    if ( survarium::free_fly_camera::keyb_event_present(v16, (int)this, 30) )
      v33 = v33 - (float)(v35 * 0.1);
    if ( survarium::free_fly_camera::keyb_event_present(v17, (int)this, 17) )
      v34 = v35 * 0.1;
    if ( survarium::free_fly_camera::keyb_event_present(v18, (int)this, 31) )
      v34 = v34 - (float)(v35 * 0.1);
    *(float *)&v20 = (float)(v31 * this->m_mouse_move.x) * 0.75;
    v29 = this->m_mouse_move.y * v31;
    v30 = v20;
    survarium::free_fly_camera::build_view_matrix(v19, (const vostok::math::float2 *)this, &v29, v32, v33, v34);
    v21 = this->m_keyb_events._M_impl._M_finish;
    if ( this->m_keyb_events._M_impl._M_start != v21 )
      this->m_keyb_events._M_impl._M_finish = (int *)stlp_std::priv::__copy_trivial(
                                                       (unsigned __int8 *)v21,
                                                       (unsigned __int8 *)v21,
                                                       (unsigned __int8 *)this->m_keyb_events._M_impl._M_start);
    v22 = (survarium::game_effect_player *)this->m_mouse_events._M_impl._M_start;
    v23 = this->m_mouse_events._M_impl._M_finish;
    if ( v22 != (survarium::game_effect_player *)v23 )
      this->m_mouse_events._M_impl._M_finish = (int *)stlp_std::priv::__copy_trivial(
                                                        (unsigned __int8 *)v23,
                                                        (unsigned __int8 *)v23,
                                                        (unsigned __int8 *)this->m_mouse_events._M_impl._M_start);
    this->m_mouse_move.x = 0.0;
    this->m_mouse_move.y = 0.0;
    this->m_mouse_move.z = 0.0;
    survarium::game_effect_player::tick(v22, &this->m_effect_player.m_current_time_in_ms, v28);
  }
}
