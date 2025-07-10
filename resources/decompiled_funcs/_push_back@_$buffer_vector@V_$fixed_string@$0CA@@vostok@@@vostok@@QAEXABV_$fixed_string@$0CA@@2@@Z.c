void __thiscall vostok::buffer_vector<vostok::fixed_string<32>>::push_back(
        vostok::buffer_vector<vostok::fixed_string<32> > *this,
        const vostok::fixed_string<32> *value)
{
  vostok::fixed_string<32> *v3; // [esp+28h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::fixed_string<32> *)operator new(0x2Cu, this->m_end);
  if ( v3 )
    vostok::fixed_string<32>::fixed_string<32>(v3, value);
  ++this->m_end;
}
