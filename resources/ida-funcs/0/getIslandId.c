int __thiscall getIslandId(const btPersistentManifold *lhs)
{
  int result; // eax

  result = *((_DWORD *)lhs->m_body0 + 55);
  if ( result < 0 )
    return *((_DWORD *)lhs->m_body1 + 55);
  return result;
}
