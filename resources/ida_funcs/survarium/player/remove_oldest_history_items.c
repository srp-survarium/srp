void __usercall survarium::player::remove_oldest_history_items(
        survarium::player *this@<ecx>,
        const unsigned int new_oldest_time_in_ms@<esi>)
{
  for ( ;
        *(int *)((char *)&dword_10E28 + (_DWORD)this) != *(int *)((char *)&dword_10E2C + (_DWORD)this);
        *(int *)((char *)&dword_10E2C + (_DWORD)this) = (unsigned int)(*(int *)((char *)&dword_10E2C + (_DWORD)this) + 1)
                                                      % *(int *)((char *)&dword_10E24 + (_DWORD)this) )
  {
    if ( *(_DWORD *)(96 * *(int *)((char *)&dword_10E2C + (_DWORD)this)
                   + *(int *)((char *)&dword_10E1C + (_DWORD)this)
                   + 92) >= new_oldest_time_in_ms )
      break;
  }
}
