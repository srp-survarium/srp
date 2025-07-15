void __thiscall vostok::ai::navigation::navigation_world::~navigation_world(
        vostok::ai::navigation::navigation_world *this)
{
  this->__vftable = (vostok::ai::navigation::navigation_world_vtbl *)&vostok::ai::navigation::navigation_world::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_graph_generator);
}
