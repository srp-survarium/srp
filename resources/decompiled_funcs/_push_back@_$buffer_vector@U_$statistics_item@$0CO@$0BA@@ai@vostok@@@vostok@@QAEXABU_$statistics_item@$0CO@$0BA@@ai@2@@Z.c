void __thiscall vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::push_back(
        vostok::buffer_vector<vostok::ai::statistics_item<46,16> > *this,
        const vostok::ai::statistics_item<46,16> *value)
{
  vostok::ai::statistics_item<46,16> *v3; // [esp+60h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::ai::statistics_item<46,16> *)operator new(0x3F4u, this->m_end);
  if ( v3 )
    vostok::ai::statistics_item<46,16>::statistics_item<46,16>(v3, value);
  ++this->m_end;
}
