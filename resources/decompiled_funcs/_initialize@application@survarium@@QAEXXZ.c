void __usercall survarium::application::initialize(
        survarium::application *this@<ecx>,
        survarium::application *a2@<eax>)
{
  vostok::engine::engine_world *v2; // ecx

  a2->m_exit_code = 0;
  survarium::application::preinitialize(this, a2);
  vostok::engine::engine_world::initialize(v2);
  PostMessageA(s_splash_screen, 2u, 0, 0);
}
