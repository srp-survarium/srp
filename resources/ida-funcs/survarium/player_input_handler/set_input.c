void __usercall survarium::player_input_handler::set_input(
        survarium::player_input_handler *this@<eax>,
        const survarium::player_input *input@<edx>)
{
  survarium::input_mode_type_enum m_input_mode; // ecx

  m_input_mode = this->m_input_mode;
  if ( m_input_mode == first_person_mode || m_input_mode == third_person_mode )
    this->m_current_input = *input;
}
