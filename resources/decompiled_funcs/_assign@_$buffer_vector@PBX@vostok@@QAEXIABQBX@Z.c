void __thiscall vostok::buffer_vector<void const *>::assign(
        vostok::buffer_vector<void const *> *this,
        survarium::game_camera *count,
        const void **value)
{
  const void **v4; // [esp+8h] [ebp-10h]
  const void **i; // [esp+Ch] [ebp-Ch]
  const void **I; // [esp+14h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = &this->m_begin[(_DWORD)count];
  survarium::weapon_user_dead_state::finalize(count);
  for ( I = this->m_begin; I != this->m_end; ++I )
  {
    v4 = (const void **)operator new(4u, I);
    if ( v4 )
      *v4 = *value;
  }
}
