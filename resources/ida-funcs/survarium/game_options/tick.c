void __usercall survarium::game_options::tick(
        survarium::game_options *this@<esi>,
        const unsigned int frame_delta@<eax>,
        survarium::flash_movie *a3@<ecx>)
{
  survarium::flash_movie *v3; // ecx
  float delta_time; // [esp+8h] [ebp-4h]

  delta_time = (double)frame_delta * 0.001;
  survarium::flash_movie::Advance(a3, (int)this->m_options_ui.m_object->movie, delta_time, 0);
  survarium::flash_movie::Advance(v3, (int)this->m_cursor_ui.m_object->movie, delta_time, 0);
}
