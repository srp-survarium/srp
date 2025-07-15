void __usercall survarium::global_input_handler::global_input_handler(
        survarium::game *game@<eax>,
        survarium::global_input_handler *this)
{
  g_input_handler.m_game = game;
  g_input_handler.__vftable = (survarium::global_input_handler_vtbl *)&survarium::global_input_handler::`vftable';
}
