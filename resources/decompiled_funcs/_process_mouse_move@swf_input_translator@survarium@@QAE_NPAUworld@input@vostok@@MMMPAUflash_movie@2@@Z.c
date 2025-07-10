char __userpurge survarium::swf_input_translator::process_mouse_move@<al>(
        survarium::flash_movie *movie@<esi>,
        survarium::flash_movie *a2@<ecx>,
        survarium::swf_input_translator *this,
        vostok::input::world *__formal,
        unsigned int x,
        float y,
        const float scroll_delta)
{
  survarium::flash_movie::HandleMouseMove(a2, (int)movie, *(float *)&this, *(float *)&__formal, x);
  return 1;
}
