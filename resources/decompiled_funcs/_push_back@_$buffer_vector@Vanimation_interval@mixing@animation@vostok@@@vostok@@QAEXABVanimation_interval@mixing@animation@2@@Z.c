void __thiscall vostok::buffer_vector<vostok::animation::mixing::animation_interval>::push_back(
        vostok::buffer_vector<vostok::animation::mixing::animation_interval> *this,
        const vostok::animation::mixing::animation_interval *value)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::buffer_vector<vostok::animation::mixing::animation_interval>::construct(this->m_end, value);
  ++this->m_end;
}
