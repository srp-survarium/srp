void __thiscall vostok::buffer_vector<vostok::fixed_string<24>>::push_back(
        vostok::buffer_vector<vostok::fixed_string<24> > *this,
        const vostok::fixed_string<24> *value)
{
  vostok::fixed_string<24> *v3; // [esp+24h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::fixed_string<24> *)operator new(0x24u, this->m_end);
  if ( v3 )
    vostok::fixed_string<24>::fixed_string<24>(v3, value);
  ++this->m_end;
}
