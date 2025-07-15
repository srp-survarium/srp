void __thiscall survarium::artefact<survarium::artefact_lifebone_core>::register_in_game_world(
        survarium::artefact<survarium::artefact_lifebone_core> *this,
        survarium::game_world_core *w)
{
  this->m_game_world_core = w;
  survarium::base_game_scene::register_drawable_object(this->m_game_world, &this->survarium::drawable_object);
}


void __thiscall survarium::artefact<survarium::artefact_onyx_core>::register_in_game_world(
        survarium::artefact<survarium::artefact_onyx_core> *this,
        survarium::game_world_core *w)
{
  this->m_game_world_core = w;
  survarium::base_game_scene::register_drawable_object(this->m_game_world, &this->survarium::drawable_object);
}


void __thiscall survarium::artefact<survarium::artefact_rattle_core>::register_in_game_world(
        survarium::artefact<survarium::artefact_rattle_core> *this,
        survarium::game_world_core *w)
{
  this->m_game_world_core = w;
  survarium::base_game_scene::register_drawable_object(this->m_game_world, &this->survarium::drawable_object);
}


void __thiscall survarium::artefact<survarium::artefact_spring_core>::register_in_game_world(
        survarium::artefact<survarium::artefact_spring_core> *this,
        survarium::game_world_core *w)
{
  this->m_game_world_core = w;
  survarium::base_game_scene::register_drawable_object(this->m_game_world, &this->survarium::drawable_object);
}
