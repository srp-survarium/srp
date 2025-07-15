void __userpurge survarium::game_world_ui::on_enemy_hitted(
        unsigned int bullet_id@<edx>,
        unsigned int victim_id@<eax>,
        survarium::game_world_ui *this,
        const bool pierced,
        const float pain_relative_amount)
{
  unsigned int m_my_last_bullet; // ecx
  survarium::game_world *m_game_world; // ecx
  float v8; // xmm0_4
  float collected_damage_amount; // xmm1_4
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  int v12; // edx
  survarium::flash_value *v13; // ecx
  survarium::game *v14; // ecx
  survarium::game_world *v15; // eax
  Scaleform::GFx::Value *v16; // esi
  int i; // edi
  survarium::flash_value v18; // [esp+Ch] [ebp-34h] BYREF
  _BYTE v19[24]; // [esp+24h] [ebp-1Ch] BYREF
  char v20; // [esp+3Ch] [ebp-4h] BYREF

  m_my_last_bullet = this->m_my_last_bullet;
  if ( bullet_id > m_my_last_bullet || m_my_last_bullet == -1 )
  {
    this->m_my_last_bullet = bullet_id;
    if ( victim_id != this->m_dealt_damage_collector.victim_id
      || this->m_game_world->get_current_time_in_ms(this->m_game_world)
       - this->m_dealt_damage_collector.last_hit_time_in_ms > s_damage_collector_timeout_in_ms )
    {
      this->m_dealt_damage_collector.victim_id = -1;
      this->m_dealt_damage_collector.last_hit_time_in_ms = 0;
      this->m_dealt_damage_collector.collected_damage_amount = 0.0;
    }
    m_game_world = this->m_game_world;
    this->m_dealt_damage_collector.collected_damage_amount = (float)(s_hit_mark_damage_amount_koef * pain_relative_amount)
                                                           + this->m_dealt_damage_collector.collected_damage_amount;
    v8 = 0.0;
    this->m_dealt_damage_collector.last_hit_time_in_ms = m_game_world->get_current_time_in_ms(m_game_world);
    this->m_dealt_damage_collector.victim_id = victim_id;
    collected_damage_amount = this->m_dealt_damage_collector.collected_damage_amount;
    if ( collected_damage_amount > 0.0 )
    {
      v8 = s_bm_current_air_resistance;
      if ( s_bm_current_air_resistance >= collected_damage_amount )
        v8 = this->m_dealt_damage_collector.collected_damage_amount;
    }
    this->m_dealt_damage_collector.collected_damage_amount = v8;
    v10 = &v18;
    do
    {
      survarium::flash_value::flash_value(v10);
      v10 = v11 + 1;
    }
    while ( v12 - 1 >= 0 );
    survarium::flash_value::SetNumber(v10, (int)&v18, this->m_dealt_damage_collector.collected_damage_amount);
    survarium::flash_value::SetUInt(v13, (int)v19, s_enemy_hit_mark_timeout_in_ms);
    Scaleform::GFx::Movie::Invoke(
      this->m_game_hud_ui.m_object->movie->m_movie,
      "root.crosshair_enemy_hit",
      0,
      (const Scaleform::GFx::Value *)&v18,
      2u);
    v15 = this->m_game_world;
    if ( pierced )
      survarium::game::play_ui_sound(v14, (int)v15->m_game, 0xBu);
    else
      survarium::game::play_ui_sound(v14, (int)v15->m_game, 0xCu);
    v16 = (Scaleform::GFx::Value *)&v20;
    for ( i = 1; i >= 0; --i )
      Scaleform::GFx::Value::~Value(--v16);
  }
}
