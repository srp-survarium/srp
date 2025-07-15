void __thiscall vostok::render::engine::world::begin_render_options_changing(
        vostok::render::engine::world *this,
        volatile int *waiting_for)
{
  vostok::render::options *v2; // edi
  int v3[2]; // [esp+8h] [ebp-8h] BYREF

  v2 = vostok::quasi_singleton<vostok::render::options>::pinst;
  survarium::parse_resolution(s_r_resolution_value.m_begin, v3);
  v2->current.m_resolution_x = v3[0];
  v2->current.m_resolution_y = v3[1];
  qmemcpy(&v2->previous, &v2->current, sizeof(v2->previous));
  if ( waiting_for )
    _InterlockedExchange(waiting_for, 0);
}
