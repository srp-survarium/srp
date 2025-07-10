void __thiscall vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(
        vostok::buffer_vector<vostok::ai::planning::expression_parameter> *this,
        const vostok::ai::planning::expression_parameter *value)
{
  vostok::ai::planning::expression_parameter *v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::ai::planning::expression_parameter *)operator new(4u, this->m_end);
  if ( v3 )
    v3->instance = value->instance;
  ++this->m_end;
}
