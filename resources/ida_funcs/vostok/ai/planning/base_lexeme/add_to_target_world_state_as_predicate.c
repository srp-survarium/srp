void __thiscall vostok::ai::planning::base_lexeme::add_to_target_world_state_as_predicate(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::specified_problem *problem,
        unsigned int *offset)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)offset);
}
