void __userpurge survarium::game_world::put_victory_item(
        survarium::game_world *this@<eax>,
        unsigned __int8 item_id@<cl>,
        const vostok::math::float4x4 *transform)
{
  this->m_victory_items._M_impl._M_start[item_id].m_object->put(
    this->m_victory_items._M_impl._M_start[item_id].m_object,
    this->m_physics_world,
    transform,
    &this->m_game->m_scheduler);
}
