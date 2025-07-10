void __cdecl dynamic_atexit_destructor_for__survarium::damage_model_cook::m_hit_types__()
{
  vostok::console_commands::command_token *i; // [esp+0h] [ebp-4h]

  for ( i = survarium::damage_model_cook::m_hit_types.m_begin; i != survarium::damage_model_cook::m_hit_types.m_end; ++i )
    ;
  survarium::damage_model_cook::m_hit_types.m_end = survarium::damage_model_cook::m_hit_types.m_begin;
}
