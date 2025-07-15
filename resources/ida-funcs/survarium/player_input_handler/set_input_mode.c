void __usercall survarium::player_input_handler::set_input_mode(
        survarium::player_input_handler *this@<ecx>,
        survarium::input_mode_type_enum input_mode@<esi>)
{
  bool v2; // dl

  v2 = 0;
  if ( this->m_input_mode_changed || this->m_input_mode != input_mode )
    v2 = 1;
  this->m_input_mode_changed = v2;
  this->m_input_mode = input_mode;
}
