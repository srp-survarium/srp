void __thiscall vostok::render::stage_foreground::execute(vostok::render::stage_foreground *this)
{
  vostok::render::stage **m_begin; // eax
  vostok::render::stage **v3; // eax
  pix_event_wrapper_dx11 v4; // [esp+7h] [ebp-1h] BYREF

  pix_event_wrapper_dx11::pix_event_wrapper_dx11((pix_event_wrapper_dx11 *)this, &v4, (int)L"stage_foreground");
  m_begin = this->m_renderer->m_stages.m_begin;
  if ( m_begin[16] )
    m_begin[16]->execute_foreground(m_begin[16]);
  v3 = this->m_renderer->m_stages.m_begin;
  if ( v3[17] )
    v3[17]->execute_foreground(v3[17]);
  D3DPERF_EndEvent();
}
