survarium::victory_items_container_core *__usercall survarium::simple_game_project::get_items_container@<eax>(
        survarium::simple_game_project *this@<edx>,
        unsigned __int8 id@<al>)
{
  void **M_start; // ecx
  void **M_finish; // edx

  M_start = this->m_victory_items_containers._M_impl._M_start;
  M_finish = this->m_victory_items_containers._M_impl._M_finish;
  if ( M_start == M_finish )
    return 0;
  while ( *((_BYTE *)*M_start + 52) != id )
  {
    if ( ++M_start == M_finish )
      return 0;
  }
  return (survarium::victory_items_container_core *)*M_start;
}
