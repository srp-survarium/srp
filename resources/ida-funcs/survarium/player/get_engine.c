survarium::engine *__thiscall survarium::player::get_engine(survarium::player *this)
{
  int v1; // eax

  v1 = *(int *)((char *)&dword_10F00 + (_DWORD)this);
  if ( v1 )
    return (survarium::engine *)(v1 + 12);
  else
    return 0;
}
