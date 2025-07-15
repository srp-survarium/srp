char __userpurge survarium::swf_input_translator::process_mouse_move@<al>(
        survarium::swf_input_translator *this@<ecx>,
        float a2@<xmm0>,
        struct vostok::input::world *x,
        float y,
        float movie,
        float a5,
        struct survarium::flash_movie *a6)
{
  survarium::flash_movie::HandleMouseMove(
    (survarium::flash_movie *)this,
    movie,
    *(const float *)&x,
    y,
    COERCE_INT(a2 * 0.0083333338));
  return 1;
}
