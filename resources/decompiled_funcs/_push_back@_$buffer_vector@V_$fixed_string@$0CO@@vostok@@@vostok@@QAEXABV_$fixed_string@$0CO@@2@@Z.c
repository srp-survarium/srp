void __thiscall vostok::buffer_vector<vostok::fixed_string<46>>::push_back(
        vostok::buffer_vector<vostok::fixed_string<46> > *this,
        const vostok::fixed_string<46> *value)
{
  vostok::fixed_string<46> *v3; // [esp+24h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::fixed_string<46> *)operator new(0x3Cu, this->m_end);
  if ( v3 )
    vostok::fixed_string<46>::fixed_string<46>(v3, value);
  ++this->m_end;
}
