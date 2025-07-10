void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::ai::weapon const *,unsigned int>>::push_back(
        vostok::buffer_vector<stlp_std::pair<char *,unsigned int> > *this,
        const stlp_std::pair<char *,unsigned int> *value)
{
  stlp_std::pair<char *,unsigned int> *v3; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (stlp_std::pair<char *,unsigned int> *)operator new(8u, this->m_end);
  if ( v3 )
    *v3 = *value;
  ++this->m_end;
}
