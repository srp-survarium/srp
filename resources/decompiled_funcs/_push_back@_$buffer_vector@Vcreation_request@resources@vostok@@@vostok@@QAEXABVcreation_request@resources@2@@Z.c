void __thiscall vostok::buffer_vector<vostok::resources::creation_request>::push_back(
        vostok::buffer_vector<vostok::resources::creation_request> *this,
        const vostok::resources::creation_request *value)
{
  vostok::resources::creation_request *v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (vostok::resources::creation_request *)operator new(0x10u, (void *)this->m_end);
  if ( v3 )
    *v3 = *value;
  ++this->m_end;
}
