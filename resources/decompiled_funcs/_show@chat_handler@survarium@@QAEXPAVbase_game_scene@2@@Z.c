void __usercall survarium::chat_handler::show(
        survarium::chat_handler *this@<esi>,
        survarium::base_game_scene *scene@<eax>,
        survarium::base_game_scene *a3@<ecx>)
{
  survarium::base_game_scene::show_movie(&this->m_chat_ui, a3, scene);
  this->m_active = 1;
}
