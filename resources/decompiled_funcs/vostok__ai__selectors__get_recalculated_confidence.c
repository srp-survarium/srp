double __cdecl vostok::ai::selectors::get_recalculated_confidence(
        vostok::ai::ai_world *world,
        vostok::ai::percept_memory_object *object)
{
  return object->confidence
       - (double)(vostok::ai::ai_world::get_current_time_in_ms(world) - object->update_time) * 0.050000001 / 1000.0;
}
