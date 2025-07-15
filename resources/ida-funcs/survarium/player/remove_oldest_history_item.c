void __thiscall survarium::player::remove_oldest_history_item(survarium::player *this)
{
  *(int *)((char *)&dword_10E2C + (_DWORD)this) = (unsigned int)(*(int *)((char *)&dword_10E2C + (_DWORD)this) + 1)
                                                % *(int *)((char *)&dword_10E24 + (_DWORD)this);
}
