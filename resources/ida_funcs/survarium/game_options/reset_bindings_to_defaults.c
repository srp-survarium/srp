void __usercall survarium::game_options::reset_bindings_to_defaults(
        survarium::game_options *this@<ecx>,
        survarium::game_options *a2@<esi>)
{
  survarium::game_options *v2; // ecx
  survarium::game_options *v3; // ecx

  survarium::key_binder::set_default_controls(a2->m_game->m_key_binder, a2->m_game->m_key_binder);
  survarium::game_options::reset_bindings(v2, a2, 0);
  survarium::game_options::apply_key_bindings(v3);
}
