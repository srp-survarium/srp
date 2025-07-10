void __userpurge vostok::ai::sensors::vision_sensor::update_frustum_objects(
        vostok::ai::sensors::vision_sensor *this@<ecx>,
        float a2@<xmm0>,
        const vostok::ai::game_object *ai_game_object)
{
  vostok::ai::sensed_visual_object *it_object; // [esp+4h] [ebp-Ch]
  bool is_actually_visible; // [esp+Bh] [ebp-5h]
  vostok::ai::npc *testing_npc; // [esp+Ch] [ebp-4h]

  is_actually_visible = !vostok::ai::sensors::vision_sensor::check_if_in_blind_zones(this, ai_game_object);
  for ( it_object = this->m_visible_objects.m_first; it_object; it_object = it_object->next )
  {
    if ( it_object->object == ai_game_object && is_actually_visible )
    {
      it_object->is_in_frustum = 1;
      return;
    }
  }
  testing_npc = ai_game_object->cast_npc(ai_game_object);
  if ( (testing_npc && testing_npc != this->m_npc || !testing_npc) && is_actually_visible )
    vostok::ai::sensors::vision_sensor::add_new_visible_object(this, a2, ai_game_object);
}
