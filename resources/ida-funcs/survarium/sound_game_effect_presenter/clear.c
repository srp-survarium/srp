void __thiscall survarium::sound_game_effect_presenter::clear(survarium::sound_game_effect_presenter *this)
{
  int v2; // edi
  int v3; // ebx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *p_sound; // eax

  if ( this->m_old_effects.m_end - this->m_old_effects.m_begin )
  {
    v2 = 0;
    v3 = this->m_old_effects.m_end - this->m_old_effects.m_begin;
    do
    {
      p_sound = &this->m_old_effects.m_begin[v2].sound;
      if ( p_sound->m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        p_sound->m_object->stop(p_sound->m_object);
      }
      ++v2;
      --v3;
    }
    while ( v3 );
  }
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)this->m_old_effects.m_begin,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&this->m_old_effects.m_end);
  this->m_old_effects.m_end = this->m_old_effects.m_begin;
}
