void __thiscall vostok::engine::engine_world::on_application_deactivate(vostok::engine::engine_world *this)
{
  _BYTE *v1; // esi
  bool v2; // zf

  v1 = (char *)&this->m_render_has_been_created + 2;
  v2 = BYTE2(this->m_render_has_been_created) == 0;
  BYTE1(this->m_render_has_been_created) = 0;
  if ( !v2 )
  {
    this->m_sound_world->__vftable[1].start_destruction(this->m_sound_world);
    *v1 = 0;
  }
}
