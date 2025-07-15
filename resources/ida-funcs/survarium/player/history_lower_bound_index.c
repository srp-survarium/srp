unsigned int __userpurge survarium::player::history_lower_bound_index@<eax>(
        survarium::player *this@<ecx>,
        int a2@<esi>,
        unsigned int time_in_ms)
{
  unsigned int result; // eax
  int v4; // ebp

  result = *(int *)((char *)&dword_10E28 + a2);
  v4 = *(int *)((char *)&dword_10E2C + a2);
  if ( result == v4 )
    return -1;
  while ( 1 )
  {
    result = (*(int *)((char *)&dword_10E24 + a2) + result - 1) % *(int *)((char *)&dword_10E24 + a2);
    if ( *(_DWORD *)(96 * result + *(int *)((char *)&dword_10E1C + a2) + 92) <= time_in_ms )
      break;
    if ( result == v4 )
      return -1;
  }
  return result;
}
