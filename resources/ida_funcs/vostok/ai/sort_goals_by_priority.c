BOOL __cdecl vostok::ai::sort_goals_by_priority(
        const vostok::ai::planning::goal *const first,
        const vostok::ai::planning::goal *const second)
{
  return second->m_priority < first->m_priority;
}
