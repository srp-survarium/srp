void __thiscall vostok::buffer_vector<vostok::fixed_string<46>>::assign<vostok::fixed_string<46> const *>(
        vostok::buffer_vector<vostok::fixed_string<46> > *this,
        const vostok::fixed_string<46> *begin,
        const vostok::fixed_string<46> *const *end)
{
  vostok::fixed_string<46> *v4; // [esp+20h] [ebp-Ch]
  vostok::fixed_string<46> *I; // [esp+28h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_end = &this->m_begin[*end - begin];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  I = this->m_begin;
  while ( begin != *end )
  {
    v4 = (vostok::fixed_string<46> *)operator new(0x3Cu, I);
    if ( v4 )
      vostok::fixed_string<46>::fixed_string<46>(v4, begin);
    ++begin;
    ++I;
  }
}
