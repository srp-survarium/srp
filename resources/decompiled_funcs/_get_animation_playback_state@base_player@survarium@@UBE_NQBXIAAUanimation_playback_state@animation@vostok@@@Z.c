void __thiscall survarium::base_player::get_animation_playback_state(
        survarium::base_player *this,
        survarium::game_camera *object,
        unsigned int mask,
        vostok::animation::animation_playback_state *result)
{
  survarium::weapon_user_dead_state::finalize(object);
  JUMPOUT(0x8E61D);
}
