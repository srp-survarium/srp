bool __cdecl vostok::sound::compare_propagator_info_by_distance(
        const vostok::sound::propagator_info *lhs,
        const vostok::sound::propagator_info *rhs)
{
  return rhs->distance_to_listener > lhs->distance_to_listener;
}
