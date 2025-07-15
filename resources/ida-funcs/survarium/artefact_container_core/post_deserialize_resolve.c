void __thiscall survarium::artefact_container_core::post_deserialize_resolve(
        survarium::artefact_container_core *this,
        survarium::game_world_core *game_world_core)
{
  survarium::usable_object::post_deserialize_resolve(
    this,
    (survarium::artefact_container_core *)((char *)this - 68),
    game_world_core);
}
