double __cdecl vostok::render::select_model_orientation()
{
  model_orientation_random.m_seed = 134775813 * model_orientation_random.m_seed + 1;
  return (double)((unsigned __int64)model_orientation_random.m_seed >> 12) * 0.00000095367432 * 6.2831855;
}
