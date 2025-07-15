bool __userpurge survarium::free_fly_camera::keyb_event_present@<al>(
        survarium::free_fly_camera *this@<ecx>,
        int a2@<eax>,
        int e)
{
  char *v3; // esi

  v3 = *(char **)(a2 + 224);
  return stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
           *(char **)(a2 + 220),
           &e,
           v3) != v3;
}
