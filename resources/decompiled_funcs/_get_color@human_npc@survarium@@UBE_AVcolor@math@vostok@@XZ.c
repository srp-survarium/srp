vostok::math::color *__thiscall survarium::human_npc::get_color(
        survarium::human_npc *this,
        vostok::math::color *result)
{
  vostok::math::color *v2; // eax

  v2 = result;
  *result = this->m_game_attributes.debug_draw_color;
  return v2;
}
