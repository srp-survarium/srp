void __thiscall vostok::sound::ogg_source_cook::delete_resource(
        vostok::sound::ogg_source_cook *this,
        vostok::resources::resource_base *resource)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)resource);
}
