void __userpurge survarium::human_npc::tick_animation_player(
        vostok::animation::subscribed_channel **current_time_in_ms@<eax>,
        survarium::human_npc *this)
{
  survarium::human_npc *v2; // ecx
  vostok::animation::mixing::n_ary_tree *p_m_mixing_tree; // [esp-Ch] [ebp-5Ch]
  _BYTE animated_object[64]; // [esp+10h] [ebp-40h] BYREF

  vostok::animation::animation_player::tick(
    (vostok::animation::animation_player *)this->m_model_instance.m_object,
    (int)this->m_model_instance.m_object->m_animation_player,
    current_time_in_ms);
  p_m_mixing_tree = &this->m_model_instance.m_object->m_animation_player->m_mixing_tree;
  vostok::animation::mixing::n_ary_tree::get_object_transform(
    p_m_mixing_tree,
    (vostok::math::float4x4 *)p_m_mixing_tree,
    animated_object);
  qmemcpy((void *)&this->m_transform, animated_object, sizeof(this->m_transform));
  survarium::human_npc::up_to_terrain(0, (int)this);
  survarium::human_npc::render_model(v2, (int)this);
}
